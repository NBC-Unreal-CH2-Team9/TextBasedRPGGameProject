#include "ConsoleOutput.h"
#include <iostream>
#include <vector>
#include <windows.h>


void ConsoleOutput::SetColor(Color backgroundColor, Color textColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (handle != nullptr) {
		SetConsoleTextAttribute(handle, (backgroundColor << 4) + textColor);
	}
}

void ConsoleOutput::SetTextColor(Color textColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (handle != nullptr) {
		SetConsoleTextAttribute(handle, (Color::BLACK << 4) + textColor);
	}
}


void ConsoleOutput::ResetColor()
{
	SetColor(Color::BLACK, Color::DRAK_WHITE);
}

void ConsoleOutput::PrintBox(std::string text, int length, Color boxColor)
{
	std::string border(length, '=');
	SetTextColor(boxColor);
	std::cout << border << "\n";
	std::cout << "| ";
	ResetColor();
	std::cout << text;
	SetTextColor(boxColor);
	std::cout << " |" << "\n";
	std::cout << border << "\n";
	ResetColor();
}

void ConsoleOutput::PrintProgressBar(int value, int max)
{
	int length = 10;
	int fill = value * length / max;
	int empty = length - fill;
	if (value < 0) {
		fill = 0;
		empty = 10;
	}
	
	ResetColor();
	std::cout << "[";
	SetColor(Color::GRAY, Color::GRAY);
	for (int n = 0; n < fill; n++) {
		std::cout << "|";
	}
	ResetColor();
	for (int n = 0; n < empty; n++) {
		std::cout << "-";
	}
	std::cout << "]";
}

void ConsoleOutput::ShowIntro()
{
	// usVng https://patorjk.com/software/taag/#p=dVsplay&h=0&v=0&f=BVg%20Money-ne&t=TextRPG
	SetColor(Color::BLACK, Color::SKY);
	std::cout << " /$$$$$$$$                       /$$     /$$$$$$$  /$$$$$$$   /$$$$$$\n"; Sleep(100);
	std::cout << "|__  $$__/                      | $$    | $$__  $$| $$__  $$ /$$__  $$\n"; Sleep(100);
	SetColor(Color::BLACK, Color::WHITE);
	std::cout << "   | $$     /$$$$$$  /$$   /$$ /$$$$$$  | $$  V $$| $$  V $$| $$  V__/\n"; Sleep(100);
	std::cout << "   | $$    /$$__  $$|  $$ /$$/|_  $$_/  | $$$$$$$/| $$$$$$$/| $$ /$$$$\n"; Sleep(100);
	std::cout << "   | $$   | $$$$$$$$ V  $$$$/   | $$    | $$__  $$| $$____/ | $$|_  $$\n"; Sleep(100);
	SetColor(Color::BLACK, Color::GRAY);
	std::cout << "   | $$   | $$_____/  >$$  $$   | $$ /$$| $$  V $$| $$      | $$  V $$\n"; Sleep(100);
	std::cout << "   | $$   |  $$$$$$$ /$$/V  $$  |  $$$$/| $$  | $$| $$      |  $$$$$$/\n"; Sleep(100);
	std::cout << "   |__/    V_______/|__/  V__/   V___/  |__/  |__/|__/       V______/\n\n"; Sleep(100);

	ResetColor();
	
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

	std::cout << "               - 만든 사람들 -               \n\n"; Sleep(500);
	std::cout << "         팀장 및 캐릭터 개발: 오동률         \n"; Sleep(800);
	std::cout << "   코드 리뷰, 출력, 상점 로직 개발: 최대근   \n"; Sleep(800);
	std::cout << "          몬스터 클래스 개발: 김효영         \n"; Sleep(800);
	std::cout << "          아이템 클래스 개발: 서정원         \n"; Sleep(800);
	std::cout << "            전투 로직 개발: 송우진           \n"; Sleep(800);
	std::cout << "            출력 관련 개발: 이서영           \n"; Sleep(800);
	std::cout << "\n";
}

void ConsoleOutput::ShowCreateCharacterIntro()
{
	PrintBox("캐릭터 생성 단계", 20, Color::SKY);
}

void ConsoleOutput::ShowBattleStart()
{
	PrintBox("      전투      ", 20, Color::DRAK_RED);
}

void ConsoleOutput::ShowShopStart()
{
	PrintBox("      상점      ", 20, Color::DRAK_ORANGE);
}

void ConsoleOutput::ShowCreateCharacterName()
{
	std::cout << "캐릭터 이름을 입력하세요 : ";
}

void ConsoleOutput::ShowSelectJob()
{
	std::cout << "캐릭터 직업을 선택하세요.\n";
}

void ConsoleOutput::ShowCharacterStatus(Character& character) {
	std::cout << "--캐릭터 현재 상태--\n";
	std::cout << "정보: " << character.GetName() << ", 레벨 " << character.GetLevel() << " " << character.GetJobName() << "\n";
	std::cout << "체력: " << character.GetHealth() << "/" << character.GetMaxHealth() << "\n";
	std::cout << "공격력: " << character.GetAttack() << "\n";
	std::cout << "경험치: " << character.GetExperience() << "/100 " << "\n";
	std::cout << "----------------\n";
}

void ConsoleOutput::ShowCharacterGoldAndItem(Character& character) {
	std::cout << "--캐릭터 소지품 정보--\n";
	std::cout << "현재 골드: " << character.GetGold() << "\n";
	std::cout << "아이템: ";
	std::vector<Item*> items = character.GetItemInventory()->GetItems();
	for (int n = 0; n < items.size(); n++) {
		std::cout << items[n]->GetName() ;
		if (n < items.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "\n";
	if (character.GetSword() != nullptr) {
		std::cout << "무기: " << character.GetSword()->GetName() << "\n";
	}
	if (character.GetArmor() != nullptr) {
		std::cout << "방어구: " << character.GetArmor()->GetName() << "\n";
	}
	std::cout << "----------------------\n";
}

void ConsoleOutput::ShowLevelUp(Character& character)
{
	std::cout << character.GetName() << "는/은 레벨업했다!\n";
	std::cout << "체력과 공격력이 상승했으며, 체력이 전부 회복되었다!\n";
}

void ConsoleOutput::ShowMonsterStatus(Monster& monster, bool isBoss) {
	if (isBoss) {
		std::cout << "--보스 몬스터 등장!!!--\n";
	}
	else {
		std::cout << "--몬스터 등장--\n";
	}
	std::cout << "이름: " << monster.GetName() << "\n";
	std::cout << "체력: " << monster.GetHealth() << "\n";
	std::cout << "공격력: " << monster.GetAttack() << "\n";
	std::cout << "----------------\n";
}

void ConsoleOutput::ShowAttackMessage(Actor& attacker, Actor& target) {
	std::cout << attacker.GetName() << "이(가) " << target.GetName() << "을(를) 공격합니다!\n";
}

void ConsoleOutput::ShowDamageMessage(Actor& who, int damage) {
	std::cout << who.GetName() << "이(가) " << damage << "의 데미지를 입습니다.\n";
}

void ConsoleOutput::ShowCriticalHit()
{
	SetTextColor(Color::PINK);
	std::cout << "크리티컬!!\n";
	ResetColor();
}

void ConsoleOutput::ShowCharacterTurn()
{
	SetTextColor(Color::GREEN);
	std::cout << "<캐릭터의 턴>\n";
	ResetColor();
}

void ConsoleOutput::ShowMonsterTurn()
{
	SetTextColor(Color::RED);
	std::cout << "<몬스터의 턴>\n";
	ResetColor();
}

void ConsoleOutput::ShowBattleProgress(Character& character, Monster& monster)
{
	std::cout << "HP:";
	PrintProgressBar(character.GetHealth(), character.GetMaxHealth());
	std::cout << character.GetName() << "\n";

	std::cout << "HP:";
	PrintProgressBar(monster.GetHealth(), monster.GetMaxHealth());
	std::cout << monster.GetName() << "\n";
	std::cout << "\n";
}

void ConsoleOutput::ShowUseHealthPotion(Character& character, HealthPotion& potion)
{
	std::cout << character.GetName() << "은/는 체력이 절반이 되어, 포션을 사용하였습니다!\n";
	std::cout << "현재 체력: " << character.GetHealth() << "(+" << potion.GetHealthRestore() << ")\n";
}

void ConsoleOutput::ShowUseAttackBoost(Character& character, AttackBoost& boost)
{
	std::cout << character.GetName() << "은/는 공격력 강화 아이템을 사용했습니다!\n";
	std::cout << "현재 공격력: " << character.GetAttack() << "(+" << boost.GetAttackincrease() << ")\n";
}

void ConsoleOutput::ShowUseItem(Character& character, Item& item)
{
	std::cout << character.GetName() << "이/가" << item.GetName() << "을 사용하였습니다.\n";
}

void ConsoleOutput::ShowDropEquip(Equipment& equip)
{
	std::cout << "장비 " << equip.GetName() << "을/를 얻었습니다!\n";
}

void ConsoleOutput::ShowDropItem(Item& item)
{
	std::cout << "아이템 " << item.GetName() << "을/를 얻었습니다!\n";
}

void ConsoleOutput::ShowDieMonster() {
	std::cout << "몬스터를 처치했습니다! 전투에서 승리하셨습니다.\n";
}

void ConsoleOutput::ShowBattleWin()
{
	SetTextColor(Color::SKY);
	std::cout << "<전투 결과>\n";
	ResetColor();
	std::cout << "전투에서 승리했습니다!\n";
}

void ConsoleOutput::ShowBattleDefeat()
{
	std::cout << "<전투 결과>\n전투에서 패배했습니다...\n";
}

void ConsoleOutput::ShowGetGold(Character& character, Monster& monster)
{
	std::cout << monster.GetName() << "으로부터 골드를 획득했습니다.\n";
	ShowCharacterGoldChange(character, monster.GetGold());
}

void ConsoleOutput::ShowGetExp(Character& character, Monster& monster)
{
	std::cout << monster.GetName() << "으로부터 경험치 " << monster.GetExperience() <<"를 획득했습니다.\n";
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
	std::cout << "소지 골드: ";
	SetTextColor(Color::YELLOW);
	std::cout << character.GetGold();
	ResetColor();
	
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
