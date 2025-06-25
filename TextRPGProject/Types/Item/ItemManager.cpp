#include "ItemManager.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <random>

Item* ItemManager::GenerateRandomItem()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    int roll = dist(gen);
    Item* dropItem = nullptr;

    if (roll <= 50) {
        dropItem = new HealthPotion(50);
    }
    else{
        dropItem = new AttackBoost(10);
    }

    return dropItem;
}