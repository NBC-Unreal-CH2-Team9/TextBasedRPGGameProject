#include "GameManager.h"
#include <iostream>
#include "../Types/Goblin.h"
#include "../Types/Orc.h"
#include "../Types/Troll.h"
#include "../Types/Slime.h"
#include <random>

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	delete[] monsters;
}

void GameManager::CreateCharacter()
{
}

void GameManager::GenerateMonster(int characterLevel)
{
	//몬스터 생성
	monsters[4] = { new Goblin("Goblin",200,100),new Orc("Orc",300,110),new Troll("Troll",400,120),new Slime("Slime",500,130)};
	isMyTurn = true;

	//랜덤 숫자 생성(몬스터,몬스터 공격력,몬스터 체력)
	std::random_device rd;                // 1) 하드웨어 난수 시드
	std::mt19937 gen(rd());               // 2) 고속 엔진
	std::uniform_int_distribution<> monsterSizeRange(0, 3);
	std::uniform_int_distribution<> monsterHealthRange(20, 30);
	std::uniform_int_distribution<> monsterAttackRange(5, 10);

	monsterNum = monsterSizeRange(gen);
	totalMonsterHealth = characterLevel * monsterHealthRange(gen);
	totalMonsterAttack = characterLevel * monsterAttackRange(gen);

	std::cout << "몬스터 " << monsters[monsterNum]->GetName() << " 등장!";
	std::cout<<"체력:" << totalMonsterHealth	<< ", 공격력 : " << totalMonsterAttack <<"\n";

}

BattleResult GameManager::Battle()
{
	// 필수 기능 [3]
	// 전투 시스템
	// 캐릭터 생성 직후, 그리고 상점 방문(또는 스킵) 이후

	// 필수 기능 [4]
	// 몬스터 설명

	//몬스터 생성
	//GenerateMonster(character->GetLevel());
	
	//테스트용
	GenerateMonster(2);

	BattleResult result;
	result.isWin = false;
	result.isBoss = false;

	isMyTurn = true;
	isFighting = true;

	//전투 로직
	while(isFighting)
	{
		if (isMyTurn)
		{
			FightUntilDeath(character, monsters[monsterNum]);
		}
		else
		{
			FightUntilDeath(monsters[monsterNum], character);
		}
	}

	if (character->GetHealth() > 0)
	{
		result.isWin = true;
	}

	delete[] monsters;

	return result;
}

void GameManager::Shop()
{
}

void GameManager::FightUntilDeath(Actor* attacker,Actor* defender)
{
	std::cout << attacker->GetName() << "가 " << defender->GetName() << "을 공격합니다! ";

	Character* player = dynamic_cast<Character*>(defender);

	int defenderHealth;

	if (player)
	{
		defender->TakeDamage(totalMonsterAttack);
		defenderHealth = defender->GetHealth();
	}
	else
	{
		totalMonsterHealth = totalMonsterHealth - attacker->GetAttack();
		defenderHealth = totalMonsterHealth;
	}


	if (defenderHealth <= 0)
	{
		std::cout << defender->GetName() << " 처치!\n";
		isFighting = false;
	}
	else
	{
		std::cout << defender->GetName() << " 체력:" << defender->GetHealth() << "\n";
	}

	isMyTurn = !isMyTurn;
}
