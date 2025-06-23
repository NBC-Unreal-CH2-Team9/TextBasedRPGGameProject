#pragma once

#include "../Actor.h"
#include "Inventory.h"
#include "../Equipment/Sword.h"
#include "../Equipment/Armor.h"

class Item;
class Equipment;


class Character : public Actor {
public:
	Character(std::string name, int health, int attack) : Actor(name, health, attack) {		
		level = 1;
		maxHealth = health;
		experience = 0;
	}
	virtual void Attack(Actor& other);
	virtual void TakeDamage(int damage);

	Inventory<Item>* GetItemInventory() {
		return &itemInventory;
	}
	Inventory<Equipment>* GetEquipmentInventory() {
		return &equipmentInventory;
	}

	int GetGold() {
		return gold;
	}
	void SetGold(int value) {
		gold = value;
	}
	int GetHealth() { return health; }
	void SetHealth(int newHealth) { health = newHealth; }

	int GetAttack() { return attack; }
	void SetAttack(int newAttack) { attack = newAttack; }

	int GetLevel() {
		return level;
	}
	void SetLevel(int value) {
		level = value;
	}

	void DisplayStatus();

	void LevelUp();

	void OnLevelChangedHealth();

	void OnLevelChangedAttack();

	void AddExperience(int exp);
	void EquipSword(Sword* newSword);
	void EquipArmor(Armor* newArmor);
	void Equip(Equipment* newEquip);

protected:
	Inventory<Item> itemInventory;
	Inventory<Equipment> equipmentInventory;
	Sword* equipSword;
	Armor* equipArmor;
	int gold;
	int level;
	int maxHealth;
	int experience;
};