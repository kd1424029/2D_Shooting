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

	newBlock.m_alpha = 1.0f;

	newBlock.m_MoveState = 0;

	newBlock.m_BulletTimer = 0;

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

	newBlock.m_radius.x = 32;
	newBlock.m_radius.y = 32;

	newBlock.m_alpha = 1.0f;

	newBlock.m_move.x = 1;   //移動スピード
	newBlock.m_move.y = 1;   //移動スピード

	newBlock.m_MoveState = 0;

	newBlock.m_BulletTimer = 0;

	newBlock.m_alive = true;

	newBlock.m_tex = Enemy.m_tex;

	m_EnemyList.push_back(newBlock);


	Math::Vector2 m_pos2 = EnemyPosList[1];

	Param newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };

	newBlock2.m_rect = { 64,0,64,64 };

	newBlock2.m_radius.x = 32;
	newBlock2.m_radius.y = 32;

	newBlock2.m_alpha = 1.0f;

	newBlock2.m_move.x = 2;   //移動スピード
	newBlock2.m_move.y = 2;   //移動スピード

	newBlock2.m_MoveState = 0;

	newBlock2.m_BulletTimer = 0;

	newBlock2.m_alive = true;

	newBlock2.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock2);

}

void C_Enemy::Stage3Init()
{
	m_EnemyList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> EnemyPosList = {
	{0.0f,-316},
	{-371,0.0f},
	{0,316.0f},
	};

	Math::Vector2 m_pos1 = EnemyPosList[0];

	Param newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };

	newBlock.m_rect = { 0,0,64,64 };

	newBlock.m_radius.x = 32;
	newBlock.m_radius.y = 32;

	newBlock.m_alpha = 1.0f;

	newBlock.m_move.x = 1;   //移動スピード
	newBlock.m_move.y = 1;   //移動スピード

	newBlock.m_MoveState = 0;

	newBlock.m_BulletTimer = 0;

	newBlock.m_alive = true;

	newBlock.m_tex = Enemy.m_tex;

	m_EnemyList.push_back(newBlock);


	Math::Vector2 m_pos2 = EnemyPosList[1];

	Param newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };

	newBlock2.m_rect = { 64,0,64,64 };

	newBlock2.m_radius.x = 32;
	newBlock2.m_radius.y = 32;

	newBlock2.m_alpha = 1.0f;

	newBlock2.m_move.x = 2;   //移動スピード
	newBlock2.m_move.y = 2;   //移動スピード

	newBlock2.m_MoveState = 0;

	newBlock2.m_BulletTimer = 0;

	newBlock2.m_alive = true;

	newBlock2.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock2);

	Math::Vector2 m_pos3 = EnemyPosList[2];

	Param newBlock3;
	newBlock3.m_pos = { m_pos3.x,m_pos3.y };

	newBlock3.m_rect = { 128,0,64,64 };

	newBlock3.m_radius.x = 32;
	newBlock3.m_radius.y = 32;

	newBlock3.m_alpha = 1.0f;

	newBlock3.m_move.x = 1;   //移動スピード
	newBlock3.m_move.y = 1;   //移動スピード

	newBlock3.m_MoveState = 0;

	newBlock3.m_BulletTimer = 0;

	newBlock3.m_alive = true;

	newBlock3.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock3);
}

void C_Enemy::Stage4Init()
{
	m_EnemyList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> EnemyPosList = {
	{0.0f,-316},
	{-371,0.0f},
	{0,316.0f},
	{371,0.0f},
	};

	Math::Vector2 m_pos1 = EnemyPosList[0];

	Param newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };

	newBlock.m_rect = { 0,0,64,64 };

	newBlock.m_radius.x = 32;
	newBlock.m_radius.y = 32;

	newBlock.m_alpha = 1.0f;

	newBlock.m_move.x = 1;   //移動スピード
	newBlock.m_move.y = 1;   //移動スピード

	newBlock.m_MoveState = 0;

	newBlock.m_BulletTimer = 0;

	newBlock.m_alive = true;

	newBlock.m_tex = Enemy.m_tex;

	m_EnemyList.push_back(newBlock);


	Math::Vector2 m_pos2 = EnemyPosList[1];

	Param newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };

	newBlock2.m_rect = { 64,0,64,64 };

	newBlock2.m_radius.x = 32;
	newBlock2.m_radius.y = 32;

	newBlock2.m_alpha = 1.0f;

	newBlock2.m_move.x = 2;   //移動スピード
	newBlock2.m_move.y = 2;   //移動スピード

	newBlock2.m_MoveState = 0;

	newBlock2.m_BulletTimer = 0;

	newBlock2.m_alive = true;

	newBlock2.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock2);

	Math::Vector2 m_pos3 = EnemyPosList[2];

	Param newBlock3;
	newBlock3.m_pos = { m_pos3.x,m_pos3.y };

	newBlock3.m_rect = { 128,0,64,64 };

	newBlock3.m_radius.x = 32;
	newBlock3.m_radius.y = 32;

	newBlock3.m_alpha = 1.0f;

	newBlock3.m_move.x = 3;   //移動スピード
	newBlock3.m_move.y = 3;   //移動スピード

	newBlock3.m_MoveState = 0;

	newBlock3.m_BulletTimer = 0;

	newBlock3.m_alive = true;

	newBlock3.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock3);

	Math::Vector2 m_pos4 = EnemyPosList[3];

	Param newBlock4;
	newBlock4.m_pos = { m_pos4.x,m_pos4.y };

	newBlock4.m_rect = { 192,0,64,64 };

	newBlock4.m_radius.x = 32;
	newBlock4.m_radius.y = 32;

	newBlock4.m_alpha = 1.0f;

	newBlock4.m_move.x = 2;   //移動スピード
	newBlock4.m_move.y = 2;   //移動スピード

	newBlock4.m_MoveState = 0;

	newBlock4.m_BulletTimer = 0;

	newBlock4.m_alive = true;

	newBlock4.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock4);
}

void C_Enemy::HardStage1Init()
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

	newBlock.m_radius.x = 32;
	newBlock.m_radius.y = 32;

	newBlock.m_alpha = 1.0f;

	newBlock.m_move.x = 2;   //移動スピード
	newBlock.m_move.y = 2;   //移動スピード

	newBlock.m_MoveState = 0;

	newBlock.m_BulletTimer = 0;

	newBlock.m_alive = true;

	newBlock.m_tex = Enemy.m_tex;

	m_EnemyList.push_back(newBlock);


	Math::Vector2 m_pos2 = EnemyPosList[1];

	Param newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };

	newBlock2.m_rect = { 64,0,64,64 };

	newBlock2.m_radius.x = 32;
	newBlock2.m_radius.y = 32;

	newBlock2.m_alpha = 1.0f;

	newBlock2.m_move.x = 3;   //移動スピード
	newBlock2.m_move.y = 3;   //移動スピード

	newBlock2.m_MoveState = 0;

	newBlock2.m_BulletTimer = 0;

	newBlock2.m_alive = true;

	newBlock2.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock2);
}

void C_Enemy::HardStage2Init()
{
	m_EnemyList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> EnemyPosList = {
	{0.0f,-316},
	{-371,0.0f},
	{0,316.0f},
	};

	Math::Vector2 m_pos1 = EnemyPosList[0];

	Param newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };

	newBlock.m_rect = { 0,0,64,64 };

	newBlock.m_radius.x = 32;
	newBlock.m_radius.y = 32;

	newBlock.m_alpha = 1.0f;

	newBlock.m_move.x = 3;   //移動スピード
	newBlock.m_move.y = 3;   //移動スピード

	newBlock.m_MoveState = 0;

	newBlock.m_BulletTimer = 0;

	newBlock.m_alive = true;

	newBlock.m_tex = Enemy.m_tex;

	m_EnemyList.push_back(newBlock);


	Math::Vector2 m_pos2 = EnemyPosList[1];

	Param newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };

	newBlock2.m_rect = { 64,0,64,64 };

	newBlock2.m_radius.x = 32;
	newBlock2.m_radius.y = 32;

	newBlock2.m_alpha = 1.0f;

	newBlock2.m_move.x = 2;   //移動スピード
	newBlock2.m_move.y = 2;   //移動スピード

	newBlock2.m_MoveState = 0;

	newBlock2.m_BulletTimer = 0;

	newBlock2.m_alive = true;

	newBlock2.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock2);

	Math::Vector2 m_pos3 = EnemyPosList[2];

	Param newBlock3;
	newBlock3.m_pos = { m_pos3.x,m_pos3.y };

	newBlock3.m_rect = { 128,0,64,64 };

	newBlock3.m_radius.x = 32;
	newBlock3.m_radius.y = 32;

	newBlock3.m_alpha = 1.0f;

	newBlock3.m_move.x = 3;   //移動スピード
	newBlock3.m_move.y = 3;   //移動スピード

	newBlock3.m_MoveState = 0;

	newBlock3.m_BulletTimer = 0;

	newBlock3.m_alive = true;

	newBlock3.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock3);
}

void C_Enemy::HardStage3Init()
{
	m_EnemyList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> EnemyPosList = {
	{0.0f,-316},
	{-371,0.0f},
	{0,316.0f},
	{371,0.0f},
	};

	Math::Vector2 m_pos1 = EnemyPosList[0];

	Param newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };

	newBlock.m_rect = { 0,0,64,64 };

	newBlock.m_radius.x = 32;
	newBlock.m_radius.y = 32;

	newBlock.m_alpha = 1.0f;

	newBlock.m_move.x = 3;   //移動スピード
	newBlock.m_move.y = 3;   //移動スピード

	newBlock.m_MoveState = 0;

	newBlock.m_BulletTimer = 0;

	newBlock.m_alive = true;

	newBlock.m_tex = Enemy.m_tex;

	m_EnemyList.push_back(newBlock);


	Math::Vector2 m_pos2 = EnemyPosList[1];

	Param newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };

	newBlock2.m_rect = { 64,0,64,64 };

	newBlock2.m_radius.x = 32;
	newBlock2.m_radius.y = 32;

	newBlock2.m_alpha = 1.0f;

	newBlock2.m_move.x = 2;   //移動スピード
	newBlock2.m_move.y = 2;   //移動スピード

	newBlock2.m_MoveState = 0;

	newBlock2.m_BulletTimer = 0;

	newBlock2.m_alive = true;

	newBlock2.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock2);

	Math::Vector2 m_pos3 = EnemyPosList[2];

	Param newBlock3;
	newBlock3.m_pos = { m_pos3.x,m_pos3.y };

	newBlock3.m_rect = { 128,0,64,64 };

	newBlock3.m_radius.x = 32;
	newBlock3.m_radius.y = 32;

	newBlock3.m_alpha = 1.0f;

	newBlock3.m_move.x = 3;   //移動スピード
	newBlock3.m_move.y = 3;   //移動スピード

	newBlock3.m_MoveState = 0;

	newBlock3.m_BulletTimer = 0;

	newBlock3.m_alive = true;

	newBlock3.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock3);

	Math::Vector2 m_pos4 = EnemyPosList[3];

	Param newBlock4;
	newBlock4.m_pos = { m_pos4.x,m_pos4.y };

	newBlock4.m_rect = { 192,0,64,64 };

	newBlock4.m_radius.x = 32;
	newBlock4.m_radius.y = 32;

	newBlock4.m_alpha = 1.0f;

	newBlock4.m_move.x = 2;   //移動スピード
	newBlock4.m_move.y = 2;   //移動スピード

	newBlock4.m_MoveState = 0;

	newBlock4.m_BulletTimer = 0;

	newBlock4.m_alive = true;

	newBlock4.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock4);
}

void C_Enemy::HardStage4Init()
{
	m_EnemyList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> EnemyPosList = {
	{0.0f,-316},
	{-371,120.0f},
	{0,316.0f},
	{371,120.0f},
	{-371,-80.0f},
	{371,-80.0f},
	};

	Math::Vector2 m_pos1 = EnemyPosList[0];

	Param newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };

	newBlock.m_rect = { 0,0,64,64 };

	newBlock.m_radius.x = 32;
	newBlock.m_radius.y = 32;

	newBlock.m_alpha = 1.0f;

	newBlock.m_move.x = 2;   //移動スピード
	newBlock.m_move.y = 2;   //移動スピード

	newBlock.m_MoveState = 0;

	newBlock.m_BulletTimer = 0;

	newBlock.m_alive = true;

	newBlock.m_tex = Enemy.m_tex;

	m_EnemyList.push_back(newBlock);


	Math::Vector2 m_pos2 = EnemyPosList[1];

	Param newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };

	newBlock2.m_rect = { 64,0,64,64 };

	newBlock2.m_radius.x = 32;
	newBlock2.m_radius.y = 32;

	newBlock2.m_alpha = 1.0f;

	newBlock2.m_move.x = 2;   //移動スピード
	newBlock2.m_move.y = 2;   //移動スピード

	newBlock2.m_MoveState = 0;

	newBlock2.m_BulletTimer = 0;

	newBlock2.m_alive = true;

	newBlock2.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock2);

	Math::Vector2 m_pos3 = EnemyPosList[2];

	Param newBlock3;
	newBlock3.m_pos = { m_pos3.x,m_pos3.y };

	newBlock3.m_rect = { 128,0,64,64 };

	newBlock3.m_radius.x = 32;
	newBlock3.m_radius.y = 32;

	newBlock3.m_alpha = 1.0f;

	newBlock3.m_move.x = 3;   //移動スピード
	newBlock3.m_move.y = 3;   //移動スピード

	newBlock3.m_MoveState = 0;

	newBlock3.m_BulletTimer = 0;

	newBlock3.m_alive = true;

	newBlock3.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock3);

	Math::Vector2 m_pos4 = EnemyPosList[3];

	Param newBlock4;

	newBlock4.m_pos = { m_pos4.x,m_pos4.y };

	newBlock4.m_rect = { 192,0,64,64 };

	newBlock4.m_radius.x = 32;
	newBlock4.m_radius.y = 32;

	newBlock4.m_alpha = 1.0f;

	newBlock4.m_move.x = 2;   //移動スピード
	newBlock4.m_move.y = 2;   //移動スピード

	newBlock4.m_MoveState = 0;

	newBlock4.m_BulletTimer = 0;

	newBlock4.m_alive = true;

	newBlock4.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock4);

	Math::Vector2 m_pos5 = EnemyPosList[4];

	Param newBlock5;

	newBlock5.m_pos = { m_pos5.x,m_pos5.y };

	newBlock5.m_rect = { 64,0,64,64 };

	newBlock5.m_radius.x = 32;
	newBlock5.m_radius.y = 32;

	newBlock5.m_alpha = 1.0f;

	newBlock5.m_move.x = 2;   //移動スピード
	newBlock5.m_move.y = 2;   //移動スピード

	newBlock5.m_MoveState = 0;

	newBlock5.m_BulletTimer = 0;

	newBlock5.m_alive = true;

	newBlock5.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock5);

	
	Math::Vector2 m_pos6 = EnemyPosList[5];

	Param newBlock6;

	newBlock6.m_pos = { m_pos6.x,m_pos6.y };

	newBlock6.m_rect = { 192,0,64,64 };

	newBlock6.m_radius.x = 32;
	newBlock6.m_radius.y = 32;

	newBlock6.m_alpha = 1.0f;

	newBlock6.m_move.x = 2;   //移動スピード
	newBlock6.m_move.y = 2;   //移動スピード

	newBlock6.m_MoveState = 0;

	newBlock6.m_BulletTimer = 0;

	newBlock6.m_alive = true;

	newBlock6.m_tex = Enemy.m_tex;


	m_EnemyList.push_back(newBlock6);
}

void C_Enemy::Stage1Action()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	C_Player* player = SCENE.GetPlayer();

	if (gameScreen->GetGameStartFlg() == false || gameScreen->GetGameOverFlg() == true)
	{
		return;
	}

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


		//プレイヤーと重なったら敵のAlpha値を少し下げる
		float Bottom = enemy.m_pos.x - player->GetPos().x;     //底辺(X座標の差)
		float Height = enemy.m_pos.y - player->GetPos().y;	   //高さ(Y座標の差)
		float Sqrt = Bottom * Bottom + Height * Height;		   //sqrtは重いため未実装
		float Radius = player->GetRadius().x + enemy.m_radius.x;

		if (Sqrt < Radius * Radius && player->GetAlive() == true)
		{
			enemy.m_alpha = 0.5f;
		}
		else
		{
			enemy.m_alpha = 1.0f;
		}
	}
}

void C_Enemy::Stage2Action()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	C_Player* player = SCENE.GetPlayer();

	if (gameScreen->GetGameStartFlg() == false || gameScreen->GetGameOverFlg() == true)
	{
		return;
	}

	for (int i = 0; i < m_EnemyList.size(); i++)
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

		//プレイヤーと重なったら敵のAlpha値を少し下げる
		float Bottom = enemy.m_pos.x - player->GetPos().x;      //底辺(X座標の差)
		float Height = enemy.m_pos.y - player->GetPos().y;	  //高さ(Y座標の差)
		float Sqrt = Bottom * Bottom + Height * Height;		  //sqrtは重いため未実装
		float Radius = player->GetRadius().x + enemy.m_radius.x;

		if (Sqrt < Radius * Radius && player->GetAlive() == true)
		{
			enemy.m_alpha = 0.5f;
		}
		else
		{
			enemy.m_alpha = 1.0f;
		}

	}
}

void C_Enemy::Stage3Action()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	C_Player* player = SCENE.GetPlayer();

	if (gameScreen->GetGameStartFlg() == false || gameScreen->GetGameOverFlg() == true)
	{
		return;
	}

	for (int i = 0; i < m_EnemyList.size(); i++)
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

				if (enemy.m_pos.y < 70)
				{
					enemy.m_pos.y += enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //下移動

				if (enemy.m_pos.y > -70)
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

		if (i == 2)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //左移動

				if (enemy.m_pos.x > -60)
				{
					enemy.m_pos.x -= enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1: //右移動

				if (enemy.m_pos.x < 60)
				{
					enemy.m_pos.x += enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 0;
				}
				break;
			}
		}

		//プレイヤーと重なったら敵のAlpha値を少し下げる
		float Bottom = enemy.m_pos.x - player->GetPos().x;      //底辺(X座標の差)
		float Height = enemy.m_pos.y - player->GetPos().y;	  //高さ(Y座標の差)
		float Sqrt = Bottom * Bottom + Height * Height;		  //sqrtは重いため未実装
		float Radius = player->GetRadius().x + enemy.m_radius.x;

		if (Sqrt < Radius * Radius && player->GetAlive() == true)
		{
			enemy.m_alpha = 0.5f;
		}
		else
		{
			enemy.m_alpha = 1.0f;
		}

	}
}

void C_Enemy::Stage4Action()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	C_Player* player = SCENE.GetPlayer();

	if (gameScreen->GetGameStartFlg() == false || gameScreen->GetGameOverFlg() == true)
	{
		return;
	}

	for (int i = 0; i < m_EnemyList.size(); ++i)
	{
		auto& enemy = m_EnemyList[i];


		if (i == 0)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //右移動

				if (enemy.m_pos.x < 70)
				{
					enemy.m_pos.x += enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //左移動

				if (enemy.m_pos.x > -70)
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

				if (enemy.m_pos.y < 100)
				{
					enemy.m_pos.y += enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //下移動

				if (enemy.m_pos.y > -80)
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

		if (i == 2)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //左移動

				if (enemy.m_pos.x > -60)
				{
					enemy.m_pos.x -= enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1: //右移動

				if (enemy.m_pos.x < 60)
				{
					enemy.m_pos.x += enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 0;
				}
				break;
			}
		}

		if (i == 3)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //下移動

				if (enemy.m_pos.y > -80)
				{
					enemy.m_pos.y -= enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //上移動

				if (enemy.m_pos.y < 100)
				{
					enemy.m_pos.y += enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 0;
				}
				break;

			}
		}

		//プレイヤーと重なったら敵のAlpha値を少し下げる
		float Bottom = enemy.m_pos.x - player->GetPos().x;      //底辺(X座標の差)
		float Height = enemy.m_pos.y - player->GetPos().y;	  //高さ(Y座標の差)
		float Sqrt = Bottom * Bottom + Height * Height;		  //sqrtは重いため未実装
		float Radius = player->GetRadius().x + enemy.m_radius.x;

		if (Sqrt < Radius * Radius && player->GetAlive() == true)
		{
			enemy.m_alpha = 0.5f;
		}
		else
		{
			enemy.m_alpha = 1.0f;
		}

	}
}

void C_Enemy::HardStage1Action()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	C_Player* player = SCENE.GetPlayer();

	if (gameScreen->GetGameStartFlg() == false || gameScreen->GetGameOverFlg() == true)
	{
		return;
	}

	for (int i = 0; i < m_EnemyList.size(); ++i)
	{
		auto& enemy = m_EnemyList[i];

		if (i == 0)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //右移動

				if (enemy.m_pos.x < 100)
				{
					enemy.m_pos.x += enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //左移動

				if (enemy.m_pos.x > -100)
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

				if (enemy.m_pos.y < 100)
				{
					enemy.m_pos.y += enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //下移動

				if (enemy.m_pos.y > -100)
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

		//プレイヤーと重なったら敵のAlpha値を少し下げる
		float Bottom = enemy.m_pos.x - player->GetPos().x;      //底辺(X座標の差)
		float Height = enemy.m_pos.y - player->GetPos().y;	  //高さ(Y座標の差)
		float Sqrt = Bottom * Bottom + Height * Height;		  //sqrtは重いため未実装
		float Radius = player->GetRadius().x + enemy.m_radius.x;

		if (Sqrt < Radius * Radius && player->GetAlive() == true)
		{
			enemy.m_alpha = 0.5f;
		}
		else
		{
			enemy.m_alpha = 1.0f;
		}

	}
}

void C_Enemy::HardStage2Action()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	C_Player* player = SCENE.GetPlayer();

	if (gameScreen->GetGameStartFlg() == false || gameScreen->GetGameOverFlg() == true)
	{
		return;
	}

	for (int i = 0; i < m_EnemyList.size(); ++i)
	{
		auto& enemy = m_EnemyList[i];

		if (i == 0)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //右移動

				if (enemy.m_pos.x < 70)
				{
					enemy.m_pos.x += enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //左移動

				if (enemy.m_pos.x > -70)
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

				if (enemy.m_pos.y < 100)
				{
					enemy.m_pos.y += enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //下移動

				if (enemy.m_pos.y > -100)
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

		if (i == 2)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //左移動

				if (enemy.m_pos.x > -90)
				{
					enemy.m_pos.x -= enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1: //右移動

				if (enemy.m_pos.x < 90)
				{
					enemy.m_pos.x += enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 0;
				}
				break;
			}
		}

		//プレイヤーと重なったら敵のAlpha値を少し下げる
		float Bottom = enemy.m_pos.x - player->GetPos().x;      //底辺(X座標の差)
		float Height = enemy.m_pos.y - player->GetPos().y;	  //高さ(Y座標の差)
		float Sqrt = Bottom * Bottom + Height * Height;		  //sqrtは重いため未実装
		float Radius = player->GetRadius().x + enemy.m_radius.x;

		if (Sqrt < Radius * Radius && player->GetAlive() == true)
		{
			enemy.m_alpha = 0.5f;
		}
		else
		{
			enemy.m_alpha = 1.0f;
		}

	}
}

void C_Enemy::HardStage3Action()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	C_Player* player = SCENE.GetPlayer();

	if (gameScreen->GetGameStartFlg() == false || gameScreen->GetGameOverFlg() == true)
	{
		return;
	}

	for (int i = 0; i < m_EnemyList.size(); ++i)
	{
		auto& enemy = m_EnemyList[i];

		if (i == 0)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //右移動

				if (enemy.m_pos.x < 110)
				{
					enemy.m_pos.x += enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //左移動

				if (enemy.m_pos.x > -110)
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

				if (enemy.m_pos.y < 110)
				{
					enemy.m_pos.y += enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //下移動

				if (enemy.m_pos.y > -110)
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

		if (i == 2)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //左移動

				if (enemy.m_pos.x > -90)
				{
					enemy.m_pos.x -= enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1: //右移動

				if (enemy.m_pos.x < 90)
				{
					enemy.m_pos.x += enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 0;
				}
				break;
			}
		}

		if (i == 3)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //下移動

				if (enemy.m_pos.y > -100)
				{
					enemy.m_pos.y -= enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //上移動

				if (enemy.m_pos.y < 100)
				{
					enemy.m_pos.y += enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 0;
				}
				break;

			}
		}

		//プレイヤーと重なったら敵のAlpha値を少し下げる
		float Bottom = enemy.m_pos.x - player->GetPos().x;      //底辺(X座標の差)
		float Height = enemy.m_pos.y - player->GetPos().y;	  //高さ(Y座標の差)
		float Sqrt = Bottom * Bottom + Height * Height;		  //sqrtは重いため未実装
		float Radius = player->GetRadius().x + enemy.m_radius.x;

		if (Sqrt < Radius * Radius && player->GetAlive() == true)
		{
			enemy.m_alpha = 0.5f;
		}
		else
		{
			enemy.m_alpha = 1.0f;
		}
	}
}

void C_Enemy::HardStage4Action()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	C_Player* player = SCENE.GetPlayer();

	if (gameScreen->GetGameStartFlg() == false || gameScreen->GetGameOverFlg() == true)
	{
		return;
	}

	for (int i = 0; i < m_EnemyList.size(); ++i)
	{
		auto& enemy = m_EnemyList[i];

		if (i == 0)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //右移動

				if (enemy.m_pos.x < 70)
				{
					enemy.m_pos.x += enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //左移動

				if (enemy.m_pos.x > -70)
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

				if (enemy.m_pos.y < 120)
				{
					enemy.m_pos.y += enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //下移動

				if (enemy.m_pos.y > 0)
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

		if (i == 2)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //左移動

				if (enemy.m_pos.x > -60)
				{
					enemy.m_pos.x -= enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1: //右移動

				if (enemy.m_pos.x < 60)
				{
					enemy.m_pos.x += enemy.m_move.x;
				}
				else
				{
					enemy.m_MoveState = 0;
				}
				break;
			}
		}

		if (i == 3)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //上移動

				if (enemy.m_pos.y < 120)
				{
					enemy.m_pos.y += enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //下移動

				if (enemy.m_pos.y > 0)
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

		if (i == 4)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //上移動

				if (enemy.m_pos.y < -80)
				{
					enemy.m_pos.y += enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //下移動

				if (enemy.m_pos.y > -200)
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

		if (i == 5)
		{
			switch (enemy.m_MoveState)
			{

			case 0: //上移動

				if (enemy.m_pos.y < -80)
				{
					enemy.m_pos.y += enemy.m_move.y;
				}
				else
				{
					enemy.m_MoveState = 1;
				}
				break;

			case 1:  //下移動

				if (enemy.m_pos.y > -200)
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

		//プレイヤーと重なったら敵のAlpha値を少し下げる
		float Bottom = enemy.m_pos.x - player->GetPos().x;      //底辺(X座標の差)
		float Height = enemy.m_pos.y - player->GetPos().y;	  //高さ(Y座標の差)
		float Sqrt = Bottom * Bottom + Height * Height;		  //sqrtは重いため未実装
		float Radius = player->GetRadius().x + enemy.m_radius.x;

		if (Sqrt < Radius * Radius && player->GetAlive() == true)
		{
			enemy.m_alpha = 0.5f;
		}
		else
		{
			enemy.m_alpha = 1.0f;
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
			SHADER.m_spriteShader.DrawTex(enemy.m_tex, enemy.m_rect, enemy.m_alpha);
		}
	}
}