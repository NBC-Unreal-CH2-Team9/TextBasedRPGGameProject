#pragma once
#include "../Monster/Monster.h"

class Slime : public Monster
{
public:
	Slime(int level) : Monster("������", (rand() % 11 + 20)* level, (rand() % 6 + 5)* level) {}
};