#include"GameScreenBlock.h"
#include"../Scene.h"

void C_GameScreenBlock::Stage3Init()
{
	m_BlockList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> BlockPosList = {
	{(64.0f * 10.0f) - 640,(-64.0f * 8.0f) + 360},
	{(64.0f * 8.2f) - 640,(-64.0f * 5.0f) + 360},
	};

	Math::Vector2 m_pos1 = BlockPosList[0];

	Object newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };
	newBlock.m_scale = 1.0f;

	newBlock.m_radiusX = 64.0f;
	newBlock.m_radiusY = 32.0f;

	newBlock.m_rect = { 0,0,128,64 };
	newBlock.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock);


	Math::Vector2 m_pos2 = BlockPosList[1];

	Object newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };
	newBlock2.m_scale = 1.0f;

	newBlock2.m_radiusX = 32.0f;
	newBlock2.m_radiusY = 64.0f;

	newBlock2.m_rect = { 128,0,64,128 };
	newBlock2.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock2);

}

void C_GameScreenBlock::Stage4Init()
{
	m_BlockList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> BlockPosList = {
	{(64.0f * 8.0f) - 640,(-64.0f * 5.0f) + 360},
	{(64.0f * 12.0f) - 640,(-64.0f * 5.0f) + 360},
	{(64.0f * 15.35f) - 640,(-64.0f * 3.0f) + 360},
	{(64.0f * 4.65f) - 640,(-64.0f * 3.0f) + 360},
	{(64.0f * 15.35f) - 640,(-64.0f * 8.0f) + 360},
	{(64.0f * 4.65f) - 640,(-64.0f * 8.0f) + 360},
	};

	Math::Vector2 m_pos1 = BlockPosList[0];

	Object newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };
	newBlock.m_scale = 1.0f;

	newBlock.m_radiusX = 32.0f;
	newBlock.m_radiusY = 64.0f;

	newBlock.m_move.x = 1;   //移動スピード
	newBlock.m_move.y = 1;   //移動スピード

	newBlock.m_MoveState = 0;

	newBlock.m_rect = { 128,0,64,128 };
	newBlock.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock);


	Math::Vector2 m_pos2 = BlockPosList[1];

	Object newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };
	newBlock2.m_scale = 1.0f;

	newBlock2.m_radiusX = 32.0f;
	newBlock2.m_radiusY = 64.0f;

	newBlock2.m_move.x = 1;   //移動スピード
	newBlock2.m_move.y = 1;   //移動スピード

	newBlock2.m_MoveState = 0;

	newBlock2.m_rect = { 128,0,64,128 };
	newBlock2.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock2);


	Math::Vector2 m_pos3 = BlockPosList[2];

	Object newBlock3;
	newBlock3.m_pos = { m_pos3.x,m_pos3.y };
	newBlock3.m_scale = 1.0f;

	newBlock3.m_radiusX = 64.0f;
	newBlock3.m_radiusY = 32.0f;

	newBlock3.m_MoveState = 0;

	newBlock3.m_rect = { 0,0,128,64 };
	newBlock3.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock3);

	Math::Vector2 m_pos4 = BlockPosList[3];

	Object newBlock4;
	newBlock4.m_pos = { m_pos4.x,m_pos4.y };
	newBlock4.m_scale = 1.0f;

	newBlock4.m_radiusX = 64.0f;
	newBlock4.m_radiusY = 32.0f;

	newBlock4.m_rect = { 0,0,128,64 };
	newBlock4.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock4);

	Math::Vector2 m_pos5 = BlockPosList[4];

	Object newBlock5;
	newBlock5.m_pos = { m_pos5.x,m_pos5.y };
	newBlock5.m_scale = 1.0f;

	newBlock5.m_radiusX = 64.0f;
	newBlock5.m_radiusY = 32.0f;

	newBlock5.m_rect = { 0,0,128,64 };
	newBlock5.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock5);

	Math::Vector2 m_pos6 = BlockPosList[5];

	Object newBlock6;
	newBlock6.m_pos = { m_pos6.x,m_pos6.y };
	newBlock6.m_scale = 1.0f;

	newBlock6.m_radiusX = 64.0f;
	newBlock6.m_radiusY = 32.0f;

	newBlock6.m_rect = { 0,0,128,64 };
	newBlock6.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock6);
}

void C_GameScreenBlock::HardStage2Init()
{
	m_BlockList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> BlockPosList = {
	{(64.0f * 8.0f) - 640,(-64.0f * 6.0f) + 360},
	};

	Math::Vector2 m_pos1 = BlockPosList[0];

	Object newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };
	newBlock.m_scale = 1.0f;

	newBlock.m_move.x = 2;   //移動スピード
	newBlock.m_move.y = 2;   //移動スピード

	newBlock.m_MoveState = 0;

	newBlock.m_radiusX = 32.0f;
	newBlock.m_radiusY = 64.0f;

	newBlock.m_rect = { 128,0,64,128 };
	newBlock.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock);
}

void C_GameScreenBlock::HardStage3Init()
{
	m_BlockList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> BlockPosList = {
	{(64.0f * 8.0f) - 640,(-64.0f * 6.0f) + 360},
	{(64.0f * 13.0f) - 640,(-64.0f * 6.0f) + 360},
	};

	Math::Vector2 m_pos1 = BlockPosList[0];

	Object newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };
	newBlock.m_scale = 1.0f;

	newBlock.m_move.x = 2;   //移動スピード
	newBlock.m_move.y = 2;   //移動スピード

	newBlock.m_MoveState = 0;

	newBlock.m_radiusX = 32.0f;
	newBlock.m_radiusY = 64.0f;

	newBlock.m_rect = { 128,0,64,128 };
	newBlock.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock);

	Math::Vector2 m_pos2 = BlockPosList[1];

	Object newBlock2;
	newBlock2.m_pos = { m_pos2.x , m_pos2.y };
	newBlock2.m_scale = 1.0f;

	newBlock2.m_move.x = 2;   //移動スピード
	newBlock2.m_move.y = 2;   //移動スピード

	newBlock2.m_MoveState = 0;

	newBlock2.m_radiusX = 32.0f;
	newBlock2.m_radiusY = 64.0f;

	newBlock2.m_rect = { 128,0,64,128 };
	newBlock2.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock2);
}

void C_GameScreenBlock::HardStage4Init()
{
	m_BlockList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> BlockPosList = {
	{(64.0f * 6.0f) - 640,(-64.0f * 3.0f) + 360},
	{(64.0f * 14.0f) - 640,(-64.0f * 3.0f) + 360},
	{(64.0f * 6.0f) - 640,(-64.0f * 9.0f) + 360},
	{(64.0f * 14.0f) - 640,(-64.0f * 9.0f) + 360},
	};

	Math::Vector2 m_pos1 = BlockPosList[0];

	Object newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };
	newBlock.m_scale = 1.0f;

	newBlock.m_radiusX = 32.0f;
	newBlock.m_radiusY = 64.0f;

	newBlock.m_rect = { 128,0,64,128 };
	newBlock.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock);

	Math::Vector2 m_pos2 = BlockPosList[1];

	Object newBlock2;
	newBlock2.m_pos = { m_pos2.x , m_pos2.y };
	newBlock2.m_scale = 1.0f;

	newBlock2.m_radiusX = 32.0f;
	newBlock2.m_radiusY = 64.0f;

	newBlock2.m_rect = { 128,0,64,128 };
	newBlock2.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock2);

	Math::Vector2 m_pos3 = BlockPosList[2];

	Object newBlock3;
	newBlock3.m_pos = { m_pos3.x , m_pos3.y };
	newBlock3.m_scale = 1.0f;

	newBlock3.m_radiusX = 32.0f;
	newBlock3.m_radiusY = 64.0f;

	newBlock3.m_rect = { 128,0,64,128 };
	newBlock3.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock3);

	Math::Vector2 m_pos4 = BlockPosList[3];

	Object newBlock4;
	newBlock4.m_pos = { m_pos4.x , m_pos4.y };
	newBlock4.m_scale = 1.0f;

	newBlock4.m_radiusX = 32.0f;
	newBlock4.m_radiusY = 64.0f;

	newBlock4.m_rect = { 128,0,64,128 };
	newBlock4.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock4);
}

void C_GameScreenBlock::Action()
{
	for (auto& block : m_BlockList)
	{
		ObjectPlayerHit(&block);
	}
}

void C_GameScreenBlock::Stage4Action()
{

	C_GameScreen* gamescreen = SCENE.GetGameScreen();

	if (gamescreen->GetGameStartFlg() == true && gamescreen->GetGameOverFlg() == false && gamescreen->GetStageClearFlg() == false)
	{

		for (int i = 0; i < m_BlockList.size(); i++)
		{

			auto& block = m_BlockList[i];

			ObjectPlayerHit(&block);


			if (i == 0)
			{
				switch (block.m_MoveState)
				{
				case 0: //上移動

					if (block.m_pos.y < 90)
					{
						block.m_pos.y += block.m_move.y;
					}
					else
					{
						block.m_MoveState = 1;
					}
					break;

				case 1:  //下移動

					if (block.m_pos.y > -60)
					{
						block.m_pos.y -= block.m_move.y;
					}
					else
					{
						block.m_MoveState = 0;
					}
					break;
				}
			}

			if (i == 1)
			{
				switch (block.m_MoveState)
				{
				case 0: //下移動

					if (block.m_pos.y > -60)
					{
						block.m_pos.y -= block.m_move.y;
					}
					else
					{
						block.m_MoveState = 1;
					}
					break;

				case 1:  //上移動

					if (block.m_pos.y < 90)
					{
						block.m_pos.y += block.m_move.y;
					}
					else
					{
						block.m_MoveState = 0;
					}
					break;
				}
			}
		}
	}
}

void C_GameScreenBlock::HardStage2Action()
{
	C_GameScreen* gamescreen = SCENE.GetGameScreen();

	if (gamescreen->GetGameStartFlg() == true && gamescreen->GetGameOverFlg() == false && gamescreen->GetStageClearFlg() == false)
	{

		for (int i = 0; i < m_BlockList.size(); i++)
		{

			auto& block = m_BlockList[i];

			ObjectPlayerHit(&block);


			switch (block.m_MoveState)
			{
			case 0: //上移動

				if (block.m_pos.y < 90)
				{
					block.m_pos.y += block.m_move.y;
				}
				else
				{
					block.m_MoveState = 1;
				}
				break;

			case 1:  //下移動

				if (block.m_pos.y > -60)
				{
					block.m_pos.y -= block.m_move.y;
				}
				else
				{
					block.m_MoveState = 0;
				}
				break;
			}

		}
	}
}

void C_GameScreenBlock::HardStage3Action()
{
	C_GameScreen* gamescreen = SCENE.GetGameScreen();

	if (gamescreen->GetGameStartFlg() == true && gamescreen->GetGameOverFlg() == false && gamescreen->GetStageClearFlg() == false)
	{

		for (int i = 0; i < m_BlockList.size(); i++)
		{

			auto& block = m_BlockList[i];

			ObjectPlayerHit(&block);

			if (i == 0)
			{
				switch (block.m_MoveState)
				{
				case 0: //上移動

					if (block.m_pos.y < 100)
					{
						block.m_pos.y += block.m_move.y;
					}
					else
					{
						block.m_MoveState = 1;
					}
					break;

				case 1:  //下移動

					if (block.m_pos.y > -80)
					{
						block.m_pos.y -= block.m_move.y;
					}
					else
					{
						block.m_MoveState = 0;
					}
					break;
				}
			}

			if (i == 1)
			{
				switch (block.m_MoveState)
				{
				case 0://下移動

					if (block.m_pos.y > -70)
					{
						block.m_pos.y -= block.m_move.y;
					}
					else
					{
						block.m_MoveState = 1;
					}
					break;


				case 1:  //上移動

					if (block.m_pos.y < 100)
					{
						block.m_pos.y += block.m_move.y;
					}
					else
					{
						block.m_MoveState = 0;
					}
					break;
				}
			}


		}
	}
}

void C_GameScreenBlock::Update()
{
	for (auto& block : m_BlockList)
	{
		block.m_transMat = Math::Matrix::CreateTranslation(block.m_pos.x, block.m_pos.y, 0);
		block.m_scaleMat = Math::Matrix::CreateScale(block.m_scale, block.m_scale, 0);
		block.m_mat = block.m_scaleMat * block.m_transMat;
	}
}

void C_GameScreenBlock::Draw()
{
	for (auto& block : m_BlockList)
	{
		SHADER.m_spriteShader.SetMatrix(block.m_mat);
		SHADER.m_spriteShader.DrawTex(block.m_tex, block.m_rect, 0.6f);
	}
}

void C_GameScreenBlock::ObjectPlayerHit(Object* a_base)
{
	C_Player* player = SCENE.GetPlayer();

	//現在の位置（移動後）での重なり具合を計算
	float PlayerRight = player->GetPos().x + player->GetRadius().x;
	float PlayerLeft = player->GetPos().x - player->GetRadius().x;
	float PlayerTop = player->GetPos().y + player->GetRadius().y;
	float PlayerBottom = player->GetPos().y - player->GetRadius().y;

	float BlockRight = a_base->m_pos.x + a_base->m_radiusX;
	float BlockLeft = a_base->m_pos.x - a_base->m_radiusX;
	float BlockTop = a_base->m_pos.y + a_base->m_radiusY;
	float BlockBottom = a_base->m_pos.y - a_base->m_radiusY;

	//そもそも重なっているかチェック（AABB判定）
	if (PlayerLeft >= BlockRight || PlayerRight <= BlockLeft || PlayerBottom >= BlockTop || PlayerTop <= BlockBottom) return;

	//各方向のめり込み量（侵入深さ）を計算
	float NextLeft = PlayerRight - BlockLeft; //プレイヤーの右側がブロックの左側にどれだけ入ったか
	float NextRight = BlockRight - PlayerLeft; //プレイヤーの左側がブロックの右側にどれだけ入ったか
	float NextTop = BlockTop - PlayerBottom; //プレイヤーの下側がブロックの上側にどれだけ入ったか
	float NextBottom = PlayerTop - BlockBottom; //プレイヤーの上側がブロックの下側にどれだけ入ったか

	//一番浅い（値が小さい）侵入方向を探す
	float MinOverLap = min(min(NextLeft, NextRight), min(NextTop, NextBottom));

	//最小の侵入軸に対してのみ補正を行う
	if (MinOverLap == NextLeft)
	{
		player->SetPosX(BlockLeft - player->GetRadius().x);
		player->SetMoveX(0);
	}

	else if (MinOverLap == NextRight)
	{
		player->SetPosX(BlockRight + player->GetRadius().x);
		player->SetMoveX(0);
	}

	else if (MinOverLap == NextTop)
	{
		player->SetPosY(BlockTop + player->GetRadius().y);
		player->SetMoveY(0); 
	}

	else if (MinOverLap == NextBottom)
	{
		player->SetPosY(BlockBottom - player->GetRadius().y);
		player->SetMoveY(0);
	}
}

bool C_GameScreenBlock::ObjectBulletHit(float bulletX, float bulletY)
{
	
	const float BulletRadius = 8;
	for (auto& block : m_BlockList)
	{
		float BulletRight = bulletX + BulletRadius;
		float BulletLeft = bulletX - BulletRadius;
		float BulletTop = bulletY + BulletRadius;
		float BulletBottom = bulletY - BulletRadius;

		float BlockRight = block.m_pos.x + block.m_radiusX;
		float BlockLeft = block.m_pos.x - block.m_radiusX;
		float BlockTop = block.m_pos.y + block.m_radiusY;
		float BlockBottom = block.m_pos.y - block.m_radiusY;

		//重なっていなければスキップ
		if (BulletLeft >= BlockRight || BulletRight <= BlockLeft ||
			BulletBottom >= BlockTop || BulletTop <= BlockBottom)
		{
			continue; //return ではなくcontinueで次のブロックへ
		}

		//当たっていた
		return true; //呼び出し側でエフェクト、弾消滅を行う
	}

	return false; //どのブロックにも当たらなかった
}


float C_GameScreenBlock::Rnd()
{
	return rand() / (float)RAND_MAX;
}