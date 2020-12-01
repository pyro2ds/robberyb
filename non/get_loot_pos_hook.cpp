#include "main.h"

int __fastcall get_loot_pos_hook(DWORD* loot, void* _EDX, int a2) {
	int ret = origGet_loot_pos(loot, a2);
	vec3* pos = (vec3*)(ret + 0x18);
	if (localPlayer && tp_items) {
		pos->x = localPlayer->pos.x;
		pos->y = localPlayer->pos.y;
	}
	//if(!items[pos])
	//	items[pos] = false;
	//Sleep(100);
	return ret;
}