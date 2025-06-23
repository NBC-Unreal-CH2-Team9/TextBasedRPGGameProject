#pragma once

#include "Equipment.h"

class Armor : public Equipment
{
public:
	Armor(std::string armorN, int healthincrease)
		: Equipment(armorN, 10), healthincrease(healthincrease) {
	};

	int GetStat() {
		return healthincrease;
	}

	std::string GetTypes() {
		return "Armor";
	}


protected:
	int healthincrease;
};

