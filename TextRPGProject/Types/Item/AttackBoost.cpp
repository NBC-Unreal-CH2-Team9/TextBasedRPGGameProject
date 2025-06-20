#include "AttackBoost.h"
#include "../Character/Character.h"

void AttackBoost::Use(Character& user) {
	int newAttack = user.GetAttack() + attackincrease;
	//hp 회복을 위한 Actor.h의  protected: attack 접근을 위해 SetAttack 함수 필요. 
	user.SetAttack(newAttack);
}