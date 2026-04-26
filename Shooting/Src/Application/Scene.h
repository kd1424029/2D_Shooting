#pragma once

#include "Chara/Player.h"
#include "Chara/PlayerBullet.h"
#include "Chara/Enemy.h"
#include "Chara/EnemyBullet.h"
#include "GameScreen/GameScreen.h"
#include "GameScreen/Timer.h"
#include "GameScreen/Count.h"
#include "GameScreen/GameScreenBlock.h"
#include "Chara/BulletEffectManager.h"
#include "SceneScreen/Title.h"

enum SceneType
{
	Title,				//タイトル
	Stage1,             //ステージ１
	Stage2,             //ステージ2
	Stage3,             //ステージ3
	Stage4,             //ステージ4
	Result,	            //リザルト
	
};

class Scene
{
private:

	//======== シーン遷移 ===========
	SceneType AnimationScene;
	SceneType PrevScene;        // 1フレーム前のシーン

	//========= プレイヤー ==========
	C_Player m_player;
	KdTexture playerTex;

	//============ 弾 ===============
	C_PlayerBullet m_playerBullet;
	KdTexture bulletTex;

	C_EnemyBullet m_enemyBullet;
	KdTexture enemyBulletTex;
	//=========== 敵 ================
	C_Enemy m_enemy;
	KdTexture enemyTex;

	//========= ゲーム画面 ==========
	C_GameScreen m_gameScreen;
	KdTexture gameScreenTex;

	KdTexture gameUiTex;

	KdTexture sceneTransitionTex;

	C_GameScreenBlock m_block;
	KdTexture blockTex;

	//========= タイマー ============
	C_Timer m_timer;
	KdTexture timerTex;

	//========= カウント ==========
	C_Count m_count;
	KdTexture countTex;

	//=========　キャラ共通用 =======
	C_CharaBase m_charaBase;
	
	//========= 弾エフェクトマネージャ =======
	C_EffectManager m_effectManager; 
	KdTexture bulletEffectTex;     

	//========= タイトル ===============
	C_Title m_title;

public:

	// 初期設定
	void Init();

	void StageInit(SceneType NowStage);    //各ステージごとの初期化

	void CommonInit();                     //各ステージの共通初期化

	void StageTexture();

	void LoadTitleTexture(); 

	void ReleaseTexture(SceneType NowStage);

	// 解放
	void Release();

	// 更新処理
	void Update();

	void CommonUpdate();

	// 描画処理
	void Draw2D();

	void DrawStage();

	// GUI処理
	void ImGuiUpdate();

	//=============== ゲッター ================
	C_Player* GetPlayer() { return &m_player; }

	C_PlayerBullet* GetBullet() { return &m_playerBullet; }

	C_Enemy* GetEnemy() { return &m_enemy; }

	C_EnemyBullet* GetEnemyBullet() { return &m_enemyBullet; }

	C_GameScreen* GetGameScreen() { return &m_gameScreen; }

	C_GameScreenBlock* GetGameScreenBlock() { return &m_block; }

	C_Timer* GetTimer() { return &m_timer; }

	C_CharaBase* GetCharaBase() { return &m_charaBase; }

	C_Count* GetCount() { return &m_count; }

	C_EffectManager* GetEffectManager() { return &m_effectManager; }

	//=============== セッター ================
	void SetAnimationScene(SceneType a_scene) { AnimationScene = a_scene; }
	

private:

	Scene() {}

	int waitFrame = 0;

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
