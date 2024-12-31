"""Create and manage gangzones on the server."""

from pysamp import (
    gang_zone_create,
    gang_zone_destroy,
    gang_zone_flash_for_all,
    gang_zone_flash_for_player,
    gang_zone_hide_for_all,
    gang_zone_hide_for_player,
    gang_zone_show_for_all,
    gang_zone_show_for_player,
    gang_zone_stop_flash_for_all,
    gang_zone_stop_flash_for_player,
)


class Gangzone:
    """Create and manage Gangzones on the server.

    Gangzones are created in 2D space, and covers a rectangular area.
    Even if a gangzone has been created, it is not shown
    by default. You need to show it for players.
    Be aware that you can only have up to 1024 gangzones.
    ```
            MinY
             v
      MinX > *-------------
             |            |
             |  Gangzone  |
             |   center   |
             |            |
             -------------* < MaxX
                          ^
                         MaxY
    ```
    """

    def __init__(  # noqa: D107
        self, id: int, min_x: float, min_y: float, max_x: float, max_y: float
    ) -> None:
        self.id = id
        self.min_x = min_x
        self.min_y = min_y
        self.max_x = max_x
        self.max_y = max_y

    @classmethod
    def create(
        cls, min_x: float, min_y: float, max_x: float, max_y: float
    ) -> "Gangzone":
        """Create a new gangzone (colored radar area).

        :param min_x: The X coordinate for the west side of the gangzone.
        :param min_y: The Y coordinate for the south side of the gangzone.
        :param max_x: The X coordinate for the east side of the gangzone.
        :param max_y: The Y coordinate for the north side of the gangzone.
        :return: An instance of :class:`Gangzone`.
        """
        return cls(
            gang_zone_create(min_x, min_y, max_x, max_y),
            min_x,
            min_y,
            max_x,
            max_y,
        )

    def get_id(self) -> int:
        """Get the gangzone id.

        :return: The gangzone id.
        """
        return self.id

    def destroy(self) -> bool:
        """Destroy the gangzone.

        :return: ``True`` if the gangzone was destroyed, ``False`` otherwise.
        """
        return gang_zone_destroy(self.id)

    def show_for_player(self, player: "Player", color: int) -> bool:
        """Show the gangzone for a player.

        :param player: The player to show the gangzone for.
        :param color: The color of the gangzone.
        """
        return gang_zone_show_for_player(player.id, self.id, color)

    def hide_for_player(self, player: "Player") -> bool:
        """Hide the ganzone for a player.

        :param player: The player to hide the gangzone for.
        """
        return gang_zone_hide_for_player(player.id, self.id)

    def show_for_all(self, color: int) -> bool:
        """Show the ganzone for all players, with the desired color.

        :param color: The color of the gangzone.
        """
        return gang_zone_show_for_all(self.id, color)

    def hide_for_all(self) -> bool:
        """Hide the gangzone for everyone."""
        return gang_zone_hide_for_all(self.id)

    def flash_for_player(self, player: "Player", flash_color: int) -> bool:
        """Make the gangzone flash for the given player,
        with the desired color.

        :param player: The player to flash the gangzone for.
        :param flash_color: The color of the flash.
        :return: ``True`` if the gangzone was flashed, ``False`` otherwise.
        """
        return gang_zone_flash_for_player(player.id, self.id, flash_color)

    def flash_for_all(self, flash_color: int) -> bool:
        """Make the gangzone flash for all players.

        :param flash_color: The color of the flash.
        """
        return gang_zone_flash_for_all(self.id, flash_color)

    def stop_flash_for_player(self, player: "Player") -> bool:
        """If a gangzone is flashing for a player,
        this can be used to stop it.

        :param player: The player to stop the flashing for.
        """
        return gang_zone_stop_flash_for_player(player.id, self.id)

    def stop_flash_for_all(self) -> bool:
        """Stop the flashing of a ganzone for all online players."""
        return gang_zone_stop_flash_for_all(self.id)


from pysamp.player import Player  # noqa
