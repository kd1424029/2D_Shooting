#include"Count.h"
#include"../Scene.h"

void C_Count::Stage1Init()
{

	m_CntList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> CntPosList = {
	{(64.0f * 18.2f) - 640,(-64.0f * 6.0f) + 360},
	{(64.0f * 18.2f) - 640,(-64.0f * 2.3f) + 360},
	};


	//============= 敵カウント用 ===========
	Math::Vector2 m_pos1 = CntPosList[0];

	Object newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };
	newBlock.m_scale = 1.5f;
	newBlock.m_rect = { 64,0,64,64 };
	newBlock.m_tex = Cnt.m_tex;

	m_CntList.push_back(newBlock);

	//======================================

	//========== ステージカウント用 ========

	Math::Vector2 m_pos2 = CntPosList[1];

	Object newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };
	newBlock2.m_scale = 1.5f;
	newBlock2.m_rect = { 0,64,64,64 };
	newBlock2.m_tex = Cnt.m_tex;

	m_CntList.push_back(newBlock2);

	//======================================

	StageClearFlg = false;   //ステージクリアフラグを初期化
}

void C_Count::Stage2Init()
{
	m_CntList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> CntPosList = {
	{(64.0f * 18.2f) - 640,(-64.0f * 6.0f) + 360},
	{(64.0f * 18.2f) - 640,(-64.0f * 2.3f) + 360},
	};


	//============= 敵カウント用 ===========
	Math::Vector2 m_pos1 = CntPosList[0];

	Object newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };
	newBlock.m_scale = 1.5f;
	newBlock.m_rect = { 128,0,64,64 };
	newBlock.m_tex = Cnt.m_tex;

	m_CntList.push_back(newBlock);

	//======================================

	//========== ステージカウント用 ========

	Math::Vector2 m_pos2 = CntPosList[1];

	Object newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };
	newBlock2.m_scale = 1.5f;
	newBlock2.m_rect = { 64,64,64,64 };
	newBlock2.m_tex = Cnt.m_tex;

	m_CntList.push_back(newBlock2);

	//======================================

	StageClearFlg = false;   //ステージクリアフラグを初期化
}

void C_Count::Stage1Action()
{
	C_Enemy* enemy = SCENE.GetEnemy();

	//敵の数をカウント
	if (enemy->GetAlive() == false)
	{
		m_CntList[0].m_rect = { 0,0,64,64 };

		StageClearFlg = true;       //敵が0になったらステージクリアフラグを立てる
	}
}

void C_Count::Stage2Action()
{
	C_Enemy* enemy = SCENE.GetEnemy();
	int aliveCount = enemy->GetAliveCount(); // 生存数を取得

	// 生存数に応じて表示を切り替え
	switch (aliveCount) {

	case 2:
		m_CntList[0].m_rect = { 128, 0, 64, 64 };  // 2の画像
		break;
	case 1:
		m_CntList[0].m_rect = { 64, 0, 64, 64 }; // 1の画像
		break;
	case 0:
		m_CntList[0].m_rect = { 0, 0, 64, 64 }; // 0（またはクリア表示）
		StageClearFlg = true;
		break;
	}
}

void C_Count::Stage1Update()
{
	
	for (auto& cnt : m_CntList)
	{
		cnt.m_transMat = Math::Matrix::CreateTranslation(cnt.m_pos.x, cnt.m_pos.y, 0);
		cnt.m_scaleMat = Math::Matrix::CreateScale(cnt.m_scale, cnt.m_scale, 0);
		cnt.m_mat = cnt.m_scaleMat * cnt.m_transMat;
	}	
}

void C_Count::Stage2Update()
{
	for (auto& cnt : m_CntList)
	{
		cnt.m_transMat = Math::Matrix::CreateTranslation(cnt.m_pos.x, cnt.m_pos.y, 0);
		cnt.m_scaleMat = Math::Matrix::CreateScale(cnt.m_scale, cnt.m_scale, 0);
		cnt.m_mat = cnt.m_scaleMat * cnt.m_transMat;
	}
}

void C_Count::Stage1Draw()
{

	for (auto& cnt : m_CntList)
	{
		SHADER.m_spriteShader.SetMatrix(cnt.m_mat);
		SHADER.m_spriteShader.DrawTex(cnt.m_tex, cnt.m_rect, 1.0f);
	}
}

void C_Count::Stage2Draw()
{
	for (auto& cnt : m_CntList)
	{
		SHADER.m_spriteShader.SetMatrix(cnt.m_mat);
		SHADER.m_spriteShader.DrawTex(cnt.m_tex, cnt.m_rect, 1.0f);
	}
}
