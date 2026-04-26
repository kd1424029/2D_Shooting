#include"GameScreenBlock.h"
#include"../Scene.h"

void C_GameScreenBlock::Init()
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

void C_GameScreenBlock::Action()
{
	for (auto& block : m_BlockList)
	{
		ObjectPlayerHit(&block);
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
		SHADER.m_spriteShader.DrawTex(block.m_tex, block.m_rect, 1.0f);
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

		// 重なっていなければスキップ
		if (BulletLeft >= BlockRight || BulletRight <= BlockLeft ||
			BulletBottom >= BlockTop || BulletTop <= BlockBottom)
		{
			continue; // ← return ではなく continue（次のブロックへ）
		}

		// 当たっていた
		return true; // ← 呼び出し側でエフェクト・弾消滅を行う
	}

	return false; // どのブロックにも当たらなかった
}


float C_GameScreenBlock::Rnd()
{
	return rand() / (float)RAND_MAX;
}