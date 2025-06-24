#include "ConsoleOutput.h"
#include <iostream>
#include <windows.h>


void ConsoleOutput::ShowIntro()
{
	// usVng https://patorjk.com/software/taag/#p=dVsplay&h=0&v=0&f=BVg%20Money-ne&t=TextRPG
	std::cout << " /$$$$$$$$                       /$$     /$$$$$$$  /$$$$$$$   /$$$$$$\n"; Sleep(100);
	std::cout << "|__  $$__/                      | $$    | $$__  $$| $$__  $$ /$$__  $$\n"; Sleep(100);
	std::cout << "   | $$     /$$$$$$  /$$   /$$ /$$$$$$  | $$  V $$| $$  V $$| $$  V__/\n"; Sleep(100);
	std::cout << "   | $$    /$$__  $$|  $$ /$$/|_  $$_/  | $$$$$$$/| $$$$$$$/| $$ /$$$$\n"; Sleep(100);
	std::cout << "   | $$   | $$$$$$$$ V  $$$$/   | $$    | $$__  $$| $$____/ | $$|_  $$\n"; Sleep(100);
	std::cout << "   | $$   | $$_____/  >$$  $$   | $$ /$$| $$  V $$| $$      | $$  V $$\n"; Sleep(100);
	std::cout << "   | $$   |  $$$$$$$ /$$/V  $$  |  $$$$/| $$  | $$| $$      |  $$$$$$/\n"; Sleep(100);
	std::cout << "   |__/    V_______/|__/  V__/   V___/  |__/  |__/|__/       V______/\n\n"; Sleep(100);
	
	std::cout << "                                                   내일배움캠프 CH2 Team 9\n";
}

void ConsoleOutput::ShowCredit()
{
	std::cout << "_________                      .___.__   __\n"; Sleep(100);
	std::cout << "V_   ___ V _______   ____    __| _/|__|_/  |_\n"; Sleep(100);
	std::cout << "/    V  V/ V_  __ V_/ __ V  / __ | |  |V   __V\n"; Sleep(100);
	std::cout << "V     V____ |  | V/V  ___/ / /_/ | |  | |  |\n"; Sleep(100);
	std::cout << " V______  / |__|    V___  >V____ | |__| |__|\n"; Sleep(100);
	std::cout << "		V/              V/      V/\n\n\n"; Sleep(100);

	std::cout << "           - 만든 사람들 -           \n\n"; Sleep(500);
	std::cout << "     팀장 및 캐릭터 개발: 오동률     \n"; Sleep(800);
	std::cout << " 코드 리뷰 및 상점 로직 개발: 최대근 \n"; Sleep(800);
	std::cout << "      몬스터 클래스 개발: 김효영     \n"; Sleep(800);
	std::cout << "      아이템 클래스 개발: 서정원     \n"; Sleep(800);
	std::cout << "        전투 로직 개발: 송우진       \n"; Sleep(800);
	std::cout << "        출력 관련 개발: 이서영       \n"; Sleep(800);
}

void ConsoleOutput::ShowCreateCharacterIntro()
{
	std::cout << "--------------------\n";
	std::cout << "캐릭터를 생성합니다.\n";
	std::cout << "--------------------\n";
}

void ConsoleOutput::ShowCreateCharacterName()
{
	std::cout << "캐릭터 이름을 입력하세요 : ";
}

void ConsoleOutput::ShowCharacterStatus(Character& character) {
	std::cout << "--캐릭터 현재 상태--\n";
	std::cout << "이름: " << character.GetName() << "\n";
	//std::cout << "직업: " << character.GetJob() << "\n";
	std::cout << "레벨: " << character.GetLevel() << "\n";
	//std::cout << "경험치: " << character.Getexperience << "/ 100 " << "\n";
	std::cout << "체력: " << character.GetHealth() << " /  " << character.GetHealth() << "\n";
	std::cout << "공격력: " << character.GetAttack() << "\n";
	std::cout << "----------------\n";
}

void ConsoleOutput::ShowCharacterGold(Character& character) {
	std::cout << "--캐릭터 지갑--\n";
	std::cout << "현재 골드: " << character.GetGold() << "\n";
	std::cout << "----------------\n";
}

void ConsoleOutput::ShowMonsterStatus(Monster& monster) {
	std::cout << "--몬스터 현재 상태--\n";
	std::cout << "이름 : " << monster.GetName() << "\n";
	//std::cout << "레벨: " << monster.GetLevel() << "\n";
	std::cout << "체력: " << monster.GetHealth() << "\n";
	std::cout << "----------------\n";
}



void ConsoleOutput::ShowAttackMessage(Actor& attacker, Actor& target) {
	std::cout << attacker.GetName() << "이(가) " << target.GetName() << "을(를) 공격합니다!\n";
}

void ConsoleOutput::ShowDamageMessage(Actor* who, int damage) {
	std::cout << who->GetName() << "이(가) " << damage << "의 데미지를 입습니다.\n";
}

void ConsoleOutput::ShowCriticalHit()
{
	std::cout << "크리티컬!!\n";
}

void ConsoleOutput::ShowDieMonster() {
	std::cout << "몬스터를 처치했습니다! 전투에서 승리하셨습니다.\n";
}


const std::string ConsoleOutput::shopQuestion = "상점에 방문하시겠습니까?";
const std::vector<std::string> ConsoleOutput::shopOptions = { "물건 사기", "물건 팔기", "상점 나가기" };

void ConsoleOutput::ShowEnterShop()
{
	std::cout << "상점에 입장했습니다.\n";
}

void ConsoleOutput::ShowSkipShop()
{
	std::cout << "상점을 방문하지 않습니다.\n";
}

void ConsoleOutput::ShowExitShop()
{
	std::cout << "상점에서 나왔습니다\n";
}

void ConsoleOutput::ShowNoItemToSell()
{
	std::cout << "판매할 물건이 없습니다.\n";
}

void ConsoleOutput::ShowNotEnoughGold()
{
	std::cout << "골드가 모자랍니다\n";
}

void ConsoleOutput::ShowCharacterGoldChange(Character& character, int change)
{
	std::cout << "남은 골드: " << character.GetGold();
	if (change > 0) {
		std::cout << "(+" << change << ")\n";
	}
	else {
		std::cout << "(" << change << ")\n";
	}
}

std::vector<std::string> ConsoleOutput::MakeShopBuyList(std::vector<Item*> list)
{
	std::vector<std::string> options;
	for (int i = 0; i < list.size(); i++) {
		options.emplace_back(list[i]->GetName() + ", (" + std::to_string(list[i]->GetPrice()) + "골드)");
	}
	return options;
}

std::vector<std::string> ConsoleOutput::MakeShopSellList(std::vector<Item*> list, float ratio)
{
	std::vector<std::string> options;
	for (int i = 0; i < list.size(); i++) {
		int sellPrice = (int)(list[i]->GetPrice() * ratio);
		options.emplace_back(list[i]->GetName() + ", (" + std::to_string(sellPrice) + "골드)");
	}
	return options;
}

void ConsoleOutput::ShowBuyItem(Item& item, Character& character)
{
	std::cout << item.GetName() << "을/를 구매 했습니다.\n";
	ShowCharacterGoldChange(character, -1 * item.GetPrice());
}

void ConsoleOutput::ShowSellItem(Item& item, Character& character, float ratio)
{
	std::cout << item.GetName() << "을/를 판매 했습니다.\n";
	ShowCharacterGoldChange(character, (int)(item.GetPrice() * ratio));
}

void ConsoleOutput::ShowSellEquipment(Equipment& equipment, Character& character, float ratio)
{
	std::cout << equipment.GetName() << "을/를 판매 했습니다.\n";
	ShowCharacterGoldChange(character, (int)(equipment.GetPrice() * ratio));
}
