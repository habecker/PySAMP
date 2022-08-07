from pysamp import (
    apply_actor_animation,
    clear_actor_animations,
    create_actor,
    destroy_actor,
    get_actor_facing_angle,
    get_actor_health,
    get_actor_pos,
    get_actor_virtual_world,
    is_actor_invulnerable,
    is_actor_streamed_in,
    is_valid_actor,
    set_actor_facing_angle,
    set_actor_health,
    set_actor_invulnerable,
    set_actor_pos,
    set_actor_virtual_world,
)
from typing import Optional, Tuple
from pysamp.event import event


class Actor:
    """
    A class that represents actors, also known as NPC's.

    These 'actors' are like NPCs, however they have limited functionality.
    They do not take up server player slots.

    Read more about actors here:
    https://open.mp/docs/scripting/functions/CreateActor
    """

    def __init__(self, id: int) -> None:
        self.id: int = id

    @classmethod
    def create(
        cls,
        model_id: int,
        x: float,
        y: float,
        z: float,
        rotation: float = 0
    ) -> Optional["Actor"]:
        """Create a new actor.

        :param int model_id: The model of the actor.
        :param float x: The model of the actor.
        :param float y: The model of the actor.
        :param float z: The model of the actor.
        :param float rotation: The model of the actor.
        :return: An :class:`Actor` object. Will return ``None`` if the actor
            limit is reached of 1000 actors.
        """
        return cls(
            create_actor(model_id, x, y, z, rotation)
        )

    def get_id(self) -> int:
        return self.id

    def destroy(self) -> bool:
        """ Remove a created actor from the world. """
        return destroy_actor(self.id)

    def streamed_in(self, for_player: "Player") -> bool:
        """ Check if a player has streamed in the actor. """
        return is_actor_streamed_in(self.id, for_player.id)

    def get_virtual_world(self) -> int:
        """ Get which virtual world ID the actor is in. """
        return get_actor_virtual_world(self.id)

    def virtual_world(self, virtual_world: int) -> bool:
        """ Set the actor to a specific virtual world id. """
        return set_actor_virtual_world(self.id, virtual_world)

    def apply_animation(
        self,
        animation_library: str,
        animation_name: str,
        delta: float,
        loop: bool,
        lock_x: bool,
        lock_y: bool,
        freeze: bool,
        time: int
    ) -> bool:
        """ Set an animation on the actor. """
        return apply_actor_animation(
            self.id,
            animation_library,
            animation_name,
            delta,
            loop,
            lock_x,
            lock_y,
            freeze,
            time
        )

    def clear_animations(self) -> bool:
        """ Clear the animations that are in use by the actor, if any. """
        return clear_actor_animations(self.id)

    def get_position(self) -> Tuple[float, float, float]:
        """ Gets the current world coordinates of where the actor is located. """
        return get_actor_pos(self.id)

    def set_position(self, position: Tuple[float, float, float]) -> bool:
        """ Set a new position for the actor. """
        try:
            x, y, z = position

        except ValueError:
            raise ValueError("Expected position as tuple: (x, y, z)")

        else:
            return set_actor_pos(self.id, x, y, z)

    def get_facing_angle(self) -> float:
        """ Get the actor's facing angle. """
        return get_actor_facing_angle(self.id)

    def set_facing_angle(self, angle: float) -> bool:
        """ Set the actor's facing angle. """
        return set_actor_facing_angle(self.id, angle)

    def get_health(self) -> float:
        """ Get how much health the actor has. """
        return get_actor_health(self.id)

    def set_health(self, health: float) -> bool:
        """ Set the health of the actor. """
        return set_actor_health(self.id, health)

    def is_invulnerable(self) -> bool:
        """ See if the actor is invulnerable to damage. """
        return is_actor_invulnerable(self.id)

    def set_invulnerable(self, invulnerable: bool = True) -> bool:
        """ Set the actor to be invulnerable to damage. """
        return set_actor_invulnerable(self.id, invulnerable)

    def is_valid(self) -> bool:
        """ Check if the actor is valid. """
        return is_valid_actor(self.id)

    @event("OnActorStreamIn")
    def on_stream_in(cls, actor_id: int, for_player_id: int):
        return (cls(actor_id), Player(for_player_id))

    @event("OnActorStreamOut")
    def on_stream_out(cls, actor_id: int, for_player_id: int):
        return (cls(actor_id), Player(for_player_id))

from pysamp.player import Player  # noqa