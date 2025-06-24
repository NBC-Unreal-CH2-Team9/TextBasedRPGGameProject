#include <iostream>
#include <string>

#include "../Core/GameManager.h"
#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"

#include "../Types/Item/Item.h"
#include "../Types/Item/HealthPotion.h"
#include "../Types/Item/AttackBoost.h"
#include "../Types/Equipment/Sword.h"
#include "../Types/Equipment/Armor.h"
#include "../Types/Character/Character.h"


void BattleTest() {
	GameManager gameManager;
	gameManager.CreateCharacter();

	std::string s = "Continue Battle ? ";
	while(ConsoleInput::SelectYesOrNo(s))
	{
		gameManager.Battle();
        gameManager.Shop();
	}
	
}

void testMonster()
{
	srand(time(nullptr));
	int playerLevel = 1;
	/*Monster* mon = MonsterManager::CreateGoblin(playerLevel);
	Monster* mon2 = MonsterManager::CreateSlime(playerLevel);
	Monster* bossMon = MonsterManager::CreateBoss(*mon);
	std::cout << "name: " << mon->GetName() << " health: " << mon->GetHealth() << 
		" attack: " << mon->GetAttack() << " gold: " << mon->GetGold() << 
		" experience: " << mon->GetExperience() << std::endl;
	std::cout << "name: " << bossMon->GetName() << " health: " << bossMon->GetHealth() << 
		" attack: " << bossMon->GetAttack() << " gold: " << bossMon->GetGold() << 
		" experience: " << bossMon->GetExperience() << std::endl;



	std::cout << "\n\nhealth: " << mon->GetHealth() << std::endl;
	std::cout << "health: " << bossMon->GetHealth() << std::endl;
	for (int i = 0; i < 10; i++)
	{
		
		mon->Attack(*bossMon);
		std::cout << bossMon->GetName() << "health: " << bossMon->GetHealth() << std::endl;
		bossMon->Attack(*mon);
		std::cout << mon->GetName() << "health: " << mon->GetHealth() << std::endl;
	}*/

    Monster* mon = MonsterManager::CreateOrc(playerLevel);
    Monster* dragon = MonsterManager::CreateDragon(playerLevel);
    std::cout << "name: " << mon->GetName() << " health: " << mon->GetHealth() <<
        " attack: " << mon->GetAttack() << " gold: " << mon->GetGold() <<
        " experience: " << mon->GetExperience() << std::endl;
    std::cout << "name: " << dragon->GetName() << " health: " << dragon->GetHealth() <<
        " attack: " << dragon->GetAttack() << " gold: " << dragon->GetGold() <<
        " experience: " << dragon->GetExperience() << std::endl;
	
    std::cout << "\n\nhealth: " << mon->GetHealth() << std::endl;
    std::cout << "health: " << dragon->GetHealth() << std::endl;
    for (int i = 0; i < 10; i++)
    {

        mon->Attack(*dragon);
        std::cout << dragon->GetName() << "health: " << dragon->GetHealth() << std::endl;
        dragon->Attack(*mon);
        std::cout << mon->GetName() << "health: " << mon->GetHealth() << std::endl;
    }
}

void testShop() {
	GameManager gameManager;
	gameManager.CreateCharacter();

	// 장비를 얻었다고 가정하기

	Character* character = gameManager.GetCharacter();
	//character->GetEquipmentInventory()->Insert(new Equipment("임시장비1", 10));
	//character->GetEquipmentInventory()->Insert(new Equipment("임시장비2", 30));

	gameManager.Shop();
}


void itemTest() {
    GameManager gameManager;
    gameManager.CreateCharacter();
    Character* character = gameManager.GetCharacter();
    // 아이템 생성
    HealthPotion hpPotion30(30);   // 체력 30 회복
    AttackBoost atkBoost10(10);     // 공격력 10 증가
    HealthPotion hpPotion50(50);   // 체력 50 회복
    AttackBoost atkBoost15(15);     // 공격력 10 증가

    //테스트 1, 2, 3
    std::cout << "아이템 이름과 가격, 각 증가량 확인" << std::endl;
    //std::cout << "HealthPotion 이름: " << hpPotion30.GetName() << ", 가격: " << hpPotion30.GetPrice() << ", 증가량: " << hpPotion30.GetStat() << std::endl;
    //std::cout << "AttackBoost 이름: " << atkBoost10.GetName() << ", 가격: " << atkBoost10.GetPrice() << ", 증가량: " << atkBoost10.GetStat() << std::endl;

    
    std::cout << "\n[초기 상태]" << std::endl;
    std::cout << character->GetName() << " 상태 | 체력: " << character->GetHealth() << ", 공격력: " << character->GetAttack() << std::endl;

    // 테스트 4
    std::cout << "\n체력 물약 사용" << std::endl;
    hpPotion30.Use(*character);
    std::cout << character->GetName() << " 상태 | 체력: " << character->GetHealth() << ", 공격력: " << character->GetAttack() << std::endl;

    // 테스트 5
    std::cout << "\n공격력 증가 아이템 사용" << std::endl;
    atkBoost10.Use(*character);
    std::cout << character->GetName() << " 상태 | 체력: " << character->GetHealth() << ", 공격력: " << character->GetAttack() << std::endl;

    // 테스트 6
    std::cout << "\n 회복량 다른 체력 물약 사용" << std::endl;
    hpPotion50.Use(*character);
    std::cout << character->GetName() << " 상태 | 체력: " << character->GetHealth() << ", 공격력: " << character->GetAttack() << std::endl;
    hpPotion30.Use(*character);
    std::cout << character->GetName() << " 상태 | 체력: " << character->GetHealth() << ", 공격력: " << character->GetAttack() << std::endl;


    // 테스트 7
    std::cout << "\n공격력 증가량 다른 아이템 사용" << std::endl;
    atkBoost15.Use(*character);
    std::cout << character->GetName() << " 상태 | 체력: " << character->GetHealth() << ", 공격력: " << character->GetAttack() << std::endl;
    atkBoost10.Use(*character);
    std::cout << character->GetName() << " 상태 | 체력: " << character->GetHealth() << ", 공격력: " << character->GetAttack() << std::endl;
}

void equipTest() {
    GameManager gameManager;
    gameManager.CreateCharacter();
    // 캐릭터 생성
    Character* character = gameManager.GetCharacter();

    // 장비 생성
    Sword* oldSword = new Sword("나무 검");
    Sword* newSword1 = new Sword("철검");
    Sword* newSword2 = new Sword("청동검");
    Armor* oldarmor = new Armor("청동갑옷");
    Armor* newarmor = new Armor("가죽갑옷");

    std::cout << "\n[초기 장비 장착]" << std::endl;
    character->EquipSword(oldSword);  // 낡은 검 장착
    character->EquipArmor(oldarmor);  // 갑옷 장착
    std::cout << "현재 공격력: " << character->GetAttack() << " 체력 : " << character->GetHealth() << std::endl;

    std::cout << "\n[더 좋은 무기 장착]" << std::endl;
    character->EquipSword(newSword1);  // 더 좋은 검으로 교체
    std::cout << "현재 공격력: " << character->GetAttack() << " 체력 : " << character->GetHealth() << std::endl;

    std::cout << "\n[살짝 안 좋은 장비 획득]" << std::endl;
    character->EquipSword(newSword2);
    character->EquipArmor(newarmor);   // 갑옷 장착
    std::cout << "현재 공격력: " << character->GetAttack() << " 체력 : " << character->GetHealth() << std::endl;

    std::cout << "\n[인벤토리 목록 출력]" << std::endl;
    auto items = character->GetEquipmentInventory()->GetItems();
    for (auto item : items) {
        std::cout << "- " << item->GetName() << " (가격: " << item->GetPrice() << ")" << std::endl;
    }

    // 장비 모두 판매 테스트
    std::cout << "\n[장비 모두 판매]" << std::endl;
    gameManager.Shop();

    std::cout << "\n[판매 후 인벤토리 목록]" << std::endl;
    items = character->GetEquipmentInventory()->GetItems();
    if (items.empty()) {
        std::cout << "장비 인벤토리가 비어 있습니다." << std::endl;
    }
    else {
        for (auto item : items) {
            std::cout << "- " << item->GetName() << " (가격: " << item->GetPrice() << ")" << std::endl;
        }
    }

    std::cout << "\n[현재 골드] " << character->GetGold() << std::endl;
}

static void dropTest() {
    GameManager gameManager;
    gameManager.CreateCharacter();
    // 캐릭터 생성
    Character* character = gameManager.GetCharacter();

    std::cout << "\n[초기 스텟]" << std::endl;
    std::cout << "현재 공격력: " << character->GetAttack() << " 체력 : " << character->GetHealth() << std::endl;

    std::cout << "\n[인벤토리 목록 출력]" << std::endl;
    auto items = character->GetEquipmentInventory()->GetItems();
    for (auto item : items) {
        std::cout << "- " << item->GetName() << " (가격: " << item->GetPrice() << ")" << std::endl;
    }

    gameManager.DropEquip();
    std::cout << "\n[장비 1회 드랍 후 스텟]" << std::endl;
    std::cout << "현재 공격력: " << character->GetAttack() << " 최대 체력 : " << character->GetMaxHealth() << " 현재 체력 : " << character->GetHealth() << std::endl;

    character->TakeDamage(100);

    gameManager.DropEquip();
    std::cout << "\n[장비 2회 드랍 후 스텟]" << std::endl;
    std::cout << "현재 공격력: " << character->GetAttack() << " 최대 체력 : " << character->GetMaxHealth() << " 현재 체력 : " << character->GetHealth() << std::endl;

    gameManager.DropEquip();
    std::cout << "\n[장비 3회 드랍 후 스텟]" << std::endl;
    std::cout << "현재 공격력: " << character->GetAttack() << " 최대 체력 : " << character->GetMaxHealth() << " 현재 체력 : " << character->GetHealth() << std::endl;

    std::cout << "\n[인벤토리 목록 출력]" << std::endl;
    items = character->GetEquipmentInventory()->GetItems();
    for (auto item : items) {
        std::cout << "- " << item->GetName() << " (가격: " << item->GetPrice() << ")" << std::endl;
    }
}


int main() {
    testMonster();
}
