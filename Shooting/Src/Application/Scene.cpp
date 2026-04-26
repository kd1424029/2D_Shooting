#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	//初期化直後の数フレームは描画させないためのコード
	if (waitFrame > 0) {
		waitFrame--;

		m_gameScreen.SceneTransitionDraw();

		return; // 描画をスキップして真っ暗にする
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

		DrawStage();

		m_block.Draw();

		break;

	case SceneType::Stage4:

		

		break;

	case SceneType::Result:

		break;
	}
}

void Scene::Update()
{

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
		AnimationScene = Result;
	}

	//各シーンの描画処理
	switch (AnimationScene) {
		//タイトル画面
	case SceneType::Title:

		m_title.Action();

		m_title.Update();

		break;

	case SceneType::Stage1:

		CommonUpdate();
		
		m_enemy.Stage1Action();
		
		m_gameScreen.Stage1Action();
		
		m_count.Stage1Action();
		
		break;

	case SceneType::Stage2:

	
		CommonUpdate();

		m_enemy.Stage2Action();
		
		m_gameScreen.Stage2Action();
		
		m_count.Stage2Action();
	
		break;

	case SceneType::Stage3:

		CommonUpdate();

		m_enemy.Stage3Action();
		
		m_gameScreen.Stage3Action();
		
		m_count.Stage3Action();

		m_block.Action();
		m_block.Update();

		break;

	case SceneType::Stage4:

		break;

	case SceneType::Result:

		break;
	}

	//================ シーン遷移の初期化関係処理 ===================
	if (PrevScene != AnimationScene) {
		waitFrame = 5;
		StageInit(AnimationScene);
		PrevScene = AnimationScene;
	}
	//===============================================================

}

void Scene::CommonUpdate()
{
	m_player.Action();
	m_player.Update();

	m_playerBullet.Action();
	m_playerBullet.Update();

	m_gameScreen.Update();

	m_enemy.Update();

	m_enemyBullet.Action();
	m_enemyBullet.Update();

	m_timer.Action();
	m_timer.Update();

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

		StageTexture();

		blockTex.Load("Texture/Screen/GameScreenBlock.png");

		m_block.SetTex(&blockTex);

		CommonInit();

		m_enemy.Stage3Init();

		m_count.Stage3Init();

		m_block.Init();

		break;

	case SceneType::Stage4:

	

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

	m_title.SetObjectStarTex(&bulletEffectTex);

	m_title.SetObjectDiamondTex(&bulletEffectTex);

	m_title.SetObjectCircleTex(&bulletEffectTex);
}
//=============================================================

//================ 各ステージ解放 =============================
void Scene::ReleaseTexture(SceneType NowStage)
{
	//各シーンの描画処理
	switch (NowStage) {
		//タイトル画面
	case SceneType::Title:

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

		

		break;

	case SceneType::Result:

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

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);

		m_player.PlayerImGui();

		m_gameScreen.GameScreenImGui();

	}
	ImGui::End();
}
