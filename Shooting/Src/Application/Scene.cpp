#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{

	//初期化直後の数フレームは描画させないためのフラグ
	static int waitFrame = 0;
	if (PrevScene != AnimationScene) {
		waitFrame = 5; // 5フレームだけ描画を待機させる
	}

	if (waitFrame > 0) {
		waitFrame--;

		m_gamescreen.SceneTransitionDraw();

		return; // 描画をスキップして真っ暗にする
	}

	//各シーンの描画処理
	switch (AnimationScene) {

		//タイトル画面
	case SceneType::Title:
		break;

	case SceneType::Stage1:

		m_gamescreen.Draw();

		m_timer.Draw();

		m_player.Draw();

		m_enemy.Stage1Draw();

		m_enemybullet.Draw();

		m_playerbullet.Draw();
		
		m_count.Stage1Draw();

		m_effectManager.Draw();

		m_gamescreen.ProductionDraw();

		break;

	case SceneType::Stage2:

		m_gamescreen.Draw();

		m_timer.Draw();

		m_player.Draw();

		m_playerbullet.Draw();

		m_gamescreen.ProductionDraw();
		
		break;

	case SceneType::Stage3:

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

	//================ シーン遷移の初期化関係処理 ===================
	if (PrevScene != AnimationScene)
	{
		StageInit(AnimationScene); // シーンが変わった瞬間だけ初期化
		PrevScene = AnimationScene;
	}
	//===============================================================

	//各シーンの描画処理
	switch (AnimationScene) {
		//タイトル画面
	case SceneType::Title:
		break;

	case SceneType::Stage1:

		m_player.Action();
		m_player.Update();

		m_enemy.Stage1Action();
		m_enemy.Stage1Update();

		m_playerbullet.Action();
		m_playerbullet.Update();

		m_enemybullet.Action();
		m_enemybullet.Update();
		
		m_gamescreen.Stage1Action();
		m_gamescreen.Update();

		m_timer.Action();
		m_timer.Update();

		m_count.Stage1Action();
		m_count.Stage1Update();

		m_effectManager.Update();

		break;

	case SceneType::Stage2:

		m_player.Action();
		m_player.Update();

		m_playerbullet.Action();
		m_playerbullet.Update();

		m_gamescreen.Stage2Action();
		m_gamescreen.Update();

		m_timer.Action();
		m_timer.Update();

		break;

	case SceneType::Stage3:

		break;

	case SceneType::Result:

		break;
	}
}

void Scene::Init()
{
	playerTex.Load("Texture/Player/player.png");

	bulletTex.Load("Texture/Player/Bullet.png");

	enemyTex.Load("Texture/Enemy/Enemy.png");

	gamescreenTex.Load("Texture/Screen/GameScreen.png");

	gamestartTex.Load("Texture/Screen/UI.png");

	gameoverTex.Load("Texture/Screen/UI.png");

	timerTex.Load("Texture/Screen/Timer.png");

	countTex.Load("Texture/Screen/Count.png");

	scenetransitionTex.Load("Texture/Screen/SceneTransition.png");

	bulletEffectTex.Load("Texture/Effect/Effect.png");

	m_player.SetTex(&playerTex);

	m_playerbullet.SetTex(&bulletTex);

	m_enemy.SetTex(&enemyTex);

	m_gamescreen.SetGameScreenTex(&gamescreenTex);

	m_gamescreen.SetGameStartTex(&gamestartTex);

	m_gamescreen.SetStageClearTex(&gamestartTex);

	m_gamescreen.SetGameOverTex(&gameoverTex);

	m_gamescreen.SetSceneTransitionTex(&scenetransitionTex);

	m_timer.SetTex(&timerTex);

	m_enemybullet.SetTex(&bulletTex);

	m_count.SetTex(&countTex);

	//================= シーン遷移の初期化関係処理 ===================

	AnimationScene = SceneType::Title; //最初はタイトル画面から
	PrevScene = AnimationScene;

	//===============================================================

}

void Scene::StageInit(SceneType NowStage)
{

	//各シーンの描画処理
	switch (NowStage) {
		//タイトル画面
	case SceneType::Title:
		break;

	case SceneType::Stage1:

		m_player.Init();

		m_enemy.Stage1Init();

		m_playerbullet.Init();

		m_enemybullet.Init();

		m_gamescreen.Init();

		m_timer.Init(); 

		m_timer.Stage1Init();//ステージ1のときだけ初期化する関数

		m_effectManager.Init(&bulletEffectTex);

		m_count.Stage1Init(); 

		break;

	case SceneType::Stage2:

		m_player.Init();

		m_playerbullet.Init();

		m_timer.Init();

		m_gamescreen.Init();

		m_count.Stage2Init();
		
		break;

	case SceneType::Stage3:

		break;
	}
}

void Scene::Release()
{
	// 画像の解放処理
	playerTex.Release();

	enemyTex.Release();

	bulletTex.Release();

	gamescreenTex.Release();

	gamestartTex.Release();

	gameoverTex.Release();

	timerTex.Release();

	countTex.Release();

	scenetransitionTex.Release();
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
	}
	ImGui::End();
}
