#pragma once

#include "../Actor.h"
#include "../Item/Item.h"
#include "Inventory.h"

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

protected:
	Inventory<Item> itemInventory;
	int gold;
	int level;
	int maxHealth;
	int experience;
};