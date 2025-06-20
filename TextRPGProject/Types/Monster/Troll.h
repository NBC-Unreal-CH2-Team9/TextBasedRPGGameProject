#pragma once
#include "../Monster/Monster.h"

class Troll : public Monster
{
public:
	Troll(int level) : Monster("Æ®·Ñ", (rand() % 11 + 20)* level, (rand() % 6 + 5)* level) {}
};