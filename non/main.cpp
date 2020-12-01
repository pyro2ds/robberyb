 
#include "main.h"
bool fly = false;
bool speed_hack_plr = false;

COORD origin = { 0, 0 };
CONSOLE_CURSOR_INFO ccinfo;
int main(HMODULE hModule) {
    NewConsole();
    MH_Initialize();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    hooks::get_procs();
    hooks::init();
    system("cls");
    
    

    while (!GetAsyncKeyState(VK_F1)) {
        localPlayer = *(ent**)((DWORD)game_proc + 0x3A0A0C);
        player_upgrades = *(upgrades**)((DWORD)game_proc + 0x3A097C);
        if (*(int*)((DWORD)game_proc + 0x3A0A24) == 0) {
            ent_list.clear();
            items.clear();
        }
        GetConsoleCursorInfo(hConsole, &ccinfo);
        ccinfo.bVisible = false;
        SetConsoleCursorInfo(hConsole, &ccinfo);

        SetConsoleCursorPosition(hConsole, origin);
        SetConsoleTextAttribute(hConsole, 3);
        
        std::cout << R"(
      _     _                   _                  _                 _ _      _ _ _ 
     | |   (_)                 | |                | |               (_|_)    | | | |
  ___| |__  _ _ __   __ _   ___| |__   ___ _ __   | |__   __ _ _ __  _ _   __| | | |
 / __| '_ \| | '_ \ / _` | / __| '_ \ / _ \ '_ \  | '_ \ / _` | '_ \| | | / _` | | |
 \__ \ | | | | | | | (_| | \__ \ | | |  __/ | | | | | | | (_| | | | | | || (_| | | |
 |___/_| |_|_|_| |_|\__, | |___/_| |_|\___|_| |_| |_| |_|\__,_|_| |_| |_(_)__,_|_|_|
                     __/ |                                         _/ |             
                    |___/                                         |__/              
)";
        std::cout << "MENU: (F1 to quit)" << "\n\n";
        print_keybox("F2", "TP EVERY ENTITY", hConsole, false);
        print_keybox("F3", "NOCLIP", hConsole, fly);
        print_keybox("F4", "TP ALL ITEMS", hConsole, tp_items);
        print_keybox("F5", "FREEZE ALL ENEMIES", hConsole, speedHack);
        print_keybox("F6", "SPEED HACK", hConsole, speed_hack_plr);
        //std::cout << localPlayer;
        if (localPlayer) {
            (fly ? localPlayer->pos.z = 1.0f : localPlayer->pos.z = 0.0f);
            //(speedHack ? localPlayer->xspeed = localPlayer->xspeed * 2.0f : localPlayer->xspeed += 0.0f);
            //(speedHack ? localPlayer->yspeed = localPlayer->yspeed * 2.0f : localPlayer->yspeed += 0.0f);
        }
            

        if (GetAsyncKeyState(VK_F2) & 1 && game_proc) {
            refresh_ent_list();
            for (auto e : ent_list) {
                DWORD* a = (DWORD*)e.first;
                ent* c = (ent*)e.first;
                 
                if (localPlayer && c != localPlayer) {
                    c->pos.x = 1000.0f;
                    c->pos.y = 1000.0f;
                }                                               
            }
            
            
            //hooks::toggleHook((void*)render_addr);
        }
        else if (GetAsyncKeyState(VK_F3) & 1 && game_proc) {
            fly = !fly;
        }
        else if (GetAsyncKeyState(VK_F4) & 1 && game_proc) {
            hooks::toggleHook((void*)get_loot_pos_addr);
            tp_items = !tp_items;
        }
        else if (GetAsyncKeyState(VK_F5) & 1 && game_proc) {
            hooks::toggleHook((void*)move_player_addr);
            speedHack = !speedHack;
        }
        else if (GetAsyncKeyState(VK_F6) & 1 && game_proc) {
            speed_hack_plr = !speed_hack_plr;
            if (player_upgrades) {
                (speed_hack_plr ? player_upgrades->speed = 500 : player_upgrades->speed = 4);
                (speed_hack_plr ? player_upgrades->stamina = 500 : player_upgrades->stamina = 4);
            }
                
            
        }
    }
    CloseConsole();
    MH_Uninitialize();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
	
}