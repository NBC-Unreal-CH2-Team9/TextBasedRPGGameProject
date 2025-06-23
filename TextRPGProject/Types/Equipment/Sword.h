#pragma once

#include "Equipment.h"

class Sword : public Equipment
{
public:
	Sword(std::string swordN, int attackincrease) 
		: Equipment(swordN, 10), attackincrease(attackincrease) {
	};

	int GetStat() {
		return attackincrease;
	}

	std::string GetTypes() {
		return "Sword";
	}


protected:
	int attackincrease;
};

