from pysamp import (
    create_object,
    get_object_model,
    get_object_pos,
    set_object_pos,
    set_object_rot,
    get_object_rot,
    set_object_no_camera_col,
    is_valid_object,
    destroy_object,
    move_object,
    stop_object,
    is_object_moving,
    set_object_material,
    set_object_material_text,
    set_objects_default_camera_col
)
from pysamp.event import event
from samp import (
    OBJECT_MATERIAL_SIZE_256x128
)

from typing import Tuple


class Object:
    """Class that creates and handles global objects.

    To create a new object, check :meth:`Object.create`.

    For player objects, check out :class:`pysamp.PlayerObject`.

    Objects are world objects represented by what object they are (model), and
    where they are created. They can be moved, rotated and customized with
    non-default textures.

    It is recommended to use a streamer if you need more than 1000 objects.
    SA-MP has a limit if approximately 1000 objects. Bypassing this limit will
    cause all objects to disappear.

    For a list of models, you can utilize tools like here:
    https://dev.prineside.com/en/gtasa_samp_model_id/
    """

    def __init__(
        self,
        id: int,
    ) -> None:
        self.id = id

    @classmethod
    def create(
        cls,
        model: int,
        x: float,
        y: float,
        z: float,
        rotation_x: float,
        rotation_y: float,
        rotation_z: float,
        draw_distance: float = 0.0
    ) -> "Object":
        """Create a new object.

        :return: An instance of an :class:`Object`.
        """
        return cls(create_object(
            model, x, y, z, rotation_x, rotation_y, rotation_z, draw_distance
        ))

    def set_position(self, x: float, y: float, z: float) -> bool:
        """Set a new position for the object using world coordinates.

        For rotation, check out ``Object.set_rotation``.
        """
        return set_object_pos(self.id, x, y, z)

    def get_position(self) -> Tuple[float, float, float]:
        """Retrieve the coordinates for where the object is right now."""
        return get_object_pos(self.id)

    def set_rotation(
        self,
        rotation_x: float,
        rotation_y: float,
        rotation_z: float
    ) -> bool:
        """Set the new rotation the object should have."""
        return set_object_rot(self.id, rotation_x, rotation_y, rotation_z)

    def get_rotation(self) -> Tuple[float, float, float]:
        """Get the rotation the object currently have."""
        return get_object_rot(self.id)

    def get_model(self) -> int:
        """Get the model of the object."""
        return get_object_model(self.id)

    def set_no_camera_collision(self) -> bool:
        """Disable camera collision on the object.

        Makes the camera freely pass through it.

        .. note:: This only works outside the map boundaries (past -3000/3000\
            on the X and Y axis).
        """
        return set_object_no_camera_col(self.id)

    def is_valid(self) -> bool:
        """Check if the object exists."""
        return is_valid_object(self.id)

    def destroy(self) -> bool:
        """Destroy the object.

        This removes the object from the world, and will no longer be
        available. It's occupied object id gets free'd up.
        """
        return destroy_object(self.id)

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
        """Move and rotate the object to given values.

        Rotation values should be -1000 if you don't want to modify the object
        rotation.

        Returns the time in seconds it takes to move the object.
        """
        return move_object(
            self.id, x, y, z, speed, rotation_x, rotation_y, rotation_z
        )

    def stop(self) -> bool:
        """Stop moving the object."""
        return stop_object(self.id)

    def is_moving(self) -> bool:
        """Check if the object is currently moving."""
        return is_object_moving(self.id)

    def set_material(
        self,
        material_index: int,
        model_id: int,
        txd_name: str,
        texture_name: str,
        material_color: int = 0
    ) -> bool:
        """Change the object materials.

        The material can be from another object model in the game.

        .. note:: Vertex lighting of the object will disappear if material\
            color is changed.

        .. warning:: You MUST use ARGB color format, not RGBA.
        """
        return set_object_material(
            self.id,
            material_index,
            model_id,
            txd_name,
            texture_name,
            material_color,
        )

    def set_material_text(
        self,
        text: str,
        material_index: int = 0,
        material_size: int = OBJECT_MATERIAL_SIZE_256x128,
        font_face: str = "Arial",
        font_size: int = 24,
        bold: bool = True,
        font_color: int = 0xFFFFFFFF,
        back_color: int = 0x00000000,
        text_alignment: int = 0
    ) -> bool:
        """Change the material text of the object.

        Example of usage:

        .. code-block:: python

            if "/text" in cmdtext:
                object = Object(19353, 0, 0, 10, 0.0, 0.0, 90.0)
                object.set_material_text(
                    "Here is text!",  # desired text
                    0,  # material index
                    OBJECT_MATERIAL_SIZE_256x128,  # material size
                    "Arial",  # font face
                    28,  # font size
                    False,  # bold?
                    0xFFFF8200,  # font color (ARGB format)
                    0xFF000000,  # background color (ARGB format)
                    OBJECT_MATERIAL_TEXT_ALIGN_CENTER  # alignment
                )
            # write "Here is text!" on the object, with orange font color
            # and black background

        .. note:: Text does not update after 16 calls on the same object.

        .. warning:: The color format is ARGB opposed to how RGBA format.
        """
        return set_object_material_text(
            self.id,
            text,
            material_index,
            material_size,
            font_face,
            font_size,
            bold,
            font_color,
            back_color,
            text_alignment
        )

    @staticmethod
    def set_default_camera_col(disable: bool) -> bool:
        """Set whether all object should by default ignore colission.

        Please note that this is a static method as it is affecting all
        objects. You call it like this:

        .. code-block:: python

            # Disable camera colission by default on all objects:
            Object.set_default_camera_col(True)
        """
        return set_objects_default_camera_col(disable)

    @event("OnObjectMoved")
    def on_moved(cls, object_id: int):
        """This event is called when an object stops moving after
        :meth:`Object.move()`.

        :param int object_id: The ID of the object that was moved.
        :returns: No return value.

        .. note:: :meth:`set_position` does not work when used in this
            event. To fix it, recreate the object.
        """
        return (cls(object_id),)
