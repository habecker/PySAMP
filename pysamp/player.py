"""A module that wraps player related functions.

This module contains all player related functions.
"""

import functools
from typing import Optional, Tuple

from pysamp import (
    allow_player_teleport,
    apply_animation,
    attach_camera_to_player_object,
    ban,
    ban_ex,
    cancel_edit,
    clear_animations,
    create_explosion_for_player,
    delete_pvar,
    disable_player_checkpoint,
    disable_player_race_checkpoint,
    disable_remote_vehicle_collisions,
    edit_attached_object,
    enable_player_camera_target,
    enable_stunt_bonus_for_player,
    force_class_selection,
    game_text_for_player,
    get_player_ammo,
    get_player_animation_index,
    get_player_armour,
    get_player_camera_aspect_ratio,
    get_player_camera_front_vector,
    get_player_camera_mode,
    get_player_camera_pos,
    get_player_camera_target_actor,
    get_player_camera_target_object,
    get_player_camera_target_player,
    get_player_camera_target_vehicle,
    get_player_camera_zoom,
    get_player_color,
    get_player_distance_from_point,
    get_player_drunk_level,
    get_player_facing_angle,
    get_player_fighting_style,
    get_player_health,
    get_player_interior,
    get_player_ip,
    get_player_keys,
    get_player_last_shot_vectors,
    get_player_money,
    get_player_name,
    get_player_ping,
    get_player_pos,
    get_player_score,
    get_player_skin,
    get_player_special_action,
    get_player_state,
    get_player_surfing_object_id,
    get_player_surfing_vehicle_id,
    get_player_target_actor,
    get_player_target_player,
    get_player_team,
    get_player_time,
    get_player_vehicle_id,
    get_player_vehicle_seat,
    get_player_velocity,
    get_player_virtual_world,
    get_player_wanted_level,
    get_player_weapon,
    get_player_weapon_data,
    get_player_weapon_state,
    get_pvar_float,
    get_pvar_int,
    get_pvar_name_at_index,
    get_pvar_string,
    get_pvar_type,
    get_pvars_upper_index,
    give_player_money,
    give_player_weapon,
    gpci,
    interpolate_camera_look_at,
    interpolate_camera_pos,
    is_player_admin,
    is_player_attached_object_slot_used,
    is_player_connected,
    is_player_in_any_vehicle,
    is_player_in_checkpoint,
    is_player_in_race_checkpoint,
    is_player_in_range_of_point,
    is_player_in_vehicle,
    is_player_npc,
    is_player_streamed_in,
    kick,
    play_audio_stream_for_player,
    play_crime_report_for_player,
    player_play_sound,
    player_spectate_player,
    player_spectate_vehicle,
    put_player_in_vehicle,
    remove_building_for_player,
    remove_player_attached_object,
    remove_player_from_vehicle,
    remove_player_map_icon,
    reset_player_money,
    reset_player_weapons,
    send_client_message,
    send_death_message_to_player,
    send_player_message_to_player,
    set_camera_behind_player,
    set_player_ammo,
    set_player_armed_weapon,
    set_player_armour,
    set_player_attached_object,
    set_player_camera_look_at,
    set_player_camera_pos,
    set_player_chat_bubble,
    set_player_checkpoint,
    set_player_color,
    set_player_drunk_level,
    set_player_facing_angle,
    set_player_fighting_style,
    set_player_health,
    set_player_interior,
    set_player_map_icon,
    set_player_marker_for_player,
    set_player_name,
    set_player_pos,
    set_player_pos_find_z,
    set_player_race_checkpoint,
    set_player_score,
    set_player_shop_name,
    set_player_skill_level,
    set_player_skin,
    set_player_special_action,
    set_player_team,
    set_player_time,
    set_player_velocity,
    set_player_virtual_world,
    set_player_wanted_level,
    set_player_weather,
    set_player_world_bounds,
    set_pvar_float,
    set_pvar_int,
    set_pvar_string,
    set_spawn_info,
    show_player_name_tag_for_player,
    spawn_player,
    start_recording_player_data,
    stop_audio_stream_for_player,
    stop_recording_player_data,
    toggle_player_clock,
    toggle_player_controllable,
    toggle_player_spectating,
)
from samp import (
    BULLET_HIT_TYPE_NONE,
    BULLET_HIT_TYPE_OBJECT,
    BULLET_HIT_TYPE_PLAYER,
    BULLET_HIT_TYPE_PLAYER_OBJECT,
    BULLET_HIT_TYPE_VEHICLE,
    CAMERA_CUT,
    INVALID_ACTOR_ID,
    INVALID_OBJECT_ID,
    INVALID_PLAYER_ID,
    INVALID_VEHICLE_ID,
    MAPICON_LOCAL,
    SELECT_OBJECT_GLOBAL_OBJECT,
    SELECT_OBJECT_PLAYER_OBJECT,
    SPECTATE_MODE_NORMAL,
)

from .commands import _NO_FUNCTION, cmd
from .event import event


class Player:
    """Class to interact with players that are online.

    A player is a client controlled character inside the server.
    The characters that are not controlled by a player are called non-player
    characters (NPCs), and are found in the ``Actor`` class.
    """

    def __init__(self, playerid: int):
        self.id: int = playerid

    def set_spawn_info(
        self,
        team: int,
        skin: int,
        x: float,
        y: float,
        z: float,
        rotation: float,
        weapon1: int,
        weapon1_ammo: int,
        weapon2: int,
        weapon2_ammo: int,
        weapon3: int,
        weapon3_ammo: int,
    ) -> bool:
        """This method can be used to change the spawn information of a
        specific player.

        It allows you to automatically set someone's weapons to spawn with,
        their team, skin and spawn position, normally used for things like
        minigames or automatic-spawn systems.
        This information is used after a player dies, to know where / how
        to spawn them.
        """
        return set_spawn_info(
            self.id,
            team,
            skin,
            x,
            y,
            z,
            rotation,
            weapon1,
            weapon1_ammo,
            weapon2,
            weapon2_ammo,
            weapon3,
            weapon3_ammo,
        )

    def get_id(self) -> int:
        """Get the player's player id."""
        return self.id

    def spawn(self) -> bool:
        """(Re)Spawns a player.

        .. note:: Kills the player if they are in a vehicle and then they spawn
            with a bottle in their hand.
        """
        return spawn_player(self.id)

    def set_pos_find_z(self, x: float, y: float, z: float) -> bool:
        """Set the player's position then adjust the player's
        z-coordinate to the nearest solid ground under the position.

        This method is useful for setting a player's position but also
        making sure they do not spawn in an inappropriate location,
        such as in water or underground. However, this method does not
        work if the new coordinates are far away from where the player
        currently is. In such a case the z-coordinate will be set to 0,
        which will likely put them underground or into a body of water.

        In order to get the most out of setting a player's position and
        avoid this problem, look into using an external plugin such as
        MapAndreas or ColAndreas.
        """
        return set_player_pos_find_z(self.id, x, y, z)

    def get_pos(self) -> Tuple[float, float, float]:
        """Get the position of the player as a tuple (x, y, z)."""
        return get_player_pos(self.id)

    def set_pos(self, x: float, y: float, z: float) -> bool:
        """Set the player's position to a given coordinate."""
        return set_player_pos(self.id, x, y, z)

    def get_facing_angle(self) -> float:
        """Get the player's facing angle."""
        return get_player_facing_angle(self.id)

    def set_facing_angle(self, angle: float) -> bool:
        """Set the player's facing angle.

        :param angle: A float, 0.0 < 360.0
        :return: This method does not return anything.

        Directly north is heading 0.0.
        """
        return set_player_facing_angle(self.id, angle)

    def is_in_range_of_point(
        self, range: float, x: float, y: float, z: float
    ) -> bool:
        """Check if the player is in range of a point.

        :param range: The radius of the circle around the point.
        :param x,y,z: The coordinate of the point.
        :return: A boolean that represents if the player is in range or not.
        """
        return is_player_in_range_of_point(self.id, range, x, y, z)

    def distance_from_point(self, x: float, y: float, z: float) -> float:
        """Calculate the distance between the player and a map coordinate."""
        return get_player_distance_from_point(self.id, x, y, z)

    def is_streamed_in(self, player: "Player") -> bool:
        """Check if the player is streamed in on another player's client."""
        return is_player_streamed_in(self.id, player.id)

    def get_interior(self) -> int:
        """Get the player's interior. Normal world is in interior 0.

        :return: A positive integer between 0-65535.

        A list of currently known interiors and their positions can be
        found here: https://open.mp/docs/scripting/resources/interiorids
        """
        return get_player_interior(self.id)

    def set_interior(self, interior_id: int) -> bool:
        """Set the interior the player to be in.

        Syncs for all players even if the player is desynced.
        """
        return set_player_interior(self.id, interior_id)

    def get_health(self) -> float:
        """Get the player's health."""
        return get_player_health(self.id)

    def set_health(self, health: float) -> bool:
        """Set the player's health.

        :param health: A float between `0.0` and `100.0`.
        :return: This method does not return anything.
        """
        return set_player_health(self.id, health)

    def get_armour(self) -> float:
        """Get the player's armour.

        Value is a float between `0.0` and `100.0`.
        """
        return get_player_armour(self.id)

    def set_armour(self, armour: float) -> bool:
        """Set the player's armour.

        :param armour: A float between `0.0` and `100.0`.
        :return: This method does not return anything.
        """
        return set_player_armour(self.id, armour)

    def get_ammo(self) -> int:
        """Get the amount of ammo in the player's current weapon."""
        return get_player_ammo(self.id)

    def set_ammo(self, weaponid: int, ammo: int) -> bool:
        """Set ammo for a weapon id.

        :param int weaponid: The ID of the weapon to set the ammo of.
        :param int ammo: The amount of ammo to set.
        :return: No return value.
        """
        return set_player_ammo(self.id, weaponid, ammo)

    def get_weapon_state(self) -> int:  # PS - this is a test docstring w/rst!
        """Check the state of the player's weapon.

        * - ID
            - Constant
            - Description
        * - -1
            - WEAPONSTATE_UNKNOWN
            - Unknown (Set when in a vehicle)
        * - 0
            - WEAPONSTATE_NO_BULLETS
            - The weapon has no remaining ammo
        * - 1
            - WEAPONSTATE_LAST_BULLET
            - The weapon has one remaining bullet
        * - 2
            - WEAPONSTATE_MORE_BULLETS
            - The weapon has multiple bullets
        * - 3
            - WEAPONSTATE_RELOADING
            - he player is reloading their weapon

        Example:
        -------

        .. code-block:: python

            if player.weapon_state = WEAPONSTATE_LAST_BULLET:
                player.send_client_message(-1, "You only have 1 bullet left!")

        """
        return get_player_weapon_state(self.id)

    def get_target_player(self) -> "Player" | None:
        """Check who the player is aiming at.

        :return: The player instance the player is aiming at. If the player
            is not aiming at anyone, will return None.
        """
        target_player_id = get_player_target_player(self.id)
        if target_player_id == INVALID_PLAYER_ID:
            return None
        return Player(target_player_id)

    def get_target_actor(self) -> "Player" | None:
        """Get which actor that the player is currently aiming at.

        :return: The player instance the player is aiming at. If the player
            is not aiming at anyone, will return None.
        """
        target_actor_id = get_player_target_actor(self.id)
        if target_actor_id == INVALID_PLAYER_ID:
            return None
        return Player(target_actor_id)

    def get_team(self) -> int:
        """Get the player's team ID.

        -  0-254  are valid teams
        -  255 is defined as NO_TEAM. The player is not on any team `(default)`
        - -1 is returned if something went wrong reading the value.

        """
        return get_player_team(self.id)

    def set_team(self, teamid: int) -> bool:
        """Set the team the player should belong to.

        0-254 are valid teams. 255 is defined as NO_TEAM.
        That means you need to set team to 255 to remove from a team.
        """
        return set_player_team(self.id, teamid)

    def get_score(self) -> int:
        """Get the player's score."""
        return get_player_score(self.id)

    def set_score(self, score: int) -> bool:
        """Set the player's score to a given value."""
        return set_player_score(self.id, score)

    def get_drunk_level(self) -> int:
        """Get the player's drunk level.

        - 0 to 2000 - No visible effect
        - 2001 to 5000 - Visible camera swaying and control issues\
            in vehicles. HUD is visible.
        - 5001 and above - Swaying continues, but HUD becomes invisible.

        .. note:: Drunk level will decrease with player fps.
            If you have 50 fps, the drunk level will decrease with 50 levels
            per second. This makes this method very useful to determine user
            FPS from server side.

        More information:
        https://open.mp/docs/scripting/functions/SetPlayerDrunkLevel
        """
        return get_player_drunk_level(self.id)

    def set_drunk_level(self, level: int) -> bool:
        """Set the player's drunk level.

        :param level:
            - 0 to 2000: No visible effect
            - 2001 to 5000: Visible camera swaying and control issues\
            in vehicles. HUD is visible.
            - 5001 and above: Swaying continues, but HUD becomes invisible.
        :return: Does not return anything.
        """
        return set_player_drunk_level(self.id, level)

    def get_color(self) -> int:
        """Get the player's color.

        .. note:: If you try to read the value before it is set, it will
            return 0 (Black).
        """
        return get_player_color(self.id)

    def set_color(self, color: int) -> bool:
        """Set a player's color to a given `color` value.

        You can use Hexadecimal numbers to make it easier. The value is
        expected in the following format ``0xRRGGBBAA``,
        where:

            - ``RR`` is red
            - ``GG`` is green
            - ``BB`` is blue
            - ``AA`` is the opacity.
        """
        return set_player_color(self.id, color)

    def get_skin(self) -> int:
        """Get the player's skin.

        :return: Skin ID, valid values are 0-311.

        A skin is the character model.
        """
        return get_player_skin(self.id)

    def set_skin(self, skinid: int) -> bool:
        """Change the skin/character of the player.

        :param skinid: ID can be between 0 and 311, except for skin ID 74.
        :return: Nothing is returned by this method.

        See available skins and the corresponding ID's here:
        https://open.mp/docs/scripting/resources/skins

        .. warning::
            Known Issues:
            If a player's skin is set when they are crouching,
            in a vehicle, or performing certain animations, they will become
            frozen or otherwise glitched. This can (in most cases) be fixed
            by using ``player.toggle_controllable(True)``.

            Players can be detected as being crouched through
            ``player.get_special_action() == SPECIAL_ACTION_DUCK``

        .. warning::
            Other players around the player may crash if they are in a vehicle
            or if they are interacting a vehicle when the skin is changed.
            Setting a player's skin when the player is dead may crash players
            around them. Breaks the sitting animation on bikes.

        Example:
        -------

        .. code-block:: python

            player.set_skin(45)

        """
        return set_player_skin(self.id, skinid)

    def give_weapon(self, weapon_id: int, ammo: int) -> bool:
        """Give the player a weapon with specified amount of ammo.

        :param weapon_id: The weapon ID to give the player.
        :param ammo: The amount of ammo the weapon should have.
        :return: This function does not return anything.

        See all weapon ID's here:
        https://open.mp/docs/scripting/resources/weaponids

        Also, notice how you can use the constants as in pawn too, to define
        the weapon. For example, ``WEAPON_KATANA``.

        .. code-block:: python

            player.give_weapon(6, 1)  # Give a shovel
            player.give_weapon(WEAPON_COLT45, 500)  # Colt45, 500 bullets
        """
        return give_player_weapon(self.id, weapon_id, ammo)

    def reset_weapons(self) -> bool:
        """Removes all weapons from a player."""
        return reset_player_weapons(self.id)

    def set_armed_weapon(self, weapon_id: int) -> bool:
        """Set which weapon the player should be armed with.

        The player needs to have this weapon for it to work.
        Calling this method will not give the player a new weapon.
        """
        return set_player_armed_weapon(self.id, weapon_id)

    def get_weapon_data(self, slot: int) -> Tuple[int, int]:
        """Get weapon data on a given slot.

        The weapon slot can be 0-13.
        The tuple returned contains `weapon, ammo`.

        Example:
        -------

        .. code-block:: python

            weapon, ammo = player.get_weapon_data(3)  # Get data in slot 3
            print(f"Weapon ID: {weapon} || Ammo: {ammo}")

        """
        return get_player_weapon_data(self.id, slot)

    def give_money(self, money: int) -> bool:
        """Give money or take money from a player.

        The amount of money you want to give can be negative to reduce money.

        :Example:

        .. code-block:: python

            player.give_money(1000)  # Give player $1000

        """
        return give_player_money(self.id, money)

    def reset_money(self) -> bool:
        """Use this method to reset player money to 0."""
        return reset_player_money(self.id)

    def get_name(self) -> str:
        """Get the player's name."""
        return get_player_name(self.id)

    def set_name(self, name: str) -> int:
        r"""Set a new name for the player.

        :param name: The name to set. Must be 2-24 characters long and only
            contain valid characters (0-9, a-z, A-Z, [], (), \\$ @ . _ and =).
        :return: This method does not return anything.


        .. warning:: Player names can be up to 24 characters when using this
            function, but when joining the server from the SA-MP server
            browser, players' names must be no more than 20 and less than 3
            characters (the server will deny entry).
            This allows for 4 characters extra when using SetPlayerName.
            Beware that an empty name will cause the server to crash.
        """
        return set_player_name(self.id, name)

    def get_money(self) -> int:
        """Get the player's money."""
        return get_player_money(self.id)

    def set_money(self, money: int) -> bool:
        """Set the money a player should have.

        :param money: Set the new amount of money the player should have.
        :return: This method does not return anything.

        .. note:: If the player has negative amount of cash,
            numbers will be shown as red on the HUD.

        .. note:: Behind the scenes, setting money will first do
            ``reset_money`` and then
            ``give_money``.
        """
        reset_player_money(self.id)
        return give_player_money(self.id, money)

    def get_state(self) -> int:
        """Get the current player state.

        https://open.mp/docs/scripting/resources/playerstates for more info.
        """
        return get_player_state(self.id)

    def get_ip(self) -> str:
        """Get the player's IP Address."""
        return get_player_ip(self.id)

    def get_ping(self) -> int:
        """Get the player latency to server, represented in milliseconds."""
        return get_player_ping(self.id)

    def weapon(self) -> int:
        """Get the weapon id of the currently held weapon.

        :return: The weapon ID of the weapon they are holding.

        .. note:: When the player state is ``PLAYER_STATE_DRIVER`` or
            ``PLAYER_STATE_PASSENGER``, this function returns the weapon
            held by the player before they entered the vehicle.
        """
        return get_player_weapon(self.id)

    def get_keys(self) -> Tuple[int, int, int]:
        """Check which keys a player is pressing.

        :return: A tuple with 3 integers in the following order:

            :keys: A set of bits containing the player's key states
                represented as a bitmask.
            :up_down: Up/Down state
            :left_right: left/right state

        See all keys here:
        https://www.open.mp/docs/scripting/resources/keys

        .. note:: Only the FUNCTION of keys can be detected; not the actual
            keys.
            For example, it is not possible to detect if a player presses
            SPACE, but you can detect if they press SPRINT (which can be mapped
            (assigned/binded) to ANY key (but is space by default)).

        .. note:: As of update 0.3.7, the keys "A" and "D" are not
            recognized when in a vehicle.
            However, keys "W" and "S" can be detected with the "keys" return
            value.
        """
        return get_player_keys(self.id)

    def get_time(self) -> Tuple[int, int]:
        """Get the player's game time.

        Value is represented as a tuple with two values: `hour, minute`
        """
        return get_player_time(self.id)

    def set_time(self, hour: int, minute: int) -> bool:
        """Set the time for the player.

        :param int hour: Hour to set (0-23).
        :param int minute: 	Minutes to set (0-59).
        """
        return set_player_time(self.id, hour, minute)

    def toggle_clock(self, toggle: bool) -> bool:
        """Toggle the in-game clock (top-right corner) for a specific player.

        :param bool toggle: ``True`` to toggle clock on, else use ``False``.
        :return: No return value.

        When this is enabled, time will progress at 1 minute per second.
        Weather will also interpolate (slowly change over time) when set using
        :meth:`set_weather()`
        """
        return toggle_player_clock(self.id, toggle)

    def set_weather(self, weather: int) -> bool:
        """Set the player's weather.

            :param weather: The weather ID to set between 0 and 20.
            :return: This method does not return anything.

        If ``player.toggle_clock`` is on,
        then the weather will change slowly too.

        .. list-table:: Available weather IDs
            :widths: 30 30 30
            :header-rows: 1

            *  - ID
               - Constant name
               - Comments
            *  - 0
               - EXTRASUNNY_LA
               -
            *  - 1
               - SUNNY_LA
               -
            *  - 2
               - EXTRASUNNY_SMOG_LA
               -
            *  - 3
               - SUNNY_SMOG_LA
               -
            *  - 4
               - CLOUDY_LA
               -
            *  - 5
               - SUNNY_SF
               -
            *  - 6
               - EXTRASUNNY_SF
               -
            *  - 7
               - CLOUDY_SF
               -
            *  - 8
               - RAINY_SF
               -
            *  - 9
               - FOGGY_SF
               -
            *  - 10
               - SUNNY_VEGAS
               -
            *  - 11
               - EXTRASUNNY_VEGAS
               - Has heat wave effect
            *  - 12
               - CLOUDY_VEGAS
               -
            *  - 13
               - EXTRASUNNY_COUNTRYSIDE
               -
            *  - 14
               - SUNNY_COUNTRYSIDE
               -
            *  - 15
               - CLOUDY_COUNTRYSIDE
               -
            *  - 16
               - RAINY_COUNTRYSIDE
               -
            *  - 17
               - EXTRASUNNY_DESERT
               -
            *  - 18
               - SUNNY_DESERT
               -
            *  - 19
               - SANDSTORM_DESERT
               -
            *  - 20
               - UNDERWATER
               - greenish, foggy effect

        More information and details:
        https://dev.prineside.com/en/gtasa_weather_id/

        To set weather for everyone, use ``set_weather(weatherid)`` which is a
        global function.
        """
        return set_player_weather(self.id, weather)

    def force_class_selection(self) -> bool:
        """Force a player to go back to class selection on next spawn.

        .. note:: You can quickly get the player into class selection by
            toggling spectating on and then off. It will not trigger a state
            change to ``PLAYER_STATE_WASTED`` if the spectate toggle method
            is used.
        """
        return force_class_selection(self.id)

    def get_wanted_level(self) -> int:
        """Get the player's wanted level."""
        return get_player_wanted_level(self.id)

    def set_wanted_level(self, level: int) -> bool:
        """Set the player's wanted level."""
        return set_player_wanted_level(self.id, level)

    def get_fighting_style(self) -> int:
        """Get the player's special fighting style."""
        return get_player_fighting_style(self.id)

    def set_fighting_style(self, style: int) -> bool:
        """Set the player's fighting style.

        :param style: A fight style ID, shown in below table.
        :return: This method does not return anything.

        To use in-game, aim and press the 'secondary attack' key
        (ENTER by default).

        .. list-table:: Available fight styles
            :widths: 10 15
            :header-rows: 1

            * - ID
              - Constant
            * - 4
              - FIGHT_STYLE_NORMAL
            * - 5
              - FIGHT_STYLE_BOXING
            * - 6
              - FIGHT_STYLE_KUNGFU
            * - 7
              - FIGHT_STYLE_KNEEHEAD
            * - 15
              - FIGHT_STYLE_GRABKICK
            * - 16
              - FIGHT_STYLE_ELBOW
        """
        return set_player_fighting_style(self.id, style)

    def get_velocity(self) -> Tuple[float, float, float]:
        """Get the velocity of the player.

        :return: A tuple with 3 floats, representing the velocity in x, y & z
            direction.

        Example:
        -------

        .. code-block:: python

            x, y, z = player.get_velocity()
            print(f"Current velocity: {x}, {y}, {z}")
            # prints: 'Current velocity: 0.0, 0.0, 0.0'
            # given that the player is not moving.

        """
        return get_player_velocity(self.id)

    def set_velocity(self, x: float, y: float, z: float) -> bool:
        """Set the velocity of a player in X,Y,Z direction."""
        return set_player_velocity(self.id, x, y, z)

    def play_crime_report(self, suspect: "Player", crime: int) -> bool:
        """Plays a crime report for the player.

        You know when the player gets wanted in single player,
        the dispatch on the radio reads out actions and positions.
        You can also do this on SA-MP, by calling this method.


        :param suspect: The player you want to play the crime report about.
        :param crime: One of the available crime ID's in below table.

        .. list-table:: Crime ID's
            :widths: 30 30 30
            :header-rows: 1

            * - Crime id
              - 10-code that is used
              - Message from dispatcher
            * - 3
              - 10-71
              - Advise nature of fire (size, type, contents of building)
            * - 4
              - 10-47
              - Emergency road repairs needed
            * - 5
              - 10-81
              - Breatherlizer Report
            * - 6
              - 10-24
              - Assignment Completed
            * - 7
              - 10-21
              - Call () by phone
            * - 8
              - 10-21
              - Call () by phone
            * - 9
              - 10-21
              - Call () by phone
            * - 10
              - 10-17
              - Meet Complainant
            * - 11
              - 10-81
              - Breatherlizer Report
            * - 12
              - 10-91
              - Pick up prisoner/subject
            * - 13
              - 10-28
              - Vehicle registration information
            * - 14
              - 10-81
              - Breathalyzer
            * - 15
              - 10-28
              - Vehicle registration information
            * - 16
              - 10-91
              - Pick up prisoner/subject
            * - 17
              - 10-34
              - Riot
            * - 18
              - 10-37
              - (Investigate) suspicious vehicle
            * - 19
              - 10-81
              - Breathalyzer
            * - 21
              - 10-7
              - Out of service
            * - 22
              - 10-7
              - Out of service
        """
        return play_crime_report_for_player(self.id, suspect.id, crime)

    def play_audio_stream(
        self,
        url: str,
        position_x: float = 0.0,
        position_y: float = 0.0,
        position_z: float = 0.0,
        distance: float = 50.0,
        usepos: bool = False,
    ) -> bool:
        """Play an audio stream for a player.

        Normal files can also be streamed, such as MP3.
        """
        return play_audio_stream_for_player(
            self.id, url, position_x, position_y, position_z, distance, usepos
        )

    def stop_audio_stream(self) -> bool:
        """Stop the player's audio stream, if any."""
        return stop_audio_stream_for_player(self.id)

    def set_shop_name(self, shop_name: str) -> bool:
        """Load or unload an interior script for a player.

        This can for example be the ammunation menu, that belongs to the
        ammunition interior.

        Learn more here:
        https://www.open.mp/docs/scripting/resources/shopnames
        """
        return set_player_shop_name(self.id, shop_name)

    def set_skill_level(self, weapon_skill: int, level: int) -> bool:
        """Set the skill level of a certain weapon type for a player.

        :param weapon_skill: The weaponskill type (see below table).
        :param level: The level, range 0-999 where 999 is the maximum skill.
        :returns: This method does not return anything.

        .. list-table:: Weapon skills
            :widths: 10 30
            :header-rows: 1

            * - ID
              - Constant
            * - 0
              - WEAPONSKILL_PISTOL
            * - 1
              - WEAPONSKILL_PISTOL_SILENCED
            * - 2
              - WEAPONSKILL_DESERT_EAGLE
            * - 3
              - WEAPONSKILL_SHOTGUN
            * - 4
              - WEAPONSKILL_SAWNOFF_SHOTGUN
            * - 5
              - WEAPONSKILL_SPAS12_SHOTGUN
            * - 6
              - WEAPONSKILL_MICRO_UZI
            * - 7
              - WEAPONSKILL_MP5
            * - 8
              - WEAPONSKILL_AK47
            * - 9
              - WEAPONSKILL_M4
            * - 10
              - WEAPONSKILL_SNIPERRIFLE
        """
        return set_player_skill_level(self.id, weapon_skill, level)

    def get_surfing_vehicle(self) -> Optional["Vehicle"]:
        """Get the moving vehicle the player is standing on.

        .. note:: Can return ``None`` if there's no driver in the car.

        :returns: A :class:`~pysamp.vehicle.Vehicle` instance
            the player is surfing on, or ``None`` if there's no vehicle being
            surfed.
        """
        veh_id = get_player_surfing_vehicle_id(self.id)
        if veh_id == INVALID_VEHICLE_ID:
            return None
        return Vehicle(veh_id)

    def get_surfing_object(self) -> Optional["Object"]:
        """Get the moving object the player is standing on.

        :returns: An instance of :class:`~pysamp.object.Object` the player is
            standing on, or ``None`` if there's no moving object found.
        """
        obj_id = get_player_surfing_object_id(self.id)
        if obj_id == INVALID_OBJECT_ID:
            return None
        return Object(obj_id)

    def remove_building(
        self, model_id: int, x: float, y: float, z: float, radius: float
    ) -> bool:
        """Remove a standard San Andreas model for a single player within a
        specified range.

        .. list-table:: Parameters
            :widths: 30 25
            :header-rows: 1

            * - Parameter
              - Desccription
            * - model_id
              - The model to remove.
            * - Float:fX
              - The X coordinate around which the objects will be removed.
            * - Float:fY
              - The Y coordinate around which the objects will be removed.
            * - Float:fZ
              - The Z coordinate around which the objects will be removed.
            * - Float:fRadius
              - The radius around the specified point to remove objects with\
                the specified model.

        .. warning::
            - There appears to be a limit of around 1000 lines/objects.\
            There is no workaround.
            - When removing the same object for a player, they will crash.
            - Commonly, players crash when *re-connecting* to the server\
                because the server removes buildings on ``OnPlayerConnect``.

        Example usage:

        .. code-block:: python

            # This will remove ALL map objects for the player:
            player.remove_building(-1, 0.0, 0.0, 0.0, 6000.0)

        """
        return remove_building_for_player(self.id, model_id, x, y, z, radius)

    def get_last_shot_vectors(
        self,
    ) -> Tuple[float, float, float, float, float, float]:
        """Find out from where a bullet was shot, and where it hit/collided.

        The values are returned as a tuple, listed in the following table:

        .. note:: This function will only work when lag compensation is
            enabled. If the player hit nothing, the hit positions will be 0.
            This means you can't currently calculate how far a bullet travels
            through open air.

        The values in the tuple are in the following order:

        :From X:
            X coordinate of where the bullet originated from.
        :From Y:
            Y coordinate of where the bullet originated from.
        :From Z:
            Z coordinate of where the bullet originated from.
        :Hit X:
            X coordinate of where the bullet hit.
        :Hit Y:
            Y coordinate of where the bullet hit.
        :Hit Z:
            Z coordinate of where the bullet hit.

        Here is an example of how you can use it:

        .. code-block:: python

            if "/lastshot" in cmdtext[0:9]:
                # Get the coordinates
                (
                    x,
                    y,
                    z,
                    to_x,
                    to_y,
                    to_y
                ) = player.get_last_shot_vectors()

                # Send them to the player
                player.send_client_message(
                    -1,
                    "Last shot info: {}, {}, {}. Hit pos: {}, {}, {}".format(
                        str(x),
                        str(y),
                        str(z),
                        str(to_x),
                        str(to_y),
                        str(to_y)
                    )
                )

        """
        return get_player_last_shot_vectors(self.id)

    def set_attached_object(
        self,
        index: int,
        model_id: int,
        bone: int,
        offset_x: float = 0.0,
        offset_y: float = 0.0,
        offset_z: float = 0.0,
        rotation_x: float = 0.0,
        rotation_y: float = 0.0,
        rotation_z: float = 0.0,
        scale_x: float = 1.0,
        scale_y: float = 1.0,
        scale_z: float = 1.0,
        material_color_1: int = 0,
        material_color_2: int = 0,
    ) -> bool:
        """Attach an object to a specific bone on a player.

        :param int index: The index (slot) to assign the object to (0-9).
        :param int model_id: The model to attach.
        :param int bone: The bone to attach the object to. (0-18)
        :param optional, float offset_x: X axis offset for the object position.
        :param optional, float offset_y: Y axis offset for the object position.
        :param optional, float offset_z: Z axis offset for the object position.
        :param optional, float rotation_x: X axis rotation of the object.
        :param optional, float rotation_y: Y axis rotation of the object.
        :param optional, float rotation_z: Z axis rotation of the object.
        :param optional, float scale_x: X axis scale of the object.
        :param optional, float scale_y: Y axis scale of the object.
        :param optional, float scale_z: Z axis scale of the object.
        :param optional, int material_color_1: The first object color.
        :param optional, int material_color_2: The second object color.
        :returns: This method does not return anything.

        .. note:: Colors can be set as an integer or hex in ARGB color format.

        Available bones:

        .. list-table::
            :widths: 10 25
            :header-rows: 1

            * - ID
              - Bodypart
            * - 1
              - Spine
            * - 2
              - Head
            * - 3
              - Left upper arm
            * - 4
              - Right upper arm
            * - 5
              - Left hand
            * - 6
              - Right hand
            * - 7
              - Left thigh
            * - 8
              - Right thigh
            * - 9
              - Left foot
            * - 10
              - Right foot
            * - 11
              - Right calf
            * - 12
              - Left calf
            * - 13
              - Left forearm
            * - 14
              - Right forearm
            * - 15
              - Left clavicle (shoulder)
            * - 16
              - Right clavicle (shoulder)
            * - 17
              - Neck
            * - 18
              - Jaw

        Example:
        -------

        .. code-block:: python

            # Give player a white hat, and paint it green
            player.set_attached_object(
                3,
                19487,
                2,
                0.101,
                -0.0,
                0.0,
                5.50,
                84.60,
                83.7,
                1.0,
                1.0,
                1.0,
                0xFF00FF00
            )

        """
        return set_player_attached_object(
            self.id,
            index,
            model_id,
            bone,
            offset_x,
            offset_y,
            offset_z,
            rotation_x,
            rotation_y,
            rotation_z,
            scale_x,
            scale_y,
            scale_z,
            material_color_1,
            material_color_2,
        )

    def remove_attached_object(self, index: int) -> bool:
        """Remove an attached object from a player.

        :param index: The index to remove the object from (0-9)
        :return: Returns ``True`` on success, otherwise ``False``.

        .. code-block:: python

            # Remove all player-attached objects
            if "/removeall" in cmdtext[0:9]:
                for slot in range(MAX_PLAYER_ATTACHED_OBJECTS):
                    if player.is_attached_object_slot_used(slot):
                        player.remove_attached_object(slot)
        """
        return remove_player_attached_object(self.id, index)

    def is_attached_object_slot_used(self, index: int) -> bool:
        """Check if a player has an object attached in the specified index
        (slot).

         :param int index: The index (slot) to check.
         :return: Will return ``True`` if the slot is used, otherwise
            ``False``.

        .. code-block:: python

             # Count amount of attached objects currently on player
             count = 0
             for slot in range(MAX_PLAYER_ATTACHED_OBJECTS):
                 if player.is_attached_object_slot_used(slot):
                     count +=1
             print(count) # then shows the count in the log
        """
        return is_player_attached_object_slot_used(self.id, index)

    def edit_attached_object(self, index: int) -> bool:
        """Enter edit mode for an attached object.

        :param index: The slot of the attached object to edit.
        :returns: This method does not return anything.

        Available slots indexes are 0 through 9.


        Clicking save will call ``on_player_edit_attached_object``.

        .. note:: You can move the camera while editing by pressing and
            holding the spacebar (or W in vehicle) and moving your mouse

        .. warning:: Players will be able to scale objects up to a very large
            or negative value size. Limits should be put in place using
            ``on_player_edit_attached_object`` to abort the edit.
        """
        return edit_attached_object(self.id, index)

    def cancel_edit(self):
        """Cancel object edition mode for a player."""
        return cancel_edit(self.id)

    def get_pvar_int(self, var_name: str) -> int:
        """Get a player variable containing an integer.

        :param var_name: The variable name you want to get the value for.
            Case-insensitive, and is set with ``set_pvar_int``.
        :returns: The value the variable holds. Is 0 if not set.

        Player variables are reset when the player disconnects.
        """
        return get_pvar_int(self.id, var_name)

    def set_pvar_int(self, var_name: str, value: int) -> bool:
        """Set a player variable containing an integer.

        :param var_name: Case insensitive name of the player variable.
        :param value: The value you want to set for it.
        :return: Will return ``False`` if the ``var_name``
            is empty or too long, otherwise it returns ``True``.

        You can read this value across all scripts using
        ``player.get_pvar_int()``.
        """
        return set_pvar_int(self.id, var_name, value)

    def get_pvar_string(self, var_name: str) -> str:
        """Get a player variable containing a string.

        :param var_name: The variable name you want to get the value for.
            Case-insensitive, and is set with ``player.set_pvar_string()``.
        :returns: The value the variable holds. Is empty if not set.

        Player variables are reset when the player disconnects.
        """
        return get_pvar_string(self.id, var_name)

    def set_pvar_string(self, var_name: str, value: str) -> bool:
        """Set a player variable containing a string.

        :param var_name: Case insensitive name of the player variable.
        :param value: The string you want to set for it.
        :return: Will return ``False`` if the ``var_name``
            is empty or too long, otherwise it returns ``True``.

        You can read this value across all scripts using
        ``player.get_pvar_string()``.
        """
        return set_pvar_string(self.id, var_name, value)

    def get_pvar_float(self, var_name: str) -> float:
        """Get a player variable containing a float.

        :param var_name: The variable name you want to get the value for.
            Case-insensitive, and is set with ``player.set_pvar_float()``.
        :returns: The value the variable holds. Is 0.0 if not set.

        Player variables are reset when the player disconnects.
        """
        return get_pvar_float(self.id, var_name)

    def set_pvar_float(self, var_name: str, value: float) -> bool:
        """Set a player variable containing a float.

        :param var_name: Case insensitive name of the player variable.
        :param value: The string you want to set for it.
        :return: Will return ``False`` if the ``var_name``
            is empty or too long, otherwise it returns ``True``.

        You can read this value across all scripts using
        ``player.get_pvar_float()``.
        """
        return set_pvar_float(self.id, var_name, value)

    def delete_pvar(self, var_name: str) -> bool:
        """Delete a player variable.

        :param var_name: The variable name to delete.
        :returns: This method does not return anything.
        """
        return delete_pvar(self.id, var_name)

    def get_pvars_upper_index(self) -> int:
        """Each PVar (player-variable) has its own unique identification number
        for lookup, this function returns the highest ID set for a player.

        :returns: An integer representing the highest index at which there was
            found a player variable set.

        :Example:

        .. code-block:: python

            pvar_upper_index = player.get_pvars_upper_index() + 1
            pvar_count: int = 0

            for i in range(pvar_upper_index):
                var_name = player.get_pvar_name_at_index(i)
                # If the var is set (type not 0), increment p_var_count.
                if player.get_pvar_type(var_name) is not 0:
                    pvar_count = pvar_count + 1

            print(f"You have {pvar_count} player-variables set. \\
                Upper index (highest ID):\\
                {pvar_upper_index - 1}.")
        """  # noqa
        return get_pvars_upper_index(self.id)

    def get_pvar_name_at_index(self, index: int) -> str:
        """Find a player variable name at a certain index.

        :param index: Which index should be retrieved.
        :returns: The name of the variable, if set.
        """
        return get_pvar_name_at_index(self.id, index)

    def get_pvar_type(self, var_name: str) -> int:
        """Get the type (integer, float or string) of a player variable.

        :param var_name: The name of the variable you want to get the type of.
        :returns: An ID that represent either of the types. See table below.

        Possible values that can be returned:

        .. list-table:: Type values
            :widths: 10 25
            :header-rows: 1

            * - ID
              - Type
            * - 0
              - PLAYER_VARTYPE_NONE
            * - 1
              - PLAYER_VARTYPE_INT
            * - 2
              - PLAYER_VARTYPE_STRING
            * - 3
              - PLAYER_VARTYPE_FLOAT

        ``PLAYER_VARTYPE_NONE`` is returned when the variable
        with the given name does not exist.
        """
        return get_pvar_type(self.id, var_name)

    def set_chat_bubble(
        self, text: str, color: int, draw_distance: float, expiretime: int
    ) -> bool:
        """Make text appear above the nametag of a player, that other
        players can see.

        :param text: The text you would like to show.
        :param color: Which color you would like to give the font.
        :param draw_distance: How far you want the text to be visible from.
        :param expiretime: How long in miliseconds the bubble should stay.
        :return: This method does not return anything.

        .. note:: You can not see your own chat bubbles, same applies
            for 3D textlabels.
        """
        return set_player_chat_bubble(
            self.id, text, color, draw_distance, expiretime
        )

    def put_in_vehicle(self, vehicle_id: int, seat_id: int) -> bool:
        """Put the player inside a vehicle.

        :param vehicle_id: The vehicle you want to put the player in.
        :param seat_id: Which seat. (0->)

        :Available seats:
            - 0 - Driver
            - 1 - Front passenger
            - 2 - Back-left passenger
            - 3 - Back-right passenger
            - 4+ - Passenger seats (coach etc.)

        .. warning:: If this function is used on a player that is already in
            a vehicle, other players will still see them in their previous
            vehicle. To fix this, first remove the player from the vehicle.

        .. warning:: If the seat is invalid or is taken, will cause a crash
            when the player *exit* the vehicle. For example bikes may only have
            two seats.
        """
        return put_player_in_vehicle(self.id, vehicle_id, seat_id)

    def get_vehicle_id(self) -> int:
        """Get the ID of the vehicle the player is currently in.

        :returns: Vehicle ID of the vehicle.

        .. note:: NOT the model id of the vehicle. See
            ``get_vehicle_model(vehicleid)`` for that.
        """
        return get_player_vehicle_id(self.id)

    def get_vehicle_seat(self) -> int:
        """Find out which seat a player is in.

        :returns: The seat ID. -1 means they are not in a vehicle. 0-4 is
            normal
        """
        return get_player_vehicle_seat(self.id)

    def remove_from_vehicle(self) -> bool:
        """Remove a player from the current vehicle.

        :returns: This method does not return anything.

        .. note::
            - The exiting animation is not synced for other players.
            - The player is not removed if they are in a RC Vehicle.

        """
        return remove_player_from_vehicle(self.id)

    def toggle_controllable(self, toggle: bool) -> bool:
        """Freeze or unfreeze a player.

        :param toggle: Set to ``False`` to freeze, ``True`` to unfreeze.
        :returns: This method does not return antyhing.

        .. warning:: The player will also be unable to move their camera.
        """
        return toggle_player_controllable(self.id, toggle)

    def play_sound(self, soundid: int, x: float, y: float, z: float) -> bool:
        """Play a game sound for the player.

        :param soundid: The sound id you would like to play for the player.
        :param x: x coordinate to play the sound at.
        :param y: y coordinate.
        :param z: z coordinate.

        .. note:: Set the position to 0.0 if you want to ignore the position,
            and to play it no matter where the player is at.

        A list with available sound id's can be found here:
        https://www.open.mp/docs/scripting/resources/sound-ids
        """
        return player_play_sound(self.id, soundid, x, y, z)

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
        force_sync: bool = False,
    ) -> bool:
        """Apply a given animation to the player."""
        return apply_animation(
            self.id,
            animation_library,
            animation_name,
            delta,
            loop,
            lock_x,
            lock_y,
            freeze,
            time,
            force_sync,
        )

    def clear_animations(self, forcesync: bool = False) -> bool:
        """Stop any ongoing animations the player has running.

        :param optional bool forcesync: Set to ``True`` to force the player
            to sync the animation with other players in streaming radius.
        :return: This method does not have any return values.

        Clears all animations for the player (it also cancels all
        current tasks such as jetpacking, parachuting, entering vehicles,
        driving, swimming, etc..).

        """
        return clear_animations(self.id, forcesync)

    def animation_index(self) -> int:
        """Get the current playing animation index of the player.

        :returns: The animation index.
        """
        return get_player_animation_index(self.id)

    def get_special_action(self) -> int:
        """Get the special action the player is performing.

        :returns: An ID representing the special action that is being
            performed.

        Check the list with special actions here:
        https://www.open.mp/docs/scripting/resources/specialactions
        """
        return get_player_special_action(self.id)

    def set_special_action(self, action_id: int) -> bool:
        """Set a special action on a player.

        :param action_id: The special action the player should perform.
        :return: No return value for this method.

        Check the list of special actions here:
        https://www.open.mp/docs/scripting/resources/specialactions
        """
        return set_player_special_action(self.id, action_id)

    def disable_remote_vehicle_collisions(self, disable: bool) -> bool:
        """Disables collisions between occupied vehicles for a player.

        :param disable: Bool that disables colissions if set to ``True``.
        :return: No return value for this method.

        """
        return disable_remote_vehicle_collisions(self.id, disable)

    def set_checkpoint(
        self, x: float, y: float, z: float, size: float
    ) -> bool:
        """Create a checkpoint for the player. Shows a red blip on the radar.

        :param x: The x position for the checkpoint.
        :param y: The y position for the checkpoint.
        :param z: The z position for the checkpoint.
        :param size: The size of the checkpoint.

        .. note::
            Checkpoints are asynchronous, meaning only one can be
            shown at a time.

        Checkpoints don't need to be disabled before setting another one.
        """
        return set_player_checkpoint(self.id, x, y, z, size)

    def disable_checkpoint(self) -> bool:
        """Remove the active checkpoint for a player.

        :return: No value is returned by this method.
        """
        return disable_player_checkpoint(self.id)

    def set_race_checkpoint(
        self,
        type: int,
        x: float,
        y: float,
        z: float,
        next_x: float,
        next_y: float,
        next_z: float,
        size: float,
    ) -> bool:
        """Race checkpoints are red checkpoints, as used in singleplayer races.

        :param type: Can be values 0-8, see table further down for reference.
        :param x: World X coordinate to place the race checkpoint.
        :param y: World Y coordinate to place the race checkpoint.
        :param z: World Z coordinate to place the race checkpoint.
        :param next_x: The X coordinate of the next race checkpoint.
        :param next_y: The Y coordinate of the next race checkpoint.
        :param next_z: The Z coordinate of the next race checkpoint.
        :param size: The radius of the checkpoint. Also acts as the trigger
            area.
        :return: No value returned.

        .. list-table:: The available types
            :widths: 10 30 30
            :header-rows: 1

            * - ID
              - Constant name
              - Description
            * - 0
              - RACE_NORMAL
              - Normal checkpoint with arrow to the next coordinates.
            * - 1
              - RACE_FINISH
              - Checkpoint with finish flag on it.
            * - 2
              - RACE_NOTHING
              - An empty checkpoint with nothing on it.
            * - 3
              - RACE_AIR_NORMAL
              - A normal air race checkpoint (Circle).
            * - 4
              - RACE_AIR_FINISH
              - Air checkpoint with finish flag on it.
            * - 5
              - RACE_AIR_ONE
              - Air race checkpoint that rotates and stops.
            * - 6
              - RACE_AIR_TWO
              - Air race checkpoint that increases, decreases and disappears.
            * - 7
              - RACE_AIR_THREE
              - Air race checkpoint, this type swings up and down.
            * - 8
              - RACE_AIR_FOUR
              - Air race checkpoint, swings up and down.

        .. note:: If you use ``RACE_FINISH`` and at the same time use
            coordinates for the next checkpoint, it will automatically show
            ``RACE_NORMAL`` instead.

        .. warning:: Race checkpoints are asynchronous, that means only one
            can be shown at a time.

        You do not need to disable a checkpoint in order to show a new one.
        """
        return set_player_race_checkpoint(
            self.id, type, x, y, z, next_x, next_y, next_z, size
        )

    def disable_race_checkpoint(self) -> bool:
        """Remove the active race checkpoint for the player.

        :returns: This method does not return anything.
        """
        return disable_player_race_checkpoint(self.id)

    def set_world_bounds(
        self, x_max: float, x_min: float, y_max: float, y_min: float
    ) -> bool:
        """Set the world boundaries for a player.
        Players can not go out of the boundaries, they will be pushed back in.

        :param x_max: The max x coordinate of the bounds.
        :param x_min: The min x coordinate of the bounds.
        :param y_max: The max y coordinate of the bounds.
        :param y_min: The min y coordinate of the bounds.
        :return: This method does not return anything.

        :Illustration:

        .. code-block:: python

                  MinY
                    v
             MinX > *-------------
                    |            |
                    |   Bound    |
                    |   center   |
                    |            |
                    -------------* < MaxX
                                ^
                               MaxY


        """
        return set_player_world_bounds(self.id, x_max, x_min, y_max, y_min)

    def set_marker(self, showplayer: "Player", color: int) -> bool:
        """Change the colour of the player's nametag and radar blip for
        another player on the server.

        :param showplayer: The player that should see the change.
        :param color: The desired color in RGBA/Hex/Int format.
        This should only be used with the square icon (ID: 0).
        :return: Returns nothing.

        .. code-block:: python

            # "target" is a player object.
            player.set_marker(target, 0xAA3333FF)
            # Now, "target" will see the "player" with the given
            # color on their map.
        """
        return set_player_marker_for_player(self.id, showplayer.id, color)

    def show_name_tag(self, showplayer: "Player", show: bool) -> bool:
        """Show or toggle the player nametags,
        healthbars and armor bars above their head.

        :param showplayer: Player whose name tag will be shown or hidden.
        :param show: ``False`` to hide, ``True`` to show.
        :return: Returns nothing.

        For use of a similar function like this on a global level,
        check out ``show_name_tags()`` function.
        """
        return show_player_name_tag_for_player(self.id, showplayer.id, show)

    def set_map_icon(
        self,
        icon_id: int,
        x: float,
        y: float,
        z: float,
        marker_type: int,
        color: int,
        style: int = MAPICON_LOCAL,
    ) -> bool:
        """Place an icon/marker on a player's map. Can be used to mark
        locations.

        :param icon_id: The icon slot you want to use.
            Maximum 100 icons can be shown (0-99).
        :param x: The world x-coordinate.
        :param y: The world y-coordinate.
        :param z: The world z-coordinate.
        :param marker_type: Which type of icon or marker you want to show.
            More here: https://www.open.mp/docs/scripting/resources/mapicons
        :param color: The color you want to give the marker, in RGBA format.
        :param style: The icon style:
            https://www.open.mp/docs/scripting/resources/mapiconstyles
        :return: This method does not return anything.

        .. note::
            If you use an invalid marker type, it will create ID 1
            (White Square). If you use an icon ID that is already in use,
            it will replace the current map icon using that ID.

        .. warning::
            You can only have 100 icons.
            Marker type 1, 2, 4 and 56 can make the client crash.

        """
        return set_player_map_icon(
            self.id, icon_id, x, y, z, marker_type, color, style
        )

    def remove_map_icon(self, icon_id: int) -> bool:
        """Remove a map icon that was set with ``player.set_map_icon``.

        :param icon_id: The icon slot to remove the icon from (0-99).
        :return: No return value.
        """
        return remove_player_map_icon(self.id, icon_id)

    def allow_teleport(self, allow: bool) -> bool:
        """Enable or disable teleporting when marking the map with the map-
        marker.

        :param allow: A bool to allow or disallow teleport.
        :return: Nothing.

        .. warning:: Deprecated since 0.3d.
            Please use the callback ``player.on_click_map`` instead.
        """
        return allow_player_teleport(self.id, allow)

    def set_camera_look_at(
        self, x: float, y: float, z: float, cut: int = CAMERA_CUT
    ) -> bool:
        """Make the camera look towards a set corrdinate.

        :param float x: The x coordinate to look at.
        :param float y: The y coordinate to look at.
        :param float z: The z coordinate to look at.
        :param optional int cut: The
            `style
            <https://www.open.mp/docs/scripting/resources/cameracutstyles>`_
            of the change. Can be used to interpolate (change slowly)
            from old pos to new pos using ``CAMERA_MOVE``.
        """
        return set_player_camera_look_at(self.id, x, y, z, cut)

    def set_camera_behind(self) -> bool:
        """Restore the camera to a place behind the player, after using ex.
        :py:meth:`Player.set_camera_pos`.

        :returns: This method does not return anything.
        """
        return set_camera_behind_player(self.id)

    def get_camera_position(self) -> Tuple[float, float, float]:
        """Get the current camera position for the player.

        :returns: A tuple with 3 floats, representing x, y and z position.

        .. note:: Player's camera positions are only updated once a second,
            unless aiming.
        """
        return get_player_camera_pos(self.id)

    def set_camera_position(self, x: float, y: float, z: float) -> bool:
        """Set the camera position to a given coordinate.

        :param float x: The X coordinate to place the camera at.
        :param float y: The Y coordinate to place the camera at.
        :param float z: The Z coordinate to place the camera at.
        :return: This method does not return anything.
        """
        return set_player_camera_pos(self.id, x, y, z)

    def get_camera_front_vector(self) -> Tuple[float, float, float]:
        """Get the current direction of player's aiming
        in 3-D space, the coords are relative to the camera position,
        see :meth:`Player.get_camera_pos`.

        :return: This function returns a tuple with 3 floats, that represents
            the forward facing vector in x, y and z direction.
        """
        return get_player_camera_front_vector(self.id)

    def get_camera_mode(self) -> int:
        """Get the GTA camera mode for the requested player.

        :return: A number that represents the camera mode the player currently
            is in.

        The camera modes are useful in determining whether a player is
        aiming, doing a passenger driveby etc.

        Please look at the below table for an overview of the available camera
        modes.

        .. list-table::
            :header-rows: 1

            * - Value
              - Constant
              - Description
            * - 3
              - MODE_BEHINDCAR
              - Train/tram camera
            * - 4
              - MODE_FOLLOWPED
              - Follow ped (normal behind player camera), several variable\
                distances
            * - 7
              - MODE_SNIPER
              - Sniper aiming (sniper scope)
            * - 8
              - MODE_ROCKETLAUNCHER
              - Rocket Launcher aiming (rocket launcher scope)
            * - 15
              - MODE_FIXED
              - Fixed camera (non-moving) - used for garages, chase camera,\
                entering buildings, buying food etc
            * - 16
              - MODE_1STPERSON
              - Vehicle front camera, bike side camera
            * - 18
              - MODE_CAM_ON_A_STRING
              - Normal car (+ skimmer + helicopter + airplane), several\
                variable distances
            * - 22
              - MODE_BEHINDBOAT
              - Normal boat camera
            * - 46
              - MODE_CAMERA
              - Weapon aiming (weapon scope)
            * - 51
              - MODE_ROCKETLAUNCHER_HS
              - Heat-seeking Rocket Launcher aiming
            * - 53
              - MODE_AIMWEAPON
              - Aiming any other weapon
            * - 55
              - MODE_AIMWEAPON_FROMCAR
              - Vehicle passenger aiming camera (drive by as a player)
            * - 56
              - MODE_DW_HELI_CHASE
              - Chase camera: helicopter/bird view
            * - 57
              - MODE_DW_CAM_MAN
              - Chase camera: ground camera, zooms in quite quickly\
                and pan to the vehicle
            * - 58
              - MODE_DW_BIRDY
              - Chase camera: horizontal flyby past vehicle
            * - 59
              - MODE_DW_PLANE_SPOTTER
              - Chase camera (for air vehicles only): ground camera,\
                looking up to the air vehicle
            * - 62
              - MODE_DW_PLANECAM1
              - Chase camera (for air vehicles only): vertical flyby past air\
                vehicle
            * - 63
              - MODE_DW_PLANECAM2
              - Chase camera (for air vehicles only): horizontal flyby\
                past air vehicle (similar to 58 and 62)
            * - 64
              - MODE_DW_PLANECAM3
              - Chase camera (for air vehicles only): camera focused on\
                pilot, similar to pressing LOOK_BEHIND key on foot, but in\
                air vehicle

        """
        return get_player_camera_mode(self.id)

    def enable_camera_target(self, enable: bool) -> bool:
        """Toggle camera targeting functions for a player. Disabled by default
        to save bandwidth.

        :param bool enable: ``False`` to disable, ``True`` to enable.
        :return: This method does not return anything.
        """
        return enable_player_camera_target(self.id, enable)

    def get_camera_target_object(self) -> Optional["Object"]:
        """Retrieve the map object the player is looking at.

        :return: The :class:`~object.Object` the player is looking at.
            If ``None`` is returned, player isn't
            looking at any object.

        .. note:: This function is disabled by default to save bandwidth.
            Use :meth:`Player.enable_camera_target` to enable it for each
            player.
        """
        object_id = get_player_camera_target_object(self.id)
        if object_id == INVALID_OBJECT_ID:
            return None
        return Object(object_id)

    def get_camera_target_vehicle(self) -> Optional["Vehicle"]:
        """Retrieve the ID of the vehicle the player is looking at.

        :return: The :class:`~vehicle.Vehicle` the player is looking at.
            If ``None`` is returned, player isn't
            looking at any vehicle.

        .. note:: This function is disabled by default to save bandwidth.
            Use :meth:`Player.enable_camera_target` to enable it for each
            player.

        .. note:: While a player may look at multiple vehicles, this method
            only returns one ID at a time. By experience, this usually returns
            the closest vehicle in sight.
        """
        vehicle_id = get_player_camera_target_vehicle(self.id)
        if vehicle_id == INVALID_VEHICLE_ID:
            return None
        return Vehicle(vehicle_id)

    def get_camera_target_player(self) -> Optional["Player"]:
        """Get the player the current player is looking at.

        :return: A :class:`Player` instance representing the player. If no
            player is being targeted by the camera, it will return ``None``.

        .. note:: This function is disabled by default to save bandwidth.
            Use :meth:`Player.enable_camera_target` to enable it for each
            player.
        """
        player_id = get_player_camera_target_player(self.id)

        if player_id == INVALID_PLAYER_ID:
            return None
        return Player(player_id)

    def camera_target_actor(self) -> Optional["Actor"]:
        """Get the :class:`~actor.Actor` the current player is looking at.

        :return: A :class:`actor.Actor` instance representing the actor. If no
            actor is being targeted by the camera, it will return ``None``.
        """
        actor_id = get_player_camera_target_actor(self.id)

        if actor_id == INVALID_ACTOR_ID:
            return None
        return Actor(actor_id)

    def get_camera_aspect_ratio(self) -> float:
        """Get the player's aspect ratio on the camera.

        :return: 4/3, 5/4 or 16/9. For example, 4/3 = 1.3333333333333.

        .. note:: The return value of this function represents the value
            of the "widescreen" option in the game's display settings,
            not the actual aspect ratio of the player's display.
        """
        return get_player_camera_aspect_ratio(self.id)

    def get_camera_zoom(self) -> float:
        """Get the game camera zoom level for a given player.

        :return: The zoom level as a float. Useful to check zoom level when
            using a sniper, etc.

        .. note:: This retrieves the zoom level of the GAME Camera
            (including Sniper scope), not the camera weapon.
        """
        return get_player_camera_zoom(self.id)

    def interpolate_camera_position(
        self,
        from_x: float,
        from_y: float,
        from_z: float,
        to_x: float,
        to_y: float,
        to_z: float,
        time: int,
        cut: int = CAMERA_CUT,
    ) -> bool:
        """Smoothly move the camera position from one coordinate to another,
        using a given time on the transition.

        :param from_x: X coordinate to start from.
        :param from_y: Y coordinate to start from.
        :param from_z: Z coordinate to start from.
        :param to_x: X coordinate to end at.
        :param to_y: Y coordinate to end at.
        :param to_z: Z coordinate to end at.
        :param time: The time in milliseconds for the transition to last.
        :param cut: The camera style you want to use. Check `style
            <https://www.open.mp/docs/scripting/resources/cameracutstyles>`_
            for the available styles.
        :return: This method does not return anything.

        This method only moves the physical position of the camera.
        If you want to make it rotate or look at something specific, you
        need to use this method in conjunction with
        :meth:`interpolate_camera_look_at`.

        A tip to make objects load while the camera is moving, is to
        put the player into spectate mode. This also removes the hud.
        Reset the player camera back to normal by using
        :meth:`set_camera_behind`.
        """
        return interpolate_camera_pos(
            self.id, from_x, from_y, from_z, to_x, to_y, to_z, time, cut
        )

    def interpolate_camera_look_at(
        self,
        from_x: float,
        from_y: float,
        from_z: float,
        to_x: float,
        to_y: float,
        to_z: float,
        time: int,
        cut: int = CAMERA_CUT,
    ) -> bool:
        """Make the camera change the "focus" from one coordinate to another.

        :param from_x: Initial x coordinate to start looking at.
        :param from_y: Initial y coordinate to start looking at.
        :param from_z: Initial z coordinate to start looking at.
        :param to_x: X coordinate to end looking at.
        :param to_y: Y coordinate to end looking at.
        :param to_z: Z coordinate to end looking at.
        :param time: The time in milliseconds for the transition to last.
        :param cut: The camera style you want to use. Check `style
            <https://www.open.mp/docs/scripting/resources/cameracutstyles>`_
            for the available styles.
        :return: This method does not return anything.

        This method is often used in conjunction with
        :meth:`interpolate_camera_position` in order to create smooth camera
        transitions and cutscenes.
        """
        return interpolate_camera_look_at(
            self.id, from_x, from_y, from_z, to_x, to_y, to_z, time, cut
        )

    def is_connected(self) -> bool:
        """Check if the player is connected.

        :return: ``True`` if connected, otherwise ``False``
        """
        return is_player_connected(self.id)

    def is_in_vehicle(self, vehicle_id: int) -> bool:
        """Check if the player is in a specific vehicle ID.

        :param int vehicle_id: The vehicle ID to check they are in
        :return: ``True`` if they are, otherwise ``False``.

        In order to check if they are in any vehicle, use
        :meth:`is_in_any_vehicle`.
        """
        return is_player_in_vehicle(self.id, vehicle_id)

    def is_in_any_vehicle(self) -> bool:
        """Check if the player is currently in any vehicle.

        :return: ``True`` if they are, otherwise ``False``.
        """
        return is_player_in_any_vehicle(self.id)

    def is_in_checkpoint(self) -> bool:
        """Check if the player is currently inside a checkpoint.

        :return: ``True`` if they are, ``False`` if not.

        .. note:: Race checkpoints are not compatible with this method. Please
            use :meth:`is_in_race_checkpoint` to check that.
        """
        return is_player_in_checkpoint(self.id)

    def is_in_race_checkpoint(self) -> bool:
        """Check if the given player is inside a race checkpoint.

        :return: ``True`` if they are, otherwise ``False``.

        .. note:: non-race checkpoints are not compatible with this method.
            Please use :meth:`is_in_checkpoint` to check that.
        """
        return is_player_in_race_checkpoint(self.id)

    def get_virtual_world(self) -> int:
        """Get the player's current virtual world.

        :return: The current virtual world.
        """
        return get_player_virtual_world(self.id)

    def set_virtual_world(self, world_id: int) -> bool:
        """Set the player to be part of a different virtual world.

        :param int world_id: The world ID (0-65535).
        :return: This method does not return anything.
        """
        return set_player_virtual_world(self.id, world_id)

    def enable_stunt_bonus(self, enable: bool) -> bool:
        """Toggle stunt bonus when doing jumps and flips for the given player.

        :param bool enable: Boolean to toggle it on or off. ``True`` = enabled.
        :return: This method does not return anything.
        """
        return enable_stunt_bonus_for_player(self.id, enable)

    def toggle_spectating(self, toggle: bool) -> bool:
        """Toggle the player in and out of spectate mode. When in spectate
        mode, the HUD is removed.

        :param bool toggle: Toggle spectate on with ``True`` or off with
            ``False``.
        :return: No return value.

        While in spectator mode a the player can spectate (watch) other players
        and vehicles. After using this method, either :meth:`spectate_player`
        or :meth:`spectate_vehicle` needs to be used.

        .. note::
            When spectator mode is disabled, OnPlayerSpawn will automatically
            be called, if you wish to restore player to state before
            spectating, you will have to handle that in OnPlayerSpawn.
            Note also, that player can also go to class selection before if
            they used F4 during spectate, a player also CAN die in spectate
            mode due to various glitches.

        .. warning::
            If the player is not loaded in before setting the spectate
            status to ``False``, the connection can be closed unexpectedly.
        """
        return toggle_player_spectating(self.id, toggle)

    def spectate_player(
        self, target_player: "Player", mode: int = SPECTATE_MODE_NORMAL
    ) -> bool:
        """Spectate a specific player.

        :param Player target_player: The player to spectate.
        :param optional mode: The spectate mode to use. Default:
            ``SPECTATE_MODE_NORMAL``
        :return: No return value.

        Spectate modes:

            - ``SPECTATE_MODE_NORMAL``: Normal spectate mode\
                (third person point of view). Camera can not be changed. This\
                is the default mode.
            - ``SPECTATE_MODE_FIXED``: Use :meth:`set_camera_position`\
                after this to position\
                the player's camera, and it will track the player.
            - ``SPECTATE_MODE_SIDE``: The camera will be attached to the side\
                of the player (like when you're in first-person camera on a\
                bike and you do a wheelie)
        """
        return player_spectate_player(self.id, target_player.id, mode)

    def spectate_vehicle(
        self, target_vehicle: "Vehicle", mode: int = SPECTATE_MODE_NORMAL
    ) -> bool:
        """Spectate a specific vehicle.

        :param Vehicle target_vehicle: The vehicle to spectate.
        :param optional int mode: The spectate mode to use. Default:
            ``SPECTATE_MODE_NORMAL``.

        Avaialable spectate modes:

            - ``SPECTATE_MODE_NORMAL``: Normal spectate mode\
                (third person point of view). Camera can not be changed. This\
                is the default mode.
            - ``SPECTATE_MODE_FIXED``: Use :meth:`set_camera_position`\
                after this to position\
                the player's camera, and it will track the vehicle.
            - ``SPECTATE_MODE_SIDE``: The camera will be attached to the side\
                of the vehicle (like when you're in first-person camera on a\
                bike and you do a wheelie)
        """
        return player_spectate_vehicle(self.id, target_vehicle.id, mode)

    def start_recording_data(self, recordtype: int, recordname: str) -> bool:
        """Start recording NPC data."""
        return start_recording_player_data(self.id, recordtype, recordname)

    def stop_recording_data(self) -> bool:
        """Stop recording NPC data, started with :meth:`start_recording_data`."""
        return stop_recording_player_data(self.id)

    def create_explosion(
        self, x: float, y: float, z: float, type: int, radius: float
    ) -> bool:
        """Create an explosion only visible to the player.

        :param float x: The x coordinate to create the explosion at.
        :param float y: The y coordinate to create the explosion at.
        :param float z: The z coordinate to create the explosion at.
        :param int type: Thich type of explosion.
        :param float radius: The radious for the explosion.
        :return: No value returned.

        Explosion list:
        https://www.open.mp/docs/scripting/resources/explosionlist
        """
        return create_explosion_for_player(self.id, x, y, z, type, radius)

    def send_client_message(self, color: int, message: str) -> bool:
        """Send a chat message only visible to the player.

        :param int color: The color, in ``0xRRGGBBAA`` format.
        :param str message: The message to send to the player.

        .. note:: A client message can only contain 128 characters, including
            embedded color codes.
        """
        return send_client_message(self.id, color, message)

    def send_message_to_player(self, sender: "Player", message: str) -> bool:
        """Have the player receive a direct message from the ``sender``.

        :param Player sender: The player that authored the message.
        :param str message: The message the ``sender`` wrote.
        :return: No return value.
        """
        return send_player_message_to_player(self.id, sender.id, message)

    def send_death_message(
        self, killer: "Player", killee: "Player", weapon: int
    ) -> bool:
        """Send a death message only to the current player.

        :param Player killer: The player who killed.
        :param Player killee: The player who was killed.
        :param int weapon: The weapon that was used.
        :return: No return value.
        """
        return send_death_message_to_player(
            self.id, killer.id, killee.id, weapon
        )

    def game_text(self, text: str, time: int, style: int) -> bool:
        """Send a big text to the player visible on their screen.

        :param str text: The text to show.
        :param int time: The time it should be shown in ms.
        :param int style: The style of the text. (0, 1 or 5).
        :return: No value returned.

        .. warning::
            Do note that the players may crash because of odd number of tilde
            (~) symbols used in the game text. Using color codes (e.g. ~r~)
            beyond the 255th character may crash the client.

            Also, a blank space at end of the string may result in faliure.
            For example: "Headshot " results in failure. Instead it should be
            "Headshot" or "`Headshot_`".
        """
        return game_text_for_player(self.id, text, time, style)

    def is_npc(self) -> bool:
        """Check if the player is an NPC.

        :return: ``True`` if yes, otherwise ``False``.
        """
        return is_player_npc(self.id)

    def is_admin(self) -> bool:
        """Check if player is logged in to RCON.

        :return: ``True`` if they are, otherwise ``False``.
        """
        return is_player_admin(self.id)

    def kick(self) -> bool:
        """Kick the player from the server.

        :return: No value is returned.
        """
        return kick(self.id)

    def ban(self) -> bool:
        """Ban the player from the server.

        :return: No value is returned.

        This writes their IP to the server samp.ban file, and they will not be
        able to reconnect using the same IP.
        """
        return ban(self.id)

    def ban_ex(self, reason: str) -> bool:
        """Ban the player from the server with a given reason.

        :param str reason: The reason to write together with the ban.
        :return: No value is returned.

        The reason will be written as a comment together with the IP in the
        samp.ban file.
        """
        return ban_ex(self.id, reason)

    def gpci(self) -> str:
        """Get a hash that represents the installation directory of SA-MP for
        the client.

        This is linked to their SAMP/GTA path on their computer.

        .. warning:: This hash is NOT Unique, and can be same across multiple
            players.

        .. code-block:: python

            print(player.gpci())
        """
        return gpci(self.id)

    def attach_camera_to_player_object(
        self, player_object: "PlayerObject"
    ) -> bool:
        """Attach the player camera to a player object.

        :param PlayerObject player_object: The player object you want to
            attach to.
        :returns: No return value.
        """
        return attach_camera_to_player_object(self.id, player_object.id)

    @event("OnEnterExitModShop")
    def on_enter_exit_mod_shop(
        cls, playerid: int, enterexit: int, interiorid: int
    ):
        """Event that is called when a player enters or exits a mod shop.

        :param Player player: The player that entered or exited.
        :param int enterexit: 1 if entering, 0 if exiting.
        :param int interiorid: The ID of the interior.
        """
        return (cls(playerid), enterexit, interiorid)

    @event("OnPlayerConnect")
    def on_connect(cls, playerid: int):
        """Event that is called when a player connects to the server.

        :param Player player: The player that connected.
        """
        return (cls(playerid),)

    @event("OnPlayerDisconnect")
    def on_disconnect(cls, playerid: int, reason: int):
        """Event that is called when a player disconnects from the server.

        :param Player player: The player that disconnected.
        :param int reason: The reason of the disconnect.
            Reason is a number from 0 to 2.
        """
        return (cls(playerid), reason)

    @event("OnPlayerSpawn")
    def on_spawn(cls, playerid: int):
        """Event that is called when a player spawns.

        :param Player player: The player that spawned.
        """
        return (cls(playerid),)

    @event("OnPlayerDeath")
    def on_death(cls, playerid: int, killerid: int, reason: int):
        """Event that is called when a player dies.

        :param Player player: The player that died.
        :param Player killer: The killer is the player who killed the player.
            If the killer is not a player, it is set to INVALID_PLAYER_ID.
        :param int reason: The reason is the weapon that caused the player to
            die. See: https://www.open.mp/docs/scripting/resources/weaponids
            for the available weapons.
        """
        return (
            cls(playerid),
            killerid if killerid == INVALID_PLAYER_ID else cls(killerid),
            reason,
        )

    @event("OnPlayerText")
    def on_text(cls, playerid: int, text: str):
        """Event that is called when a player sends a message in the chat.

        :param Player player: The player that sent the message.
        :param str text: The text that was sent in chat.
        """
        return (cls(playerid), text)

    @event("OnPlayerCommandText")
    def on_command_text(cls, playerid: int, command_text: str):
        """Event that is called when a player sends a command text.

        For creating and using commands, it is recommended to take a look
        at the `pysamp.commands` module, instead of using this event.

        :param Player player: The player that sent the command.
        :param str command_text: The text that was sent in chat, including the
            forward slash.

        """
        return (cls(playerid), command_text)

    @event("OnPlayerRequestClass")
    def on_request_class(cls, playerid: int, classid: int):
        """Event that is called when a player requests a class.

        :param Player player: The player.
        :param int classid: The ID of the class.
        """
        return (cls(playerid), classid)

    @event("OnPlayerEnterVehicle")
    def on_enter_vehicle(
        cls,
        playerid: int,
        vehicleid: int,
        is_passenger: bool,
    ):
        """Event that is called when a player enters a vehicle by pressing
        ENTER / F.

        :param Player player: The player that entered.
        :param Vehicle vehicle: The vehicle that the player entered.
        :param bool is_passenger: Whether the player is a passenger or not.

        """
        return (cls(playerid), Vehicle(vehicleid), is_passenger)

    @event("OnPlayerExitVehicle")
    def on_exit_vehicle(cls, playerid: int, vehicleid: int):
        """Event that is called when a player exits a vehicle by pressing
        ENTER / F.

        :param Player player: The player that exited.
        :param Vehicle vehicle: The vehicle that the player exited.
        """
        return (cls(playerid), Vehicle(vehicleid))

    @event("OnPlayerStateChange")
    def on_state_change(cls, playerid, newstate: int, oldstate: int):
        """Event that is called when a player changes state. For example
        changing from spectator to onfoot, or dies.

        :param Player player: The player that changed state.
        :param int newstate: The new state of the player.
        :param int oldstate: The old state of the player.

        States can be found here:
        https://www.open.mp/docs/scripting/resources/playerstates
        """
        return (cls(playerid), newstate, oldstate)

    @event("OnPlayerEnterCheckpoint")
    def on_enter_checkpoint(cls, playerid: int):
        """Event that is called when a player enters a checkpoint.

        :param Player player: The player that entered the checkpoint.
        """
        return (cls(playerid),)

    @event("OnPlayerLeaveCheckpoint")
    def on_leave_checkpoint(cls, playerid: int):
        """Event that is called when a player leaves a checkpoint.

        :param Player player: The player that left the checkpoint.
        """
        return (cls(playerid),)

    @event("OnPlayerEnterRaceCheckpoint")
    def on_enter_race_checkpoint(cls, playerid: int):
        """Event that is called when a player enters a race checkpoint.

        :param Player player: The player that entered the checkpoint.
        """
        return (cls(playerid),)

    @event("OnPlayerLeaveRaceCheckpoint")
    def on_leave_race_checkpoint(cls, playerid: int):
        """Event that is called when a player leaves a race checkpoint.

        :param Player player: The player that left the checkpoint.
        """
        return (cls(playerid),)

    @event("OnPlayerRequestSpawn")
    def on_request_spawn(cls, playerid: int):
        """Event that is called when a player requests to spawn.

        :param Player player: The player that requested to spawn.
        """
        return (cls(playerid),)

    @event("OnPlayerPickUpPickup")
    def on_pick_up_pickup(cls, playerid, pickupid: int):
        """Event that is called when a player picks up a pickup.

        :param Player player: The player that picked up the pickup.
        :param Pickup pickup: The pickup that was picked up.
        """
        return (cls(playerid), Pickup(pickupid))

    @event("OnPlayerSelectedMenuRow")
    def on_selected_menu_row(cls, playerid: int, row: int):
        """Event that is called when a player selects a menu row.

        :param Player player: The player that selected the menu row.
        :param int row: The row that was selected.
        """
        return (cls(playerid), row)

    @event("OnPlayerExitedMenu")
    def on_exited_menu(cls, playerid: int):
        """Event that is called when a player exits a menu.

        :param Player player: The player that exited the menu.
        """
        return (cls(playerid),)

    @event("OnPlayerInteriorChange")
    def on_interior_change(
        cls,
        playerid: int,
        newinteriorid: int,
        oldinteriorid: int,
    ):
        """Event that is called when a player changes interior.

        :param Player player: The player that changed interior.
        :param int newinteriorid: The ID of the new interior.
        :param int oldinteriorid: The ID of the old interior.
        """
        return (cls(playerid), newinteriorid, oldinteriorid)

    @event("OnPlayerKeyStateChange")
    def on_key_state_change(cls, playerid: int, newkeys: int, oldkeys: int):
        """Event that is called when a player changes keys.

        :param Player player: The player that changed keys.
        :param int newkeys: The new keys of the player.
        :param int oldkeys: The old keys of the player.
        """
        return (cls(playerid), newkeys, oldkeys)

    @event("OnPlayerUpdate")
    def on_update(cls, playerid: int):
        """Event that is called when a player updates.

        :param Player player: The player that updated.
        """
        return (cls(playerid),)

    @event("OnPlayerStreamIn")
    def on_stream_in(cls, playerid: int, forplayerid: int):
        """Event that is called when a player streams in.

        :param Player player: The player that streamed in.
        :param Player forplayer: The player that streamed in.
        """
        return (cls(playerid), cls(forplayerid))

    @event("OnPlayerStreamOut")
    def on_stream_out(cls, playerid: int, forplayerid: int):
        """Event that is called when a player streams out.

        :param Player player: The player that streamed out.
        :param Player forplayer: The player that streamed out.
        """
        return (cls(playerid), cls(forplayerid))

    @event("OnPlayerTakeDamage")
    def on_take_damage(
        cls,
        playerid: int,
        issuerid: int,
        amount: float,
        weaponid: int,
        bodypart: int,
    ):
        """Event that is called when a player takes damage.

        :param Player player: The player that took damage.
        :param Player issuer: The player that caused the damage.
        :param float amount: The amount of damage that was taken.
        :param int weaponid: The ID of the weapon that was used.
        :param int bodypart: The body part that was damaged.
        """
        return (
            cls(playerid),
            issuerid if issuerid == INVALID_PLAYER_ID else cls(issuerid),
            amount,
            weaponid,
            bodypart,
        )

    @event("OnPlayerGiveDamage")
    def on_give_damage(
        cls,
        playerid: int,
        damagedid: int,
        amount: float,
        weaponid: int,
        bodypart: int,
    ):
        """Event that is called when a player gives damage to another player.

        :param Player player: The player that gave damage.
        :param Player damaged: The player that was damaged.
        :param float amount: The amount of damage that was given.
        :param int weaponid: The ID of the weapon that was used.
        :param int bodypart: The body part that was damaged.
        """
        return (
            cls(playerid),
            damagedid if damagedid == INVALID_PLAYER_ID else cls(damagedid),
            amount,
            weaponid,
            bodypart,
        )

    @event("OnPlayerGiveDamageActor")
    def on_give_damage_actor(
        cls,
        playerid: int,
        damaged_actorid: int,
        amount: float,
        weaponid: int,
        bodypart: int,
    ):
        """Event that is called when a player gives damage to an actor.

        :param Player player: The player that gave damage.
        :param Actor damaged: The actor that was damaged.
        :param float amount: The amount of damage that was given.
        :param int weaponid: The ID of the weapon that was used.
        :param int bodypart: The body part that was damaged.
        """
        return (
            cls(playerid),
            Actor(damaged_actorid),
            amount,
            weaponid,
            bodypart,
        )

    @event("OnPlayerClickMap")
    def on_click_map(cls, playerid: int, x: float, y: float, z: float):
        """Event that is called when a player clicks on the map.

        :param Player player: The player that clicked on the map.
        :param float x: The X coordinate of the click.
        :param float y: The Y coordinate of the click.
        :param float z: The Z coordinate of the click.
        """
        return (cls(playerid), x, y, z)

    @event("OnPlayerClickTextDraw")
    def on_click_textdraw(cls, playerid: int, clickedid: int):
        """Event that is called when a player clicks on a textdraw.

        :param Player player: The player that clicked on the textdraw.
        :param TextDraw textdraw: The textdraw that was clicked on.
        """
        return (cls(playerid), TextDraw(clickedid))

    @event("OnPlayerClickPlayerTextDraw")
    def on_click_playertextdraw(cls, playerid: int, playertextid: int):
        """Event that is called when a player clicks on a player textdraw.

        :param Player player: The player that clicked on the textdraw.
        :param TextDraw textdraw: The textdraw that was clicked on.
        """
        return (cls(playerid), PlayerTextDraw(playertextid, cls(playerid)))

    @event("OnPlayerClickPlayer")
    def on_click_player(cls, playerid: int, clickedplayerid: int, source: int):
        """Event that is called when a player clicks on another player.

        :param Player player: The player that clicked on the player.
        :param Player clickedplayer: The player that was clicked on.
        :param int source: The source of the click.
        """
        return (cls(playerid), cls(clickedplayerid), source)

    @event("OnPlayerEditObject")
    def on_edit_object(
        cls,
        playerid: int,
        is_playerobject: bool,
        objectid: int,
        response: int,
        x: float,
        y: float,
        z: float,
        rot_x: float,
        rot_y: float,
        rot_z: float,
    ):
        """Event that is called when a player edits an object.

        :param Player player: The player that edited the object.
        :param Object object: The object that was edited.
        :param int response: The response of the edit.
        :param float x: The X coordinate of the edit.
        :param float y: The Y coordinate of the edit.
        :param float z: The Z coordinate of the edit.
        :param float rot_x: The X rotation of the edit.
        :param float rot_y: The Y rotation of the edit.
        :param float rot_z: The Z rotation of the edit.
        """
        return (
            cls(playerid),
            PlayerObject(objectid) if is_playerobject else Object(objectid),
            response,
            x,
            y,
            z,
            rot_x,
            rot_y,
            rot_z,
        )

    @event("OnPlayerEditAttachedObject")
    def on_edit_attached_object(
        cls,
        playerid: int,
        response: int,
        index: int,
        modelid: int,
        boneid: int,
        offset_x: float,
        offset_y: float,
        offset_z: float,
        rot_x: float,
        rot_y: float,
        rot_z: float,
        scale_x: float,
        scale_y: float,
        scale_z: float,
    ):
        """Event that is called when a player edits an attached object.

        :param Player player: The player that edited the object.
        :param int response: The response of the edit.
        :param int index: The index (slot) to assign the object to (0-9).
        :param int modelid: The model to attach.
        :param int boneid: The bone to attach the object to. (0-18)
        :param float offset_x: X axis offset for the object position.
        :param float offset_y: Y axis offset for the object position.
        :param float offset_z: Z axis offset for the object position.
        :param float rot_x: X axis rotation of the object.
        :param float rot_y: Y axis rotation of the object.
        :param float rot_z: Z axis rotation of the object.
        :param float scale_x: X axis scale of the object.
        :param float scale_y: Y axis scale of the object.
        :param float scale_z: Z axis scale of the object.
        """
        return (
            cls(playerid),
            response,
            index,
            modelid,
            boneid,
            offset_x,
            offset_y,
            offset_z,
            rot_x,
            rot_y,
            rot_z,
            scale_x,
            scale_y,
            scale_z,
        )

    @event("OnPlayerSelectObject")
    def on_select_object(
        cls,
        playerid: int,
        type: int,
        objectid: int,
        modelid: int,
        x: float,
        y: float,
        z: float,
    ):
        """Event that is called when a player selects an object.

        :param Player player: The player that selected the object.
        :param Object object: The object that was selected.
        :param int modelid: The model of the object.
        :param float x: The X coordinate of the object.
        :param float y: The Y coordinate of the object.
        :param float z: The Z coordinate of the object.
        """
        object_cls = {
            SELECT_OBJECT_GLOBAL_OBJECT: Object,
            SELECT_OBJECT_PLAYER_OBJECT: PlayerObject,
        }
        return (
            cls(playerid),
            object_cls[type](objectid),
            modelid,
            x,
            y,
            z,
        )

    @event("OnPlayerWeaponShot")
    def on_weapon_shot(
        cls,
        playerid: int,
        weaponid: int,
        hittype: int,
        hitid: int,
        x: float,
        y: float,
        z: float,
    ):
        """Event that is called when a player fires a weapon.

        Depending on the hittype, the hitid will be different.
        You will need to check the hit_cls for the type of hit.

        :param Player player: The player that fired the weapon.
        :param int weaponid: The id of the weapon that was fired.
        :param (Vehicle|Object|PlayerObject|None) hit: The object that was hit.
        :param int hitid: The id of the hit.
        :param float x: The X coordinate of the hit.
        :param float y: The Y coordinate of the hit.
        :param float z: The Z coordinate of the hit.
        """
        hit_cls = {
            BULLET_HIT_TYPE_NONE: lambda _: None,
            BULLET_HIT_TYPE_PLAYER: cls,
            BULLET_HIT_TYPE_VEHICLE: Vehicle,
            BULLET_HIT_TYPE_OBJECT: Object,
            BULLET_HIT_TYPE_PLAYER_OBJECT: PlayerObject,
        }
        return (
            cls(playerid),
            weaponid,
            hit_cls[hittype](hitid),
            x,
            y,
            z,
        )

    @classmethod
    def command(cls, function=_NO_FUNCTION, **kwargs):
        """Decorate a command handler to register it with the given options.

        :param function: The command handler to register.
            Useful when there is no need for other arguments, one can use the
            bare decorator without calling it.
        """
        if function is _NO_FUNCTION:
            return functools.partial(cls.command, **kwargs)

        @functools.wraps(function)
        def handler(playerid, *args):
            return function(cls(playerid), *args)

        return cmd(handler, **kwargs)


from .actor import Actor  # noqa
from .object import Object  # noqa
from .pickup import Pickup  # noqa
from .playerobject import PlayerObject  # noqa
from .playertextdraw import PlayerTextDraw  # noqa
from .textdraw import TextDraw  # noqa
from .vehicle import Vehicle  # noqa
