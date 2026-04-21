#include"GameScreen.h"
#include"../Scene.h"

void C_GameScreen::Init()
{
	//============= ステージ背景 ===============

	GameScreen.m_pos.x = 0;
	GameScreen.m_pos.y = 0;

	//==========================================

	//============= ゲームスタート用 ===========
	GameStart.m_pos.x = 0;
	GameStart.m_pos.y = 0;

	GameStart.m_scale = 1.5f;

	GameStart.alpha = 1.0f;

	GameStartFlg = false;
	StartTimer = 0;  

	//=========================================

	//============= ステージクリア用 ===========

	StageClear.m_pos.x = 0;
	StageClear.m_pos.y = 0;

	StageClear.m_scale = 1.5f;

	StageClear.alpha = 1.0f;

	StageClearFlg = false;

	StageClearTimer = 0;

	
	SceneTransition.m_pos.x = 0;
	SceneTransition.m_pos.y = 0;

	SceneTransition.m_scale = 1.0f;

	SceneTransition.alpha = 0.0f;

	//==========================================
	    
}

void C_GameScreen::Action()
{
	// スタート演出制御
	if (!GameStartFlg)
	{
		StartTimer++;

		// 0.7秒後くらいからフェード開始
		if (StartTimer > 50)
		{
			GameStart.alpha -= 0.02f;
		}

		// 完全に消えたらゲーム開始
		if (GameStart.alpha <= 0.0f)
		{
			GameStartFlg = true;
		}
	}

	//ステージクリア演出制御
	if (StageClearFlg == true)
	{
		StageClearTimer++;

		// 1.0秒後くらいからフェード開始
		if (StageClearTimer > 60)
		{
			StageClear.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (StageClear.alpha <= 0.0f)
		{
			StageClearFlg = false;

			SCENE.SetAnimationScene(SceneType::Stage2); //ステージ2へ遷移
		}
	}

}

void C_GameScreen::Update()
{
	//============= ステージ背景 ===============

	GameScreen.m_transMat = Math::Matrix::CreateTranslation(GameScreen.m_pos.x, GameScreen.m_pos.y, 0);
	GameScreen.m_mat = GameScreen.m_transMat;

	//==========================================

	//============= ゲームスタート用 ===========
	GameStart.m_transMat = Math::Matrix::CreateTranslation(GameStart.m_pos.x, GameStart.m_pos.y, 0);
	GameStart.m_scaleMat = Math::Matrix::CreateScale(GameStart.m_scale, GameStart.m_scale, 0);
	GameStart.m_mat = GameStart.m_scaleMat * GameStart.m_transMat;

	//=========================================

	//============= ステージクリア用 ===========

	StageClear.m_transMat = Math::Matrix::CreateTranslation(StageClear.m_pos.x, StageClear.m_pos.y, 0);
	StageClear.m_scaleMat = Math::Matrix::CreateScale(StageClear.m_scale, StageClear.m_scale, 0);
	StageClear.m_mat = StageClear.m_scaleMat * StageClear.m_transMat;


	SceneTransition.m_transMat = Math::Matrix::CreateTranslation(SceneTransition.m_pos.x, SceneTransition.m_pos.y, 0);
	SceneTransition.m_scaleMat = Math::Matrix::CreateScale(SceneTransition.m_scale, SceneTransition.m_scale, 0);
	SceneTransition.m_mat = SceneTransition.m_scaleMat * SceneTransition.m_transMat;

	//==========================================

	
}

void C_GameScreen::Draw()
{
	//ステージ背景
	SHADER.m_spriteShader.SetMatrix(GameScreen.m_mat);
	SHADER.m_spriteShader.DrawTex(GameScreen.m_tex, Math::Rectangle{ 0,0,1280,720 }, 1.0f);

}

void C_GameScreen::ProductionDraw()
{
	//================== スタート画像用 =================
	if (!GameStartFlg)
	{
		SHADER.m_spriteShader.SetMatrix(GameStart.m_mat);

		SHADER.m_spriteShader.DrawTex(GameStart.m_tex, Math::Rectangle{ 0,128,128,64 }, GameStart.alpha);
	}

	//===================================================

	//============= ステージクリア演出用 ===========
	if (StageClearFlg == true)
	{
		SHADER.m_spriteShader.SetMatrix(StageClear.m_mat);

		SHADER.m_spriteShader.DrawTex(StageClear.m_tex, Math::Rectangle{ 320,64,256,64 }, StageClear.alpha);


		SHADER.m_spriteShader.SetMatrix(SceneTransition.m_mat);

		SHADER.m_spriteShader.DrawTex(SceneTransition.m_tex, Math::Rectangle{ 0,0,1280,720 }, SceneTransition.alpha);
	}
	//==============================================
}
