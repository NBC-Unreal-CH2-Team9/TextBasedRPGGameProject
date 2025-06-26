#include "Mage.h"  
#include <iostream>  

void Mage::OnLevelChangedHealth() {  
	int newHealth = (maxHealth + level * 10);  
	health = newHealth;  
	maxHealth = newHealth;  
}  

void Mage::OnLevelChangedAttack() { 
	attack += (level * 6);  
}