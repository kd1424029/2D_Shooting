#include"Enemy.h"
#include"../Scene.h"

void C_Enemy::Stage1Init()
{
	Enemy.m_pos.x = 0;
	Enemy.m_pos.y = -316;

	Enemy.m_move.x = 1;   //移動スピード
	Enemy.m_move.y = 1;   //移動スピード

	Enemy.m_radius.x = 32;
	Enemy.m_radius.y = 32;

	Enemy.m_rect = { 0,0,64,64 };

	Enemy.m_alive = true;

	MoveState = 0;
}

void C_Enemy::Stage2Init()
{
}

void C_Enemy::Stage1Action()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	C_Player* player = SCENE.GetPlayer();

	if (gameScreen->GetGameStartFlg() == true && gameScreen->GetGameOverFlg() == false && player->GetAlive() == true)
	{
		switch (MoveState)
		{

		case 0: //右移動

			if (Enemy.m_pos.x < 50)
			{
				Enemy.m_pos.x += Enemy.m_move.x;
			}
			else
			{
				MoveState = 1;
			}
			break;

		case 1:  //左移動

			if (Enemy.m_pos.x > -50)
			{
				Enemy.m_pos.x -= Enemy.m_move.x;
			}
			else
			{
				MoveState = 0;
			}
			break;
		}
	}
}

void C_Enemy::Stage2Action()
{
}

void C_Enemy::Stage1Update()
{
	if (Enemy.m_alive == true)
	{
		Enemy.m_transMat = Math::Matrix::CreateTranslation(Enemy.m_pos.x, Enemy.m_pos.y, 0);
		Enemy.m_mat = Enemy.m_transMat;
	}
}

void C_Enemy::Stage2Update()
{
}

void C_Enemy::Stage1Draw()
{
	if (Enemy.m_alive == true)
	{
		SHADER.m_spriteShader.SetMatrix(Enemy.m_mat);
		SHADER.m_spriteShader.DrawTex(Enemy.m_tex, Enemy.m_rect, 1.0f);
	}
}

void C_Enemy::Stage2Draw()
{
}
