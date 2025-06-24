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

	EquipmentType GetType() {
		return EquipmentType::SWORD;
	}


protected:
	int attackincrease;
};

