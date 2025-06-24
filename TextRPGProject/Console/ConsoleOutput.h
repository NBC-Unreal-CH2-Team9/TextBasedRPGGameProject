#pragma once
#include "../Types/Character/Character.h"
#include "../Types/Actor.h"
#include "../Types/Monster/Monster.h"

#include "../Types/Item/Item.h"
#include "../Types/Item/AttackBoost.h"
#include "../Types/Item/HealthPotion.h"


class ConsoleOutput
{
public:
	// 인트로, 아웃트로
	static void ShowIntro();
	static void ShowCredit();

	//캐릭터 생성
	static void ShowCreateCharacterIntro();
	static void ShowCreateCharacterName();
	static void ShowSelectJob();

	
	// 캐릭터 상태 
	static void ShowCharacterStatus(Character& Character);
	static void ShowCharacterGoldAndItem(Character& character);
	static void ShowLevelUp(Character& character);

	
	// 몬스터 상태
	static void ShowMonsterStatus(Monster& monster, bool isBoos);

	
	// 공격과 피해, 크리티컬, 전투
	static void ShowBattleStart();
	static void ShowAttackMessage(Actor& attacker, Actor& target);
	static void ShowDamageMessage(Actor& who, int damage);
	static void ShowCriticalHit();
	static void ShowCharacterTurn();
	static void ShowMonsterTurn();

	static void ShowBattleProgress(Character& character, Monster& monster);

	// 아이템 사용
	static void ShowUseHealthPotion(Character& character, HealthPotion& potion);
	static void ShowUseAttackBoost(Character& character, AttackBoost& boost);
	static void ShowUseItem(Character& character, Item& item);

	
	// 몬스터 사망
	static void ShowDieMonster();

	
	// 승리 시 아이템, 경험치 획득
	static void ShowBattleWin();
	static void ShowBattleDefeat();
	static void ShowGetGold(Character& character, Monster& monster);
	static void ShowGetExp(Character& character, Monster& monster);

	
	// 상점
	static const std::string shopQuestion;
	static const std::vector<std::string> shopOptions;

	static void ShowShopStart();
	static void ShowEnterShop();
	static void ShowSkipShop();
	static void ShowExitShop();
	static void ShowNoItemToSell();
	static void ShowNotEnoughGold();
	static void ShowCharacterGoldChange(Character& character, int change);

	static std::vector<std::string> MakeShopBuyList(std::vector<Item*> list);
	static std::vector<std::string> MakeShopSellList(std::vector<Item*> list, float ratio = 0.6f);

	static void ShowBuyItem(Item& item, Character& character);
	static void ShowSellItem(Item& item, Character& character, float ratio);
	static void ShowSellEquipment(Equipment& equipment, Character& character, float ratio);

private:
	enum Color {
		BLACK,
		DRAK_BLUE,
		DRAK_GREEN,
		DRAK_SKY,
		DRAK_RED,
		DRAK_PINK,
		DRAK_ORANGE,
		DRAK_WHITE,
		GRAY,
		BLUE,
		GREEN,
		SKY,
		RED,
		PINK,
		YELLOW,
		WHITE
	};

	static void SetColor(Color backgroundColor, Color textColor); 
	static void SetTextColor(Color textColor);
	static void ResetColor();


	static void PrintBox(std::string text, int length, Color boxColor);
	static void PrintProgressBar(int value, int max);
};
