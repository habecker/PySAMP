"""Actors module, to handle and create actors.

These 'actors' are like NPCs, however they have limited functionality.
They do not take up server player slots.
"""

from typing import Optional, Tuple

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
from pysamp.event import event


class Actor:
    """A class that represents actors, also known as NPC's.

    These 'actors' are like NPCs, however they have limited functionality.
    They do not take up server player slots.

    Read more about actors here:
    https://open.mp/docs/scripting/functions/CreateActor
    """

    def __init__(self, id: int) -> None:  # noqa: D107
        self.id: int = id

    @classmethod
    def create(
        cls, modelid: int, x: float, y: float, z: float, rotation: float
    ) -> Optional["Actor"]:
        """Create a new actor.

        :param int modelid: The model of the actor.
        :param float x: The model of the actor.
        :param float y: The model of the actor.
        :param float z: The model of the actor.
        :param float rotation: The model of the actor.
        :return: An :class:`Actor` object. Will return ``None`` if the actor
            limit is reached of 1000 actors.
        """
        return cls(create_actor(modelid, x, y, z, rotation))

    def get_id(self) -> int:
        """Get the actor ID."""
        return self.id

    def destroy(self) -> bool:
        """Remove a created actor from the world."""
        return destroy_actor(self.id)

    def is_streamed_in(self, for_player: "Player") -> bool:
        """Check if a player has streamed in the actor."""
        return is_actor_streamed_in(self.id, for_player.id)

    def get_virtual_world(self) -> int:
        """Get which virtual world ID the actor is in."""
        return get_actor_virtual_world(self.id)

    def set_virtual_world(self, virtual_world: int) -> bool:
        """Set the actor to a specific virtual world id.

        :param int virtual_world: The virtual world ID (0-65535).
        :return: This method does not return anything.
        """
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
        time: int,
    ) -> bool:
        """Set an animation on the actor.

        :param str animation_library: The name of the animation library.
        :param str animation_name: The name of the animation.
        :param float delta: The animation delta.
        :param bool loop: Whether the animation should loop.
        :param bool lock_x: Whether the animation should lock the X axis.
        :param bool lock_y: Whether the animation should lock the Y axis.
        :param bool freeze: Whether the animation should freeze.
        :param int time: The animation time.
        :return: This method does not return anything.
        """
        return apply_actor_animation(
            self.id,
            animation_library,
            animation_name,
            delta,
            loop,
            lock_x,
            lock_y,
            freeze,
            time,
        )

    def clear_animations(self) -> bool:
        """Clear the animations that are in use by the actor, if any.

        :return: This method does not return anything.
        """
        return clear_actor_animations(self.id)

    def get_position(self) -> Tuple[float, float, float]:
        """Get the current world coordinates of where the actor is located.

        :return: A tuple of (x, y, z).
        """
        return get_actor_pos(self.id)

    def set_position(self, x: float, y: float, z: float) -> bool:
        """Set a new position for the actor.

        For rotation, check out method :meth:`~set_facing_angle`.
        """
        if not self.is_valid():
            return False
        return set_actor_pos(self.id, x, y, z)

    def get_facing_angle(self) -> float:
        """Get the actor's facing angle.

        :return: The actor's facing angle.
        """
        return get_actor_facing_angle(self.id)

    def set_facing_angle(self, angle: float) -> bool:
        """Set the actor's facing angle.

        For position, check out method :meth:`~set_position`.
        """
        if not self.is_valid():
            return False
        return set_actor_facing_angle(self.id, angle)

    def get_health(self) -> float:
        """Get how much health the actor has.

        :return: The actor's health, between `0.0` and `100.0`.
        """
        return get_actor_health(self.id)

    def set_health(self, health: float) -> bool:
        """Set the health of the actor.

        :param health: A float between `0.0` and `100.0`.
        :return: This method does not return anything.
        """
        return set_actor_health(self.id, health)

    def is_invulnerable(self) -> bool:
        """See if the actor is invulnerable to damage.

        :return: ``True`` if the actor is invulnerable, ``False`` otherwise.
        """
        return is_actor_invulnerable(self.id)

    def set_invulnerable(self, invulnerable: bool = True) -> bool:
        """Set the actor to be invlunerable to damage.

        :param bool invulnerable: Whether the actor should be invulnerable.
        :return: This method does not return anything.
        """
        return set_actor_invulnerable(self.id, invulnerable)

    def is_valid(self) -> bool:
        """Check if the actor is valid.

        :return: ``True`` if valid, otherwise ``False``.
        """
        return is_valid_actor(self.id)

    @event("OnActorStreamIn")
    def on_stream_in(cls, actorid: int, forplayerid: int):
        """Event that is triggered when an actor is streamed in to a player.

        :param Actor actor: The actor that was streamed in.
        :param Player forplayer: The player that streamed the actor in.
        """
        return (cls(actorid), Player(forplayerid))

    @event("OnActorStreamOut")
    def on_stream_out(cls, actorid: int, forplayerid: int):
        """Event that is triggered when an actor is streamed out of a player.

        :param Actor actor: The actor that was streamed out.
        :param Player forplayer: The player that streamed the actor out.
        """
        return (cls(actorid), Player(forplayerid))


from pysamp.player import Player  # noqa
