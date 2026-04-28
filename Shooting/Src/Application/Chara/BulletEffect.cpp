#include"BulletEffect.h"
#include"../Scene.h"

void C_BulletEffect::Init()
{

	BulletEffect.m_pos.x = 0;
	BulletEffect.m_pos.y = 0;

	BulletEffect.m_move.x = 0;
	BulletEffect.m_move.y = 0;

	BulletEffect.m_size = 1.0f;

	BulletEffect.m_color = {1, 1, 1, 1};

	BulletEffect.m_rect = { 0,0,16,16 };

	BulletEffect.m_lifespan = 0;

	BulletEffect.m_bRepeat = false;
}

void C_BulletEffect::Update(Math::Vector2 a_pos, bool a_move)
{
	BulletEffect.m_lifespan--;

	if (BulletEffect.m_lifespan <= 0)
	{
		if (!BulletEffect.m_bRepeat)return;
		if (a_move)
		{
			Emit({ a_pos.x,a_pos.y },
				{ Rnd() * 6 - 3, Rnd() * 6 - 3 },
				Rnd() * 6 - 3, { 0,0.58f,1,0.3f }, 100, true);
		}
	}

	//位置更新
	BulletEffect.m_move *= 1.005f;
	BulletEffect.m_pos += BulletEffect.m_move;
	if (BulletEffect.m_pos.y >= 360)BulletEffect.m_move.y *= -1;
	if (BulletEffect.m_pos.y <= -360)BulletEffect.m_move.y *= -1;
	if (BulletEffect.m_pos.x >= 640)BulletEffect.m_move.x *= -1;
	if (BulletEffect.m_pos.x <= -640)BulletEffect.m_move.x *= -1;

	//徐々に小さくなる
	BulletEffect.m_size *= 0.9f;
	
	Math::Matrix scaleMat = Math::Matrix::CreateScale(BulletEffect.m_size);
	Math::Matrix transMat = Math::Matrix::CreateTranslation(BulletEffect.m_pos.x, BulletEffect.m_pos.y, 0);
	BulletEffect.m_mat = scaleMat * transMat;
}

void C_BulletEffect::Draw()
{
	SHADER.m_spriteShader.SetMatrix(BulletEffect.m_mat);
	SHADER.m_spriteShader.DrawTex(BulletEffect.m_tex, 0, 0, &BulletEffect.m_rect, &BulletEffect.m_color);
}

float C_BulletEffect::Rnd()
{
	return rand() / (float)RAND_MAX;
}

void C_BulletEffect::Emit(Math::Vector2 a_pos, Math::Vector2 a_move, float a_size, Math::Color a_color, int a_lifeapan, bool a_bRepeat)
{
	BulletEffect.m_pos = a_pos;
	BulletEffect.m_move = a_move;
	BulletEffect.m_size = a_size;
	BulletEffect.m_color = a_color;
	BulletEffect.m_lifespan = a_lifeapan;
	BulletEffect.m_bRepeat = a_bRepeat;
}

