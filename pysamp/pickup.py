"""A pickup is a global item that can be picked up by a player.

Pickups triggers :meth:`~pysamp.Player.on_pick_up_pickup` when picked up.
"""

from pysamp import create_pickup, destroy_pickup  # add_static_pickup


class Pickup:
    """Pickups are global items that can be "picked" up by a player.

    Pickups triggers :meth:`~pysamp.Player.on_pick_up_pickup` when picked up.

    Benefit of having pickups compared to static pickups, is that you can
    recreate, destroy and modify pickups, while static pickups can only be
    created and have pre-made actions that make them work (such as health).
    """

    def __init__(self, id: int) -> None:  # noqa: D107
        self.id = id
        """The pickup ID (readonly int)."""

    @classmethod
    def create(
        cls,
        model: int,
        type: int,
        x: float,
        y: float,
        z: float,
        virtual_world: int = 0,
    ) -> "Pickup":
        """Create a new global pickup.

        :param int model: The pickup model to use. `You can use any model here.
            <https://dev.prineside.com/gtasa_samp_model_id/>`_
        :param int type: The pickup type. `See here for available types
            <https://www.open.mp/docs/scripting/resources/pickuptypes>`_.
        :param float x: The x coordinate to place the pickup at.
        :param float y: The y coordinate to place the pickup at.
        :param float z: The z coordinate to place the pickup at.
        :param optional int virtual_world: Which world should it be visible in?
            The default value is 0.
        :return: This method does not return anything.

        .. warning:: Pickups that have a X or Y < -4096.0  or > 4096.0 will not
            show up and won't trigger any events either.

        .. note::
            - Only pickup type that can be picked up from within a car,\
            is ID 14.
            - Certain pickup types come with 'automatic responses',\
            for example using an M4 model in the pickup will automatically\
            give the player the weapon and some ammo.
        """
        return cls(create_pickup(model, type, x, y, z, virtual_world))

    def destroy(self) -> bool:
        """Destroy the pickup.

        :return: No return value.

        This removes the pickup from the world.
        """
        return destroy_pickup(self.id)
