#pragma once
#include <string>

// 인터페이스 [1]
// 전투 시스템을 위한 인터페이스, Actor

// Character와 Monster의 공통 부분을 모아서 만든 클래스
// 이제 전투 시스템은 Actor와 Actor 사이에서 일어나는 일이 되었으므로
// 전투 시스템을 구현하는 사람은, Monster와 Character의 구체적인 구현 내용을 알지 않아도 된다.
// 
// 예를 들어,
// Character가 스킬을 가지고 있어도, 전투 시스템을 구현한 사람은 'Attack()'만 호출하면 된다.
// Monster가 방어력을 가지고 있어도, 전투 시스템을 구현한 사람은 'TakeDamage()'만 호출하면 된다.
// Actor를 수정해야 할 일이 있다면, 그건 기획이 Actor 구현에 반영되지 못한 것이다.

class Actor {
public:
	Actor(std::string name, int health, int attack) : name(name), health(health), attack(attack) {}
	virtual void Attack(Actor& other) = 0;
	virtual void TakeDamage(int damage) = 0;
	std::string GetName() {	return name; }
	int GetHealth() { return health; }
	int GetAttack() { return attack; }

protected:
	std::string name;
	int health;
	int attack;
};