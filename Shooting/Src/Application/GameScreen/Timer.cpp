#include"Timer.h"
#include"../Scene.h"
#include <Application/main.h>

void C_Timer::Stage1Init()
{
	ElapsedTime = 0;

	SaveFlg = true;
	
	ClearTime = 0.0f;
}

void C_Timer::Init()
{
	//============= タイマー用 ===========

	m_TimerList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> TimerPosList = {
	{(64.0f * 17.2f) - 640,(-64.0f * 9.0f) + 360},
	{(64.0f * 17.8f) - 640,(-64.0f * 9.0f) + 360},
	{(64.0f * 18.8f) - 640,(-64.0f * 9.0f) + 360},
	{(64.0f * 19.4f) - 640,(-64.0f * 9.0f) + 360},
	};

	Math::Vector2 m_pos1 = TimerPosList[0];

	Object newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };
	newBlock.m_scale = 1.5f;
	newBlock.m_rect = { 0,0,64,64 };
	newBlock.m_tex = Timer.m_tex;

	m_TimerList.push_back(newBlock);


	Math::Vector2 m_pos2 = TimerPosList[1];

	Object newBlock2;
	newBlock2.m_pos = { m_pos2.x,m_pos2.y };
	newBlock2.m_scale = 1.5f;
	newBlock2.m_rect = { 0,0,64,64 };
	newBlock2.m_tex = Timer.m_tex;

	m_TimerList.push_back(newBlock2);

	Math::Vector2 m_pos3 = TimerPosList[2];

	Object newBlock3;
	newBlock3.m_pos = { m_pos3.x,m_pos3.y };
	newBlock3.m_scale = 1.5f;
	newBlock3.m_rect = { 0,0,64,64 };
	newBlock3.m_tex = Timer.m_tex;

	m_TimerList.push_back(newBlock3);

	Math::Vector2 m_pos4 = TimerPosList[3];

	Object newBlock4;
	newBlock4.m_pos = { m_pos4.x,m_pos4.y };
	newBlock4.m_scale = 1.5f;
	newBlock4.m_rect = { 0,0,64,64 };
	newBlock4.m_tex = Timer.m_tex;

	m_TimerList.push_back(newBlock4);

	//=====================================


	//============= Colon用 ===============

	Colon.m_pos.x = (64.0f * 18.3f) - 640;
	Colon.m_pos.y = (-64.0f * 9.0f) + 360;

	Colon.m_scale = 0.4f;

	Colon.m_rect = { 640,0,64,128 };

	Colon.m_tex = Timer.m_tex;

	//=====================================

	//============= タイマー用 ===========

	TimerDigitCnt = 0;

	//===================================
}

void C_Timer::Action()
{
	C_Count* cnt = SCENE.GetCount();

	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	//ステージクリアフラグが立っていないまたはスタートフラグが立っているときのみタイマーの更新を受け付ける
	if (cnt->GetStageClearFlg() == false && gameScreen->GetGameStartFlg() == true)
	{

		//経過時間を加算 (APP.m_DeltaTime はフレーム間の時間)
		ElapsedTime += APP.m_DeltaTime;

		//秒数から表示すべき数字を算出
		int Seconds = (int)ElapsedTime % 60;

		int Minutes = (int)ElapsedTime / 60;

		int DigitSeconds1 = Seconds % 10; // 1秒単位の桁

		int DigitSeconds2 = Seconds / 10; // 10秒単位の桁

		int DigitMinutes1 = (Minutes / 10) % 10; // 10分単位の桁

		int DigitMinutes2 = Minutes % 10; // 1分単位の桁

		// m_TimerListの各ブロックに新しいRectを設定

		// m_TimerList[0] が10分単位

		// m_TimerList[1] が1分単位

		// m_TimerList[2] が10秒単位

		// m_TimerList[3] が1秒単位
		m_TimerList[0].m_rect = { ((long)DigitMinutes1 * 64), 0, 64, 64 };

		m_TimerList[1].m_rect = { ((long)DigitMinutes2 * 64), 0, 64, 64 };

		m_TimerList[2].m_rect = { ((long)DigitSeconds2 * 64), 0, 64, 64 };

		m_TimerList[3].m_rect = { ((long)DigitSeconds1 * 64), 0, 64, 64 };
	}
	else
	{
		//1回だけ保存
		if (!SaveFlg)
		{
			ClearTime = ElapsedTime;
			SaveFlg = true;
		}
	}

}

void C_Timer::Update()
{
	C_Count* cnt = SCENE.GetCount();

	//ステージクリアフラグが立っていないときのみタイマーの更新を受け付ける
	if (cnt->GetStageClearFlg() == false)
	{

		//============= タイマー用 ===========

		for (auto& timer : m_TimerList)
		{
			timer.m_transMat = Math::Matrix::CreateTranslation(timer.m_pos.x, timer.m_pos.y, 0);
			timer.m_scaleMat = Math::Matrix::CreateScale(timer.m_scale, timer.m_scale, 0);
			timer.m_mat = timer.m_scaleMat * timer.m_transMat;
		}

		//===================================

		//============= Colon用 =============

		Colon.m_transMat = Math::Matrix::CreateTranslation(Colon.m_pos.x, Colon.m_pos.y, 0);
		Colon.m_scaleMat = Math::Matrix::CreateScale(Colon.m_scale, Colon.m_scale, 0);
		Colon.m_mat = Colon.m_scaleMat * Colon.m_transMat;

		//===================================
	}
}

void C_Timer::Draw()
{
	//============= タイマー用 ===========

	for (const auto& timer : m_TimerList)
	{

		SHADER.m_spriteShader.SetMatrix(timer.m_mat);
		SHADER.m_spriteShader.DrawTex(timer.m_tex, timer.m_rect, 1.0f);

	}

	//===================================

	//============= Colon用 =============

	SHADER.m_spriteShader.SetMatrix(Colon.m_mat);
	SHADER.m_spriteShader.DrawTex(Colon.m_tex, Colon.m_rect, 1.0f);

	//===================================

}
