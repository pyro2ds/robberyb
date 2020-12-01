#include "main.h"
#include "hook_funcs.h"

DWORD* __fastcall hook_move_player(DWORD* cent, void* _EDX, vec3* pos) {
    ent* e = (ent*)cent;
    
    if (localPlayer && e != localPlayer && speedHack) {
        pos = new vec3{ 0,0,0 };
    }
    DWORD* ret = origMove_player(cent, pos);
   

    
    return nullptr;
}