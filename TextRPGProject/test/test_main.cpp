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
    
        if (dragon->GetMaxHealth() / 3 > dragon->GetHealth())
        {
            std::cout << "체력 절반!!!!!" << std::endl;
            std::cout << dragon->GetAttack() << std::endl;
            std::cout << mon->GetAttack() << std::endl;
        }
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
    AttackBoost atkBoost15(15);     // 공격력 15 증가

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
    Character* character = gameManager.GetCharacter();

    // 장비 생성
    Sword* sword1 = new Sword("나무검");
    Sword* sword2 = new Sword("청동검");
    Sword* sword3 = new Sword("철검");

    Armor* armor1 = new Armor("가죽갑옷");
    Armor* armor2 = new Armor("청동갑옷");
    Armor* armor3 = new Armor("철갑옷");

    // 테스트 1, 2: 장비 기본 스탯 및 가격 출력
    std::cout << "\n[장비 가격 및 스탯]" << std::endl;
    std::cout << sword1->GetName() << " - 공격력: " << sword1->GetStat() << ", 가격: " << sword1->GetPrice() << std::endl;
    std::cout << sword2->GetName() << " - 공격력: " << sword2->GetStat() << ", 가격: " << sword2->GetPrice() << std::endl;
    std::cout << sword3->GetName() << " - 공격력: " << sword3->GetStat() << ", 가격: " << sword3->GetPrice() << std::endl;
    std::cout << armor1->GetName() << " - 체력: " << armor1->GetStat() << ", 가격: " << armor1->GetPrice() << std::endl;
    std::cout << armor2->GetName() << " - 체력: " << armor2->GetStat() << ", 가격: " << armor2->GetPrice() << std::endl;
    std::cout << armor3->GetName() << " - 체력: " << armor3->GetStat() << ", 가격: " << armor3->GetPrice() << std::endl;

    // 테스트 3: 초기 장비 장착 전 상태
    std::cout << "\n[초기 장비 장착 전]" << std::endl;
    std::cout << "공격력: " << character->GetAttack()
        << ", 체력: " << character->GetHealth()
        << ", 최대 체력: " << character->GetMaxHealth() << std::endl;

    // 나무검, 가죽갑옷 장착
    character->Equip(sword1);
    character->Equip(armor1);

    std::cout << "\n[초기 장비 장착 후]" << std::endl;
    std::cout << "공격력: " << character->GetAttack()
        << ", 체력: " << character->GetHealth()
        << ", 최대 체력: " << character->GetMaxHealth() << std::endl;

    // 테스트 4, 7: 더 좋은 무기와 갑옷으로 교체
    std::cout << "\n[더 좋은 장비 장착]" << std::endl;
    character->Equip(sword2);
    character->Equip(armor2);

    std::cout << "공격력: " << character->GetAttack()
        << ", 체력: " << character->GetHealth()
        << ", 최대 체력: " << character->GetMaxHealth() << std::endl;

    // 테스트 5: 인벤토리 아이템 출력
    std::cout << "\n[인벤토리 목록]" << std::endl;
    auto items = character->GetEquipmentInventory()->GetItems();
    for (auto item : items) {
        std::cout << "- " << item->GetName() << " (가격: " << item->GetPrice() << ")" << std::endl;
    }
    std::cout << "인벤토리 총 개수: " << character->GetEquipmentInventory()->Count() << std::endl;

    // 테스트 6: 성능이 낮은 장비 다시 획득 및 장착 시도
    std::cout << "\n[낮은 성능 장비 획득 및 장착 시도]" << std::endl;
    character->Equip(sword1);
    character->Equip(new Armor("가죽갑옷"));

    std::cout << "공격력: " << character->GetAttack()
        << ", 체력: " << character->GetHealth()
        << ", 최대 체력: " << character->GetMaxHealth() << std::endl;

    // 최종 인벤토리 출력
    std::cout << "\n[최종 인벤토리 목록]" << std::endl;
    items = character->GetEquipmentInventory()->GetItems();
    for (auto item : items) {
        std::cout << "- " << item->GetName() << " (가격: " << item->GetPrice() << ")" << std::endl;
    }
    std::cout << "인벤토리 총 개수: " << character->GetEquipmentInventory()->Count() << std::endl;
}


void dropTest() {
    GameManager gameManager;
    gameManager.CreateCharacter();
    // 캐릭터 생성
    Character* character = gameManager.GetCharacter();

    std::cout << "\n[초기 스텟]" << std::endl;
    std::cout << "현재 공격력: " << character->GetAttack() << " 체력 : " << character->GetHealth() << std::endl;

    std::cout << "\n[인벤토리 목록 출력]" << std::endl;
    auto items = character->GetEquipmentInventory()->GetItems();
    for (auto item : items) {
        if (item->GetType() == Equipment::SWORD)
            std::cout << "- [무기] " << item->GetName() << " (공격력: " << item->GetStat() << ", 가격: " << item->GetPrice() << ")" << std::endl;
        else if (item->GetType() == Equipment::ARMOR)
            std::cout << "- [방어구] " << item->GetName() << " (체력: " << item->GetStat() << ", 가격: " << item->GetPrice() << ")" << std::endl;
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
        if (item->GetType() == Equipment::SWORD)
            std::cout << "- [무기] " << item->GetName() << " (공격력: " << item->GetStat() << ", 가격: " << item->GetPrice() << ")" << std::endl;
        else if (item->GetType() == Equipment::ARMOR)
            std::cout << "- [방어구] " << item->GetName() << " (체력: " << item->GetStat() << ", 가격: " << item->GetPrice() << ")" << std::endl;
    }

}


int main() {
    testMonster();
}
