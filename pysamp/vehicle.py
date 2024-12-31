"""A module that wraps vehicle related functions."""

from typing import Optional, Tuple

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
        """Create a new vehicle with the given arguments.

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
            ),
        )

    def is_valid(self) -> bool:
        """Check if the vehicle is valid."""
        return is_valid_vehicle(self.id)

    def get_distance_from_point(self, x: float, y: float, z: float) -> float:
        """Check how far away the vehicle is from a given coordinate."""
        return get_vehicle_distance_from_point(self.id, x, y, z)

    def destroy(self) -> bool:
        """Remove the vehicle from the server."""
        return destroy_vehicle(self.id)

    def is_streamed_in(self, for_player: "Player") -> bool:
        """Lets you know if a specific player has streamed in the vehicle."""
        return is_vehicle_streamed_in(self.id, for_player.id)

    def get_position(self) -> Tuple[float, float, float]:
        """Get the vehicle's current position."""
        return get_vehicle_pos(self.id)

    def set_position(self, x: float, y: float, z: float) -> bool:
        """Set the vehicle position directly to the passed position."""
        return set_vehicle_pos(self.id, x, y, z)

    def get_z_angle(self) -> float:
        """Get the heading the vehicle has. Can be >= 0.0 and < 360."""
        return get_vehicle_z_angle(self.id)

    def set_z_angle(self, z_angle: float) -> bool:
        """Set the vehicle's heading hangle. 0.0 => z_angle < 360.0."""
        return set_vehicle_z_angle(self.id, z_angle)

    def get_rotation_quat(self) -> Tuple[float, float, float, float]:
        """Get the vehicle's rotation on all axes as a quaternion."""
        return get_vehicle_rotation_quat(self.id)

    def set_params_for_player(
        self,
        player: "Player",
        objective: int,
        doors_locked: int,
    ) -> bool:
        """Set the parameters on the vehicle."""
        return set_vehicle_params_for_player(
            self.id,
            player.id,
            objective,
            doors_locked,
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
            self.id,
            engine,
            lights,
            alarm,
            doors,
            bonnet,
            boot,
            objective,
        )

    def get_params_siren_state(self) -> int:
        """Check if the sirens are on or off.

        Returns -1 if the siren hasn't been set up.
        Otherwise, it will return 0 (off) or 1 (on).
        """
        return get_vehicle_params_siren_state(self.id)

    def get_params_car_doors(self) -> Tuple[int, int, int, int]:
        """Get and retrieve the current state of a vehicle's doors.

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
            self.id,
            driver,
            passenger,
            backleft,
            backright,
        )

    def get_params_car_windows(self) -> Tuple[int, int, int, int]:
        """Check if windows are available and if they are closed / open."""
        return get_vehicle_params_car_windows(self.id)

    def set_params_car_windows(
        self,
        driver: int,
        passenger: int,
        backleft: int,
        backright: int,
    ) -> bool:
        """Open and close the windows of a vehicle."""
        return set_vehicle_params_car_windows(
            self.id,
            driver,
            passenger,
            backleft,
            backright,
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
        """Add a component (often referred to as a modification)
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
        """Get the installed component ID in the specific slot."""
        return get_vehicle_component_in_slot(self.id, slot)

    def repair(self) -> bool:
        """Fully repair the vehicle and restore health to 1000.0."""
        return repair_vehicle(self.id)

    def get_velocity(self) -> Tuple[float, float, float]:
        """Get the car velocity. Relative to the car axis."""
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
        """Get information about if parts of the
        car has been damaged or if tires has been deflated.

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
            self.id,
            panels,
            doors,
            lights,
            tires,
        )

    def get_virtual_world(self) -> int:
        """Find out which virtual world ID the vehicle is currently in."""
        return get_vehicle_virtual_world(self.id)

    def set_virtual_world(self, world_id: int) -> bool:
        """Set the virtual world ID that the vehicle should be visible in."""
        return set_vehicle_virtual_world(self.id, world_id)

    @event("OnTrailerUpdate")
    def on_trailer_update(cls, playerid: int, trailerid: int):
        """Event that is triggered when a trailer is attached to a vehicle."""
        return (Player(playerid), cls(trailerid))

    @event("OnVehicleDamageStatusUpdate")
    def on_damage_status_update(cls, vehicleid: int, playerid: int):
        """Event that is triggered when vehicle damage status changes."""
        return (cls(vehicleid), Player(playerid))

    @event("OnVehicleDeath")
    def on_death(cls, vehicleid: int, killerid: int):
        """Event that is triggered when a vehicle dies."""
        return (
            cls(vehicleid),
            Player(killerid) if killerid != INVALID_PLAYER_ID else killerid,
        )

    @event("OnVehicleMod")
    def on_mod(cls, playerid: int, vehicleid: int, componentid: int):
        """Event that is triggered when a vehicle component is modified."""
        return (Player(playerid), cls(vehicleid), componentid)

    @event("OnVehiclePaintjob")
    def on_paintjob(cls, playerid: int, vehicleid: int, paintjobid: int):
        """Event that is triggered when a vehicle paintjob is changed."""
        return (Player(playerid), cls(vehicleid), paintjobid)

    @event("OnVehicleRespray")
    def on_respray(
        cls,
        playerid: int,
        vehicleid: int,
        color1: int,
        color2: int,
    ):
        """Event that is triggered when a vehicle is resprayed in
        a respray shop, native to GTA San Andreas.
        """
        return (Player(playerid), cls(vehicleid), color1, color2)

    @event("OnVehicleSirenStateChange")
    def on_siren_state_change(
        cls,
        playerid: int,
        vehicleid: int,
        newstate: int,
    ):
        """Event that is triggered when a vehicle's siren state changes,
        for example when a police vehicle is stopping its siren.
        """
        return (Player(playerid), cls(vehicleid), newstate)

    @event("OnVehicleSpawn")
    def on_spawn(cls, vehicleid: int):
        """Event that is triggered when a vehicle is spawned."""
        return (cls(vehicleid),)

    @event("OnVehicleStreamIn")
    def on_stream_in(cls, vehicleid: int, forplayerid: int):
        """Event that is triggered when a vehicle is streamed in for a player."""
        return (cls(vehicleid), Player(forplayerid))

    @event("OnVehicleStreamOut")
    def on_stream_out(cls, vehicleid: int, forplayerid: int):
        """Event that is triggered when a vehicle is streamed out for a player."""
        return (cls(vehicleid), Player(forplayerid))

    @event("OnUnoccupiedVehicleUpdate")
    def on_unoccupied_update(
        cls,
        vehicleid: int,
        playerid: int,
        passenger_seat: int,
        new_x: float,
        new_y: float,
        new_z: float,
        vel_x: float,
        vel_y: float,
        vel_z: float,
    ):
        """Event that is called whenever an unoccupied vehicle is updated.

        Please refer to:
        https://www.open.mp/docs/scripting/callbacks/OnUnoccupiedVehicleUpdate
        """
        return (
            cls(vehicleid),
            Player(playerid),
            passenger_seat,
            new_x,
            new_y,
            new_z,
            vel_x,
            vel_y,
            vel_z,
        )


from pysamp.player import Player  # noqa
