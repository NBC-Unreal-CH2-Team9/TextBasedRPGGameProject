#include "Character.h"
#include "Inventory.h"
#include <iostream>

void Character::Attack(Actor& other)
{	
	other.TakeDamage(attack);	
}

void Character::TakeDamage(int damage)
{
	health -= damage;	
	// hp가 10이하로 떨어지는 경우 랜덤하게 아이템 사용
	if (health > 0 && health <= 10) {
		UseRandomItem();
	}
}

void Character::DisplayStatus()
{
	std::cout << "==Status==" << std::endl;
	std::cout << "name:" << name << std::endl;
	std::cout << "level:" << level << std::endl;
	std::cout << "experience:" << experience << std::endl;
	std::cout << "health:" << health << std::endl;
	std::cout << "maxHealth:" << maxHealth << std::endl;
	std::cout << "attack:" << attack << std::endl;	
}

void Character::LevelUp()
{	
	if (level < 10) {
		level++;
		std::cout << "Level Up!" << std::endl;		
		OnLevelChangedHealth();
		OnLevelChangedAttack();
	}	
}

void Character::OnLevelChangedHealth() {}

void Character::OnLevelChangedAttack() {}

void Character::AddExperience(int exp)
{
	int newExp = experience + exp; // 현재 경험치 + 추가 경험치
	if(newExp >= 100) {		
		LevelUp();
		experience = 0; // 레벨업 후 경험치를 초기화
	}
}

void Character::UseRandomItem()
{
	// TODO: 랜덤하게 아이템 사용
	std::vector<Item*> items = itemInventory.GetItems();
}

void Character::GetRandomItem(Item* item)
{
	itemInventory.Insert(item);
}

void Character::EquipSword(Sword* newSword)
{	//기존 검이 없거나 새로 얻은 검이 더 좋을 때
	if (equipSword == nullptr || newSword->GetStat() > equipSword->GetStat()) {
		//기존 검을 장비 인벤토리에 넣기.
		if (equipSword != nullptr) {
			int newAttack = attack - equipSword->GetStat();
			SetAttack(newAttack);
			equipmentInventory.Insert(new Sword(*equipSword));  // 복사본 삽입
		}

		equipSword = newSword;
		int newAttack = attack + equipSword->GetStat();
		SetAttack(newAttack);
	}
	//새로 얻은 검을 장비 인벤토리에 넣기.
	else {
		equipmentInventory.Insert(new Sword(*newSword));  // 복사본 삽입
	}

}

void Character::EquipArmor(Armor* newArmor)
{
	if (equipArmor == nullptr || newArmor->GetStat() > equipArmor->GetStat())
	{
		// 기존 갑옷이 있다면 인벤토리에 추가
		if (equipArmor != nullptr) {
			equipmentInventory.Insert(new Armor(*equipArmor));  // 복사본 삽입
		}

		equipArmor = newArmor;

		// 최대 체력 재계산: 기본 maxHealth + 갑옷 스탯
		int newMaxHealth = maxHealth + equipArmor->GetStat();
		SetHealth(newMaxHealth);

		// 현재 체력은 최대 체력 이하로 조정 가능 (옵션)
		if (GetHealth() > newMaxHealth)
			SetHealth(newMaxHealth);
	}
	else
	{
		// 새 갑옷 인벤토리에 복사본 삽입
		equipmentInventory.Insert(new Armor(*newArmor));
	}
}


//새로운 장비를 얻을 때 실행. 검인지 갑옷인지 판단 후 위 함수 실행
void Character::Equip(Equipment* newEquip) {
	std::string type = newEquip->GetType();

	if (type == "Sword") {
		EquipSword(dynamic_cast<Sword*>(newEquip));
	}
	else if (type == "Armor") {
		EquipArmor(dynamic_cast<Armor*>(newEquip));
	}
}
