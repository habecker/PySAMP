"""Create and manage menus using this class."""

from typing import Optional

from pysamp import (
    add_menu_item,
    create_menu,
    destroy_menu,
    disable_menu,
    disable_menu_row,
    get_player_menu,
    hide_menu_for_player,
    is_valid_menu,
    set_menu_column_header,
    show_menu_for_player,
)
from samp import INVALID_MENU


class Menu:
    """Create and manage menus using this class.

    Create a new menu with :meth:`create`. Then add items to it with
    :meth:`add_item`, and finally show it to players using :meth:`show`.
    """

    def __init__(self, id: int) -> None:
        self.id = id

    @classmethod
    def create(
        cls,
        title: str,
        columns: int,
        x: float,
        y: float,
        column_1_width: float,
        column_2_width: float = 0.0,
    ) -> "Menu":
        """Create a new menu.

        :param str title: The menu title.
        :param int columns: How many columns the meny should have.
        :param float x: The X position on the screen (horizontally).
        :param float y: the Y position on the screen (vertically)
        :param float column_1_width: The width of the first column.
        :param optional float column_2_width: The width of the second column.
        :return: Returns an instance of :class:`~pysamp.menu.Menu`.

        .. note::  If the title's length is equal to or greater than 32 chars,
            the title is truncated to 30 characters.
            You can only create and access 2 columns (0 & 1).

        .. warning:: There is a limit of 12 items per menu, and a limit of
            128 menus in total.
        """
        return cls(
            create_menu(title, columns, x, y, column_1_width, column_2_width)
        )

    def add_item(self, column: int, text: str) -> None:
        """Add a new menu item to the menu.

        :param int column: The columt to add to. (0 or 1)
        :param str text: The text to write. Max length: 31
        :return: No return value.

        .. note:: You can only have 12 items per menu.
            You can only add 8 color codes per one item.
        """
        if self.is_valid():
            add_menu_item(self.id, column, text)
        return

    def destroy(self) -> None:
        """Destroy the menu.

        :return: No return value.
        """
        if self.is_valid():
            destroy_menu(self.id)
        return

    def disable(self) -> None:
        """Disable the menu.

        :return: No return value.
        """
        if self.is_valid():
            disable_menu(self.id)
        return

    def disable_row(self, row: int) -> None:
        """Disable one of the menu rows for all players.

        :param int row: The row to disable. Rows start at 0.
        :return: No return value.
        """
        if self.is_valid():
            disable_menu_row(self.id, row)
        return

    @staticmethod
    def get_player_menu(player: "Player") -> Optional["Menu"]:
        """Figure out which menu a has last had open when no menu is currently
        open.

        :param Player player: The player to check last open menu for.
        :return: An instance of the menu. None if no menu was opened.
        """
        id = get_player_menu(player.id)
        if id == INVALID_MENU or id is None:
            return None
        return Menu(id)

    def hide_for_player(self, player: "Player") -> None:
        """Hide the menu for a player.

        :param Player player: The player you want to hide the menu for.
        :return: No return value.
        """
        if self.is_valid():
            hide_menu_for_player(self.id, player.id)
        return

    def is_valid(self) -> bool:
        """Check if the menu is valid.

        :return: ``True`` if valid, otherwise ``False``.
        """
        return is_valid_menu(self.id)

    def set_column_header(self, column: int, text: str) -> None:
        """Set the menu column header text.

        :param int column: The column you want to set the header for. (0 or 1)
        :param str text: The header text you would like to set.
        :return: No return value.
        """
        if self.is_valid():
            set_menu_column_header(self.id, column, text)
        return

    def show(self, player: "Player") -> None:
        """Show the menu for a given player.

        :param Player player: The player you would like to see the menu.
        :return: No return value.
        """
        if self.is_valid():
            show_menu_for_player(self.id, player.id)
        return


from pysamp.player import Player  # noqa
