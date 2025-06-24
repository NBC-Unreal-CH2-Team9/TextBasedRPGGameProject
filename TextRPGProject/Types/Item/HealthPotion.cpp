#include "HealthPotion.h"
#include "../Character/Character.h"

void HealthPotion::Use(Character& user) {
	int newHealth = user.GetHealth() + healthRestore;
	//hp 회복 로직. 최대 체력 초과해서 회복 못함.
	if (user.GetMaxHealth() < newHealth) {
		user.SetHealth(user.GetMaxHealth());
	}
	else {
		user.SetHealth(newHealth);
	}
	
}