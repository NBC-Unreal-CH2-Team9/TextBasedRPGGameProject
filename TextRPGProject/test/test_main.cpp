// 빌드 설정을 'Debug', 'Release'가 아닌 'Test'으로 지정하면, 여기에 있는 main이 실행됩니다.
// 코드를 테스트해야할 일이 있다면, 여기에서 테스트 바랍니다.

#include <iostream>
#include "../Types/Monster/Monster.h"

#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"
#include "../Core/GameManager.h"

int main() {
	std::srand(std::time(nullptr));

	//Goblin goblin(1);
	int testCharacterLevel = 1;
	Monster* orc = MonsterManager::CreateOrc(testCharacterLevel);
	Monster* dragon = MonsterManager::CreateDragon(testCharacterLevel);

	std::cout << orc->GetName() << "체력: " << orc->GetHealth() << " 공격력: " << orc->GetAttack() << std::endl;
	std::cout << dragon->GetName() << "체력: " << dragon->GetHealth() << " 공격력: " << dragon->GetAttack() << std::endl;
	//std::cout << goblin.GetName() << "체력: " << goblin.GetHealth() << " 공격력: " << goblin.GetAttack() << std::endl;

	int i = 5;
	while(i > 0)
	{
		dragon->Attack(*orc);
		if (dragon->GetHealth() < 1 || orc->GetHealth() < 1)
		{
			std::cout << "전투 종료!" << std::endl;
			break;
		}
		orc->Attack(*dragon);
		i--;
		if (dragon->GetHealth() < 1 || orc->GetHealth() < 1)
		{
			std::cout << "전투 종료!" << std::endl;
			break;
		}
	}
	return 0;
}