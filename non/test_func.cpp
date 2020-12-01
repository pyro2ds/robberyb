#include "main.h"

int __fastcall render_hook(BYTE* cent, void* _EDX) {
	int ret = origRender_addr(cent);
    DWORD* current_ent = (DWORD*)cent;
	//std::cout << ent << "\n";
    if (*(int*)((DWORD)game_proc + 0x3A0A24) == 0) {
        ent_list.clear();
    }
    ent_list[current_ent] = false;
    if (*current_ent == 0xDA438C) {
        ent_list[current_ent] = true;
        localPlayer = (ent*)current_ent;
    }
	return ret;
}