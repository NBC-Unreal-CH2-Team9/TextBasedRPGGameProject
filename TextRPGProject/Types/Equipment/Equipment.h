#pragma once
#include <string>

class Equipment {
public:
	Equipment(std::string name, int pirce) : name(name), price(pirce) {};
	int GetPrice() {
		return price;
	}
	std::string GetName() {
		return name;
	}

	// 장비 타입 추가
	enum EquipmentType{
		SWORD = 100,
		ARMOR = 200
	};

	// 각 장비가 가지고 있는 주요 스탯 반환. 검: 공격력, 갑옷: 체력
	virtual int GetStat() = 0;

	// 각 장비가 형태 반환. 장비 얻었을 때 자동 장착 시 필요.
	virtual EquipmentType GetType() = 0;


protected:
	std::string name;
	int price;
};

