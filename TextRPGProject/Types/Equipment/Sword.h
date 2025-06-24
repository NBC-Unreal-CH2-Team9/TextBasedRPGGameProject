#pragma once

#include "Equipment.h"

class Sword : public Equipment
{
public:
    Sword(std::string swordN)
        : Equipment(swordN, 10)
    {
        if (swordN == "나무검") {
            this->attackincrease = 1;
            price = 10;
        }
        else if (swordN == "청동검") {
            this->attackincrease = 3;
            price = 20;
        }
        else if (swordN == "철검") {
            this->attackincrease = 5;
            price = 30;
        }
        else {
            this->attackincrease = 0;
            price = 5;
        }
    }

    Sword(const Sword& other)
        : Equipment(other.name, other.price), attackincrease(other.attackincrease) {
    }

	int GetStat() {
		return attackincrease;
	}

	EquipmentType GetType() {
		return EquipmentType::SWORD;
	}


protected:
	int attackincrease;
};

