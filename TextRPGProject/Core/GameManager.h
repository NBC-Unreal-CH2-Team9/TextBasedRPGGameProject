#pragma once

struct BattleResult {
public:
	bool isWin;
	bool isBoss;
};

class GameManager {

public:
	GameManager();
	~GameManager();

	/* �ʿ��ϸ� return type �߰� */
	void CreateCharacter(/*�ʿ��ϸ� parameter �߰�*/);

	/* �ʿ��ϸ� return type ���� */
	BattleResult Battle(/*�ʿ��ϸ� parameter �߰�*/);

	/* �ʿ��ϸ� return type ���� */
	void Shop(/*�ʿ��ϸ� parameter �߰�*/);
};