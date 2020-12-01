#include "main.h"

int __fastcall glimmer_loop_hook(BYTE* cent, void* _EDX, float a2) {
	std::cout << (DWORD*)cent << "\n";
	int ret = origGlimmer_loop(cent, a2);
	return ret;
}