"""Snake case wrappers for PEP8 compatibility."""

# Disable warnings for missing docstrings in modukle:
# pylint: disable=C0114

import functools
from typing import Callable, Tuple

from pysamp.event import registry
from samp import (
    CAMERA_CUT,
    INVALID_PLAYER_ID,
    INVALID_VEHICLE_ID,
    MAPICON_LOCAL,
    SPECTATE_MODE_NORMAL,
    AddMenuItem,
    AddPlayerClass,
    AddPlayerClassEx,
    AddStaticPickup,
    AddStaticVehicle,
    AddStaticVehicleEx,
    AddVehicleComponent,
    AllowAdminTeleport,
    AllowInteriorWeapons,
    AllowPlayerTeleport,
    ApplyActorAnimation,
    ApplyAnimation,
    Attach3DTextLabelToPlayer,
    Attach3DTextLabelToVehicle,
    AttachCameraToObject,
    AttachCameraToPlayerObject,
    AttachObjectToObject,
    AttachObjectToPlayer,
    AttachObjectToVehicle,
    AttachPlayerObjectToPlayer,
    AttachPlayerObjectToVehicle,
    AttachTrailerToVehicle,
    Ban,
    BanEx,
    BlockIpAddress,
    CallNativeFunction,
    CallRemoteFunction,
    CancelEdit,
    CancelSelectTextDraw,
    ChangeVehicleColor,
    ChangeVehiclePaintjob,
    ClearActorAnimations,
    ClearAnimations,
    ConnectNPC,
    Create3DTextLabel,
    CreateActor,
    CreateExplosion,
    CreateExplosionForPlayer,
    CreateMenu,
    CreateObject,
    CreatePickup,
    CreatePlayer3DTextLabel,
    CreatePlayerObject,
    CreatePlayerTextDraw,
    CreateVehicle,
    Delete3DTextLabel,
    DeletePlayer3DTextLabel,
    DeletePVar,
    DeleteSVar,
    DestroyActor,
    DestroyMenu,
    DestroyObject,
    DestroyPickup,
    DestroyPlayerObject,
    DestroyVehicle,
    DetachTrailerFromVehicle,
    DisableInteriorEnterExits,
    DisableMenu,
    DisableMenuRow,
    DisableNameTagLOS,
    DisablePlayerCheckpoint,
    DisablePlayerRaceCheckpoint,
    DisableRemoteVehicleCollisions,
    EditAttachedObject,
    EditObject,
    EditPlayerObject,
    EnablePlayerCameraTarget,
    EnableStuntBonusForAll,
    EnableStuntBonusForPlayer,
    EnableTirePopping,
    EnableVehicleFriendlyFire,
    EnableZoneNames,
    ForceClassSelection,
    GameModeExit,
    GameTextForAll,
    GameTextForPlayer,
    GangZoneCreate,
    GangZoneDestroy,
    GangZoneFlashForAll,
    GangZoneFlashForPlayer,
    GangZoneHideForAll,
    GangZoneHideForPlayer,
    GangZoneShowForAll,
    GangZoneShowForPlayer,
    GangZoneStopFlashForAll,
    GangZoneStopFlashForPlayer,
    GetActorFacingAngle,
    GetActorHealth,
    GetActorPoolSize,
    GetActorPos,
    GetActorVirtualWorld,
    GetAnimationName,
    GetConsoleVarAsBool,
    GetConsoleVarAsInt,
    GetConsoleVarAsString,
    GetGravity,
    GetMaxPlayers,
    GetNetworkStats,
    GetObjectModel,
    GetObjectPos,
    GetObjectRot,
    GetPlayerAmmo,
    GetPlayerAnimationIndex,
    GetPlayerArmour,
    GetPlayerCameraAspectRatio,
    GetPlayerCameraFrontVector,
    GetPlayerCameraMode,
    GetPlayerCameraPos,
    GetPlayerCameraTargetActor,
    GetPlayerCameraTargetObject,
    GetPlayerCameraTargetPlayer,
    GetPlayerCameraTargetVehicle,
    GetPlayerCameraZoom,
    GetPlayerColor,
    GetPlayerDistanceFromPoint,
    GetPlayerDrunkLevel,
    GetPlayerFacingAngle,
    GetPlayerFightingStyle,
    GetPlayerHealth,
    GetPlayerInterior,
    GetPlayerIp,
    GetPlayerKeys,
    GetPlayerLastShotVectors,
    GetPlayerMenu,
    GetPlayerMoney,
    GetPlayerName,
    GetPlayerNetworkStats,
    GetPlayerObjectModel,
    GetPlayerObjectPos,
    GetPlayerObjectRot,
    GetPlayerPing,
    GetPlayerPoolSize,
    GetPlayerPos,
    GetPlayerScore,
    GetPlayerSkin,
    GetPlayerSpecialAction,
    GetPlayerState,
    GetPlayerSurfingObjectID,
    GetPlayerSurfingVehicleID,
    GetPlayerTargetActor,
    GetPlayerTargetPlayer,
    GetPlayerTeam,
    GetPlayerTime,
    GetPlayerVehicleID,
    GetPlayerVehicleSeat,
    GetPlayerVelocity,
    GetPlayerVersion,
    GetPlayerVirtualWorld,
    GetPlayerWantedLevel,
    GetPlayerWeapon,
    GetPlayerWeaponData,
    GetPlayerWeaponState,
    GetPVarFloat,
    GetPVarInt,
    GetPVarNameAtIndex,
    GetPVarString,
    GetPVarsUpperIndex,
    GetPVarType,
    GetServerTickRate,
    GetServerVarAsBool,
    GetServerVarAsInt,
    GetServerVarAsString,
    GetSVarFloat,
    GetSVarInt,
    GetSVarNameAtIndex,
    GetSVarString,
    GetSVarsUpperIndex,
    GetSVarType,
    GetTickCount,
    GetVehicleComponentInSlot,
    GetVehicleComponentType,
    GetVehicleDamageStatus,
    GetVehicleDistanceFromPoint,
    GetVehicleHealth,
    GetVehicleModel,
    GetVehicleModelInfo,
    GetVehicleParamsCarDoors,
    GetVehicleParamsCarWindows,
    GetVehicleParamsEx,
    GetVehicleParamsSirenState,
    GetVehiclePoolSize,
    GetVehiclePos,
    GetVehicleRotationQuat,
    GetVehicleTrailer,
    GetVehicleVelocity,
    GetVehicleVirtualWorld,
    GetVehicleZAngle,
    GetWeaponName,
    GivePlayerMoney,
    GivePlayerWeapon,
    HideMenuForPlayer,
    InterpolateCameraLookAt,
    InterpolateCameraPos,
    IsActorInvulnerable,
    IsActorStreamedIn,
    IsObjectMoving,
    IsPlayerAdmin,
    IsPlayerAttachedObjectSlotUsed,
    IsPlayerConnected,
    IsPlayerInAnyVehicle,
    IsPlayerInCheckpoint,
    IsPlayerInRaceCheckpoint,
    IsPlayerInRangeOfPoint,
    IsPlayerInVehicle,
    IsPlayerNPC,
    IsPlayerObjectMoving,
    IsPlayerStreamedIn,
    IsTrailerAttachedToVehicle,
    IsValidActor,
    IsValidMenu,
    IsValidObject,
    IsValidPlayerObject,
    IsValidVehicle,
    IsVehicleStreamedIn,
    Kick,
    KillTimer,
    LimitGlobalChatRadius,
    LimitPlayerMarkerRadius,
    LinkVehicleToInterior,
    ManualVehicleEngineAndLights,
    MoveObject,
    MovePlayerObject,
    NetStats_BytesReceived,
    NetStats_BytesSent,
    NetStats_ConnectionStatus,
    NetStats_GetConnectedTime,
    NetStats_GetIpPort,
    NetStats_MessagesReceived,
    NetStats_MessagesRecvPerSecond,
    NetStats_MessagesSent,
    NetStats_PacketLossPercent,
    OBJECT_MATERIAL_SIZE_256x128,
    PlayAudioStreamForPlayer,
    PlayCrimeReportForPlayer,
    PlayerPlaySound,
    PlayerSpectatePlayer,
    PlayerSpectateVehicle,
    PlayerTextDrawAlignment,
    PlayerTextDrawBackgroundColor,
    PlayerTextDrawBoxColor,
    PlayerTextDrawColor,
    PlayerTextDrawDestroy,
    PlayerTextDrawFont,
    PlayerTextDrawHide,
    PlayerTextDrawLetterSize,
    PlayerTextDrawSetOutline,
    PlayerTextDrawSetPreviewModel,
    PlayerTextDrawSetPreviewRot,
    PlayerTextDrawSetPreviewVehCol,
    PlayerTextDrawSetProportional,
    PlayerTextDrawSetSelectable,
    PlayerTextDrawSetShadow,
    PlayerTextDrawSetString,
    PlayerTextDrawShow,
    PlayerTextDrawTextSize,
    PlayerTextDrawUseBox,
    PutPlayerInVehicle,
    RegisterCallback,
    RemoveBuildingForPlayer,
    RemovePlayerAttachedObject,
    RemovePlayerFromVehicle,
    RemovePlayerMapIcon,
    RemoveVehicleComponent,
    RepairVehicle,
    ResetPlayerMoney,
    ResetPlayerWeapons,
    SelectObject,
    SelectTextDraw,
    SendClientMessage,
    SendClientMessageToAll,
    SendDeathMessage,
    SendDeathMessageToPlayer,
    SendPlayerMessageToAll,
    SendPlayerMessageToPlayer,
    SendRconCommand,
    SetActorFacingAngle,
    SetActorHealth,
    SetActorInvulnerable,
    SetActorPos,
    SetActorVirtualWorld,
    SetCameraBehindPlayer,
    SetDeathDropAmount,
    SetGameModeText,
    SetGravity,
    SetMenuColumnHeader,
    SetNameTagDrawDistance,
    SetObjectMaterial,
    SetObjectMaterialText,
    SetObjectNoCameraCol,
    SetObjectPos,
    SetObjectRot,
    SetObjectsDefaultCameraCol,
    SetPlayerAmmo,
    SetPlayerArmedWeapon,
    SetPlayerArmour,
    SetPlayerAttachedObject,
    SetPlayerCameraLookAt,
    SetPlayerCameraPos,
    SetPlayerChatBubble,
    SetPlayerCheckpoint,
    SetPlayerColor,
    SetPlayerDrunkLevel,
    SetPlayerFacingAngle,
    SetPlayerFightingStyle,
    SetPlayerHealth,
    SetPlayerInterior,
    SetPlayerMapIcon,
    SetPlayerMarkerForPlayer,
    SetPlayerName,
    SetPlayerObjectMaterial,
    SetPlayerObjectMaterialText,
    SetPlayerObjectNoCameraCol,
    SetPlayerObjectPos,
    SetPlayerObjectRot,
    SetPlayerPos,
    SetPlayerPosFindZ,
    SetPlayerRaceCheckpoint,
    SetPlayerScore,
    SetPlayerShopName,
    SetPlayerSkillLevel,
    SetPlayerSkin,
    SetPlayerSpecialAction,
    SetPlayerTeam,
    SetPlayerTime,
    SetPlayerVelocity,
    SetPlayerVirtualWorld,
    SetPlayerWantedLevel,
    SetPlayerWeather,
    SetPlayerWorldBounds,
    SetPVarFloat,
    SetPVarInt,
    SetPVarString,
    SetSpawnInfo,
    SetSVarFloat,
    SetSVarInt,
    SetSVarString,
    SetTeamCount,
    SetTimer,
    SetVehicleAngularVelocity,
    SetVehicleHealth,
    SetVehicleNumberPlate,
    SetVehicleParamsCarDoors,
    SetVehicleParamsCarWindows,
    SetVehicleParamsEx,
    SetVehicleParamsForPlayer,
    SetVehiclePos,
    SetVehicleToRespawn,
    SetVehicleVelocity,
    SetVehicleVirtualWorld,
    SetVehicleZAngle,
    SetWeather,
    SetWorldTime,
    ShowMenuForPlayer,
    ShowNameTags,
    ShowPlayerDialog,
    ShowPlayerMarkers,
    ShowPlayerNameTagForPlayer,
    SpawnPlayer,
    StartRecordingPlayerData,
    StopAudioStreamForPlayer,
    StopObject,
    StopPlayerObject,
    StopRecordingPlayerData,
    TextDrawAlignment,
    TextDrawBackgroundColor,
    TextDrawBoxColor,
    TextDrawColor,
    TextDrawCreate,
    TextDrawDestroy,
    TextDrawFont,
    TextDrawHideForAll,
    TextDrawHideForPlayer,
    TextDrawLetterSize,
    TextDrawSetOutline,
    TextDrawSetPreviewModel,
    TextDrawSetPreviewRot,
    TextDrawSetPreviewVehCol,
    TextDrawSetProportional,
    TextDrawSetSelectable,
    TextDrawSetShadow,
    TextDrawSetString,
    TextDrawShowForAll,
    TextDrawShowForPlayer,
    TextDrawTextSize,
    TextDrawUseBox,
    TogglePlayerClock,
    TogglePlayerControllable,
    TogglePlayerSpectating,
    UnBlockIpAddress,
    Update3DTextLabelText,
    UpdatePlayer3DTextLabelText,
    UpdateVehicleDamageStatus,
    UsePlayerPedAnims,
    VectorSize,
)
from samp import gpci as _gpci

from .callbacks import _path_hook  # noqa


def set_spawn_info(
    player_id: int,
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
    return SetSpawnInfo(
        player_id,
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


def spawn_player(player_id: int) -> bool:
    return SpawnPlayer(player_id)


def set_player_pos(player_id: int, x: float, y: float, z: float) -> bool:
    return SetPlayerPos(player_id, x, y, z)


def set_player_pos_find_z(
    player_id: int, x: float, y: float, z: float
) -> bool:
    return SetPlayerPosFindZ(player_id, x, y, z)


def get_player_pos(player_id: int) -> Tuple[float, float, float]:
    return GetPlayerPos(player_id)


def set_player_facing_angle(player_id: int, angle: float) -> bool:
    return SetPlayerFacingAngle(player_id, angle)


def get_player_facing_angle(player_id: int) -> float:
    return GetPlayerFacingAngle(player_id)


def is_player_in_range_of_point(
    player_id: int, range: float, x: float, y: float, z: float
) -> bool:
    return IsPlayerInRangeOfPoint(player_id, range, x, y, z)


def get_player_distance_from_point(
    player_id: int, x: float, y: float, z: float
) -> float:
    return GetPlayerDistanceFromPoint(player_id, x, y, z)


def is_player_streamed_in(player_id: int, for_player_id: int) -> bool:
    return IsPlayerStreamedIn(player_id, for_player_id)


def set_player_interior(player_id: int, interior_id: int) -> bool:
    return SetPlayerInterior(player_id, interior_id)


def get_player_interior(player_id: int) -> int:
    return GetPlayerInterior(player_id)


def set_player_health(player_id: int, health: float) -> bool:
    return SetPlayerHealth(player_id, health)


def get_player_health(player_id: int) -> float:
    return GetPlayerHealth(player_id)


def set_player_armour(player_id: int, armour: float) -> bool:
    return SetPlayerArmour(player_id, armour)


def get_player_armour(player_id: int) -> float:
    return GetPlayerArmour(player_id)


def set_player_ammo(player_id: int, weapon_id: int, ammo: int) -> bool:
    return SetPlayerAmmo(player_id, weapon_id, ammo)


def get_player_ammo(player_id: int) -> int:
    return GetPlayerAmmo(player_id)


def get_player_weapon_state(player_id: int) -> int:
    return GetPlayerWeaponState(player_id)


def get_player_target_player(player_id: int) -> int:
    return GetPlayerTargetPlayer(player_id)


def get_player_target_actor(player_id: int) -> int:
    return GetPlayerTargetActor(player_id)


def set_player_team(player_id: int, team_id: int) -> bool:
    return SetPlayerTeam(player_id, team_id)


def get_player_team(player_id: int) -> int:
    return GetPlayerTeam(player_id)


def set_player_score(player_id: int, score: int) -> bool:
    return SetPlayerScore(player_id, score)


def get_player_score(player_id: int) -> int:
    return GetPlayerScore(player_id)


def get_player_drunk_level(player_id: int) -> int:
    return GetPlayerDrunkLevel(player_id)


def set_player_drunk_level(player_id: int, level: int) -> bool:
    return SetPlayerDrunkLevel(player_id, level)


def set_player_color(player_id: int, color: int) -> bool:
    return SetPlayerColor(player_id, color)


def get_player_color(player_id: int) -> int:
    return GetPlayerColor(player_id)


def set_player_skin(player_id: int, skin_id: int) -> bool:
    return SetPlayerSkin(player_id, skin_id)


def get_player_skin(player_id: int) -> int:
    return GetPlayerSkin(player_id)


def give_player_weapon(player_id: int, weapon_id: int, ammo: int) -> bool:
    return GivePlayerWeapon(player_id, weapon_id, ammo)


def reset_player_weapons(player_id: int) -> bool:
    return ResetPlayerWeapons(player_id)


def set_player_armed_weapon(player_id: int, weapon_id: int) -> bool:
    return SetPlayerArmedWeapon(player_id, weapon_id)


def get_player_weapon_data(player_id: int, slot: int) -> Tuple[int, int]:
    return GetPlayerWeaponData(player_id, slot)


def give_player_money(player_id: int, money: int) -> bool:
    return GivePlayerMoney(player_id, money)


def reset_player_money(player_id: int) -> bool:
    return ResetPlayerMoney(player_id)


def set_player_name(player_id: int, name: str) -> int:
    return SetPlayerName(player_id, name)


def get_player_money(player_id: int) -> int:
    return GetPlayerMoney(player_id)


def get_player_state(player_id: int) -> int:
    return GetPlayerState(player_id)


def get_player_ip(player_id: int) -> str:
    return GetPlayerIp(player_id)


def get_player_ping(player_id: int) -> int:
    return GetPlayerPing(player_id)


def get_player_weapon(player_id: int) -> int:
    return GetPlayerWeapon(player_id)


def get_player_keys(player_id: int) -> Tuple[int, int, int]:
    return GetPlayerKeys(player_id)


def get_player_name(player_id: int) -> str:
    return GetPlayerName(player_id)


def set_player_time(player_id: int, hour: int, minute: int) -> bool:
    return SetPlayerTime(player_id, hour, minute)


def get_player_time(player_id: int) -> Tuple[int, int]:
    return GetPlayerTime(player_id)


def toggle_player_clock(player_id: int, toggle: bool) -> bool:
    return TogglePlayerClock(player_id, toggle)


def set_player_weather(player_id: int, weather: int) -> bool:
    return SetPlayerWeather(player_id, weather)


def force_class_selection(player_id: int) -> bool:
    return ForceClassSelection(player_id)


def set_player_wanted_level(player_id: int, level: int) -> bool:
    return SetPlayerWantedLevel(player_id, level)


def get_player_wanted_level(player_id: int) -> int:
    return GetPlayerWantedLevel(player_id)


def set_player_fighting_style(player_id: int, style: int) -> bool:
    return SetPlayerFightingStyle(player_id, style)


def get_player_fighting_style(player_id: int) -> int:
    return GetPlayerFightingStyle(player_id)


def set_player_velocity(player_id: int, x: float, y: float, z: float) -> bool:
    return SetPlayerVelocity(player_id, x, y, z)


def get_player_velocity(player_id: int) -> Tuple[float, float, float]:
    return GetPlayerVelocity(player_id)


def play_crime_report_for_player(
    player_id: int, suspect_id: int, crime: int
) -> bool:
    return PlayCrimeReportForPlayer(player_id, suspect_id, crime)


def play_audio_stream_for_player(
    player_id: int,
    url: str,
    x: float = 0.0,
    y: float = 0.0,
    z: float = 0.0,
    distance: float = 50.0,
    use_pos: bool = False,
) -> bool:
    return PlayAudioStreamForPlayer(player_id, url, x, y, z, distance, use_pos)


def stop_audio_stream_for_player(player_id: int) -> bool:
    return StopAudioStreamForPlayer(player_id)


def set_player_shop_name(player_id: int, shop_name: str) -> bool:
    return SetPlayerShopName(player_id, shop_name)


def set_player_skill_level(player_id: int, skill: int, level: int) -> bool:
    return SetPlayerSkillLevel(player_id, skill, level)


def get_player_surfing_vehicle_id(player_id: int) -> int:
    return GetPlayerSurfingVehicleID(player_id)


def get_player_surfing_object_id(player_id: int) -> int:
    return GetPlayerSurfingObjectID(player_id)


def remove_building_for_player(
    player_id: int, model_id: int, x: float, y: float, z: float, radius: float
) -> bool:
    return RemoveBuildingForPlayer(player_id, model_id, x, y, z, radius)


def get_player_last_shot_vectors(
    player_id: int,
) -> Tuple[float, float, float, float, float, float]:
    """This function returns two coordinates in a tuple.
    The first three values are the coordinate where the shot was shot from.
    The last three values are where the bullet hit (if it hit something).

    -> NB: This function only works when lag compensation is enabled.
    The last three values may also be 0, that if the bullet did not hit
    anything in range of the weapon.
    """
    return GetPlayerLastShotVectors(player_id)


def set_player_attached_object(
    player_id: int,
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
    return SetPlayerAttachedObject(
        player_id,
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


def remove_player_attached_object(player_id: int, index: int) -> bool:
    return RemovePlayerAttachedObject(player_id, index)


def is_player_attached_object_slot_used(player_id: int, index: int) -> bool:
    return IsPlayerAttachedObjectSlotUsed(player_id, index)


def edit_attached_object(player_id: int, index: int) -> bool:
    return EditAttachedObject(player_id, index)


def create_player_text_draw(
    player_id: int, x: float, y: float, text: str
) -> int:
    return CreatePlayerTextDraw(player_id, x, y, text)


def player_text_draw_destroy(player_id: int, textdraw_id: int) -> bool:
    return PlayerTextDrawDestroy(player_id, textdraw_id)


def player_text_draw_letter_size(
    player_id: int, textdraw_id: int, x: float, y: float
) -> bool:
    return PlayerTextDrawLetterSize(player_id, textdraw_id, x, y)


def player_text_draw_text_size(
    player_id: int, textdraw_id: int, x: float, y: float
) -> bool:
    return PlayerTextDrawTextSize(player_id, textdraw_id, x, y)


def player_text_draw_alignment(
    player_id: int, textdraw_id: int, alignment: int
) -> bool:
    return PlayerTextDrawAlignment(player_id, textdraw_id, alignment)


def player_text_draw_color(
    player_id: int, textdraw_id: int, color: int
) -> bool:
    return PlayerTextDrawColor(player_id, textdraw_id, color)


def player_text_draw_use_box(
    player_id: int, textdraw_id: int, use: bool
) -> bool:
    return PlayerTextDrawUseBox(player_id, textdraw_id, use)


def player_text_draw_box_color(
    player_id: int, textdraw_id: int, color: int
) -> bool:
    return PlayerTextDrawBoxColor(player_id, textdraw_id, color)


def player_text_draw_set_shadow(
    player_id: int, textdraw_id: int, size: int
) -> bool:
    return PlayerTextDrawSetShadow(player_id, textdraw_id, size)


def player_text_draw_set_outline(
    player_id: int, textdraw_id: int, size: int
) -> bool:
    return PlayerTextDrawSetOutline(player_id, textdraw_id, size)


def player_text_draw_background_color(
    player_id: int, textdraw_id: int, color: int
) -> bool:
    return PlayerTextDrawBackgroundColor(player_id, textdraw_id, color)


def player_text_draw_font(player_id: int, textdraw_id: int, font: int) -> bool:
    return PlayerTextDrawFont(player_id, textdraw_id, font)


def player_text_draw_set_proportional(
    player_id: int, textdraw_id: int, set: bool
) -> bool:
    return PlayerTextDrawSetProportional(player_id, textdraw_id, set)


def player_text_draw_set_selectable(
    player_id: int, textdraw_id: int, set: bool
) -> bool:
    return PlayerTextDrawSetSelectable(player_id, textdraw_id, set)


def player_text_draw_show(player_id: int, textdraw_id: int) -> bool:
    return PlayerTextDrawShow(player_id, textdraw_id)


def player_text_draw_hide(player_id: int, textdraw_id: int) -> bool:
    return PlayerTextDrawHide(player_id, textdraw_id)


def player_text_draw_set_string(
    player_id: int, textdraw_id: int, string: str
) -> bool:
    return PlayerTextDrawSetString(player_id, textdraw_id, string)


def player_text_draw_set_preview_model(
    player_id: int, textdraw_id: int, modelindex: int
) -> bool:
    return PlayerTextDrawSetPreviewModel(player_id, textdraw_id, modelindex)


def player_text_draw_set_preview_rot(
    player_id: int,
    textdraw_id: int,
    rotation_x: float,
    rotation_y: float,
    rotation_z: float,
    zoom: float = 1.0,
) -> bool:
    return PlayerTextDrawSetPreviewRot(
        player_id, textdraw_id, rotation_x, rotation_y, rotation_z, zoom
    )


def player_text_draw_set_preview_veh_col(
    player_id: int, textdraw_id: int, color1: int, color2: int
) -> bool:
    return PlayerTextDrawSetPreviewVehCol(
        player_id, textdraw_id, color1, color2
    )


def set_pvar_int(player_id: int, var_name: str, value: int) -> bool:
    return SetPVarInt(player_id, var_name, value)


def get_pvar_int(player_id: int, var_name: str) -> int:
    return GetPVarInt(player_id, var_name)


def set_pvar_string(player_id: int, var_name: str, value: str) -> bool:
    return SetPVarString(player_id, var_name, value)


def get_pvar_string(player_id: int, var_name: str) -> str:
    return GetPVarString(player_id, var_name)


def set_pvar_float(player_id: int, var_name: str, value: float) -> bool:
    return SetPVarFloat(player_id, var_name, value)


def get_pvar_float(player_id: int, var_name: str) -> float:
    return GetPVarFloat(player_id, var_name)


def delete_pvar(player_id: int, var_name: str) -> bool:
    return DeletePVar(player_id, var_name)


def get_pvars_upper_index(player_id: int) -> int:
    return GetPVarsUpperIndex(player_id)


def get_pvar_name_at_index(player_id: int, index: int) -> str:
    return GetPVarNameAtIndex(player_id, index)


def get_pvar_type(player_id: int, var_name: str) -> int:
    return GetPVarType(player_id, var_name)


def set_player_chat_bubble(
    player_id: int, text: str, color: int, drawdistance: float, expiretime: int
) -> bool:
    return SetPlayerChatBubble(
        player_id, text, color, drawdistance, expiretime
    )


def put_player_in_vehicle(
    player_id: int, vehicle_id: int, seat_id: int
) -> bool:
    return PutPlayerInVehicle(player_id, vehicle_id, seat_id)


def get_player_vehicle_id(player_id: int) -> int:
    return GetPlayerVehicleID(player_id)


def get_player_vehicle_seat(player_id: int) -> int:
    return GetPlayerVehicleSeat(player_id)


def remove_player_from_vehicle(player_id: int) -> bool:
    return RemovePlayerFromVehicle(player_id)


def toggle_player_controllable(player_id: int, toggle: bool) -> bool:
    return TogglePlayerControllable(player_id, toggle)


def player_play_sound(
    player_id: int, sound_id: int, x: float, y: float, z: float
) -> bool:
    return PlayerPlaySound(player_id, sound_id, x, y, z)


def apply_animation(
    player_id: int,
    anim_lib: str,
    anim_name: str,
    delta: float,
    loop: bool,
    lock_x: bool,
    lock_y: bool,
    freeze: bool,
    time: int,
    forcesync: bool = False,
) -> bool:
    return ApplyAnimation(
        player_id,
        anim_lib,
        anim_name,
        delta,
        loop,
        lock_x,
        lock_y,
        freeze,
        time,
        forcesync,
    )


def clear_animations(player_id: int, force_sync: bool = False) -> bool:
    return ClearAnimations(player_id, force_sync)


def get_player_animation_index(player_id: int) -> int:
    return GetPlayerAnimationIndex(player_id)


def get_animation_name(index: int) -> str:
    return GetAnimationName(index)


def get_player_special_action(player_id: int) -> int:
    return GetPlayerSpecialAction(player_id)


def set_player_special_action(player_id: int, action_id: int) -> bool:
    return SetPlayerSpecialAction(player_id, action_id)


def disable_remote_vehicle_collisions(player_id: int, disable: bool) -> bool:
    return DisableRemoteVehicleCollisions(player_id, disable)


def set_player_checkpoint(
    player_id: int, x: float, y: float, z: float, size: float
) -> bool:
    return SetPlayerCheckpoint(player_id, x, y, z, size)


def disable_player_checkpoint(player_id: int) -> bool:
    return DisablePlayerCheckpoint(player_id)


def set_player_race_checkpoint(
    player_id: int,
    type: int,
    x: float,
    y: float,
    z: float,
    next_x: float,
    next_y: float,
    next_z: float,
    size: float,
) -> bool:
    return SetPlayerRaceCheckpoint(
        player_id, type, x, y, z, next_x, next_y, next_z, size
    )


def disable_player_race_checkpoint(player_id: int) -> bool:
    return DisablePlayerRaceCheckpoint(player_id)


def set_player_world_bounds(
    player_id: int, x_max: float, x_min: float, y_max: float, y_min: float
) -> bool:
    return SetPlayerWorldBounds(player_id, x_max, x_min, y_max, y_min)


def set_player_marker_for_player(
    player_id: int, showplayer_id: int, color: int
) -> bool:
    return SetPlayerMarkerForPlayer(player_id, showplayer_id, color)


def show_player_name_tag_for_player(
    player_id: int, showplayer_id: int, show: bool
) -> bool:
    return ShowPlayerNameTagForPlayer(player_id, showplayer_id, show)


def set_player_map_icon(
    player_id: int,
    iconid: int,
    x: float,
    y: float,
    z: float,
    markertype: int,
    color: int,
    style: int = MAPICON_LOCAL,
) -> bool:
    return SetPlayerMapIcon(
        player_id, iconid, x, y, z, markertype, color, style
    )


def remove_player_map_icon(player_id: int, icon_id: int) -> bool:
    return RemovePlayerMapIcon(player_id, icon_id)


def allow_player_teleport(player_id: int, allow: bool) -> bool:
    return AllowPlayerTeleport(player_id, allow)


def set_player_camera_pos(
    player_id: int, x: float, y: float, z: float
) -> bool:
    return SetPlayerCameraPos(player_id, x, y, z)


def set_player_camera_look_at(
    player_id: int, x: float, y: float, z: float, cut: int = CAMERA_CUT
) -> bool:
    return SetPlayerCameraLookAt(player_id, x, y, z, cut)


def set_camera_behind_player(player_id: int) -> bool:
    return SetCameraBehindPlayer(player_id)


def get_player_camera_pos(player_id: int) -> Tuple[float, float, float]:
    return GetPlayerCameraPos(player_id)


def get_player_camera_front_vector(
    player_id: int,
) -> Tuple[float, float, float]:
    return GetPlayerCameraFrontVector(player_id)


def get_player_camera_mode(player_id: int) -> int:
    return GetPlayerCameraMode(player_id)


def enable_player_camera_target(player_id: int, enable: bool) -> bool:
    return EnablePlayerCameraTarget(player_id, enable)


def get_player_camera_target_object(player_id: int) -> int:
    return GetPlayerCameraTargetObject(player_id)


def get_player_camera_target_vehicle(player_id: int) -> int:
    return GetPlayerCameraTargetVehicle(player_id)


def get_player_camera_target_player(player_id: int) -> int:
    return GetPlayerCameraTargetPlayer(player_id)


def get_player_camera_target_actor(player_id: int) -> int:
    return GetPlayerCameraTargetActor(player_id)


def get_player_camera_aspect_ratio(player_id: int) -> float:
    return GetPlayerCameraAspectRatio(player_id)


def get_player_camera_zoom(player_id: int) -> float:
    return GetPlayerCameraZoom(player_id)


def attach_camera_to_object(player_id: int, object_id: int) -> bool:
    return AttachCameraToObject(player_id, object_id)


def attach_camera_to_player_object(
    player_id: int, player_object_id: int
) -> bool:
    return AttachCameraToPlayerObject(player_id, player_object_id)


def interpolate_camera_pos(
    player_id: int,
    from_x: float,
    from_y: float,
    from_z: float,
    to_x: float,
    to_y: float,
    to_z: float,
    time: int,
    cut: int = CAMERA_CUT,
) -> bool:
    return InterpolateCameraPos(
        player_id, from_x, from_y, from_z, to_x, to_y, to_z, time, cut
    )


def interpolate_camera_look_at(
    player_id: int,
    from_x: float,
    from_y: float,
    from_z: float,
    to_x: float,
    to_y: float,
    to_z: float,
    time: int,
    cut: int = CAMERA_CUT,
) -> bool:
    return InterpolateCameraLookAt(
        player_id, from_x, from_y, from_z, to_x, to_y, to_z, time, cut
    )


def is_player_connected(player_id: int) -> bool:
    return IsPlayerConnected(player_id)


def is_player_in_vehicle(player_id: int, vehicle_id: int) -> bool:
    return IsPlayerInVehicle(player_id, vehicle_id)


def is_player_in_any_vehicle(player_id: int) -> bool:
    return IsPlayerInAnyVehicle(player_id)


def is_player_in_checkpoint(player_id: int) -> bool:
    return IsPlayerInCheckpoint(player_id)


def is_player_in_race_checkpoint(player_id: int) -> bool:
    return IsPlayerInRaceCheckpoint(player_id)


def set_player_virtual_world(player_id: int, world_id: int) -> bool:
    return SetPlayerVirtualWorld(player_id, world_id)


def get_player_virtual_world(player_id: int) -> int:
    return GetPlayerVirtualWorld(player_id)


def enable_stunt_bonus_for_player(player_id: int, enable: bool) -> bool:
    return EnableStuntBonusForPlayer(player_id, enable)


def enable_stunt_bonus_for_all(enable: bool) -> bool:
    return EnableStuntBonusForAll(enable)


def toggle_player_spectating(player_id: int, toggle: bool) -> bool:
    return TogglePlayerSpectating(player_id, toggle)


def player_spectate_player(
    player_id: int, target_player_id: int, mode: int = SPECTATE_MODE_NORMAL
) -> bool:
    return PlayerSpectatePlayer(player_id, target_player_id, mode)


def player_spectate_vehicle(
    player_id: int, target_vehicle_id: int, mode: int = SPECTATE_MODE_NORMAL
) -> bool:
    return PlayerSpectateVehicle(player_id, target_vehicle_id, mode)


def start_recording_player_data(
    player_id: int,
    record_type: int,
    record_name: str,
) -> bool:
    return StartRecordingPlayerData(player_id, record_type, record_name)


def stop_recording_player_data(player_id: int) -> bool:
    return StopRecordingPlayerData(player_id)


def create_explosion_for_player(
    player_id: int, x: float, y: float, z: float, type: int, radius: float
) -> bool:
    return CreateExplosionForPlayer(player_id, x, y, z, type, radius)


def create_object(
    model_id: int,
    x: float,
    y: float,
    z: float,
    rotation_x: float,
    rotation_y: float,
    rotation_z: float,
    draw_distance: float = 0.0,
) -> bool:
    return CreateObject(
        model_id, x, y, z, rotation_x, rotation_y, rotation_z, draw_distance
    )


def attach_object_to_vehicle(
    object_id: int,
    vehicle_id: int,
    offset_x: float,
    offset_y: float,
    offset_z: float,
    rotation_x: float,
    rotation_y: float,
    rotation_z: float,
) -> bool:
    return AttachObjectToVehicle(
        object_id,
        vehicle_id,
        offset_x,
        offset_y,
        offset_z,
        rotation_x,
        rotation_y,
        rotation_z,
    )


def attach_object_to_object(
    object_id: int,
    attach_to_id: int,
    offset_x: float,
    offset_y: float,
    offset_z: float,
    rotation_x: float,
    rotation_y: float,
    rotation_z: float,
    sync_rotation: bool,
) -> bool:
    return AttachObjectToObject(
        object_id,
        attach_to_id,
        offset_x,
        offset_y,
        offset_z,
        rotation_x,
        rotation_y,
        rotation_z,
        sync_rotation,
    )


def attach_object_to_player(
    object_id: int,
    player_id: int,
    offset_x: float,
    offset_y: float,
    offset_z: float,
    rotation_x: float,
    rotation_y: float,
    rotation_z: float,
) -> bool:
    return AttachObjectToPlayer(
        object_id,
        player_id,
        offset_x,
        offset_y,
        offset_z,
        rotation_x,
        rotation_y,
        rotation_z,
    )


def set_object_pos(object_id: int, x: float, y: float, z: float) -> bool:
    return SetObjectPos(object_id, x, y, z)


def get_object_pos(object_id: int) -> Tuple[float, float, float]:
    return GetObjectPos(object_id)


def set_object_rot(
    object_id: int, rotation_x: float, rotation_y: float, rotation_z: float
) -> bool:
    return SetObjectRot(object_id, rotation_x, rotation_y, rotation_z)


def get_object_rot(object_id: int) -> Tuple[float, float, float]:
    return GetObjectRot(object_id)


def get_object_model(object_id: int) -> int:
    return GetObjectModel(object_id)


def set_object_no_camera_col(object_id: int) -> bool:
    return SetObjectNoCameraCol(object_id)


def is_valid_object(object_id: int) -> bool:
    return IsValidObject(object_id)


def destroy_object(object_id: int) -> bool:
    return DestroyObject(object_id)


def move_object(
    object_id: int,
    x: float,
    y: float,
    z: float,
    speed: float,
    rotation_x: float = -1000.0,
    rotation_y: float = -1000.0,
    rotation_z: float = -1000.0,
) -> int:
    """Move and rotate an object to given values.

    Rotation values should be -1000 if you don't want to modify the object
    rotation.

    Returns the time in seconds it takes to move the object.
    """
    return MoveObject(
        object_id, x, y, z, speed, rotation_x, rotation_y, rotation_z
    )


def stop_object(object_id: int) -> bool:
    """Stop moving an object."""
    return StopObject(object_id)


def is_object_moving(object_id: int) -> bool:
    """Check if an object is currently moving."""
    return IsObjectMoving(object_id)


def edit_object(player_id: int, object_id: int) -> bool:
    """Let the player_id edit the object."""
    return EditObject(player_id, object_id)


def edit_player_object(player_id: int, object_id: int) -> bool:
    """Let the player_id edit the given player object."""
    return EditPlayerObject(player_id, object_id)


def select_object(player_id: int) -> bool:
    """Allow the player_id to select an object with their mouse pointer.

    When the player selects an object, the on_player_select_object callback
    is called.
    """
    return SelectObject(player_id)


def cancel_edit(player_id: int) -> bool:
    """End the object selection mode for the player."""
    return CancelEdit(player_id)


def create_player_object(
    player_id: int,
    model_id: int,
    x: float,
    y: float,
    z: float,
    rotation_x: float,
    rotation_y: float,
    rotation_z: float,
    draw_distance: float = 0.0,
) -> int:
    return CreatePlayerObject(
        player_id,
        model_id,
        x,
        y,
        z,
        rotation_x,
        rotation_y,
        rotation_z,
        draw_distance,
    )


def attach_player_object_to_player(
    objectplayer: int,
    object_id: int,
    attachplayer: int,
    offset_x: float,
    offset_y: float,
    offset_z: float,
    rotation_x: float,
    rotation_y: float,
    rotation_z: float,
) -> bool:
    return AttachPlayerObjectToPlayer(
        objectplayer,
        object_id,
        attachplayer,
        offset_x,
        offset_y,
        offset_z,
        rotation_x,
        rotation_y,
        rotation_z,
    )


def attach_player_object_to_vehicle(
    player_id: int,
    object_id: int,
    vehicle_id: int,
    offset_x: float,
    offset_y: float,
    offset_z: float,
    rotation_x: float,
    rotation_y: float,
    rotation_z: float,
) -> bool:
    return AttachPlayerObjectToVehicle(
        player_id,
        object_id,
        vehicle_id,
        offset_x,
        offset_y,
        offset_z,
        rotation_x,
        rotation_y,
        rotation_z,
    )


def set_player_object_pos(
    player_id: int, object_id: int, x: float, y: float, z: float
) -> bool:
    return SetPlayerObjectPos(player_id, object_id, x, y, z)


def get_player_object_pos(
    player_id: int, object_id: int
) -> Tuple[float, float, float]:
    return GetPlayerObjectPos(player_id, object_id)


def set_player_object_rot(
    player_id: int,
    object_id: int,
    rotation_x: float,
    rotation_y: float,
    rotation_z: float,
) -> bool:
    return SetPlayerObjectRot(
        player_id, object_id, rotation_x, rotation_y, rotation_z
    )


def get_player_object_rot(
    player_id: int, object_id: int
) -> Tuple[float, float, float]:
    return GetPlayerObjectRot(player_id, object_id)


def get_player_object_model(player_id: int, object_id: int) -> int:
    return GetPlayerObjectModel(player_id, object_id)


def set_player_object_no_camera_col(player_id: int, object_id: int) -> bool:
    return SetPlayerObjectNoCameraCol(player_id, object_id)


def is_valid_player_object(player_id: int, object_id: int) -> bool:
    return IsValidPlayerObject(player_id, object_id)


def destroy_player_object(player_id: int, object_id: int) -> bool:
    return DestroyPlayerObject(player_id, object_id)


def move_player_object(
    player_id: int,
    object_id: int,
    x: float,
    y: float,
    z: float,
    speed: float,
    rotation_x: float = -1000.0,
    rotation_y: float = -1000.0,
    rotation_z: float = -1000.0,
) -> int:
    return MovePlayerObject(
        player_id,
        object_id,
        x,
        y,
        z,
        speed,
        rotation_x,
        rotation_y,
        rotation_z,
    )


def stop_player_object(player_id: int, object_id: int) -> bool:
    return StopPlayerObject(player_id, object_id)


def is_player_object_moving(player_id: int, object_id: int) -> bool:
    return IsPlayerObjectMoving(player_id, object_id)


def set_object_material(
    object_id: int,
    material_index: int,
    model_id: int,
    txd_name: str,
    texture_name: str,
    material_color: int = 0,
) -> bool:
    return SetObjectMaterial(
        object_id,
        material_index,
        model_id,
        txd_name,
        texture_name,
        material_color,
    )


def set_player_object_material(
    player_id: int,
    object_id: int,
    material_index: int,
    model_id: int,
    txd_name: str,
    texture_name: str,
    material_color: int = 0,
) -> bool:
    return SetPlayerObjectMaterial(
        player_id,
        object_id,
        material_index,
        model_id,
        txd_name,
        texture_name,
        material_color,
    )


def set_object_material_text(
    object_id: int,
    text: str,
    material_index: int = 0,
    material_size: int = OBJECT_MATERIAL_SIZE_256x128,
    font_face: str = "Arial",
    font_size: int = 24,
    bold: bool = True,
    font_color: int = 0xFFFFFFFF,
    back_color: int = 0,
    text_alignment: int = 0,
) -> bool:
    return SetObjectMaterialText(
        object_id,
        text,
        material_index,
        material_size,
        font_face,
        font_size,
        bold,
        font_color,
        back_color,
        text_alignment,
    )


def set_player_object_material_text(
    player_id: int,
    object_id: int,
    text: str,
    material_index: int = 0,
    material_size: int = OBJECT_MATERIAL_SIZE_256x128,
    font_face: str = "Arial",
    font_size: int = 24,
    bold: bool = True,
    font_color: int = 0xFFFFFFFF,
    back_color: int = 0,
    text_alignment: int = 0,
) -> bool:
    return SetPlayerObjectMaterialText(
        player_id,
        object_id,
        text,
        material_index,
        material_size,
        font_face,
        font_size,
        bold,
        font_color,
        back_color,
        text_alignment,
    )


def set_objects_default_camera_col(disable: bool) -> bool:
    return SetObjectsDefaultCameraCol(disable)


def send_client_message(player_id: int, color: int, message: str) -> bool:
    return SendClientMessage(player_id, color, message)


def send_client_message_to_all(color: int, message: str) -> bool:
    return SendClientMessageToAll(color, message)


def send_player_message_to_player(
    player_id: int, senderid: int, message: str
) -> bool:
    return SendPlayerMessageToPlayer(player_id, senderid, message)


def send_player_message_to_all(senderid: int, message: str) -> bool:
    return SendPlayerMessageToAll(senderid, message)


def send_death_message(killer: int, killee: int, weapon: int) -> bool:
    return SendDeathMessage(killer, killee, weapon)


def send_death_message_to_player(
    player_id: int, killer: int, killee: int, weapon: int
) -> bool:
    return SendDeathMessageToPlayer(player_id, killer, killee, weapon)


def game_text_for_all(text: str, time: int, style: int) -> bool:
    return GameTextForAll(text, time, style)


def game_text_for_player(
    player_id: int, text: str, time: int, style: int
) -> bool:
    return GameTextForPlayer(player_id, text, time, style)


def get_tick_count() -> int:
    return GetTickCount()


def get_max_players() -> int:
    return GetMaxPlayers()


def vector_size(x: float, y: float, z: float) -> float:
    return VectorSize(x, y, z)


def get_player_pool_size() -> int:
    return GetPlayerPoolSize()


def get_vehicle_pool_size() -> int:
    return GetVehiclePoolSize()


def get_actor_pool_size() -> int:
    return GetActorPoolSize()


def set_svar_int(var_name: str, int_value: int) -> bool:
    return SetSVarInt(var_name, int_value)


def get_svar_int(var_name: str) -> int:
    return GetSVarInt(var_name)


def set_svar_string(var_name: str, string_value: str) -> bool:
    return SetSVarString(var_name, string_value)


def get_svar_string(var_name: str) -> str:
    return GetSVarString(var_name)


def set_svar_float(var_name: str, float_value: float) -> bool:
    return SetSVarFloat(var_name, float_value)


def get_svar_float(var_name: str) -> float:
    return GetSVarFloat(var_name)


def delete_svar(var_name: str) -> bool:
    return DeleteSVar(var_name)


def get_svars_upper_index() -> int:
    return GetSVarsUpperIndex()


def get_svar_name_at_index(index: int) -> str:
    return GetSVarNameAtIndex(index)


def get_svar_type(var_name: str) -> int:
    return GetSVarType(var_name)


def set_game_mode_text(text: str) -> bool:
    return SetGameModeText(text)


def set_team_count(count: int) -> bool:
    return SetTeamCount(count)


def add_player_class(
    model_id: int,
    spawn_x: float,
    spawn_y: float,
    spawn_z: float,
    z_angle: float,
    weapon1: int,
    weapon1_ammo: int,
    weapon2: int,
    weapon2_ammo: int,
    weapon3: int,
    weapon3_ammo: int,
) -> int:
    return AddPlayerClass(
        model_id,
        spawn_x,
        spawn_y,
        spawn_z,
        z_angle,
        weapon1,
        weapon1_ammo,
        weapon2,
        weapon2_ammo,
        weapon3,
        weapon3_ammo,
    )


def add_player_class_ex(
    teamid: int,
    model_id: int,
    spawn_x: float,
    spawn_y: float,
    spawn_z: float,
    z_angle: float,
    weapon1: int,
    weapon1_ammo: int,
    weapon2: int,
    weapon2_ammo: int,
    weapon3: int,
    weapon3_ammo: int,
) -> int:
    return AddPlayerClassEx(
        teamid,
        model_id,
        spawn_x,
        spawn_y,
        spawn_z,
        z_angle,
        weapon1,
        weapon1_ammo,
        weapon2,
        weapon2_ammo,
        weapon3,
        weapon3_ammo,
    )


def add_static_vehicle(
    model_id: int,
    spawn_x: float,
    spawn_y: float,
    spawn_z: float,
    z_angle: float,
    color1: int,
    color2: int,
) -> int:
    return AddStaticVehicle(
        model_id, spawn_x, spawn_y, spawn_z, z_angle, color1, color2
    )


def add_static_vehicle_ex(
    model_id: int,
    spawn_x: float,
    spawn_y: float,
    spawn_z: float,
    z_angle: float,
    color1: int,
    color2: int,
    respawn_delay: int,
    addsiren: bool = False,
) -> int:
    return AddStaticVehicleEx(
        model_id,
        spawn_x,
        spawn_y,
        spawn_z,
        z_angle,
        color1,
        color2,
        respawn_delay,
        addsiren,
    )


def add_static_pickup(
    model: int, type: int, x: float, y: float, z: float, virtualworld: int = 0
) -> int:
    return AddStaticPickup(model, type, x, y, z, virtualworld)


def create_pickup(
    model: int, type: int, x: float, y: float, z: float, virtualworld: int = 0
) -> int:
    return CreatePickup(model, type, x, y, z, virtualworld)


def destroy_pickup(pickup: int) -> bool:
    return DestroyPickup(pickup)


def show_name_tags(show: bool) -> bool:
    return ShowNameTags(show)


def show_player_markers(mode: int) -> bool:
    return ShowPlayerMarkers(mode)


def game_mode_exit() -> bool:
    return GameModeExit()


def set_world_time(hour: int) -> bool:
    return SetWorldTime(hour)


def get_weapon_name(weapon_id: int) -> str:
    return GetWeaponName(weapon_id)


def enable_tire_popping(enable: bool) -> bool:
    return EnableTirePopping(enable)


def enable_vehicle_friendly_fire() -> bool:
    return EnableVehicleFriendlyFire()


def allow_interior_weapons(allow: bool) -> bool:
    return AllowInteriorWeapons(allow)


def set_weather(weather_id: int) -> bool:
    return SetWeather(weather_id)


def set_gravity(gravity: float) -> bool:
    return SetGravity(gravity)


def get_gravity() -> float:
    return GetGravity()


def allow_admin_teleport(allow: bool) -> bool:
    return AllowAdminTeleport(allow)


def set_death_drop_amount(amount: int) -> bool:
    return SetDeathDropAmount(amount)


def create_explosion(
    x: float, y: float, z: float, type: int, radius: float
) -> bool:
    return CreateExplosion(x, y, z, type, radius)


def enable_zone_names(enable: bool) -> bool:
    return EnableZoneNames(enable)


def use_player_ped_anims() -> bool:
    return UsePlayerPedAnims()


def disable_interior_enter_exits() -> bool:
    return DisableInteriorEnterExits()


def set_name_tag_draw_distance(distance: float) -> bool:
    return SetNameTagDrawDistance(distance)


def disable_name_tag_los() -> bool:
    return DisableNameTagLOS()


def limit_global_chat_radius(chat_radius: float) -> bool:
    return LimitGlobalChatRadius(chat_radius)


def limit_player_marker_radius(marker_radius: float) -> bool:
    return LimitPlayerMarkerRadius(marker_radius)


def connect_npc(name: str, script: str) -> bool:
    return ConnectNPC(name, script)


def is_player_npc(player_id: int) -> bool:
    return IsPlayerNPC(player_id)


def is_player_admin(player_id: int) -> bool:
    return IsPlayerAdmin(player_id)


def kick(player_id: int) -> bool:
    return Kick(player_id)


def ban(player_id: int) -> bool:
    return Ban(player_id)


def ban_ex(player_id: int, reason: str) -> bool:
    return BanEx(player_id, reason)


def send_rcon_command(command: str) -> bool:
    return SendRconCommand(command)


def get_player_network_stats(player_id: int) -> str:
    return GetPlayerNetworkStats(player_id)


def get_network_stats() -> str:
    return GetNetworkStats()


def get_player_version(player_id: int) -> str:
    return GetPlayerVersion(player_id)


def block_ip_address(ip_address: str, time_in_ms: int) -> bool:
    return BlockIpAddress(ip_address, time_in_ms)


def un_block_ip_address(ip_address: str) -> bool:
    return UnBlockIpAddress(ip_address)


def get_server_var_as_string(var_name: str) -> str:
    return GetServerVarAsString(var_name)


def get_server_var_as_int(var_name: str) -> int:
    return GetServerVarAsInt(var_name)


def get_server_var_as_bool(var_name: str) -> bool:
    return GetServerVarAsBool(var_name)


def get_console_var_as_string(var_name: str) -> str:
    return GetConsoleVarAsString(var_name)


def get_console_var_as_int(var_name: str) -> int:
    return GetConsoleVarAsInt(var_name)


def get_console_var_as_bool(var_name: str) -> bool:
    return GetConsoleVarAsBool(var_name)


def get_server_tick_rate() -> int:
    return GetServerTickRate()


def net_stats_get_connected_time(player_id: int) -> int:
    return NetStats_GetConnectedTime(player_id)


def net_stats_messages_received(player_id: int) -> int:
    return NetStats_MessagesReceived(player_id)


def net_stats_bytes_received(player_id: int) -> int:
    return NetStats_BytesReceived(player_id)


def net_stats_messages_sent(player_id: int) -> int:
    return NetStats_MessagesSent(player_id)


def net_stats_bytes_sent(player_id: int) -> int:
    return NetStats_BytesSent(player_id)


def net_stats_messages_recv_per_second(player_id: int) -> int:
    return NetStats_MessagesRecvPerSecond(player_id)


def net_stats_packet_loss_percent(player_id: int) -> float:
    return NetStats_PacketLossPercent(player_id)


def net_stats_connection_status(player_id: int) -> int:
    return NetStats_ConnectionStatus(player_id)


def net_stats_get_ip_port(player_id: int) -> str:
    return NetStats_GetIpPort(player_id)


def create_menu(
    title: str,
    columns: int,
    x: float,
    y: float,
    column_1_width: float,
    column_2_width: float = 0.0,
) -> bool:
    return CreateMenu(title, columns, x, y, column_1_width, column_2_width)


def destroy_menu(menu_id: int) -> bool:
    return DestroyMenu(menu_id)


def add_menu_item(menu_id: int, column: int, menu_text: str) -> int:
    return AddMenuItem(menu_id, column, menu_text)


def set_menu_column_header(
    menu_id: int, column: int, column_header: str
) -> bool:
    return SetMenuColumnHeader(menu_id, column, column_header)


def show_menu_for_player(menu_id: int, player_id: int) -> bool:
    return ShowMenuForPlayer(menu_id, player_id)


def hide_menu_for_player(menu_id: int, player_id: int) -> bool:
    return HideMenuForPlayer(menu_id, player_id)


def is_valid_menu(menu_id: int) -> bool:
    return IsValidMenu(menu_id)


def disable_menu(menu_id: int) -> bool:
    return DisableMenu(menu_id)


def disable_menu_row(menu_id: int, row: int) -> bool:
    return DisableMenuRow(menu_id, row)


def get_player_menu(player_id: int) -> int:
    return GetPlayerMenu(player_id)


def text_draw_create(x: float, y: float, text: str) -> int:
    return TextDrawCreate(x, y, text)


def text_draw_destroy(text_draw_id: int) -> bool:
    return TextDrawDestroy(text_draw_id)


def text_draw_letter_size(text_draw_id: int, x: float, y: float) -> bool:
    return TextDrawLetterSize(text_draw_id, x, y)


def text_draw_text_size(text_draw_id: int, x: float, y: float) -> bool:
    return TextDrawTextSize(text_draw_id, x, y)


def text_draw_alignment(text_draw_id: int, alignment: int) -> bool:
    return TextDrawAlignment(text_draw_id, alignment)


def text_draw_color(text_draw_id: int, color: int) -> bool:
    return TextDrawColor(text_draw_id, color)


def text_draw_use_box(text_draw_id: int, use: bool) -> bool:
    return TextDrawUseBox(text_draw_id, use)


def text_draw_box_color(text_draw_id: int, color: int) -> bool:
    return TextDrawBoxColor(text_draw_id, color)


def text_draw_set_shadow(text_draw_id: int, size: int) -> bool:
    return TextDrawSetShadow(text_draw_id, size)


def text_draw_set_outline(text_draw_id: int, size: int) -> bool:
    return TextDrawSetOutline(text_draw_id, size)


def text_draw_background_color(text_draw_id: int, color: int) -> bool:
    return TextDrawBackgroundColor(text_draw_id, color)


def text_draw_font(text_draw_id: int, font: int) -> bool:
    return TextDrawFont(text_draw_id, font)


def text_draw_set_proportional(text_draw_id: int, set: bool) -> bool:
    return TextDrawSetProportional(text_draw_id, set)


def text_draw_set_selectable(text_draw_id: int, set: bool) -> bool:
    return TextDrawSetSelectable(text_draw_id, set)


def text_draw_show_for_player(player_id: int, text_draw_id: int) -> bool:
    return TextDrawShowForPlayer(player_id, text_draw_id)


def text_draw_hide_for_player(player_id: int, text_draw_id: int) -> bool:
    return TextDrawHideForPlayer(player_id, text_draw_id)


def text_draw_show_for_all(text_draw_id: int) -> bool:
    return TextDrawShowForAll(text_draw_id)


def text_draw_hide_for_all(text_draw_id: int) -> bool:
    return TextDrawHideForAll(text_draw_id)


def text_draw_set_string(text_draw_id: int, string: str) -> bool:
    return TextDrawSetString(text_draw_id, string)


def text_draw_set_preview_model(text_draw_id: int, modelindex: int) -> bool:
    return TextDrawSetPreviewModel(text_draw_id, modelindex)


def text_draw_set_preview_rot(
    text_draw_id: int,
    rotation_x: float,
    rotation_y: float,
    rotation_z: float,
    zoom: float = 1.0,
) -> bool:
    return TextDrawSetPreviewRot(
        text_draw_id, rotation_x, rotation_y, rotation_z, zoom
    )


def text_draw_set_preview_veh_col(
    text_draw_id: int, color1: int, color2: int
) -> bool:
    return TextDrawSetPreviewVehCol(text_draw_id, color1, color2)


def select_text_draw(player_id: int, hover_color: int) -> bool:
    return SelectTextDraw(player_id, hover_color)


def cancel_select_text_draw(player_id: int) -> bool:
    return CancelSelectTextDraw(player_id)


def gang_zone_create(
    min_x: float, min_y: float, max_x: float, max_y: float
) -> int:
    return GangZoneCreate(min_x, min_y, max_x, max_y)


def gang_zone_destroy(zone_id: int) -> bool:
    return GangZoneDestroy(zone_id)


def gang_zone_show_for_player(
    player_id: int, zone_id: int, color: int
) -> bool:
    return GangZoneShowForPlayer(player_id, zone_id, color)


def gang_zone_show_for_all(zone_id: int, color: int) -> bool:
    return GangZoneShowForAll(zone_id, color)


def gang_zone_hide_for_player(player_id: int, zone_id: int) -> bool:
    return GangZoneHideForPlayer(player_id, zone_id)


def gang_zone_hide_for_all(zone_id: int) -> bool:
    return GangZoneHideForAll(zone_id)


def gang_zone_flash_for_player(
    player_id: int, zone_id: int, flashcolor: int
) -> bool:
    return GangZoneFlashForPlayer(player_id, zone_id, flashcolor)


def gang_zone_flash_for_all(zone_id: int, flashcolor: int) -> bool:
    return GangZoneFlashForAll(zone_id, flashcolor)


def gang_zone_stop_flash_for_player(player_id: int, zone_id: int) -> bool:
    return GangZoneStopFlashForPlayer(player_id, zone_id)


def gang_zone_stop_flash_for_all(zone_id: int) -> bool:
    return GangZoneStopFlashForAll(zone_id)


def show_player_dialog(
    player_id: int,
    dialog_id: int,
    style: int,
    caption: str,
    info: str,
    button1: str,
    button2: str,
) -> bool:
    return ShowPlayerDialog(
        player_id, dialog_id, style, caption, info, button1, button2
    )


def is_valid_vehicle(vehicle_id: int) -> bool:
    return IsValidVehicle(vehicle_id)


def get_vehicle_distance_from_point(
    vehicle_id: int, x: float, y: float, z: float
) -> float:
    return GetVehicleDistanceFromPoint(vehicle_id, x, y, z)


def create_vehicle(
    vehicletype: int,
    x: float,
    y: float,
    z: float,
    rotation: float,
    color1: int,
    color2: int,
    respawn_delay: int,
    addsiren: bool = False,
) -> int:
    return CreateVehicle(
        vehicletype, x, y, z, rotation, color1, color2, respawn_delay, addsiren
    )


def destroy_vehicle(vehicle_id: int) -> bool:
    return DestroyVehicle(vehicle_id)


def is_vehicle_streamed_in(vehicle_id: int, forplayer_id: int) -> bool:
    return IsVehicleStreamedIn(vehicle_id, forplayer_id)


def get_vehicle_pos(vehicle_id: int) -> Tuple[float, float, float]:
    return GetVehiclePos(vehicle_id)


def set_vehicle_pos(vehicle_id: int, x: float, y: float, z: float) -> bool:
    return SetVehiclePos(vehicle_id, x, y, z)


def get_vehicle_z_angle(vehicle_id: int) -> float:
    return GetVehicleZAngle(vehicle_id)


def get_vehicle_rotation_quat(
    vehicle_id: int,
) -> Tuple[float, float, float, float]:
    return GetVehicleRotationQuat(vehicle_id)


def set_vehicle_z_angle(vehicle_id: int, z_angle: float) -> bool:
    return SetVehicleZAngle(vehicle_id, z_angle)


def set_vehicle_params_for_player(
    vehicle_id: int, player_id: int, objective: int, doorslocked: int
) -> bool:
    return SetVehicleParamsForPlayer(
        vehicle_id, player_id, objective, doorslocked
    )


def manual_vehicle_engine_and_lights() -> bool:
    return ManualVehicleEngineAndLights()


def set_vehicle_params_ex(
    vehicle_id: int,
    engine: int,
    lights: int,
    alarm: int,
    doors: int,
    bonnet: int,
    boot: int,
    objective: int,
) -> bool:
    return SetVehicleParamsEx(
        vehicle_id, engine, lights, alarm, doors, bonnet, boot, objective
    )


def get_vehicle_params_ex(
    vehicle_id: int,
) -> Tuple[int, int, int, int, int, int, int]:
    return GetVehicleParamsEx(vehicle_id)


def get_vehicle_params_siren_state(vehicle_id: int) -> bool:
    return GetVehicleParamsSirenState(vehicle_id)


def set_vehicle_params_car_doors(
    vehicle_id: int,
    driver: int,
    passenger: int,
    back_left: int,
    back_right: int,
) -> bool:
    return SetVehicleParamsCarDoors(
        vehicle_id, driver, passenger, back_left, back_right
    )


def get_vehicle_params_car_doors(vehicle_id: int) -> Tuple[int, int, int, int]:
    return GetVehicleParamsCarDoors(vehicle_id)


def set_vehicle_params_car_windows(
    vehicle_id: int,
    driver: int,
    passenger: int,
    back_left: int,
    back_right: int,
) -> bool:
    return SetVehicleParamsCarWindows(
        vehicle_id, driver, passenger, back_left, back_right
    )


def get_vehicle_params_car_windows(
    vehicle_id: int,
) -> Tuple[int, int, int, int]:
    return GetVehicleParamsCarWindows(vehicle_id)


def set_vehicle_to_respawn(vehicle_id: int) -> bool:
    return SetVehicleToRespawn(vehicle_id)


def link_vehicle_to_interior(vehicle_id: int, interior_id: int) -> bool:
    return LinkVehicleToInterior(vehicle_id, interior_id)


def add_vehicle_component(vehicle_id: int, component_id: int) -> bool:
    return AddVehicleComponent(vehicle_id, component_id)


def remove_vehicle_component(vehicle_id: int, component_id: int) -> bool:
    return RemoveVehicleComponent(vehicle_id, component_id)


def change_vehicle_color(vehicle_id: int, color1: int, color2: int) -> bool:
    return ChangeVehicleColor(vehicle_id, color1, color2)


def change_vehicle_paintjob(vehicle_id: int, paint_job_id: int) -> bool:
    return ChangeVehiclePaintjob(vehicle_id, paint_job_id)


def set_vehicle_health(vehicle_id: int, health: float) -> bool:
    return SetVehicleHealth(vehicle_id, health)


def get_vehicle_health(vehicle_id: int) -> float:
    return GetVehicleHealth(vehicle_id)


def attach_trailer_to_vehicle(trailer_id: int, vehicle_id: int) -> bool:
    return AttachTrailerToVehicle(trailer_id, vehicle_id)


def detach_trailer_from_vehicle(vehicle_id: int) -> bool:
    return DetachTrailerFromVehicle(vehicle_id)


def is_trailer_attached_to_vehicle(vehicle_id: int) -> bool:
    return IsTrailerAttachedToVehicle(vehicle_id)


def get_vehicle_trailer(vehicle_id: int) -> int:
    return GetVehicleTrailer(vehicle_id)


def set_vehicle_number_plate(vehicle_id: int, number_plate: str) -> bool:
    return SetVehicleNumberPlate(vehicle_id, number_plate)


def get_vehicle_model(vehicle_id: int) -> int:
    return GetVehicleModel(vehicle_id)


def get_vehicle_component_in_slot(vehicle_id: int, slot: int) -> int:
    return GetVehicleComponentInSlot(vehicle_id, slot)


def get_vehicle_component_type(component: int) -> int:
    return GetVehicleComponentType(component)


def repair_vehicle(vehicle_id: int) -> bool:
    return RepairVehicle(vehicle_id)


def get_vehicle_velocity(vehicle_id: int) -> Tuple[float, float, float]:
    return GetVehicleVelocity(vehicle_id)


def set_vehicle_velocity(
    vehicle_id: int, x: float, y: float, z: float
) -> bool:
    return SetVehicleVelocity(vehicle_id, x, y, z)


def set_vehicle_angular_velocity(
    vehicle_id: int, x: float, y: float, z: float
) -> bool:
    return SetVehicleAngularVelocity(vehicle_id, x, y, z)


def get_vehicle_damage_status(vehicle_id: int) -> Tuple[int, int, int, int]:
    return GetVehicleDamageStatus(vehicle_id)


def update_vehicle_damage_status(
    vehicle_id: int, panels: int, doors: int, lights: int, tires: int
) -> bool:
    return UpdateVehicleDamageStatus(vehicle_id, panels, doors, lights, tires)


def set_vehicle_virtual_world(vehicle_id: int, world_id: int) -> bool:
    return SetVehicleVirtualWorld(vehicle_id, world_id)


def get_vehicle_virtual_world(vehicle_id: int) -> int:
    return GetVehicleVirtualWorld(vehicle_id)


def get_vehicle_model_info(
    model: int, infotype: int
) -> Tuple[float, float, float]:
    return GetVehicleModelInfo(model, infotype)


def create_actor(
    model_id: int, x: float, y: float, z: float, rotation: float
) -> int:
    return CreateActor(model_id, x, y, z, rotation)


def destroy_actor(actorid: int) -> bool:
    return DestroyActor(actorid)


def is_actor_streamed_in(actorid: int, forplayer_id: int) -> bool:
    return IsActorStreamedIn(actorid, forplayer_id)


def set_actor_virtual_world(actorid: int, vworld: int) -> bool:
    return SetActorVirtualWorld(actorid, vworld)


def get_actor_virtual_world(actorid: int) -> int:
    return GetActorVirtualWorld(actorid)


def apply_actor_animation(
    actorid: int,
    animation_library: str,
    animation_name: str,
    delta: float,
    loop: bool,
    lock_x: bool,
    lock_y: bool,
    freeze: bool,
    time: int,
) -> bool:
    return ApplyActorAnimation(
        actorid,
        animation_library,
        animation_name,
        delta,
        loop,
        lock_x,
        lock_y,
        freeze,
        time,
    )


def clear_actor_animations(actorid: int) -> bool:
    return ClearActorAnimations(actorid)


def set_actor_pos(actorid: int, x: float, y: float, z: float) -> bool:
    return SetActorPos(actorid, x, y, z)


def get_actor_pos(actorid: int) -> Tuple[float, float, float]:
    return GetActorPos(actorid)


def set_actor_facing_angle(actorid: int, angle: float) -> bool:
    return SetActorFacingAngle(actorid, angle)


def get_actor_facing_angle(actorid: int) -> float:
    return GetActorFacingAngle(actorid)


def set_actor_health(actorid: int, health: float) -> bool:
    return SetActorHealth(actorid, health)


def get_actor_health(actorid: int) -> float:
    return GetActorHealth(actorid)


def set_actor_invulnerable(actorid: int, invulnerable: bool = True) -> bool:
    return SetActorInvulnerable(actorid, invulnerable)


def is_actor_invulnerable(actorid: int) -> bool:
    return IsActorInvulnerable(actorid)


def is_valid_actor(actorid: int) -> bool:
    return IsValidActor(actorid)


def create_3d_text_label(
    text: str,
    color: int,
    x: float,
    y: float,
    z: float,
    draw_distance: float,
    virtual_world: int,
    test_line_of_sight: bool = False,
) -> int:
    return Create3DTextLabel(
        text, color, x, y, z, draw_distance, virtual_world, test_line_of_sight
    )


def delete_3d_text_label(id: int) -> bool:
    return Delete3DTextLabel(id)


def attach_3d_text_label_to_player(
    id: int, player_id: int, offset_x: float, offset_y: float, offset_z: float
) -> bool:
    return Attach3DTextLabelToPlayer(
        id, player_id, offset_x, offset_y, offset_z
    )


def attach_3d_text_label_to_vehicle(
    id: int, vehicle_id: int, offset_x: float, offset_y: float, offset_z: float
) -> bool:
    return Attach3DTextLabelToVehicle(
        id, vehicle_id, offset_x, offset_y, offset_z
    )


def update_3d_text_label_text(id: int, color: int, text: str) -> bool:
    return Update3DTextLabelText(id, color, text)


def create_player_3d_text_label(
    player_id: int,
    text: str,
    color: int,
    x: float,
    y: float,
    z: float,
    draw_distance: float,
    attached_player: int = INVALID_PLAYER_ID,
    attached_vehicle: int = INVALID_VEHICLE_ID,
    test_line_of_sight: bool = False,
) -> int:
    return CreatePlayer3DTextLabel(
        player_id,
        text,
        color,
        x,
        y,
        z,
        draw_distance,
        attached_player,
        attached_vehicle,
        test_line_of_sight,
    )


def delete_player_3d_text_label(player_id: int, id: int) -> bool:
    return DeletePlayer3DTextLabel(player_id, id)


def update_player_3d_text_label_text(
    player_id: int, id: int, color: int, text: str
) -> bool:
    return UpdatePlayer3DTextLabelText(player_id, id, color, text)


def gpci(playerid: int) -> str:
    return _gpci(playerid)


def set_timer(
    function: Callable, interval_ms: int, repeating: bool = False, *args: Tuple
) -> int:
    return SetTimer(function, interval_ms, repeating, *args)


def kill_timer(timer_id: int) -> None:
    return KillTimer(timer_id)


def call_native_function(name: str, *arguments):
    return CallNativeFunction(name, *arguments)


def call_remote_function(name: str, *arguments):
    return CallRemoteFunction(name, *arguments)


def register_callback(name: str, arguments: str):
    return RegisterCallback(name, arguments)


on_gamemode_init = functools.partial(
    registry.register_callback,
    "OnGameModeInit",
    group="pysamp.on_gamemode_init",
)

on_gamemode_exit = functools.partial(
    registry.register_callback,
    "OnGameModeExit",
    group="pysamp.on_gamemode_exit",
)

on_rcon_login_attempt = functools.partial(
    registry.register_callback,
    "OnRconLoginAttempt",
    group="pysamp.on_rcon_login_attempt",
)

on_incoming_connection = functools.partial(
    registry.register_callback,
    "OnIncomingConnection",
    group="pysamp.on_incoming_connection",
)
