"""Textdraws that are global. For that are separate for
individual players, check out :class:`PlayerTextDraw`.
"""

from pysamp import (
    cancel_select_text_draw,
    select_text_draw,
    text_draw_alignment,
    text_draw_background_color,
    text_draw_box_color,
    text_draw_color,
    text_draw_create,
    text_draw_destroy,
    text_draw_font,
    text_draw_hide_for_all,
    text_draw_hide_for_player,
    text_draw_letter_size,
    text_draw_set_outline,
    text_draw_set_preview_model,
    text_draw_set_preview_rot,
    text_draw_set_preview_veh_col,
    text_draw_set_proportional,
    text_draw_set_selectable,
    text_draw_set_shadow,
    text_draw_set_string,
    text_draw_show_for_all,
    text_draw_show_for_player,
    text_draw_text_size,
    text_draw_use_box,
)


class TextDraw:
    """Textdraws that are global. For that are separate for
    individual players, check out :class:`PlayerTextDraw`.

    :param id: The ID that represents a textdraw.

    Max 2048 textdraws can be created globally.

    To create a new textdraw, use :meth:`TextDraw.create`.
    """

    def __init__(self, id: int) -> None:
        self.id = id

    @classmethod
    def create(cls, x: float, y: float, text: str) -> "TextDraw":
        """Create a new global textdraw.

        :param float x: the x-position on the screen.
        :param float y: the y-position on the screen.
        :param str text: The text to show.
        :return: An instance of :class:`TextDraw`.

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
        return cls(text_draw_create(x, y, text))

    def destroy(self) -> bool:
        """Destroy the textdraw.

        :return: Does not return anything.
        """
        return text_draw_destroy(self.id)

    def letter_size(self, x: float, y: float) -> bool:
        """Set the width and height of the letters.

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
        return text_draw_letter_size(self.id, x, y)

    def text_size(self, x: float, y: float) -> bool:
        """Change the size of the textdraw (box if :meth:`use_box`
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
        return text_draw_text_size(self.id, x, y)

    def alignment(self, alignment: int) -> bool:
        """Set the text-alignment of the textdraw.

        :param int alignment: Alignment can be 1: left, 2: center, 3: right.
        :return: This method does not return anything.

        .. note::
            For alignment 2 (center) the x and y values of :meth:`text_size`
            need to be swapped.
        """
        return text_draw_alignment(self.id, alignment)

    def color(self, color: int) -> bool:
        """Set the text color of the textdraw.

        :param int color: The color you want to give the textdraw, in a
            ``0xRRGGBBAA`` format.

        You can also use :meth:`~pysamp.player.game_text`
        colors (like ``~r~`` and ``~w~``) directly in
        the text if you want.

        .. note:: The textdraw must be re-shown to the player in order to
            update the color.
        """
        return text_draw_color(self.id, color)

    def use_box(self, use: bool) -> bool:
        """Toggle the box on the textdraw.

        :param bool use: ``True`` to use a box, ``False`` to hide the box.
        :return: This method does not return anything.
        """
        return text_draw_use_box(self.id, use)

    def box_color(self, color: int) -> bool:
        """Set the text color of a textdraw box.

        :param int color: Color in ``0xRRGGBBAA`` format.
        :return: This method does not return anything.
        """
        return text_draw_box_color(self.id, color)

    def set_shadow(self, size: int) -> bool:
        """Add a shadow to the bottom-right side of the text in a
        textdraw. The shadow font matches the text font.

        :param int size: The size of the shadow. 0 will hide the shadow.
        :return: No value is returned.

        .. note::
            The shadow can be cut by the box area if the size is set too big
            for the area.
        """
        return text_draw_set_shadow(self.id, size)

    def set_outline(self, size: int) -> bool:
        """Set the outline of a textdraw. The outline colour cannot be
        changed unless :meth:`background_color` is used.

        :param int size: The thickness of the outline.
        :return: This method does not return anything.
        """
        return text_draw_set_outline(self.id, size)

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
        return text_draw_background_color(self.id, color)

    def font(self, font: int) -> bool:
        """Change the font of a textdraw.

        :param int font: A font ID to give the textdraw (0-3).
        :return: No value is returned.

        See all fonts here:
        https://www.open.mp/docs/scripting/functions/TextDrawFont

        .. warning:: Setting the ``font`` above 3 may crash the client.
        """
        return text_draw_font(self.id, font)

    def set_proportional(self, set: bool) -> bool:
        """Appears to scale text spacing to a proportional ratio.
        Useful when using :meth:`letter_size` to ensure the text has an
        even character spacing.

        :param bool set: ``True`` to enable proportionality,
            ``False`` to disable.
        :return: Does not return anything.
        """
        return text_draw_set_proportional(self.id, set)

    def set_selectable(self, set: bool) -> bool:
        """Set the textdraw selectable.

        :param bool set: Toggle the textdraw selectable or not.
        :return: No return value.

        .. warning:: This method _must_ be used before the textdraw is shown to
            the player.

        :meth:`text_size` defines the clickable area.
        """
        return text_draw_set_selectable(self.id, set)

    def show_for_all(self) -> bool:
        """Use this method to show the textdraw for all online players.

        :return: This method does not return anything.
        """
        return text_draw_show_for_all(self.id)

    def hide_for_all(self) -> bool:
        """Use this method to hide the textdraw for everyone.

        :return: This method does not return anything.
        """
        return text_draw_hide_for_all(self.id)

    def set_string(self, string: str) -> bool:
        """Update the shown text in the textdraw.

        :param str string: The new string for the textdraw.
            Max length: 1024 characters.
        :return: This method does not return anything.

        You don't have to show the textdraw again in order to apply the changes
        """
        return text_draw_set_string(self.id, string)

    def set_preview_model(self, model_index: int) -> bool:
        """Set the textdraw 2D preview sprite of a specified model ID.

        :param int model_index: The model to show.
        :return: This method does not return anything.
        """
        return text_draw_set_preview_model(self.id, model_index)

    def set_preview_rotation(
        self,
        rotation_x: float,
        rotation_y: float,
        rotation_z: float,
        zoom: float = 1.0,
    ) -> bool:
        """Set the rotation and zoom of a 3D model preview textdraw.

        :param float rotation_x: The X rotation value.
        :param float rotation_y: The Y rotation value.
        :param float rotation_z: The Z rotation value.
        :param optional float zoom: The zoom value, default value 1.0,
            smaller values make the camera closer and larger values make
            the camera further away.
        :return: This method does not return anything.
        """
        return text_draw_set_preview_rot(
            self.id, rotation_x, rotation_y, rotation_z, zoom
        )

    def set_preview_vehicle_color(self, color1: int, color2: int) -> bool:
        """Set the color of a vehicle in a textdraw model preview
        (if a vehicle is shown).

        :param int color1: The color to set the vehicle's primary color to.
        :param int color2: The color to set the vehicle's secondary color to.
        :return: This method does not return anything.

        The textdraw must use the font ``TEXT_DRAW_FONT_MODEL_PREVIEW`` and be
        showing a vehicle, in order for this method to have an effect.
        """
        return text_draw_set_preview_veh_col(self.id, color1, color2)

    def hide_for_player(self, player: "Player") -> bool:
        """Hide a global textdraw for the player.

        :param Player player: The player to hide the textdraw for.
        :return: This method does not return anything.
        """
        return text_draw_hide_for_player(player.id, self.id)

    def show_for_player(self, player: "Player") -> bool:
        """Show a global textdraw for the selected player.

        :param Player player: The player to show the textdraw for.
        :return: This method does not return anything.
        """
        return text_draw_show_for_player(player.id, self.id)

    def select(self, player: "Player", hover_color: int) -> bool:
        """Display the cursor and allow the player to select a textdraw.

        :param Player player: The player that should be able to
        select a textdraw.
        :param int hover_color: The color of the textdraw when hovering over
        with mouse (RGBA).
        :return: This method does not return anything.
        """
        return select_text_draw(player.id, hover_color)

    def cancel_select(self, player: "Player") -> bool:
        """Cancel textdraw selection with the mouse.

        :param Player player: The player that should be the textdraw
        selection disabled.
        :return: This method does not return anything.
        """
        return cancel_select_text_draw(player.id)


from .player import Player  # noqa
