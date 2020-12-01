#pragma once
#include "main.h"

extern HMODULE game_proc;

extern std::unordered_map<void*, int32_t> ent_list;
extern std::unordered_map<vec3*, bool> items;
extern bool tp_items;
extern bool speedHack;
extern upgrades* player_upgrades;
extern ent* localPlayer;