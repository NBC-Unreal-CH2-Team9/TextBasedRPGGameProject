#pragma once

#include "Equipment.h"

class Armor : public Equipment
{
public:
	Armor(std::string armorN)
		: Equipment(armorN, 10){
        if (armorN == "가죽갑옷") {
            this->healthincrease = 10;
            price = 10;
        }
        else if (armorN == "청동갑옷") {
            this->healthincrease = 30;
            price = 20;
        }
        else if (armorN == "철갑옷") {
            this->healthincrease = 50;
            price = 30;
        }
        else {
            this->healthincrease = 0;
            price = 5;
        }
	};

    Armor(const Armor& other)
        : Equipment(other.name, other.price), healthincrease(other.healthincrease) {
    }

	int GetStat() {
		return healthincrease;
	}

	EquipmentType GetType() {
		return EquipmentType::ARMOR;
	}


protected:
	int healthincrease;
};

