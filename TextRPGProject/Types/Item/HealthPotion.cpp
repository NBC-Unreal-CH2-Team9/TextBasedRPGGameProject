#include "HealthPotion.h"
#include "../Character/Character.h"

void HealthPotion::Use(Character& user) {
	int newHealth = user.GetHealth() + healthRestore;
	//hp ȸ���� ���� Actor.h��  protected: health ������ ���� SetHealth �Լ� �ʿ�. 
	user.SetHealth(newHealth);
}