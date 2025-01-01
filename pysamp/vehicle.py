from pysamp import (
    add_vehicle_component,
    change_vehicle_color,
    change_vehicle_paintjob,
    create_vehicle,
    destroy_vehicle,
    detach_trailer_from_vehicle,
    get_vehicle_component_in_slot,
    get_vehicle_damage_status,
    get_vehicle_distance_from_point,
    get_vehicle_health,
    get_vehicle_model,
    get_vehicle_params_car_doors,
    get_vehicle_params_car_windows,
    get_vehicle_params_ex,
    get_vehicle_params_siren_state,
    get_vehicle_pos,
    get_vehicle_rotation_quat,
    get_vehicle_trailer,
    get_vehicle_velocity,
    get_vehicle_virtual_world,
    get_vehicle_z_angle,
    is_trailer_attached_to_vehicle,
    is_valid_vehicle,
    is_vehicle_streamed_in,
    link_vehicle_to_interior,
    remove_vehicle_component,
    repair_vehicle,
    set_vehicle_angular_velocity,
    set_vehicle_health,
    set_vehicle_number_plate,
    set_vehicle_params_car_doors,
    set_vehicle_params_car_windows,
    set_vehicle_params_ex,
    set_vehicle_params_for_player,
    set_vehicle_pos,
    set_vehicle_to_respawn,
    set_vehicle_velocity,
    set_vehicle_virtual_world,
    set_vehicle_z_angle,
    update_vehicle_damage_status,
)

from typing import Optional, Tuple
from pysamp.event import event
from samp import INVALID_PLAYER_ID


class Vehicle:
    """A class that represents server vehicles.

    :param id: The ID of the vehicle.

    Edit and work on them using this class. This class represents all drivable
    vehicles (Planes, boats, bikes, trains, trailers ++)

    A car that explodes or dies, will be respawned at its original
    coordinates where it was created.

    To create a new vehicle, check out :meth:`~create`
    """

    def __init__(self, id: int):
        self.id = id

    @classmethod
    def create(
        cls,
        model: int,
        x: float,
        y: float,
        z: float,
        rotation: float,
        color1: int,
        color2: int,
        respawn_delay: int,
        add_siren: bool = False,
    ) -> "Vehicle":
        """Create a new vehicle with the given model, position, colors and
        settings.

        :param model: The model of the car (400-622).
        :param float x: The x coordinate to spawn the vehicle.
        :param float y: The y coordinate to spawn the vehicle.
        :param float z: The z coordinate to spawn the vehicle.
        :param float rotation: Set the vehicle heading.
        :param int color1: Primary color (0-255).
        :param int color2: Secondary color (if available) (0-255).
        :param int respawn_delay: How long it should take for it to
            automatically respawn.
        :param optional bool add_siren: Set if the car should have
            a siren. Defaults to False.
        :return: An instance of :class:`Vehicle`.
        """
        return cls(
            create_vehicle(
                model,
                x,
                y,
                z,
                rotation,
                color1,
                color2,
                respawn_delay,
                add_siren,
            )
        )

    def is_valid(self) -> bool:
        """Check if the vehicle is valid"""
        return is_valid_vehicle(self.id)

    def get_distance_from_point(self, x: float, y: float, z: float) -> float:
        """Check how far away the vehicle is from a given coordinate."""
        return get_vehicle_distance_from_point(self.id, x, y, z)

    def destroy(self) -> bool:
        """Removes the vehicle from the server."""
        return destroy_vehicle(self.id)

    def is_streamed_in(self, for_player: "Player") -> bool:
        """Lets you know if a specific player has streamed in the vehicle."""
        return is_vehicle_streamed_in(self.id, for_player.id)

    def get_position(self) -> Tuple[float, float, float]:
        """Get the vehicle's current position."""
        return get_vehicle_pos(self.id)

    def set_position(self, x: float, y: float, z: float) -> bool:
        """Sets the vehicle position directly on the passed position."""
        return set_vehicle_pos(self.id, x, y, z)

    def get_z_angle(self) -> float:
        """Returns the heading the vehicle has. Can be >= 0.0 and < 360."""
        return get_vehicle_z_angle(self.id)

    def set_z_angle(self, z_angle: float) -> bool:
        """Set the vehicle's heading hangle. 0.0 => z_angle < 360.0"""
        return set_vehicle_z_angle(self.id, z_angle)

    def get_rotation_quat(self) -> Tuple[float, float, float, float]:
        """Returns a vehicle's rotation on all axes as a quaternion"""
        return get_vehicle_rotation_quat(self.id)

    def set_params_for_player(
        self, player: "Player", objective: int, doors_locked: int
    ) -> bool:
        """Set the parameters on the vehicle."""
        return set_vehicle_params_for_player(
            self.id, player.id, objective, doors_locked
        )

    def get_params_ex(self) -> Tuple[int, int, int, int, int, int, int]:
        """Get the vehicle's params."""
        return get_vehicle_params_ex(self.id)

    def set_params_ex(
        self,
        engine: int,
        lights: int,
        alarm: int,
        doors: int,
        bonnet: int,
        boot: int,
        objective: int,
    ) -> bool:
        """Set additional parameters on the vehicle."""
        return set_vehicle_params_ex(
            self.id, engine, lights, alarm, doors, bonnet, boot, objective
        )

    def get_params_siren_state(self) -> int:
        """Check if the sirens are on or off.

        Returns -1 if the siren hasn't been set up.
        Otherwise, it will return 0 (off) or 1 (on).
        """
        return get_vehicle_params_siren_state(self.id)

    def get_params_car_doors(self) -> Tuple[int, int, int, int]:
        """Allows you to retrieve the current state of a vehicle's doors

        Returns -1 if the door state is not set, like on a bike or a 2-door.
        Otherwise, it will return 0 (closed) or 1 (open).

        The tuple contains information about doors in this order:
        (driver, passenger, back_left, back_right)
        """
        return get_vehicle_params_car_doors(self.id)

    def set_params_car_doors(
        self,
        driver: int,
        passenger: int,
        backleft: int,
        backright: int,
    ) -> bool:
        """Open and close vehicle doors.

        The doors tuple should be in this order:
        (driver, passenger, back_left, back_right)

        Setting an unavailable door to 0 or 1, has no effect.
        """
        return set_vehicle_params_car_doors(
            self.id, driver, passenger, backleft, backright
        )

    def get_params_car_windows(self) -> Tuple[int, int, int, int]:
        """Check if windows are available and if they are closed / open."""
        return get_vehicle_params_car_windows(self.id)

    def set_params_car_windows(
        self, driver: int, passenger: int, backleft: int, backright: int
    ) -> bool:
        """Allows you to open and close the windows of a vehicle."""
        return set_vehicle_params_car_windows(
            self.id, driver, passenger, backleft, backright
        )

    def set_to_respawn(self) -> bool:
        """Respawn the vehicle. It will spawn at its created coordinates."""
        return set_vehicle_to_respawn(self.id)

    def link_to_interior(self, interior_id: int) -> bool:
        """Link the vehicle to a specific interior id.

        Only if the players are in the same interior,
        they can interact with and see the vehicle.
        """
        return link_vehicle_to_interior(self.id, interior_id)

    def add_component(self, component_id: int) -> bool:
        """Adds a component (often referred to as a modification)
        to a vehicle.

        Valid components can be found here:
        https://open.mp/docs/scripting/resources/carcomponentid

        NB: Using an invalid component ID crashes the player's game.
        There are no internal checks for this.
        """
        return add_vehicle_component(self.id, component_id)

    def remove_component(self, component_id: int) -> bool:
        """Remove an added component by its component id."""
        return remove_vehicle_component(self.id, component_id)

    def change_color(self, color_1: int, color_2: int) -> bool:
        """Change a vehicle's primary and secondary colors.

        Some vehicles have only a primary color and some can not have
        the color changed at all. A few (cement, squallo) have 4 colors,
        of which 2 can not be changed in SA:MP.
        """
        return change_vehicle_color(self.id, color_1, color_2)

    def change_paintjob(self, paint_job_id: int) -> bool:
        """Change a vehicle's paintjob.

        If vehicle is black, it may not show.
        """
        return change_vehicle_paintjob(self.id, paint_job_id)

    def get_health(self) -> float:
        """Get the vehicle's health. Vehicle starts burning at < 250.0."""
        return get_vehicle_health(self.id)

    def set_health(self, health: float) -> bool:
        """Set the vehicle's health.

        When the vehicle's health decreases the engine will produce
        smoke, and finally fire when it decreases to less than 250.0 (25%).
        """
        return set_vehicle_health(self.id, health)

    def detach_trailer(self) -> bool:
        """Detach a trailer from the vehicle, if any."""
        return detach_trailer_from_vehicle(self.id)

    def is_trailer_attached(self) -> bool:
        """Check if a trailer is attached to the vehicle."""
        return is_trailer_attached_to_vehicle(self.id)

    def get_trailer(self) -> Optional["Vehicle"]:
        """Get the Vehicle of the trailer that the vehicle is pulling.

        :returns: An instance of :class:`~pysamp.vehicle.Vehicle` that is the
            trailer, or ``None`` if no trailer found.
        """
        trailer_id = get_vehicle_trailer(self.id)
        if trailer_id == 0:
            return None
        return Vehicle(trailer_id)

    def set_number_plate(self, number_plate: str) -> bool:
        """Set the vehicle number plate text.

        .. note:: This method has no internal error checking.

        Do not assign custom number plates to vehicles without plates
        (boats, planes, etc) as this will result in some unneeded processing
        time on the client. The vehicle must be re-spawned or re-streamed for
        the changes to take effect. There's a limit of 32 characters on each
        number plate (including embedded colors). The text length that can be
        seen on the number plate is around 9 to 10 characters. More characters
        will cause the text to split. Some vehicle models has a backward
        number plate, e.g. Boxville (498).

        :param str number_plate: The text you want to set.
        :returns: No return value.
        """
        return set_vehicle_number_plate(self.id, number_plate)

    def get_model(self) -> int:
        """Get the vehicle model."""
        return get_vehicle_model(self.id)

    def get_component_in_slot(self, slot: int) -> int:
        """Retrieves the installed component ID in the specific slot."""
        return get_vehicle_component_in_slot(self.id, slot)

    def repair(self) -> bool:
        """Fully repairs the vehicle - including health"""
        return repair_vehicle(self.id)

    def get_velocity(self) -> Tuple[float, float, float]:
        """Get the vehicle velocity. Vector is relative to the car axis"""
        return get_vehicle_velocity(self.id)

    def set_velocity(self, x: float, y: float, z: float) -> bool:
        """Set the car velocity. Relative to the car axis."""
        return set_vehicle_velocity(self.id, x, y, z)

    def set_angular_velocity(self, x: float, y: float, z: float) -> bool:
        """Set the angular velocity of a vehicle.

        This is set relative to world space and not vehicle's local space.
        """
        return set_vehicle_angular_velocity(self.id, x, y, z)

    def get_damage_status(self) -> Tuple[int, int, int, int]:
        """This method returns information to you about if parts of the
        car has been damaged, or tires has been deflated.

        Please refer to:
        https://open.mp/docs/scripting/resources/damagestatus

        The returned values in the tuple are 4 bits each. For example the
        tires are represented as 4 bits, where a flat tire is 0 and a normal
        tire is represented by 1.
        """
        return get_vehicle_damage_status(self.id)

    def set_damage_status(
        self,
        panels: int,
        doors: int,
        lights: int,
        tires: int,
    ) -> bool:
        """Set vehicle damage status.

        Please refer to:
        https://open.mp/docs/scripting/resources/damagestatus
        """
        return update_vehicle_damage_status(
            self.id, panels, doors, lights, tires
        )

    def get_virtual_world(self) -> int:
        """Find out which virtual world ID the vehicle is currently in."""
        return get_vehicle_virtual_world(self.id)

    def set_virtual_world(self, world_id: int) -> bool:
        """Set the virtual world ID that the vehicle should be visible in."""
        return set_vehicle_virtual_world(self.id, world_id)

    @event("OnTrailerUpdate")
    def on_trailer_update(cls, player_id: int, trailer_id: int):
        """This event is called when the player sent a trailer update.

        :param int player_id: The ID of the player who sent a trailer update.
        :param int trailer_id: The trailer being updated.
        :returns: No return value.

        .. warning::
            This event is called very frequently per second per trailer.
            You should refrain from implementing intensive calculations
            or intensive file writing/reading operations in this event.
        """
        return (Player(player_id), cls(trailer_id))

    @event("OnVehicleDamageStatusUpdate")
    def on_damage_status_update(cls, vehicle_id: int, player_id: int):
        """This event is called when a vehicle element such as
        doors, tyres, panels, or lights change their damage status.

        :param int vehicle_id: The ID of the vehicle that was changed
        its damage status.
        :param int player_id: The ID of the player who synced the change in
        the damage status (who had the car damaged or repaired)
        :returns: No return value.

        .. note:: This does not include vehicle health changes.
        """
        return (cls(vehicle_id), Player(player_id))

    @event("OnVehicleDeath")
    def on_death(cls, vehicle_id: int, killer_id: int):
        """This event is called when a vehicle is destroyed - either by
        exploding or becoming submerged in water.

        :param int vehicle_id: The ID of the vehicle that was destroyed.
        :param int killer_id: The ID of the player that reported the
        vehicle's destruction (name is misleading). Generally the driver or
        a passenger (if any) or the closest player.
        :returns: No return value.

        .. note::
            This event will also be called when a vehicle enters water, but
            the vehicle can be saved by teleportation or driving out.
            The event won't be called a second time,\
            and the vehicle may disappear when the driver exits, or after a short time.
        """
        return (
            cls(vehicle_id),
            Player(vehicle_id) if killer_id != INVALID_PLAYER_ID else killer_id,
        )

    @event("OnVehicleMod")
    def on_mod(cls, player_id: int, vehicle_id: int, component_id: int):
        """This event is called when a vehicle is modded.

        :param int player_id: The ID of the driver of the vehicle.
        :param int vehicle_id: The ID of the vehicle which is modded.
        :param int component_id: The ID of the component which was added to
        the vehicle.
        :returns: No return value.

        .. note:: This event is NOT called by :meth:`Vehicle.add_component()`.
        """
        return (Player(player_id), cls(vehicle_id), component_id)

    @event("OnVehiclePaintjob")
    def on_paintjob(cls, player_id: int, vehicle_id: int, paintjob_id: int):
        """This event is called when a player previews a vehicle paintjob
        inside a mod shop.
        Watch out, this event is NOT called when the player buys the paintjob.

        :param int player_id: The ID of the player that changed the paintjob
        of their vehicle.
        :param int vehicle_id: The ID of the vehicle that had its
        paintjob changed.
        :param int paintjob_id: The ID of the new paintjob.
        :returns: No return value.

        .. note:: This event isn't called by :meth:`Vehicle.change_paintjob()`.
        """
        return (Player(player_id), cls(vehicle_id), paintjob_id)

    @event("OnVehicleRespray")
    def on_respray(
        cls, player_id: int, vehicle_id: int, color1: int, color2: int
    ):
        """This event is called when a player exits a mod shop, even if the
        colors weren't changed.

        Watch out, the name is ambiguous, Pay 'n' Spray shops don't call
        this event.

        :param int player_id: The ID of the player that is driving the vehicle.
        :param int vehicle_id: The ID of the vehicle that was resprayed.
        :param int color1: The color that the vehicle's primary color
        was changed to.
        :param int color2: The color that the vehicle's secondary color
        was changed to.
        :returns: No return value.

        .. note::
            This event is not called by :meth:`Vehicle.change_color()`.
            Misleadingly, this event is not called for pay 'n' spray.

        .. warning::
            Known Bug(s): previewing a component inside a mod shop might call
            this event.
        """
        return (Player(player_id), cls(vehicle_id), color1, color2)

    @event("OnVehicleSirenStateChange")
    def on_siren_state_change(
        cls, player_id: int, vehicle_id: int, new_state: int
    ):
        """This event is called when a vehicle's siren is toggled.

        :param int player_id: The ID of the player that toggled the
        siren (driver).
        :param int vehicle_id: The ID of the vehicle of which the siren was
        toggled for.
        :param int new_state: ``0`` if siren was turned off, ``1`` if siren
        was turned on.
        :returns: No return value.

        .. note::
            This event is only called when a vehicle's siren is on or off,
            NOT when the alternate siren is in use (holding horn).
        """
        return (Player(player_id), cls(vehicle_id), new_state)

    @event("OnVehicleSpawn")
    def on_spawn(cls, vehicle_id: int):
        """This event is called when a vehicle respawns.

        :param int vehicle_id: The ID of the vehicle that spawned.
        :returns: No return value.

        .. warning::
            This event is called only when vehicle respawns!
            :meth:`Vehicle.create()` and :meth:`add_static_vehicle/ex` won't
            trigger this event.
        """
        return (cls(vehicle_id),)

    @event("OnVehicleStreamIn")
    def on_stream_in(cls, vehicle_id: int, for_player_id: int):
        """This event is called when a vehicle is streamed for a
        player's client.

        :param int vehicle_id: The ID of the vehicle that streamed in
        for the player.
        :param int for_player_id: The ID of the player who the vehicle
        streamed in for.
        :returns: No return value.
        """
        return (cls(vehicle_id), Player(for_player_id))

    @event("OnVehicleStreamOut")
    def on_stream_out(cls, vehicle_id: int, for_player_id: int):
        """This event is called when a vehicle is streamed out for a
        player's client

        :param int vehicle_id: The ID of the vehicle that streamed out.
        :param int for_player_id: The ID of the player who is no longer
        streaming the vehicle.
        :returns: No return value.
        """
        return (cls(vehicle_id), Player(for_player_id))

    @event("OnUnoccupiedVehicleUpdate")
    def on_unoccupied_update(
        cls,
        vehicle_id: int,
        player_id: int,
        passenger_seat: int,
        new_x: float,
        new_y: float,
        new_z: float,
        vel_x: float,
        vel_y: float,
        vel_z: float,
    ):
        """This event is called when a player's client updates / syncs the
        position of a vehicle they're not driving.
        This can happen outside of the vehicle or when the player is a
        passenger of a vehicle that has no driver.

        :param int vehicle_id: The ID of the vehicle that's position
        was updated.
        :param int player_id: The ID of the player that sent a vehicle
        position sync update.
        :param int passenget_seat: The ID of the seat if the player
        is a passenger.
        :param float new_x: The new X coordinate of the vehicle.
        :param float new_y: The new Y coordinate of the vehicle.
        :param float new_z: The new Z coordinate of the vehicle.
        :param float vel_x: The new X velocity of the vehicle.
        :param float vel_y: The new Y velocity of the vehicle.
        :param float vel_z: The new Z velocity of the vehicle.
        :returns: No return value.

        .. list-table:: Seats
            :header-rows: 1

            * - ID
              - Definition
            * - 0
              - Not in vehicle
            * - 1
              - Front passenger
            * - 2
              - Backleft
            * - 3
              - Backright
            * - 4+
              - Coach/Bus etc.

        .. warning::
            This event is called very frequently per second per
            unoccupied vehicle.
            You should refrain from implementing intensive calculations or
            intensive file writing/reading operations in this event.
            :meth:`Vehicle.get_pos()` will return the old coordinates of
            the vehicle before this update.
        """
        return (
            cls(vehicle_id),
            Player(player_id),
            passenger_seat,
            new_x,
            new_y,
            new_z,
            vel_x,
            vel_y,
            vel_z,
        )


from pysamp.player import Player  # noqa
