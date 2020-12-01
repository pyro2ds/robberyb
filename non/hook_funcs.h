#pragma once
#include "main.h"


namespace hooks {
	void toggleHook(void* addr);
	bool init();
	void get_procs();
}

DWORD* __fastcall hook_move_player(DWORD* cent, void* _EDX, vec3* pos);
int __fastcall render_hook(BYTE* ent, void* _EDX);
int __fastcall spawn_loot_hook(char* item, void* _EDX);
int __fastcall glimmer_loop_hook(BYTE* cent, void* _EDX, float a2);
int __fastcall get_loot_pos_hook(DWORD* loot, void* _EDX, int a2);