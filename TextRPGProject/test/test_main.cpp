// ���� ������ 'Debug', 'Release'�� �ƴ� 'Test'���� �����ϸ�, ���⿡ �ִ� main�� ����˴ϴ�.
// �ڵ带 �׽�Ʈ�ؾ��� ���� �ִٸ�, ���⿡�� �׽�Ʈ �ٶ��ϴ�.

#include <iostream>
#include "../Types/Monster/Goblin.h"
#include "../Types/Monster/Orc.h"
#include "../Types/Monster/Dragon.h"


int main() {
	std::srand(std::time(nullptr));


	//Goblin goblin(1);
	Orc orc(1);
	Dragon dragon(1);

	std::cout << orc.GetName() << "ü��: " << orc.GetHealth() << " ���ݷ�: " << orc.GetAttack() << std::endl;
	std::cout << dragon.GetName() << "ü��: " << dragon.GetHealth() << " ���ݷ�: " << dragon.GetAttack() << std::endl;
	//std::cout << goblin.GetName() << "ü��: " << goblin.GetHealth() << " ���ݷ�: " << goblin.GetAttack() << std::endl;

	int i = 5;
	while(i > 0)
	{
		dragon.Attack(orc);
		if (dragon.GetHealth() < 1 || orc.GetHealth() < 1)
		{
			std::cout << "���� ����!" << std::endl;
			break;
		}
		orc.Attack(dragon);
		i--;
		if (dragon.GetHealth() < 1 || orc.GetHealth() < 1)
		{
			std::cout << "���� ����!" << std::endl;
			break;
		}
	}


	


	return 0;
}