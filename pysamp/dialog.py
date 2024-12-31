"""Handles player dialogs."""

import string
from typing import Callable, Dict, Optional

from pysamp import show_player_dialog
from pysamp.event import registry


class ColorCompatibleFormatter(string.Formatter):
    def get_value(self, key, args, kwargs):
        # Allow color escapes like {FF0000} or {808080}
        if key not in kwargs:
            return "{%s}" % key
        return kwargs[key]


dialog_formatter = ColorCompatibleFormatter()


class Dialog:
    """Class to create and show dialogs.

    A dialog is a menu that the player can interact with.
    To create a new dialog, use :meth:`create`.

    The player will see the dialog when you do :meth:`show`. The Dialog class
    will behind the scenes keep track of if a dialog is shown to a player, and
    will that way automatically prevent traditional spoofing of dialogs.
    """

    _ID: int = 32767  # just a random dialog ID that will be used on SA-MP
    _shown_for: Dict[int, "Dialog"] = {}

    def __init__(
        self,
        type: int,
        title: str,
        content: str,
        button_1: str,
        button_2: str,
        on_response: Optional[Callable] = None,
    ) -> None:
        self.type = type
        self.title = title
        self.content = content
        self.button_1 = button_1
        self.button_2 = button_2
        self.on_response = on_response

    @classmethod
    def create(
        cls,
        type: int,
        title: str,
        content: str,
        button_1: str,
        button_2: str,
        on_response: Optional[Callable] = None,
    ) -> "Dialog":
        """Create/prepare a dialog for use later.

        Use :meth:`show` to show the dialog to a player after creating it.

        :param type: The type of dialog you want to make. There are 6 different
            types: ``DIALOG_STYLE_MSGBOX``, ``DIALOG_STYLE_INPUT``,
            ``DIALOG_STYLE_LIST``, ``DIALOG_STYLE_PASSWORD``,
            ``DIALOG_STYLE_TABLIST``and ``DIALOG_STYLE_TABLIST_HEADERS``.
        :param title: The dialog title show at top.
        :param content: The content of the dialog.
        :param button_1: The positive dialog response button. Can't be longer
            than 8 characters, else it looks weird.
        :param button_2: The second button, negative response.
            If it is left empty, it will be hidden from the dialog.
        :param Callable on_response: The function to call on response.
        :return: This classmethod creates a new instance of :class:`Dialog`.
        """
        return cls(type, title, content, button_1, button_2, on_response)

    def show(
        self,
        for_player: "Player",
        title_format=None,
        content_format=None,
    ) -> None:
        """Show the dialog created with :meth:`create` to a specific player.

        :param Player for_player: The player you want to show
            the dialog for.
        :return: No return value.

        .. note:: You can only show one dialog to a player at a time. Showing
            a new dialog will close the old one, if shown.
        """
        title, content = self.title, self.content

        if title_format:
            title = dialog_formatter.vformat(title, (), title_format)

        if content_format:
            content = dialog_formatter.vformat(content, (), content_format)

        show_player_dialog(
            for_player.id,
            Dialog._ID,  # we only occupy one ID on SA-MP side.
            self.type,
            title,
            content,
            self.button_1,
            self.button_2,
        )
        Dialog._shown_for[for_player.id] = self

    @staticmethod
    def hide(for_player: "Player") -> None:
        """Shows a dialog with ID -1 to hide open dialog.

        :param Player for_player: The player you'd like to hide open
            dialogs for.
        :return: No return value.
        """
        show_player_dialog(for_player.id, -1, 0, "", "", "", "")
        Dialog._shown_for.pop(for_player.id, None)

    @classmethod
    def handle(
        cls,
        player_id: int,
        dialog_id: int,
        response: int,
        list_item: int,
        input_text: str,
    ):
        if dialog_id != Dialog._ID:
            # This dialog is either invalid or handled in pawn.
            return

        instance = Dialog._shown_for.get(player_id)

        if not instance or not instance.on_response:
            return

        return instance.on_response(
            Player(player_id), response, list_item, input_text
        )


registry.register_callback(
    "OnDialogResponse",
    Dialog.handle,
    "pysamp.dialogs",
)

from pysamp.player import Player  # noqa
