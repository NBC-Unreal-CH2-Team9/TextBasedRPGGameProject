#include "Dragon.h"

void Dragon::Attack(Actor& other)
{
	// TODO: ConsoleOutput�� ����ؼ� ������ ��
	std::cout << name << "��(��) " << other.GetName() << "��(��)";

	if (rand() % 10 < 2)
	{
		std::cout << " �극�������մϴ�. ";
		other.TakeDamage(attack * 2);
	}
	else
	{
		std::cout << " �����մϴ�! ";
		other.TakeDamage(attack);
	}
}
