#include "main.h"
void refresh_ent_list() {
	get_ent get_entities = (get_ent)((DWORD)game_proc + 0x3C2A0);
	DWORD** temp_list = (DWORD**)get_entities();
	ent_list.clear();
	DWORD* curr_addr = 0;
	if(temp_list)
		for (int i = 0; i < *(int*)((DWORD)game_proc + 0x3A0A24); i++){
			curr_addr = temp_list[i];
			ent* cur_ent = (ent*)temp_list[i];
			ent_list[curr_addr] = cur_ent->type;
			//std::cout << std::hex << *curr_addr << "\n";

			if (cur_ent->type == 2 && *curr_addr == ((DWORD)game_proc + 0x35438C)) {
				std::cout << std::hex << curr_addr << "\n";
				localPlayer = cur_ent;
			}
		}			
		
}
