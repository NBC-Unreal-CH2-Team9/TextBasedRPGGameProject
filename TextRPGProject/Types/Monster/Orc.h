#pragma once

#include "../Monster/Monster.h"

class Orc : public Monster
{
public:
	Orc(int level) : Monster("ø¿≈©", (rand() % 11 + 20) * level, (rand() % 6 + 5) * level) {}
};