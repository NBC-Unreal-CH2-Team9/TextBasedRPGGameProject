#include "ConsoleOutput.h"
#include <iostream>


// 캐릭터 생성 시 안내메시지 출력
void ShowCreateCharacterIntro()
{
	std::cout << "----------------\n";
	std::cout << "캐릭터를 생성합니다.\n";
	std::cout << "----------------\n";
}
// 캐릭터 이름을 생성할 때 출력하는 함수
void ShowCreateCharacterName()
{
	std::cout << "캐릭터 이름을 입력하세요 : " << std::endl;
}
// 캐릭터 직업을 선택할 때 출력하는 함수
void ShowSelectJob()
{
	std::cout << "캐릭터의 직업을 입력하세요.\n";
	std::cout << "1 : 전사\n";
	std::cout << "2 : 마법사" << std::endl;
	//std::cout << "2 : 마법사" << std::endl;
}
// 캐릭터 생성 확인을 출력하는 함수 구현 예정 


// 캐릭터 현재 상태를 출력하는 함수
void ConsoleOutput::ShowCharacterStatus(Character& character) {
	std::cout << "--캐릭터 현재 상태--\n";
	std::cout << "이름: " << character.GetName() << "\n";
	//std::cout << "직업: " << character.GetJob() << "\n";
	std::cout << "레벨: " << character.GetLevel() << "\n";
	//std::cout << "경험치: " << character.Getexperience << "/ 100 " << "\n";
	std::cout << "체력: " << character.GetHealth() << " /  " << character.GetHealth() << "\n";
	std::cout << "공격력: " << character.GetAttack() << "\n";
	std::cout << "----------------\n";

	// 아이템 출력 구현 예정
}
// 캐릭터의 골드를 출력하는 함수
void ConsoleOutput::ShowCharacterGold(Character& character) {
	std::cout << "--캐릭터 지갑--\n";
	std::cout << "현재 골드: " << character.GetGold() << "\n";
	std::cout << "----------------\n";
}


// 몬스터의 상태를 출력하는 함수
void ConsoleOutput::ShowMonsterStatus(Monster& monster) {
	std::cout << "--몬스터 현재 상태--\n";
	std::cout << "이름 : " << monster.GetName() << "\n";
	//std::cout << "레벨: " << monster.GetLevel() << "\n";
	std::cout << "체력: " << monster.GetHealth() << "\n";
	std::cout << "----------------\n";
}


// 공격을 출력하는 함수
void ShowAttackMessage(Actor& attacker, Actor& target) {
	std::cout << attacker.GetName() << "이(가) " << target.GetName() << "을(를) 공격합니다!\n";
}
// 피해를 출력하는 함수
void ShowDamageMessage(Actor* who, int damage) {
	std::cout << who->GetName() << "이(가) " << damage << "의 데미지를 입습니다.\n";
}
// 크리티컬을 출력하는 함수
void ShowCriticalHit()
{
	std::cout << "크리티컬!!\n";
}


// 캐릭터가 몬스터를 처치해 전투에서 승리했을 때의 메시지를 출력하는 함수
void ConsoleOutput::ShowDieMonster() {
	std::cout << "몬스터가 처치되었습니다! 전투에서 승리하셨습니다.\n";
}


// 상점에 들어갈 것인지 물어보는 메시지를 출력하는 함수
void ShowAskEnterShop()
{
	std::cout << "----------------\n";
	std::cout << "상점에 입장하겠습까?\n";
	std::cout << "1 : 예\n";
	std::cout << "2 : 아니오\n";
	std::cout << "----------------" << std::endl;
}
//상점에 입장했을 때 입장 메시지를 출력하는 함수
void ShowEnterShop()
{
	std::cout << "상점에 입장했습니다.\n";
}
// 상점에서 나갈 것인지 물어보는 메시지를 출력하는 함수
void ShowAskExitShop()
{
	std::cout << "----------------\n";
	std::cout << "상점에서 나가겠습까?\n";
	std::cout << "1 : 예\n";
	std::cout << "2 : 아니오\n";
	std::cout << "----------------" << std::endl;
}
//상점에 나갔을 때 메시지를 출력하는 함수
void ShowExitShop()
{
	std::cout << "상점에서 나왔습니다\n";
}