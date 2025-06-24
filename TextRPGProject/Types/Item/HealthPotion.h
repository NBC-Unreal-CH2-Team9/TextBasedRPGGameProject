#pragma once

#include "Item.h"

class HealthPotion : public Item{
public:
	HealthPotion(int healthRestore) 
		: Item("Health Potion", 10), healthRestore(healthRestore) {};
	
	void Use(Character& user);

	int GetStat() {
		return healthRestore;
	}

protected:
	int healthRestore;
};

