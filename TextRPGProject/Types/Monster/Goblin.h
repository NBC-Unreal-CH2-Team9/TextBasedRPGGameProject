#pragma once
#include "../Monster/Monster.h"


class Goblin : public Monster
{
public:
	Goblin(int level) : Monster("°íºí¸°", (rand() % 11 + 20) * level, (rand() % 6 + 5) * level) {}
};