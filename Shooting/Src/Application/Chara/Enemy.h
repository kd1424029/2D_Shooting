#pragma once
#include"CharaBase.h"

class C_Enemy : public C_CharaBase
{
public:

	C_Enemy() {}
	~C_Enemy() {}

	void Stage1Init();
	void Stage2Init();

	void Stage1Action();
	void Stage2Action();

	void Stage1Update();
	void Stage2Update();

	void Stage1Draw();
	void Stage2Draw();

	//=========== ゲッター =================
	Math::Vector2 GetPos() { return Enemy.m_pos; }
	Math::Vector2 GetRadius() { return Enemy.m_radius; }
	bool GetAlive() { return Enemy.m_alive; }
	
	//=========== セッター =================
	void SetTex(KdTexture* tex) { Enemy.m_tex = tex; }
	void SetAlive(bool alive) { Enemy.m_alive = alive; }

private:

	int MoveState;   //移動パターン　 // 0:右移動, 1:左移動
};