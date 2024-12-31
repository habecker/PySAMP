from pysamp import (
    attach_3d_text_label_to_player,
    attach_3d_text_label_to_vehicle,
    create_3d_text_label,
    delete_3d_text_label,
    update_3d_text_label_text,
)


class TextLabel:
    """Create and adjust 3D-Textlabels that can be attached to
    vehicles, players or world coordinates.
    """

    def __init__(self, id: int) -> None:  # noqa: D107
        self.id: int = id

    @classmethod
    def create(
        cls,
        text: str,
        color: int,
        x: float,
        y: float,
        z: float,
        draw_distance: float,
        virtual_world: int,
        testLOS: bool = False,
    ) -> "TextLabel":
        """Create a new 3D Textlabel.

        :param str text: The text you want to show.
        :param int color: The color you would like the text to have.
        :param float x: The X coordinate of the 3D Textlabel.
        :param float y: The Y coordinate of the 3D Textlabel.
        :param float z: The Z coordinate of the 3D Textlabel.
        :param float draw_distance: The maximum distance at which the 3D
            Textlabel can be drawn.
        :param int virtual_world: The virtual world in which the 3D Textlabel
            should be shown.
        :param optional bool testLOS: Set if the 3D Textlabel should test
            for line of sight. Defaults to False.
        :return: An instance of :class:`TextLabel`.
        """
        return cls(
            create_3d_text_label(
                text,
                color,
                x,
                y,
                z,
                draw_distance,
                virtual_world,
                testLOS,
            ),
        )

    def delete(self) -> bool:
        """Remove/Delete a 3D text label.

        :return: This method does not return any value.
        """
        return delete_3d_text_label(self.id)

    def attach_to_player(
        self,
        player: "Player",
        offset_x: float,
        offset_y: float,
        offset_z: float,
    ) -> bool:
        """Attach a 3D Textlabel to a player.

        :param Player player: The player to attach to.
        :param float offset_x: The relative X coordinate offset on the player.
        :param float offset_y: The relative Y coordinate offset on the player.
        :param float offset_z: The relative Z coordinate offset on the player.
        :return: This method does not return anything.
        """
        return attach_3d_text_label_to_player(
            self.id,
            player.id,
            offset_x,
            offset_y,
            offset_z,
        )

    def attach_to_vehicle(
        self,
        vehicle: "Vehicle",
        offset_x: float,
        offset_y: float,
        offset_z: float,
    ) -> bool:
        """Attach a 3D Textlabel to a vehicle.

        :param Vehicle vehicle: The vehicle to attach to.
        :param float offset_x: The relative X coordinate offset on the vehicle.
        :param float offset_y: The relative Y coordinate offset on the vehicle.
        :param float offset_z: The relative Z coordinate offset on the vehicle.
        :return: This method does not return anything.
        """
        return attach_3d_text_label_to_vehicle(
            self.id,
            vehicle.id,
            offset_x,
            offset_y,
            offset_z,
        )

    def update_text(self, color: int, text: str) -> bool:
        """Update the 3D Textlabel text.

        :param int color: The color you would like the text to have.
        :param str text: The text you want to show.
        :return: This method does not return anything.
        """
        return update_3d_text_label_text(self.id, color, text)


from pysamp.vehicle import Vehicle  # noqa
from pysamp.player import Player  # noqa
