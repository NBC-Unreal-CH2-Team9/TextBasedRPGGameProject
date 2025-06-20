﻿#pragma once

#include "../Types/Character/Character.h"

struct BattleResult {
public:
	bool isWin;
	bool isBoss;
};

class GameManager {

public:
	GameManager();
	~GameManager();

	/* 필요하면 return type 추가 */
	void CreateCharacter(/*필요하면 parameter 추가*/);

	/* 필요하면 return type 변경 */
	BattleResult Battle(/*필요하면 parameter 추가*/);

	void Shop();
	void ShopBuy();
	void ShopSell();

	Character* GetCharacter() {
		return character;
	}

protected:
	Character* character;

private:
	static const std::string shopMessage;
	static const std::vector<std::string> shopPrompt;
};