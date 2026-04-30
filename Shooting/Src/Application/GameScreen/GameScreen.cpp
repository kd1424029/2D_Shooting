#include"GameScreen.h"
#include"../Scene.h"

void C_GameScreen::Init()
{
	//============= ステージ背景 ===============

	GameScreen.m_pos.x = 0;
	GameScreen.m_pos.y = 0;

	GameScreen.m_rect = { 0,0,1280,720 };

	//==========================================

	//============= ゲームスタート用 ===========
	GameStart.m_pos.x = 0;
	GameStart.m_pos.y = 0;

	GameStart.m_scale = 1.7f;

	GameStart.m_rect = { 0,128,128,64 };

	GameStart.alpha = 1.0f;

	GameStartFlg = false;
	StartTimer = 0;

	//=========================================

	//============= ステージクリア用 ===========

	StageClear.m_pos.x = 0;
	StageClear.m_pos.y = 0;

	StageClear.m_scale = 1.7f;

	StageClear.m_rect = { 320,64,256,64 };

	StageClear.alpha = 1.0f;

	StageClearFlg = false;

	StageClearTimer = 0;

	//==========================================

	//============= シーン切り替え用 ===========

	SceneTransition.m_pos.x = 0;
	SceneTransition.m_pos.y = 0;

	SceneTransition.m_scale = 1.0f;

	SceneTransition.m_rect = { 0,0,1280,720 };

	SceneTransition.alpha = 1.0f;

	//==========================================

	//============= ゲームオーバー用 ===========

	GameOver.m_pos.x = 0;
	GameOver.m_pos.y = 0;

	GameOver.m_scale = 1.7f;

	GameOver.m_rect = { 256,0,256,64 };

	GameOver.alpha = 1.0f;

	GameOverFlg = false;

	GameOverTimer = 0;

	//==========================================
}

void C_GameScreen::Stage1Action()
{

	C_Sound* sound = SCENE.GetSound();

	// スタート演出制御
	if (!GameStartFlg)
	{
		StartTimer++;

		if (StartTimer == 40)
		{
			sound->StartSE();
		}

		SceneTransition.alpha -= 0.02f; //ゲーム画面を明るくする用

		if (SceneTransition.alpha < 0.0f)
		{
			SceneTransition.alpha = 0.0f;
		}

		// 0.7秒後くらいからフェード開始
		if (StartTimer > 50)
		{
			GameStart.alpha -= 0.02f;
		}

		// 完全に消えたらゲーム開始
		if (GameStart.alpha <= 0.0f)
		{
			GameStartFlg = true;
			SceneTransition.alpha = 0.0f;
		}
	}


	//ステージクリア演出制御
	if (StageClearFlg == true && GameOverFlg == false)
	{
		StageClearTimer++;

		if (StageClearTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (StageClearTimer > 60)
		{
			StageClear.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (StageClear.alpha <  -0.5f)
		{
			StageClearFlg = false;

			SCENE.SetAnimationScene(SceneType::Stage2); //ステージ2へ遷移
		}
	}

	//ゲームオーバー演出制御
	if (GameOverFlg == true && StageClearFlg == false)
	{
		GameOverTimer++;

		if (GameOverTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (GameOverTimer > 60)
		{
			GameOver.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (GameOver.alpha < -0.5f)
		{
			GameOverFlg = false;

			SCENE.SetAnimationScene(SceneType::GameOverResult); //リザルトへ遷移
		}
	}

}

void C_GameScreen::Stage2Action()
{

	C_Sound* sound = SCENE.GetSound();

	// スタート演出制御
	if (GameStartFlg == false)
	{
		StartTimer++;

		if (StartTimer == 40)
		{
			sound->StartSE();
		}

		SceneTransition.alpha -= 0.02f; //ゲーム画面を明るくする用

		if (SceneTransition.alpha < 0.0f)
		{
			SceneTransition.alpha = 0.0f;
		}

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
	else if (StageClearFlg == true && GameOverFlg == false)
	{
		StageClearTimer++;

		if (StageClearTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (StageClearTimer > 60)
		{
			StageClear.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (StageClear.alpha < -0.5f)
		{
			StageClearFlg = false;

			SCENE.SetAnimationScene(SceneType::Stage3); //ステージ3へ遷移
		}
	}

	//ゲームオーバー演出制御
	else if (GameOverFlg == true && StageClearFlg == false)
	{
		GameOverTimer++;

		if (GameOverTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (GameOverTimer > 60)
		{
			GameOver.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (GameOver.alpha < -0.5f)
		{
			GameOverFlg = false;

			SCENE.SetAnimationScene(SceneType::GameOverResult); //リザルトへ遷移
		}
	}
}

void C_GameScreen::Stage3Action()
{

	C_Sound* sound = SCENE.GetSound();

	// スタート演出制御
	if (GameStartFlg == false)
	{
		StartTimer++;

		if (StartTimer == 40)
		{
			sound->StartSE();
		}

		SceneTransition.alpha -= 0.02f; //ゲーム画面を明るくする用

		if (SceneTransition.alpha < 0.0f)
		{
			SceneTransition.alpha = 0.0f;
		}

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
	else if (StageClearFlg == true && GameOverFlg == false)
	{
		StageClearTimer++;

		if (StageClearTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (StageClearTimer > 60)
		{
			StageClear.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (StageClear.alpha < -0.5f)
		{
			StageClearFlg = false;

			SCENE.SetAnimationScene(SceneType::Stage4); //ステージ4へ遷移
		}
	}

	//ゲームオーバー演出制御
	else if (GameOverFlg == true && StageClearFlg == false)
	{
		GameOverTimer++;

		if (GameOverTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (GameOverTimer > 60)
		{
			GameOver.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (GameOver.alpha < -0.5f)
		{
			GameOverFlg = false;

			SCENE.SetAnimationScene(SceneType::GameOverResult); //リザルトへ遷移
		}
	}
}

void C_GameScreen::Stage4Action()
{

	C_Sound* sound = SCENE.GetSound();

	// スタート演出制御
	if (GameStartFlg == false)
	{
		StartTimer++;

		if (StartTimer == 40)
		{
			sound->StartSE();
		}

		SceneTransition.alpha -= 0.02f; //ゲーム画面を明るくする用

		if (SceneTransition.alpha < 0.0f)
		{
			SceneTransition.alpha = 0.0f;
		}

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
	else if (StageClearFlg == true && GameOverFlg == false)
	{
		StageClearTimer++;

		if (StageClearTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (StageClearTimer > 60)
		{
			StageClear.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (StageClear.alpha < -0.5f)
		{
			StageClearFlg = false;

			SCENE.SetAnimationScene(SceneType::ClearResult); //クリアリザルトへ遷移
		}
	}

	//ゲームオーバー演出制御
	else if (GameOverFlg == true && StageClearFlg == false)
	{
		GameOverTimer++;

		if (GameOverTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (GameOverTimer > 60)
		{
			GameOver.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (GameOver.alpha < -0.5f)
		{
			GameOverFlg = false;

			SCENE.SetAnimationScene(SceneType::GameOverResult); //リザルトへ遷移
		}
	}
}

void C_GameScreen::HardStage1Action()
{

	C_Sound* sound = SCENE.GetSound();

	// スタート演出制御
	if (GameStartFlg == false)
	{
		StartTimer++;

		if (StartTimer == 40)
		{
			sound->StartSE();
		}

		SceneTransition.alpha -= 0.02f; //ゲーム画面を明るくする用

		if (SceneTransition.alpha < 0.0f)
		{
			SceneTransition.alpha = 0.0f;
		}

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
	else if (StageClearFlg == true && GameOverFlg == false)
	{
		StageClearTimer++;

		if (StageClearTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (StageClearTimer > 60)
		{
			StageClear.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (StageClear.alpha < -0.5f)
		{
			StageClearFlg = false;

			SCENE.SetAnimationScene(SceneType::HardStage2); //ハードステージ２へ遷移
		}
	}

	//ゲームオーバー演出制御
	else if (GameOverFlg == true && StageClearFlg == false)
	{
		GameOverTimer++;

		if (GameOverTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (GameOverTimer > 60)
		{
			GameOver.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (GameOver.alpha < -0.5f)
		{
			GameOverFlg = false;

			SCENE.SetAnimationScene(SceneType::GameOverResult); //リザルトへ遷移
		}
	}
}

void C_GameScreen::HardStage2Action()
{

	C_Sound* sound = SCENE.GetSound();

	// スタート演出制御
	if (GameStartFlg == false)
	{
		StartTimer++;

		if (StartTimer == 40)
		{
			sound->StartSE();
		}

		SceneTransition.alpha -= 0.02f; //ゲーム画面を明るくする用

		if (SceneTransition.alpha < 0.0f)
		{
			SceneTransition.alpha = 0.0f;
		}

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
	else if (StageClearFlg == true && GameOverFlg == false)
	{
		StageClearTimer++;

		if (StageClearTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (StageClearTimer > 60)
		{
			StageClear.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (StageClear.alpha < -0.5f)
		{
			StageClearFlg = false;

			SCENE.SetAnimationScene(SceneType::HardStage3); //ハードステージ3へ遷移
		}
	}

	//ゲームオーバー演出制御
	else if (GameOverFlg == true && StageClearFlg == false)
	{
		GameOverTimer++;

		if (GameOverTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (GameOverTimer > 60)
		{
			GameOver.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (GameOver.alpha < -0.5f)
		{
			GameOverFlg = false;

			SCENE.SetAnimationScene(SceneType::GameOverResult); //リザルトへ遷移
		}
	}
}

void C_GameScreen::HardStage3Action()
{

	C_Sound* sound = SCENE.GetSound();

	// スタート演出制御
	if (GameStartFlg == false)
	{
		StartTimer++;

		if (StartTimer == 40)
		{
			sound->StartSE();
		}

		SceneTransition.alpha -= 0.02f; //ゲーム画面を明るくする用

		if (SceneTransition.alpha < 0.0f)
		{
			SceneTransition.alpha = 0.0f;
		}

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
	else if (StageClearFlg == true && GameOverFlg == false)
	{
		StageClearTimer++;

		if (StageClearTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (StageClearTimer > 60)
		{
			StageClear.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (StageClear.alpha < -0.5f)
		{
			StageClearFlg = false;

			SCENE.SetAnimationScene(SceneType::HardStage4); //ハードステージ4へ遷移
		}
	}

	//ゲームオーバー演出制御
	else if (GameOverFlg == true && StageClearFlg == false)
	{
		GameOverTimer++;

		if (GameOverTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (GameOverTimer > 60)
		{
			GameOver.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (GameOver.alpha < -0.5f)
		{
			GameOverFlg = false;

			SCENE.SetAnimationScene(SceneType::GameOverResult); //リザルトへ遷移
		}
	}
}

void C_GameScreen::HardStage4Action()
{

	C_Sound* sound = SCENE.GetSound();

	// スタート演出制御
	if (GameStartFlg == false)
	{
		StartTimer++;

		if (StartTimer == 40)
		{
			sound->StartSE();
		}

		SceneTransition.alpha -= 0.02f; //ゲーム画面を明るくする用

		if (SceneTransition.alpha < 0.0f)
		{
			SceneTransition.alpha = 0.0f;
		}

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
	else if (StageClearFlg == true && GameOverFlg == false)
	{
		StageClearTimer++;

		if (StageClearTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (StageClearTimer > 60)
		{
			StageClear.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (StageClear.alpha < -0.5f)
		{
			StageClearFlg = false;

			SCENE.SetAnimationScene(SceneType::ClearResult); //クリアリザルトへ遷移
		}
	}

	//ゲームオーバー演出制御
	else if (GameOverFlg == true && StageClearFlg == false)
	{
		GameOverTimer++;

		if (GameOverTimer == 30)
		{
			sound->StartSE();
		}

		// 1.0秒後くらいからフェード開始
		if (GameOverTimer > 60)
		{
			GameOver.alpha -= 0.02f;

			SceneTransition.alpha += 0.02f; //ゲーム画面を暗くする用
		}

		// 完全に消えたらシーン切り替え
		if (GameOver.alpha < -0.5f)
		{
			GameOverFlg = false;

			SCENE.SetAnimationScene(SceneType::GameOverResult); //リザルトへ遷移
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

	//============= ゲームオーバー用 ===========

	GameOver.m_transMat = Math::Matrix::CreateTranslation(GameOver.m_pos.x, GameOver.m_pos.y, 0);
	GameOver.m_scaleMat = Math::Matrix::CreateScale(GameOver.m_scale, GameOver.m_scale, 0);
	GameOver.m_mat = GameOver.m_scaleMat * GameOver.m_transMat;
	
	//==========================================
	
}

void C_GameScreen::Draw()
{
	//ステージ背景
	SHADER.m_spriteShader.SetMatrix(GameScreen.m_mat);
	SHADER.m_spriteShader.DrawTex(GameScreen.m_tex, GameScreen.m_rect, 1.0f);

}

void C_GameScreen::SceneTransitionDraw()
{
	SHADER.m_spriteShader.SetMatrix(SceneTransition.m_mat);

	SHADER.m_spriteShader.DrawTex(SceneTransition.m_tex, SceneTransition.m_rect, SceneTransition.alpha);
}

void C_GameScreen::ProductionDraw()
{
	//================== スタート画像用 =================
	if (!GameStartFlg)
	{
		SHADER.m_spriteShader.SetMatrix(GameStart.m_mat);

		SHADER.m_spriteShader.DrawTex(GameStart.m_tex, GameStart.m_rect, GameStart.alpha);

		SHADER.m_spriteShader.SetMatrix(SceneTransition.m_mat);

		SHADER.m_spriteShader.DrawTex(SceneTransition.m_tex, SceneTransition.m_rect, SceneTransition.alpha);
	}

	//===================================================

	//============= ステージクリア演出用 ===========
	else if (StageClearFlg == true)
	{
		SHADER.m_spriteShader.SetMatrix(StageClear.m_mat);

		SHADER.m_spriteShader.DrawTex(StageClear.m_tex, StageClear.m_rect, StageClear.alpha);


		SHADER.m_spriteShader.SetMatrix(SceneTransition.m_mat);

		SHADER.m_spriteShader.DrawTex(SceneTransition.m_tex, SceneTransition.m_rect, SceneTransition.alpha);
	}
	//==============================================

	//============= ゲームオーバー演出用 ===========
	else if (GameOverFlg == true)
	{
		SHADER.m_spriteShader.SetMatrix(GameOver.m_mat);

		SHADER.m_spriteShader.DrawTex(GameOver.m_tex, GameOver.m_rect, GameOver.alpha);

		SHADER.m_spriteShader.SetMatrix(SceneTransition.m_mat);

		SHADER.m_spriteShader.DrawTex(SceneTransition.m_tex, SceneTransition.m_rect, SceneTransition.alpha);

	}

	//==============================================

}

void C_GameScreen::GameScreenImGui()
{
	ImGui::Text("StageClearFlg:%d", StageClearFlg);
	ImGui::Text("GameStartFlg:%d", GameStartFlg);
	ImGui::Text("GameOverFlg:%d", GameOverFlg);
}
