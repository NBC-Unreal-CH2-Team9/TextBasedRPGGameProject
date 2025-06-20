#pragma once
#include <string>

// �������̽� [1]
// ���� �ý����� ���� �������̽�, Actor

// Character�� Monster�� ���� �κ��� ��Ƽ� ���� Ŭ����
// ���� ���� �ý����� Actor�� Actor ���̿��� �Ͼ�� ���� �Ǿ����Ƿ�
// ���� �ý����� �����ϴ� �����, Monster�� Character�� ��ü���� ���� ������ ���� �ʾƵ� �ȴ�.
// 
// ���� ���,
// Character�� ��ų�� ������ �־, ���� �ý����� ������ ����� 'Attack()'�� ȣ���ϸ� �ȴ�.
// Monster�� ������ ������ �־, ���� �ý����� ������ ����� 'TakeDamage()'�� ȣ���ϸ� �ȴ�.
// Actor�� �����ؾ� �� ���� �ִٸ�, �װ� ��ȹ�� Actor ������ �ݿ����� ���� ���̴�.

class Actor {
public:
	Actor(std::string name, int health, int attack) : name(name), health(health), attack(attack) {}
	virtual void Attack(Actor& other) = 0;
	virtual void TakeDamage(int damage) = 0;

	std::string GetName() { return name; };
	int GetHealth();
	int GetAttack();

protected:
	std::string name;
	int health;
	int attack;
};