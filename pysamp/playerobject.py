from typing import Tuple

from pysamp.event import event

from samp import OBJECT_MATERIAL_SIZE_256x128

from pysamp import (
    attach_player_object_to_vehicle,
    create_player_object,
    destroy_player_object,
    edit_player_object,
    get_player_object_model,
    get_player_object_pos,
    get_player_object_rot,
    is_player_object_moving,
    is_valid_player_object,
    move_player_object,
    set_player_object_material,
    set_player_object_material_text,
    set_player_object_no_camera_col,
    set_player_object_pos,
    set_player_object_rot,
    stop_player_object,
)


class PlayerObject:
    """Create, modify and remove Player Objects using this class.

    Player Objects are almost same as normal objects, except for that they
    are only shown for the player they are created for.

    Situations you can consider objects like these, are to preview things for
    a player, maybe while they are adjusting said thing. Could be used for
    custom gate systems, where you only want the player to see what they are
    working on. Or race in systems if you want to show an object for a player
    in a checkpoint or so.

    If you are looking to attach an object to a player, have a look at
    :meth:`pysamp.player.Player.set_attached_object`

    In order to create a new player object, please use :meth:`~create`.

    .. note:: Please note that the global object limit still applies to player
        objects.
    """

    def __init__(self, id: int, player_id: int):
        self.id = id
        self._player_id = player_id

    def get_player(self) -> "Player":
        """Get the player who owns the player object.

        :returns: An instance of :class:~`pysamp.player.Player`
        """
        return Player(self._player_id)

    @classmethod
    def create(
        cls,
        player: "Player",
        model_id: int,
        x: float,
        y: float,
        z: float,
        rotation_x: float,
        rotation_y: float,
        rotation_z: float,
        draw_distance: float,
    ) -> "PlayerObject":
        """Create a player object.

        :param Player player: The player that should have an object created.
        :param int model_id: Which model of the object to create.
        :param float x: The world x-coordinate to create the object at.
        :param float y: The world y-coordinate to create the object at.
        :param float z: The world z-coordinate to create the object at.
        :param float rotation_x: X-axis rotation of the object.
        :param float rotation_y: Y-axis rotation of the object.
        :param float rotation_z: Z-axis rotation of the object.
        :param optional float draw_distance: The distance at which the object
            should start being visible at.
        :returns: An instance of :class:`~PlayerObject`.

        """
        return cls(
            create_player_object(
                player.id,
                model_id,
                x,
                y,
                z,
                rotation_x,
                rotation_y,
                rotation_z,
                draw_distance,
            ),
            player.id,
        )

    def attach_to_vehicle(
        self,
        vehicle: "Vehicle",
        offset_x: float,
        offset_y: float,
        offset_z: float,
        rotation_x: float,
        rotation_y: float,
        rotation_z: float,
    ) -> bool:
        """Attach the player object to a vehicle.

        :param Vehicle vehicle: The vehicle to attach the player object to.
        :param float offset_x: X-coordinate relative to car center.
        :param float offset_y: Y-coordinate relative to car center.
        :param float offset_z: Z-coordinate relative to car center.
        :param float rotation_x: X-axis rotation of the object.
        :param float rotation_y: Y-axis rotation of the object.
        :param float rotation_z: Z-axis rotation of the object.
        :returns: No return value.

        .. note:: You need to create the object before attaching it.
            If you are calling this method after :meth:`~set_material_text`
            you most likely will lose the text. Call this method first, then
            call :meth:`~set_material_text` after to circumvent it.
        """
        return attach_player_object_to_vehicle(
            self._player_id,
            self.id,
            vehicle.id,
            offset_x,
            offset_y,
            offset_z,
            rotation_x,
            rotation_y,
            rotation_z,
        )

    def set_material_text(
        self,
        text: str,
        material_index: int = 0,
        material_size: int = OBJECT_MATERIAL_SIZE_256x128,
        font_face: str = "Arial",
        font_size: int = 24,
        bold: bool = True,
        font_color: int = 4294967295,
        back_color: int = 0,
        text_alignment: int = 0,
    ) -> bool:
        """Replace the texture of a player object with text.

        :param str text: The text to set. Max 2048 characters.
        :param optional int material_index: The material index to replace with
            text. Default is 0. Valid values are 0-15.
        :param optional int material_size: The size of the material.
            Default size is 256x128. See table below for all possible values.
        :param optional str font_face: The font to use. Default is "Arial".
        :param optional int font_size: The size of the font. Default is 24.
        :param optional bool bold: Whether the text should be bold or not.
        :param optional int font_color: The color of the text.
            Default is white (-1).
        :param optional int back_color: The background color.
            Default is transparent.
        :param optional int text_alignment: The alignment of the text. Can be
            0 (left), 1 (center) or 2 (right). Default value is 0.
        :returns: No return value.

        .. list-table:: material_size's for :meth:`set_material_text`.
            :widths: 30 25
            :header-rows: 1

            * - Constant
              - Value as integer
            * - OBJECT_MATERIAL_SIZE_32x32
              - 10
            * - OBJECT_MATERIAL_SIZE_64x32
              - 20
            * - OBJECT_MATERIAL_SIZE_64x64
              - 30
            * - OBJECT_MATERIAL_SIZE_128x32
              - 40
            * - OBJECT_MATERIAL_SIZE_128x64
              - 50
            * - OBJECT_MATERIAL_SIZE_128x128
              - 60
            * - OBJECT_MATERIAL_SIZE_256x32
              - 70
            * - OBJECT_MATERIAL_SIZE_256x64
              - 80
            * - OBJECT_MATERIAL_SIZE_256x128
              - 90
            * - OBJECT_MATERIAL_SIZE_256x256
              - 100
            * - OBJECT_MATERIAL_SIZE_512x64
              - 110
            * - OBJECT_MATERIAL_SIZE_512x128
              - 120
            * - OBJECT_MATERIAL_SIZE_512x256
              - 130
            * - OBJECT_MATERIAL_SIZE_512x512
              - 140

        """
        return set_player_object_material_text(
            self._player_id,
            self.id,
            text,
            material_index,
            material_size,
            font_face,
            font_size,
            bold,
            font_color,
            back_color,
            text_alignment,
        )

    def set_position(self, x: float, y: float, z: float) -> bool:
        """Set the world coordinates of the player object

        :param float x: The world x coordinate to set.
        :param float y: The world y coordinate to set.
        :param float z: The world z coordinate to set.
        :returns: No return value.
        """
        return set_player_object_pos(self._player_id, self.id, x, y, z)

    def set_rotation(
        self, rotation_x: float, rotation_y: float, rotation_z: float
    ) -> bool:
        """Set object rotation values.

        :param float rotation_x: The object x rotation to set.
        :param float rotation_y: The object y rotation to set.
        :param float rotation_z: The object z rotation to set.
        :returns: No return value.
        """
        return set_player_object_rot(
            self._player_id, self.id, rotation_x, rotation_y, rotation_z
        )

    def get_position(self) -> Tuple[float, float, float]:
        """Get the current coordinates for the player object.

        :returns: A tuple with 3 floats; The x, y and z coordinate.
        """
        return get_player_object_pos(self._player_id, self.id)

    def get_rotation(self) -> Tuple[float, float, float]:
        """Get the current rotation values for the player object.

        :returns: A tuple with 3 floats; The x, y and z rotation.
        """
        return get_player_object_rot(self._player_id, self.id)

    def edit(self) -> bool:
        """Put the player in edit mode to move/rotate the object.

        :returns: No return value.
        """
        return edit_player_object(self._player_id, self.id)

    def get_model(self) -> int:
        """Get the current object model the player object is.

        :returns: An integer representing the object model.
        """
        return get_player_object_model(self._player_id, self.id)

    def set_no_camera_col(self) -> bool:
        """Disable player object camera collision.

        :returns: No return value.
        """
        return set_player_object_no_camera_col(self._player_id, self.id)

    def is_valid(self) -> bool:
        """Check if the player object is valid.

        :returns: True/False depending on it if is valid or not.
        """
        return is_valid_player_object(self._player_id, self.id)

    def destroy(self) -> bool:
        """Destroys the player object.

        This removes the object for the player, and it can no longer be
        interacted with.

        :returns: No return value.
        """
        return destroy_player_object(self._player_id, self.id)

    def move(
        self,
        x: float,
        y: float,
        z: float,
        speed: float,
        rotation_x: float = -1000.0,
        rotation_y: float = -1000.0,
        rotation_z: float = -1000.0,
    ) -> int:
        """Move and rotate the player object to given values.

        Rotation values should be ``-1000`` if you don't want to modify
        the object rotation.

        :param float x: The new x-coordinate you want to move the object to.
        :param float y: The new y-coordinate you want to move the object to.
        :param float z: The new z-coordinate you want to move the object to.
        :param float speed: The speed of the object moving from old to new pos.
        :param float rotation_x: The new object x rotation to set.
        :param float rotation_y: The new object y rotation to set.
        :param float rotation_z: The new object z rotation to set.
        :returns: The time in milliseconds it takes to move the object.

        .. note:: The rotation will only work if you also move the object. If
            you do not give it new x,y,z, the rotation will not apply.
        """
        return move_player_object(
            self._player_id,
            self.id,
            x,
            y,
            z,
            speed,
            rotation_x,
            rotation_y,
            rotation_z,
        )

    def stop(self) -> bool:
        """Stop a moving player object.

        This method will only have an effect if you used :meth:`~move` first.

        :returns: No return value.
        """
        return stop_player_object(self._player_id, self.id)

    def is_moving(self) -> bool:
        """Check if the player object is currently moving.

        :returns: A bool (True/False) depending on if it is moving or not.
        """
        return is_player_object_moving(self._player_id, self.id)

    def set_material(
        self,
        material_index: int,
        model_id: int,
        txd_name: str,
        texture_name: str,
        material_color: int = 0,
    ) -> bool:
        """Replace the texture of a player-object with the texture from
        another model in the game.

        .. note:: Vertex lightning of the object will disappear if material
            color is changed.

        .. warning:: You MUST use ARGB color format, not RGBA like used
            in client messages etc.

        :param int material_index: 	The material index on the object to change
            (0 to 15).
        :param int model_id: The modelid on which replacement texture is
            located. Use 0 for alpha.
            Use -1 to change the material color without altering the existing
            texture.
        :param str txd_name: The name of the txd file which contains the
            replacement texture (use "none" if not required).
        :param str texture_name: The name of the texture to use as the
            replacement (use "none" if not required).
        :param int material_color: The object color to set, as an integer or
            hex in ARGB format. Using 0 keeps the existing material color.
        :returns: No return value.
        """
        return set_player_object_material(
            self._player_id,
            self.id,
            material_index,
            model_id,
            txd_name,
            texture_name,
            material_color,
        )

    @event("OnPlayerObjectMoved")
    def on_moved(cls, player_id: int, object_id: int):
        """This event is called when a player object is moved after
        :meth:`PlayerObject.move()` (when it stops moving).

        :param int player_id: The player id the object is assigned to.
        :param int object_id: The ID of the player object that was moved.
        :returns: No return value.
        """
        return (cls(object_id, player_id), Player(object_id))

from pysamp.player import Player  # noqa
from pysamp.vehicle import Vehicle  # noqa
