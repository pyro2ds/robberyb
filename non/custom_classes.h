#pragma once
#include "main.h"
struct vec3 {
	float x;
	float y;
	float z;
};

class ent
{
public:
	char pad_0000[12]; //0x0000
	int32_t type; //0x000C
	char pad_0010[68]; //0x0010
	vec3 pos; //0x0054
	char pad_0060[4]; //0x0060
	float xspeed; //0x0064
	float yspeed; //0x0068
	char pad_006C[2012]; //0x006C
}; //Size: 0x0848

class upgrades
{
public:
	char pad_0000[24]; //0x0000
	int32_t stealth; //0x0018
	int32_t stamina; //0x001C
	int32_t speed; //0x0020
	int32_t grab; //0x0024
	char pad_0028[2072]; //0x0028
}; //Size: 0x0840