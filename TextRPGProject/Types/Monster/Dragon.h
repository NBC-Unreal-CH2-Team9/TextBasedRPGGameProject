#pragma once

#include "../Monster/Monster.h"


class Dragon : public Monster
{
public:
	Dragon(int level) : Monster("µå·¡°ï", (rand() % 11 + 20) * level * 1.5, (rand() % 6 + 5) * level * 1.5) {}

	void Attack(Actor& other) override;
};