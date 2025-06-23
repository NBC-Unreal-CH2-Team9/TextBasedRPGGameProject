#include <iostream>
#include <string>

#include "../Core/GameManager.h"
#include "../Console/ConsoleInput.h"
#include "../Console/ConsoleOutput.h"

#include "../Types/Item/Item.h"
#include "../Types/Equipment/Sword.h"
#include "../Types/Equipment/Armor.h"
#include "../Types/Character/Character.h"


void testBattle() {
	GameManager gameManager;
	gameManager.CreateCharacter();
	gameManager.Battle();
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


void equipTest() {
    GameManager gameManager;
    gameManager.CreateCharacter();
    // 캐릭터 생성
    Character* character = gameManager.GetCharacter();

    // 장비 생성
    Sword* oldSword = new Sword("나무 검", 1);
    Sword* newSword1 = new Sword("철검", 5);
    Sword* newSword2 = new Sword("청동검", 3);
    Armor* oldarmor = new Armor("청동갑옷", 30);
    Armor* newarmor = new Armor("가죽갑옷", 10);

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

    // 메모리 정리
    delete oldSword;
    delete newSword1;
    delete newSword2;
    delete oldarmor;
    delete newarmor;
}


int main() {
    equipTest();
}

