#pragma once
#include "../Monster/Monster.h"


class Goblin : public Monster
{
public:
	Goblin(int level) : Monster("���", (rand() % 11 + 20) * level, (rand() % 6 + 5) * level) {}
};