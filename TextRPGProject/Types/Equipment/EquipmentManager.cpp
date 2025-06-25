#include "EquipmentManager.h"
#include "Sword.h"
#include "Armor.h"
#include <random>

Equipment* EquipmentManager::GenerateRandomEquipment()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    int roll = dist(gen);
    Equipment* dropEquip = nullptr;

    if (roll <= 25) {
        dropEquip = new Sword("나무검");
    }
    else if (roll <= 50) {
        dropEquip = new Sword("청동검");
    }
    else if (roll <= 65) {
        dropEquip = new Sword("철검");
    }
    else if (roll <= 80) {
        dropEquip = new Armor("가죽갑옷");
    }
    else if (roll <= 90) {
        dropEquip = new Armor("청동갑옷");
    }
    else {
        dropEquip = new Armor("철갑옷");
    }

    return dropEquip;
}