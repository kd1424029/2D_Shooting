#include"Enemy.h"
#include"../Scene.h"

void C_Enemy::Stage1Init()
{

	m_EnemyList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> EnemyPosList = {
	{0.0f,-316},
	};

	Math::Vector2 m_pos1 = EnemyPosList[0];

	Param newBlock;

	newBlock.m_pos = { m_pos1.x , m_pos1.y };

	newBlock.m_rect = { 0,0,64,64 };

	newBlock.m_move.x = 1;   //移動スピード
	newBlock.m_move.y = 1;   //移動スピード

	newBlock.m_radius.x = 32;
	newBlock.m_radius.y = 32;

	newBlock.m_MoveState = 0;

	newBlock.m_alive = true;
	newBlock.m_tex = Enemy.m_tex;

	m_EnemyList.push_back(newBlock);
	
}

void C_Enemy::Stage2Init()
{
	m_EnemyList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> EnemyPosList = {
	{0.0f,-316},
	{-371,0.0f},
	};

	Math::Vector2 m_pos1 = EnemyPosList[0];

	Param newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };

	newBlock.m_rect = { 0,0,64,64 };

	newBlock.m_move.x = 1;   //移動スピード
	newBlock.m_move.y = 1;   //移動スピード

	newBlock.m_MoveState = 0;

	newBlock.m_alive = true;

	newBlock.m_tex = Enemy.m_tex;

	m_EnemyList.push_back(newBlock);


	Math::Vector2 m_pos2 = EnemyPosList[1];

	Param newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };

	newBlock2.m_rect = { 64,0,64,64 };

	newBlock2.m_move.x = 2;   //移動スピード
	newBlock2.m_move.y = 2;   //移動スピード

	newBlock2.m_MoveState = 0;

	newBlock2.m_alive = true;

	newBlock2.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock2);

}

void C_Enemy::Stage1Action()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	C_Player* player = SCENE.GetPlayer();

	if (gameScreen->GetGameStartFlg() == true && gameScreen->GetGameOverFlg() == false && player->GetAlive() == true)
	{

		for (auto& enemy : m_EnemyList)
		{

			switch (enemy.m_MoveState)
			{

			case 0: //右移動

				if (enemy.m_pos.x < 50)
				{
					enemy.m_pos.x += enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //左移動

				if (enemy.m_pos.x > -50)
				{
					enemy.m_pos.x -= enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 0;
				}
				break;
			}
		}
	}
}

void C_Enemy::Stage2Action()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	C_Player* player = SCENE.GetPlayer();

	if (gameScreen->GetGameStartFlg() == true && gameScreen->GetGameOverFlg() == false && player->GetAlive() == true)
	{

		for (int i = 0;i < m_EnemyList.size(); i++)
		{
			auto& enemy = m_EnemyList[i];

			if (i == 0)
			{
				switch (enemy.m_MoveState)
				{

				case 0: //右移動

					if (enemy.m_pos.x < 50)
					{
						enemy.m_pos.x += enemy.m_move.x;
					}
					else
					{
						enemy.m_MoveState = 1;
					}
					break;

				case 1:  //左移動

					if (enemy.m_pos.x > -50)
					{
						enemy.m_pos.x -= enemy.m_move.x;
					}
					else
					{
						enemy.m_MoveState = 0;
					}
					break;
				}
			}

			if (i == 1)
			{
				switch (enemy.m_MoveState)
				{

				case 0: //上移動

					if (enemy.m_pos.y < 50)
					{
						enemy.m_pos.y += enemy.m_move.y;
					}
					else
					{
						enemy.m_MoveState = 1;
					}
					break;

				case 1:  //下移動

					if (enemy.m_pos.y > -50)
					{
						enemy.m_pos.y -= enemy.m_move.y;
					}
					else
					{
						enemy.m_MoveState = 0;
					}
					break;
				}
			}
		}
	}
}

void C_Enemy::Update()
{
	for (auto& enemy : m_EnemyList)
	{
		if (enemy.m_alive == true)
		{
			enemy.m_transMat = Math::Matrix::CreateTranslation(enemy.m_pos.x, enemy.m_pos.y, 0);
			enemy.m_mat = enemy.m_transMat;
		}
	}
}

void C_Enemy::Draw()
{
	for (auto& enemy : m_EnemyList)
	{
		if (enemy.m_alive == true)
		{
			SHADER.m_spriteShader.SetMatrix(enemy.m_mat);
			SHADER.m_spriteShader.DrawTex(enemy.m_tex, enemy.m_rect, 1.0f);
		}
	}
}