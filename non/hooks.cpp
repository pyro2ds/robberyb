#include "main.h"
#pragma warning(disable: 26812)

bool hooks::init() {
    if (game_proc) {
        std::cout <<
            MH_StatusToString(MH_CreateHook((LPVOID)move_player_addr,
                &hook_move_player,
                reinterpret_cast<LPVOID*>(&origMove_player)))
            << "\n"
            << MH_StatusToString(MH_CreateHook((LPVOID)render_addr,
                &render_hook,
                reinterpret_cast<LPVOID*>(&origRender_addr)))
            << "\n"
            << MH_StatusToString(MH_CreateHook((LPVOID)spawn_loot_addr,
                &spawn_loot_hook,
                reinterpret_cast<LPVOID*>(&origSpawn_loot)))
            << "\n"
            << MH_StatusToString(MH_CreateHook((LPVOID)glimmer_loop_addr,
                &glimmer_loop_hook,
                reinterpret_cast<LPVOID*>(&origGlimmer_loop)))
            << "\n"
            << MH_StatusToString(MH_CreateHook((LPVOID)get_loot_pos_addr,
                &get_loot_pos_hook,
                reinterpret_cast<LPVOID*>(&origGet_loot_pos)))
            << "\n";
        return true;
    } 
    return false;
}

void hooks::toggleHook(void* addr) {

    MH_STATUS ret = MH_EnableHook((LPVOID)addr);
    //std::cout << MH_StatusToString(ret) << "\n";
    if (ret == MH_ERROR_ENABLED) {
        MH_DisableHook((LPVOID)addr);
    }

}

void hooks::get_procs() {
    game_proc = GetModuleHandleA("RobberyBob.exe");
    move_player_addr = ((DWORD)game_proc + 0x1611F0);
    render_addr = ((DWORD)game_proc + 0x1612D0);
    spawn_loot_addr = ((DWORD)game_proc + 0x1755a0);
    glimmer_loop_addr = ((DWORD)game_proc + 0x1d9ee0);
    get_loot_pos_addr = ((DWORD)game_proc + 0x130D00);
}


