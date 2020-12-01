#pragma once
#include "main.h"


typedef DWORD* (__thiscall* move_player)(DWORD* ent, vec3* a2);
typedef int(__thiscall* test)(BYTE* ent);
typedef void* (__cdecl* get_ent)();
typedef int (__thiscall* spawn_loot)(char* item);
typedef int(__thiscall* glimmer_loop)(BYTE* glim, float a2);
typedef int(__thiscall* get_loot_pos)(DWORD* loot, int a2);

extern move_player origMove_player;
extern test origRender_addr;
extern spawn_loot origSpawn_loot;
extern glimmer_loop origGlimmer_loop;
extern get_loot_pos origGet_loot_pos;


extern DWORD move_player_addr;
extern DWORD render_addr;
extern DWORD spawn_loot_addr;
extern DWORD glimmer_loop_addr;
extern DWORD get_loot_pos_addr;