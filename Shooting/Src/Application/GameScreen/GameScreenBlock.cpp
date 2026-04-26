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

	newBlock.m_radiusX = 66.0f;
	newBlock.m_radiusY = 34.0f;

	newBlock.m_rect = { 0,0,128,64 };
	newBlock.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock);


	Math::Vector2 m_pos2 = BlockPosList[1];

	Object newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };
	newBlock2.m_scale = 1.0f;

	newBlock2.m_radiusX = 34.0f;
	newBlock2.m_radiusY = 66.0f;

	newBlock2.m_rect = { 128,0,64,128 };
	newBlock2.m_tex = Block.m_tex;

	m_BlockList.push_back(newBlock2);

}

void C_GameScreenBlock::Action()
{
	for (auto& block : m_BlockList)
	{
		ObjectHit(&block);
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

void C_GameScreenBlock::ObjectHit(Object* a_base)
{
	C_Player* player = SCENE.GetPlayer();	//プレイヤーのインスタンス情報を獲得

	//プレイヤー
	const float playerRight = player->GetPos().x + player->GetRadius().x;
	const float playerLeft = player->GetPos().x - player->GetRadius().x;
	const float playerTop = player->GetPos().y + player->GetRadius().y;
	const float playerBottom = player->GetPos().y - player->GetRadius().y;

	const float nextRight = player->GetFuturePos().x + player->GetRadius().x;
	const float nextLeft = player->GetFuturePos().x - player->GetRadius().x;
	const float nextTop = player->GetFuturePos().y + player->GetRadius().y;
	const float nextBottom = player->GetFuturePos().y - player->GetRadius().y;

	//ブロック
	const float blockRight = a_base->m_pos.x + a_base->m_radiusX;
	const float blockLeft = a_base->m_pos.x - a_base->m_radiusX;
	const float blockTop = a_base->m_pos.y + a_base->m_radiusY;
	const float blockBottom = a_base->m_pos.y - a_base->m_radiusY;

	//上下で重なった場合
	if (playerRight > blockLeft && blockRight > playerLeft)
	{
		//上判定
		if (nextBottom < blockTop && blockTop < nextTop)
		{
			player->SetPosY(blockTop + player->GetRadius().y);
		}
		//下判定
		else if (nextTop > blockBottom && blockBottom > nextBottom)
		{
			player->SetPosY(blockBottom - player->GetRadius().y);
		}
	}

	//左右で重なった場合
	if (playerTop > blockBottom && blockTop > playerBottom)
	{
		//右判定
		if (nextLeft < blockRight && nextRight > blockRight)
		{
			player->SetPosX(blockRight + player->GetRadius().x);
		}
		//左判定
		else if (nextRight > blockLeft && nextLeft < blockLeft)
		{
			player->SetPosX(blockLeft - player->GetRadius().x);
		}
	}
}

