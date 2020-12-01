#pragma once
#include <Windows.h>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include "MinHook.h"
#include "custom_classes.h"
#include "typedef.h"
#include "hook_funcs.h"
#include "help.h"
#include "globals.h"
#pragma comment(lib, "minhook.lib")


int main(HMODULE hModule);
void refresh_ent_list();

