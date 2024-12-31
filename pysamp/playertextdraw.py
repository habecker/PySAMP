"""Textdraws that are per-player. For global textdraws that are shown for
all players, check out :class:`TextDraw`.
"""

from pysamp import (
    create_player_text_draw,
    player_text_draw_alignment,
    player_text_draw_background_color,
    player_text_draw_box_color,
    player_text_draw_color,
    player_text_draw_destroy,
    player_text_draw_font,
    player_text_draw_hide,
    player_text_draw_letter_size,
    player_text_draw_set_outline,
    player_text_draw_set_preview_model,
    player_text_draw_set_preview_rot,
    player_text_draw_set_preview_veh_col,
    player_text_draw_set_proportional,
    player_text_draw_set_selectable,
    player_text_draw_set_shadow,
    player_text_draw_set_string,
    player_text_draw_show,
    player_text_draw_text_size,
    player_text_draw_use_box,
)
from pysamp.player import Player


class PlayerTextDraw:
    """Textdraws that are per-player. For global textdraws that are shown for
    all players, check out :class:`TextDraw`.

    :param id: The ID that represents a textdraw.

    Players can have up to 256 textdraws shown of this type at once.
    Exceeding this will cause issues with other textdraws.

    To create a new textdraw, use :meth:`PlayerTextDraw.create`.
    """

    def __init__(self, id: int, player: "Player") -> None:
        self.id = id
        self.player = player

    @classmethod
    def create(
        cls, player: "Player", x: float, y: float, text: str
    ) -> "PlayerTextDraw":
        """Create a textdraw for the player.

        :param Player player: The :class:`Player` to create the Textdraw for.
        :param float x: the x-position on the screen.
        :param float y: the y-position on the screen.
        :param str text: The text to show.
        :return: An instance of :class:`PlayerTextDraw`.

        .. note::
            - The (0,0) coordinate is the top left coordinate for the textdraw\
                area based on a 640x448 "canvas" (irrespective of screen\
                resolution). If you plan on using\
                ``player.text_draw_alignment()`` with alignment 3 (right),\
                the x,y coordinate is the *top right* coordinate\
                for the textdraw.
            - This function only "creates" the textdraw, you must use\
                ``player.text_draw_show()`` to show it to a player.
            - It is recommended to use WHOLE numbers instead of decimal\
                positions when creating player textdraws to ensure resolution\
                friendly design.
            - Player-textdraws are automatically destroyed when a player\
                disconnects
            - Keyboard key mapping codes (such as ``~k~~VEHICLE_ENTER_EXIT~``)\
                Doesn't work beyond 255th character.

        .. warning::
            - If you choose values for y that are less than 1, the first\
                text row will be invisible and only the shadow is visible.
            - ``text`` must NOT be empty or the server will crash.\
                Use " " (a space) or _ (underscore) instead.
            - If the last character in the text is a space (" "),\
                the text will all be blank.
            - If part of the text is off-screen, the color of the text will\
                not show, only the shadow (if enabled) will.
        """
        return cls(create_player_text_draw(player.id, x, y, text), player)

    def destroy(self) -> bool:
        """Destroy the player textdraw.

        :return: Does not return anything.
        """
        return player_text_draw_destroy(self.player.id, self.id)

    def letter_size(self, x: float, y: float) -> bool:
        """Sets the width and height of the letters in a player-textdraw.

        :param float x: Width of a character.
        :param float y: Height of a character.
        :return: Does not return anything.

        .. note::
            - Fonts appear to look the best with an X to Y ratio of 1 to 4.\
                (E.g. if ``x`` is 0.5 then ``y`` should be 2).
            - When using this function purely for the benefit of affecting the\
                textdraw box, multiply ``Y`` by 0.135 to convert to\
                text_size-like measurements
        """
        return player_text_draw_letter_size(self.player.id, self.id, x, y)

    def text_size(self, x: float, y: float) -> bool:
        """Change the size of the player-textdraw (box if :meth:`use_box`
        is enabled and/or clickable area for use with
        :meth:`set_selectable`).

        :param float x: The size on the X axis (left/right) following the same
            640x480 grid as :meth:`create`.
        :param float y: The size on the Y axis (up/down) following the same
            640x480 grid as :meth:`create`.
        :return: Does not return any value.

        .. note::
            The x and y have different meanings with different
            :meth:`alignment` values:

                1. (left): they are the right-most corner of the box,\
                    absolute coordinates.
                2. (center): they need to inverted (switch the two) and the\
                    x value is the overall width of the box.
                3. (right): the x and y are the coordinates of the left-most\
                    corner of the box

            Using font type 4 (sprite) and 5 (model preview) converts X and
            Y of this function from corner coordinates to WIDTH and HEIGHT
            (offsets).

        The TextDraw box starts 10.0 units up and 5.0 to the left as the origin
        (:meth:`create`).

        This function defines the clickable area for use with
        :meth:`set_selectable`, whether a box is shown or not.
        """
        return player_text_draw_text_size(self.player.id, self.id, x, y)

    def alignment(self, alignment: int) -> bool:
        """Set the text-alignment of the player-textdraw.

        :param int alignment: Alignment can be 1: left, 2: center, 3: right.
        :return: This method does not return anything.

        .. note::
            For alignment 2 (center) the x and y values of :meth:`text_size`
            need to be swapped.
        """
        return player_text_draw_alignment(self.player.id, self.id, alignment)

    def color(self, color: int) -> bool:
        """Sets the text color of the player-textdraw.

        :param int color: The color you want to give the textdraw, in a
            ``0xRRGGBBAA`` format.

        You can also use :meth:`~pysamp.player.game_text`
        colors (like ``~r~`` and ``~w~``) directly in
        the text if you want.

        .. note:: The textdraw must be re-shown to the player in order to
            update the color.
        """
        return player_text_draw_color(self.player.id, self.id, color)

    def use_box(self, use: bool) -> bool:
        """Toggle the box on the textdraw.

        :param bool use: ``True`` to use a box, ``False`` to hide the box.
        :return: This method does not return anything.
        """
        return player_text_draw_use_box(self.player.id, self.id, use)

    def box_color(self, color: int) -> bool:
        """Sets the text color of a player-textdraw box.

        :param int color: Color in ``0xRRGGBBAA`` format.
        :return: This method does not return anything.
        """
        return player_text_draw_box_color(self.player.id, self.id, color)

    def set_shadow(self, size: int) -> bool:
        """Adds a shadow to the bottom-right side of the text in a
        player-textdraw. The shadow font matches the text font.

        :param int size: The size of the shadow. 0 will hide the shadow.
        :return: No value is returned.

        .. note::
            The shadow can be cut by the box area if the size is set too big
            for the area.

        """
        return player_text_draw_set_shadow(self.player.id, self.id, size)

    def set_outline(self, size: int) -> bool:
        """Set the outline of a player-textdraw. The outline colour cannot be
        changed unless :meth:`background_color` is used.

        :param int size: The thickness of the outline.
        :return: This method does not return anything.
        """
        return player_text_draw_set_outline(self.player.id, self.id, size)

    def background_color(self, color: int) -> bool:
        """Change the textdraw's background color.

        :param int color: The color that the textdraw should be set to.
        :return: This method does not return anything.

        .. note::
            - If :meth:`set_outline` is used with size > 0, the outline\
              color will match the color used in :meth:`background_color`.
            - Changing the value of color seems to alter the color used in\
              :meth:`color`
        """
        return player_text_draw_background_color(
            self.player.id, self.id, color
        )

    def font(self, font: int) -> bool:
        """Change the font of a textdraw.

        :param int font: A font ID to give the textdraw (0-3).
        :return: No value is returned.

        See all fonts here:
        https://www.open.mp/docs/scripting/functions/PlayerTextDrawFont

        .. warning:: Setting the ``font`` above 3 may crash the client.
        """
        return player_text_draw_font(self.player.id, self.id, font)

    def set_proportional(self, set: bool) -> bool:
        """Appears to scale text spacing to a proportional ratio.
        Useful when using :meth:`letter_size` to ensure the text has an
        even character spacing.

        :param bool set: ``True`` to enable proportionality,
            ``False`` to disable.
        :return: Does not return anything.
        """
        return player_text_draw_set_proportional(self.player.id, self.id, set)

    def set_selectable(self, set: bool) -> bool:
        """Set the textdraw selectable.

        :param bool set: Toggle the textdraw selectable or not.
        :return: No return value.

        .. warning:: This method _must_ be used before the textdraw is shown to
            the player.

        :meth:`text_size` defines the clickable area.
        """
        return player_text_draw_set_selectable(self.player.id, self.id, set)

    def show(self) -> bool:
        """Use this method to show the player-textdraw for the player.

        :return: This method does not return anything.
        """
        return player_text_draw_show(self.player.id, self.id)

    def hide(self) -> bool:
        """Use this method to hide the player-textdraw for the player.

        :return: This method does not return anything.
        """
        return player_text_draw_hide(self.player.id, self.id)

    def set_string(self, string: str) -> bool:
        """Update the shown text in the player-textdraw.

        :param str string: The new string for the textdraw.
            Max length: 1024 characters.
        :return: This method does not return anything.

        You don't have to show the textdraw again in order to apply the changes
        """
        return player_text_draw_set_string(self.player.id, self.id, string)

    def set_preview_model(self, model_index: int) -> bool:
        """Sets a player textdraw 2D preview sprite of a specified model ID.

        :param int model_index: The model to show.
        :return: This method does not return anything.
        """
        return player_text_draw_set_preview_model(
            self.player.id, self.id, model_index
        )

    def set_preview_rotation(
        self,
        rotation_x: float,
        rotation_y: float,
        rotation_z: float,
        zoom: float = 1.0,
    ) -> bool:
        """Sets the rotation and zoom of a 3D model preview player-textdraw.

        :param float rotation_x: The X rotation value.
        :param float rotation_y: The Y rotation value.
        :param float rotation_z: The Z rotation value.
        :param optional float zoom: The zoom value, default value 1.0,
            smaller values make the camera closer and larger values make
            the camera further away.
        :return: This method does not return anything.
        """
        return player_text_draw_set_preview_rot(
            self.player.id, self.id, rotation_x, rotation_y, rotation_z, zoom
        )

    def set_preview_vehicle_color(self, color1: int, color2: int) -> bool:
        """Set the color of a vehicle in a player-textdraw model preview
        (if a vehicle is shown).

        :param int color1: The color to set the vehicle's primary color to.
        :param int color2: The color to set the vehicle's secondary color to.
        :return: This method does not return anything.

        The textdraw must use the font ``TEXT_DRAW_FONT_MODEL_PREVIEW`` and be
        showing a vehicle, in order for this method to have an effect.
        """
        return player_text_draw_set_preview_veh_col(
            self.player.id, self.id, color1, color2
        )
