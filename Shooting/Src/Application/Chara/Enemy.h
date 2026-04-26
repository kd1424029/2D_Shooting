#pragma once
#include <vector>
#include"CharaBase.h"

using namespace std;

class C_Enemy : public C_CharaBase
{
public:

	C_Enemy() {}
	~C_Enemy() {}

	void Stage1Init();
	void Stage2Init();
	void Stage3Init();
	void Stage4Init();

	void Stage1Action();
	void Stage2Action();
	void Stage3Action();
	void Stage4Action();

	void Update();

	void Draw();

	//=========== ゲッター =================
	Param* GetParam() { return &Enemy; }
	vector<Param>& GetEnemyList() { return m_EnemyList; }
	Math::Vector2 GetPos() { return Enemy.m_pos; }
	Math::Vector2 GetRadius() { return Enemy.m_radius; }
	bool GetAlive() { return Enemy.m_alive; }

	// 現在生きている敵の数を返す
	int GetAliveCount() {int count = 0;for (const auto& e : m_EnemyList) {if (e.m_alive) count++;}return count;}
	
	//=========== セッター =================
	void SetTex(KdTexture* tex) { Enemy.m_tex = tex; }
	void SetAlive(bool alive) { Enemy.m_alive = alive; }

private:

	vector<Param> m_EnemyList;

	int MoveState;   //移動パターン　 // 0:右移動, 1:左移動
};