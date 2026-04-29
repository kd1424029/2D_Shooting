#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	//初期化直後の数フレームは描画させないためのコード
	if (waitFrame > 0) {
		waitFrame--;

		m_gameScreen.SceneTransitionDraw();

		return; //描画をスキップして真っ暗にする
	}

	//各シーンの描画処理
	switch (AnimationScene) {

		//タイトル画面
	case SceneType::Title:

		m_title.Draw();

		break;

	case SceneType::Stage1:

		DrawStage();

		break;

	case SceneType::Stage2:

		DrawStage();
		
		break;

	case SceneType::Stage3:

		DrawBlockStage();

		break;

	case SceneType::Stage4:

		DrawBlockStage();

		break;

	case SceneType::HardStage1:

		DrawStage();

		break;

	case SceneType::HardStage2:

		DrawBlockStage();

		break;

	case SceneType::HardStage3:
;
        DrawBlockStage();

		break;

	case SceneType::HardStage4:

		DrawBlockStage();

		break;

	case SceneType::GameOverResult:

		m_result.Draw();

		break;

	case SceneType::ClearResult:

		m_result.GameClearDraw();

		break;
	}
}

void Scene::Update()
{
	//============== デバッグキー =======================
	if (GetAsyncKeyState('M') & 0x0001)
	{
		AnimationScene = Title;
	}
	if (GetAsyncKeyState('1') & 0x0001)
	{
		AnimationScene = Stage1;
	}
	if (GetAsyncKeyState('2') & 0x0001)
	{
		AnimationScene = Stage2;
	}
	if (GetAsyncKeyState('3') & 0x0001)
	{
		AnimationScene = Stage3;
	}
	if (GetAsyncKeyState('4') & 0x0001)
	{
		AnimationScene = Stage4;
	}
	if (GetAsyncKeyState('7') & 0x0001)
	{
		AnimationScene = HardStage4;
	}
	if (GetAsyncKeyState('5') & 0x0001)
	{
		AnimationScene = ClearResult;
	}
	if (GetAsyncKeyState('6') & 0x0001)
	{
		AnimationScene = GameOverResult;
	}
	//====================================================

	//各シーンの描画処理
	switch (AnimationScene) {
		//タイトル画面
	case SceneType::Title:

		m_title.Action();

		m_title.Update();

		break;

	case SceneType::Stage1:

		CommonUpdate();
		
		m_player.Update();

		m_enemy.Stage1Action();
		
		m_gameScreen.Stage1Action();
	
		break;

	case SceneType::Stage2:

	
		CommonUpdate();

		m_player.Update();

		m_enemy.Stage2Action();
		
		m_gameScreen.Stage2Action();
		
		break;

	case SceneType::Stage3:

		CommonUpdate();

		m_enemy.Stage3Action();
		
		m_gameScreen.Stage3Action();
		
		m_block.Action();

		m_player.Update();

		m_block.Update();

		break;

	case SceneType::Stage4:

		CommonUpdate();

		m_enemy.Stage4Action();

		m_gameScreen.Stage4Action();

		m_block.Stage4Action();

		m_player.Update();

		m_block.Update();

		break;

	case SceneType::HardStage1:

		CommonUpdate();

		m_enemy.HardStage1Action();

		m_gameScreen.HardStage1Action();

		m_player.Update();

		break;

	case SceneType::HardStage2:

		CommonUpdate();

		m_enemy.HardStage2Action();

		m_gameScreen.HardStage2Action();

		m_block.HardStage2Action();

		m_player.Update();

		m_block.Update();

		break;

	case SceneType::HardStage3:
		
		CommonUpdate();

		m_enemy.HardStage3Action();

		m_gameScreen.HardStage3Action();

		m_block.HardStage3Action();

		m_player.Update();

		m_block.Update();

		break;

	case SceneType::HardStage4:

		CommonUpdate();

		m_enemy.HardStage4Action();

		m_gameScreen.HardStage4Action();

		m_block.Action();

		m_player.Update();

		m_block.Update();

		break;

	case SceneType::GameOverResult:

		m_result.Action();

		m_result.Update();

		break;

	case SceneType::ClearResult:

		m_result.GameClearAction();

		m_result.Update();

		m_timer.Update();

		break;
	}

	//================ シーン遷移の初期化関係処理 ===================
	if (PrevScene != AnimationScene) 
	{
		waitFrame = 5; //初期化直後の数フレームは描画させないためのコードで使ってる変数
		StageInit(AnimationScene);
		PrevScene = AnimationScene;
	}
	//===============================================================

}

void Scene::CommonUpdate()
{
	m_player.Action();

	m_playerBullet.Action();
	m_playerBullet.Update();

	m_gameScreen.Update();

	m_enemy.Update();

	m_enemyBullet.Action();
	m_enemyBullet.Update();

	m_timer.Action();
	m_timer.Update();

	m_count.Action();
	m_count.Update();

	m_effectManager.Update();

}

void Scene::Init()
{
	//================= シーン遷移の初期化関係処理 ===================

	AnimationScene = SceneType::Title; //最初はタイトル画面から
	PrevScene = AnimationScene;

	StageInit(AnimationScene);

	//===============================================================

}

//===================== 共通ステージDraw ===================
void Scene::DrawStage()
{
	m_gameScreen.Draw();

	m_timer.Draw();

	m_player.Draw();

	m_enemy.Draw();

	m_enemyBullet.Draw();

	m_playerBullet.Draw();

	m_count.Draw();

	m_effectManager.Draw();

	m_gameScreen.ProductionDraw();
}

void Scene::DrawBlockStage()
{
	m_gameScreen.Draw();

	m_timer.Draw();

	m_player.Draw();

	m_enemy.Draw();

	m_enemyBullet.Draw();

	m_playerBullet.Draw();

	m_block.Draw();

	m_count.Draw();

	m_effectManager.Draw();

	m_gameScreen.ProductionDraw();
}
//=========================================================


//======================== 各ステージ初期化 ==========================
void Scene::StageInit(SceneType NowStage)
{

	ReleaseTexture(NowStage);

	//各シーンの描画処理
	switch (NowStage) {
		//タイトル画面
	case SceneType::Title:

		LoadTitleTexture();

		m_title.Init();

		break;

	case SceneType::Stage1:

		StageTexture();

		CommonInit();

		m_enemy.Stage1Init();

		m_timer.Stage1Init();//ステージ1のときだけ初期化する関数

		m_count.Stage1Init(); 

		break;

	case SceneType::Stage2:

		StageTexture();

		CommonInit();

		m_enemy.Stage2Init();

		m_count.Stage2Init();
		
		break;

	case SceneType::Stage3:

		StageBlockTexture();

		CommonInit();

		m_enemy.Stage3Init();

		m_count.Stage3Init();

		m_block.Stage3Init();

		break;

	case SceneType::Stage4:

		StageBlockTexture();

		CommonInit();

		m_enemy.Stage4Init();

		m_count.Stage4Init();

		m_block.Stage4Init();

		break;

	case SceneType::HardStage1:

		StageTexture();

		CommonHardInit();

		m_player.Init();

		m_enemy.HardStage1Init();

		m_timer.Stage1Init();//ステージ1のときだけ初期化する関数

		m_count.HardStage1Init();

		break;

	case SceneType::HardStage2:

		StageBlockTexture();

		CommonHardInit();

		m_player.HardSrage2Init();

		m_enemy.HardStage2Init();

		m_count.HardStage2Init();

		m_block.HardStage2Init();

		break;

	case SceneType::HardStage3:
		
		StageBlockTexture();

		CommonHardInit();

		m_player.Init();

		m_enemy.HardStage3Init();

		m_count.HardStage3Init();

		m_block.HardStage3Init();

		break;

	case SceneType::HardStage4:

		StageBlockTexture();

		CommonHardInit();

		m_player.Init();

		m_enemy.HardStage4Init();

		m_count.HardStage4Init();

		m_block.HardStage4Init();

		break;

	case SceneType::GameOverResult:

		LoadResultTexture();

		m_result.GameOverInit();

		break;

	case SceneType::ClearResult:

		LoadResultTexture();

		m_result.GameClearInit();

		m_timer.GameClearInit();

		break;
	}
}
//==================================================================


//================== ステージ共通初期化 =====================
void Scene::CommonInit()
{
	m_player.Init();

	m_playerBullet.Init();

	m_enemyBullet.Init();

	m_gameScreen.Init();

	m_timer.Init();

	m_effectManager.Init(&bulletEffectTex);

	m_block.Clear();
}

void Scene::CommonHardInit()
{

	m_playerBullet.Init();

	m_enemyBullet.HardInit();

	m_gameScreen.Init();

	m_timer.Init();

	m_effectManager.Init(&bulletEffectTex);

	m_block.Clear();
}


//==========================================================


//================== ステージ共通読み込み =====================
void Scene::StageTexture()
{
	playerTex.Load("Texture/Player/player.png");

	bulletTex.Load("Texture/Bullet/Bullet.png");

	enemyTex.Load("Texture/Enemy/Enemy.png");

	gameScreenTex.Load("Texture/Screen/GameScreen.png");

	gameUiTex.Load("Texture/Screen/UI.png");

	timerTex.Load("Texture/Screen/Timer.png");

	countTex.Load("Texture/Screen/Count.png");

	sceneTransitionTex.Load("Texture/Screen/SceneTransition.png");

	bulletEffectTex.Load("Texture/Effect/Effect.png");

	m_player.SetTex(&playerTex);

	m_playerBullet.SetTex(&bulletTex);

	m_enemy.SetTex(&enemyTex);

	m_gameScreen.SetGameScreenTex(&gameScreenTex);

	m_gameScreen.SetGameStartTex(&gameUiTex);

	m_gameScreen.SetStageClearTex(&gameUiTex);

	m_gameScreen.SetGameOverTex(&gameUiTex);

	m_gameScreen.SetSceneTransitionTex(&sceneTransitionTex);

	m_timer.SetTex(&timerTex);

	m_enemyBullet.SetTex(&bulletTex);

	m_count.SetTex(&countTex);
}

void Scene::StageBlockTexture()
{
	playerTex.Load("Texture/Player/player.png");

	bulletTex.Load("Texture/Bullet/Bullet.png");

	enemyTex.Load("Texture/Enemy/Enemy.png");

	gameScreenTex.Load("Texture/Screen/GameScreen.png");

	gameUiTex.Load("Texture/Screen/UI.png");

	timerTex.Load("Texture/Screen/Timer.png");

	countTex.Load("Texture/Screen/Count.png");

	sceneTransitionTex.Load("Texture/Screen/SceneTransition.png");

	bulletEffectTex.Load("Texture/Effect/Effect.png");

	blockTex.Load("Texture/Screen/GameScreenBlock.png");

	m_block.SetTex(&blockTex);

	m_player.SetTex(&playerTex);

	m_playerBullet.SetTex(&bulletTex);

	m_enemy.SetTex(&enemyTex);

	m_gameScreen.SetGameScreenTex(&gameScreenTex);

	m_gameScreen.SetGameStartTex(&gameUiTex);

	m_gameScreen.SetStageClearTex(&gameUiTex);

	m_gameScreen.SetGameOverTex(&gameUiTex);

	m_gameScreen.SetSceneTransitionTex(&sceneTransitionTex);

	m_timer.SetTex(&timerTex);

	m_enemyBullet.SetTex(&bulletTex);

	m_count.SetTex(&countTex);
}
//================================================================

//==================== タイトル読み込み ========================
void Scene::LoadTitleTexture()
{
	sceneTransitionTex.Load("Texture/Screen/SceneTransition.png");

	gameUiTex.Load("Texture/Screen/UI.png");

	bulletEffectTex.Load("Texture/Effect/Effect.png");

	m_title.SetTitleBackTex(&sceneTransitionTex);

	m_title.SetTitleNameTex(&gameUiTex);

	m_title.SetTitleStartTex(&gameUiTex);

	m_title.SetTitleSceneTransitionTex(&sceneTransitionTex);

	m_title.SetTitleModeTex(&gameUiTex);

	m_title.SetTitleModeUITex(&gameUiTex);

	m_title.SetObjectStarTex(&bulletEffectTex);

	m_title.SetObjectDiamondTex(&bulletEffectTex);

	m_title.SetObjectCircleTex(&bulletEffectTex);

	m_title.SetTitlePickUITex(&gameUiTex);
}

void Scene::LoadResultTexture()
{
	sceneTransitionTex.Load("Texture/Screen/SceneTransition.png");

	gameUiTex.Load("Texture/Screen/UI.png");

	bulletEffectTex.Load("Texture/Effect/Effect.png");

	m_result.SetResultBackTex(&sceneTransitionTex);

	m_result.SetResultGameOverTex(&gameUiTex);

	m_result.SetResultSceneBackTex(&gameUiTex);

	m_result.SetResultSceneTransitionTex(&sceneTransitionTex);

	m_result.SetResultTimeTex(&gameUiTex);

	m_result.SetObjectResultStarTex(&bulletEffectTex);

	m_result.SetObjectResultDiamondTex(&bulletEffectTex);

	m_result.SetObjectResultCircleTex(&bulletEffectTex);
}
//=============================================================

//================ 各ステージ解放 =============================
void Scene::ReleaseTexture(SceneType NowStage)
{
	//各シーンの描画処理
	switch (NowStage) {
		//タイトル画面
	case SceneType::Title:

		bulletEffectTex.Release();

		gameScreenTex.Release();

		gameUiTex.Release();

		sceneTransitionTex.Release();

		break;

	case SceneType::Stage1:

		playerTex.Release();

		enemyTex.Release();

		bulletTex.Release();

		bulletEffectTex.Release();

		gameScreenTex.Release();

		gameUiTex.Release();

		timerTex.Release();

		countTex.Release();

		sceneTransitionTex.Release();

		break;

	case SceneType::Stage2:

		playerTex.Release();

		enemyTex.Release();

		bulletTex.Release();

		bulletEffectTex.Release();

		gameScreenTex.Release();

		gameUiTex.Release();

		timerTex.Release();

		countTex.Release();

		sceneTransitionTex.Release();

		break;

	case SceneType::Stage3:

		playerTex.Release();

		enemyTex.Release();

		bulletTex.Release();

		gameScreenTex.Release();

		gameUiTex.Release();

		timerTex.Release();

		countTex.Release();

		blockTex.Release();

		sceneTransitionTex.Release();

		break;

	case SceneType::Stage4:

		playerTex.Release();

		enemyTex.Release();

		bulletTex.Release();

		gameScreenTex.Release();

		gameUiTex.Release();

		timerTex.Release();

		countTex.Release();

		blockTex.Release();

		sceneTransitionTex.Release();

		break;

	case SceneType::HardStage1:

		playerTex.Release();

		enemyTex.Release();

		bulletTex.Release();

		gameScreenTex.Release();

		gameUiTex.Release();

		timerTex.Release();

		countTex.Release();

		sceneTransitionTex.Release();

		break;

	case SceneType::HardStage2:

		playerTex.Release();

		enemyTex.Release();

		bulletTex.Release();

		gameScreenTex.Release();

		gameUiTex.Release();

		timerTex.Release();

		countTex.Release();

		blockTex.Release();

		sceneTransitionTex.Release();

		break;

	case SceneType::HardStage3:
		
		playerTex.Release();

		enemyTex.Release();

		bulletTex.Release();

		gameScreenTex.Release();

		gameUiTex.Release();

		timerTex.Release();

		countTex.Release();

		blockTex.Release();

		sceneTransitionTex.Release();

		break;

	case SceneType::HardStage4:

		playerTex.Release();

		enemyTex.Release();

		bulletTex.Release();

		gameScreenTex.Release();

		gameUiTex.Release();

		timerTex.Release();

		countTex.Release();

		blockTex.Release();

		sceneTransitionTex.Release();

		break;

	case SceneType::GameOverResult:

		bulletEffectTex.Release();

		gameScreenTex.Release();

		gameUiTex.Release();

		break;

	case SceneType::ClearResult:

		bulletEffectTex.Release();

		gameScreenTex.Release();

		gameUiTex.Release();

		break;

	}
}
//=========================================================

void Scene::Release()
{
	ReleaseTexture(AnimationScene);
}

void Scene::ImGuiUpdate()
{
	//return;

	//ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	//ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	//// デバッグウィンドウ
	//if (ImGui::Begin("Debug Window"))
	//{
	//	ImGui::Text("FPS : %d", APP.m_fps);

	//	m_player.PlayerImGui();

	//	m_gameScreen.GameScreenImGui();

	//}
	//ImGui::End();
}
