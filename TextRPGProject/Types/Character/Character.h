#pragma once

#include "../Actor.h"
#include "Inventory.h"

class Item;
class Equipment;

class Character : public Actor {
public:
	Character(int level, std::string name, int health, int attack, int exp) : Actor(name, health, attack) {
		this->level = level;
		maxHealth = health;
		experience = exp;
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

	int GetMaxHealth() { return maxHealth; }

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

	virtual void OnLevelChangedHealth();

	virtual void OnLevelChangedAttack();

	void AddExperience(int exp);	

	void UseRandomItem(); // 전투중 랜덤하게 사용

	void GetRandomItem(Item* item); // 전투승리시 아이템 획득

protected:
	Inventory<Item> itemInventory;
	Inventory<Equipment> equipmentInventory;
	int gold;
	int level;
	
	int maxHealth;
	int experience;
};