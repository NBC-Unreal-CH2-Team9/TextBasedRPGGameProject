#include "AttackBoost.h"
#include "../Character/Character.h"

void AttackBoost::Use(Character& user) {
	int newAttack = user.GetAttack() + attackincrease;
	//hp ȸ���� ���� Actor.h��  protected: attack ������ ���� SetAttack �Լ� �ʿ�. 
	user.SetAttack(newAttack);
}