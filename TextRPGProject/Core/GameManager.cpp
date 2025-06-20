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
	//���� ����
	monsters[4] = { new Goblin("Goblin",200,100),new Orc("Orc",300,110),new Troll("Troll",400,120),new Slime("Slime",500,130)};
	isMyTurn = true;

	//���� ���� ����(����,���� ���ݷ�,���� ü��)
	std::random_device rd;                // 1) �ϵ���� ���� �õ�
	std::mt19937 gen(rd());               // 2) ��� ����
	std::uniform_int_distribution<> monsterSizeRange(0, 3);
	std::uniform_int_distribution<> monsterHealthRange(20, 30);
	std::uniform_int_distribution<> monsterAttackRange(5, 10);

	monsterNum = monsterSizeRange(gen);
	totalMonsterHealth = characterLevel * monsterHealthRange(gen);
	totalMonsterAttack = characterLevel * monsterAttackRange(gen);

	std::cout << "���� " << monsters[monsterNum]->GetName() << " ����!";
	std::cout<<"ü��:" << totalMonsterHealth	<< ", ���ݷ� : " << totalMonsterAttack <<"\n";

}

BattleResult GameManager::Battle()
{
	// �ʼ� ��� [3]
	// ���� �ý���
	// ĳ���� ���� ����, �׸��� ���� �湮(�Ǵ� ��ŵ) ����

	// �ʼ� ��� [4]
	// ���� ����

	//���� ����
	//GenerateMonster(character->GetLevel());
	
	//�׽�Ʈ��
	GenerateMonster(2);

	BattleResult result;
	result.isWin = false;
	result.isBoss = false;

	isMyTurn = true;
	isFighting = true;

	//���� ����
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
	std::cout << attacker->GetName() << "�� " << defender->GetName() << "�� �����մϴ�! ";

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
		std::cout << defender->GetName() << " óġ!\n";
		isFighting = false;
	}
	else
	{
		std::cout << defender->GetName() << " ü��:" << defender->GetHealth() << "\n";
	}

	isMyTurn = !isMyTurn;
}
