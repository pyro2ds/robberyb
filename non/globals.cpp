#include "globals.h"

HMODULE game_proc = 0;

move_player origMove_player = 0;
test origRender_addr = 0;
spawn_loot origSpawn_loot = 0;
glimmer_loop origGlimmer_loop = 0;
get_loot_pos origGet_loot_pos = 0;

DWORD move_player_addr = 0;
DWORD render_addr = 0;
DWORD spawn_loot_addr = 0;
DWORD glimmer_loop_addr = 0;
DWORD get_loot_pos_addr = 0;

std::unordered_map<void*, int32_t> ent_list = {};
std::unordered_map<vec3*, bool> items = {};
bool tp_items = false;
bool speedHack = false;
upgrades* player_upgrades = nullptr;
ent* localPlayer = nullptr;