#include "main.h"

int __fastcall spawn_loot_hook(char* item, void* _EDX) {
	ent* c = (ent*)item;
	int ret = origSpawn_loot(item);
	return ret;
}



