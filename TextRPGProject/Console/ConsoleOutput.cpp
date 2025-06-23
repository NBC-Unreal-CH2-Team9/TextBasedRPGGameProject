#include "ConsoleOutput.h"
#include <iostream>

// 캐릭터 현재 상태를 출력하는 함수
void ShowCharacterStatus(int level, int experience, int health, int maxHealth, int attackpower) {
	std::cout << "--캐릭터 현재 상태-- " << std::endl;
	std::cout << "레벨: " << level << std::endl;
	std::cout << "경험치: " << experience << std::endl;
	std::cout << "체력: " << health << " / " << maxHealth << std::endl;
	std::cout << "공격력: " << attackpower << std::endl;
	std::cout << "----------------" << std::endl;
}

// 캐릭터의 골드를 출력하는 함수
void ShowCharacterGold(int gold) {
	std::cout << "--캐릭터 지갑-- " << std::endl;
	std::cout << "현재 골드: " << gold << std::endl;
	std::cout << "----------------" << std::endl;
}

// 몬스터의 상태를 출력하는 함수
static void ShowMonsterStatus(const int level, int health) {
	std::cout << "--몬스터 현재 상태-- " << std::endl;
	std::cout << "레벨: " << level << std::endl;
	std::cout << "체력: " << health << std::endl;
	std::cout << "----------------" << std::endl;
}

// 캐릭터가 공격을 받았을 때의 메시지를 출력하는 함수
void MonsterAttack(const std::string monster, std::string charactor, int damage) {
	std::cout << monster << "이(가) " << charactor << "을(를) 공격합니다! ";
	std::cout << monster << "이(가) " << damage << "의 데미지를 입습니다. ";
}

// 캐릭터가 공격을 했을 때의 메시지를 출력하는 함수
void CharactorAttack(const std::string Charactor, std::string monster, int damage) {
	std::cout << Charactor << "이(가) " << monster << "을(를) 공격합니다! ";
	std::cout << Charactor << "이(가) " << damage << "의 데미지를 입습니다. ";
}

// 캐릭터가 몬스터를 처치했을 때의 메시지를 출력하는 함수
void DieMonster() {
	std::cout << "몬스터가 처치되었습니다!" << std::endl;
}
