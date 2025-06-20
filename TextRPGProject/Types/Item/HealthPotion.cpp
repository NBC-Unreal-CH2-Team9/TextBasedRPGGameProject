#include "HealthPotion.h"
#include "../Character/Character.h"

void HealthPotion::Use(Character& user) {
	int newHealth = user.GetHealth() + healthRestore;
	//hp 회복을 위한 Actor.h의  protected: health 접근을 위해 SetHealth 함수 필요. 
	user.SetHealth(newHealth);
}