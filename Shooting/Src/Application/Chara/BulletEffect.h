#pragma once
#include"CharaBase.h"

class C_BulletEffect : public C_CharaBase
{
public:

	C_BulletEffect() {}
	~C_BulletEffect() {}

	void Init();

	void Action();

	void Update(Math::Vector2 a_pos, bool a_move);

	void Draw();

	float Rnd();

	void Emit(Math::Vector2 a_pos, Math::Vector2 a_move, float a_size,
		Math::Color a_color, int a_lifeapan, bool a_bRepeat);

	//=========== ゲッター =================
	

	//=========== セッター =================
	void SetTex(KdTexture* tex) { BulletEffect.m_tex = tex; }

private:

	
};