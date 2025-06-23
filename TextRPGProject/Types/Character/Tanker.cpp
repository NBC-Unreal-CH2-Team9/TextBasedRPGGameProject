#include "Tanker.h"

#include <iostream>  

void Tanker::OnLevelChangedHealth() {
	std::cout << "Tanker's health increased!" << std::endl;

	int newHealth = (maxHealth + level * 20);
	health = newHealth;
	maxHealth = newHealth;
}

void Tanker::OnLevelChangedAttack() {
	std::cout << "Tanker's attack increased!" << std::endl;
	attack += (level * 5);
}