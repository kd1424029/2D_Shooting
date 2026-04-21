#pragma once
#include "Chara/Player.h"
#include "Chara/PlayerBullet.h"
#include "Chara/Enemy.h"
#include "Chara/EnemyBullet.h"
#include "GameScreen/GameScreen.h"
#include "GameScreen/Timer.h"
#include "GameScreen/Count.h"
#include "Chara/BulletEffect.h"

enum SceneType
{
	Title,				//タイトル
	Stage1,             //ステージ１
	Stage2,             //ステージ2
	Stage3,             //ステージ3
	Result,				//リザルト
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
	C_PlayerBullet m_playerbullet;
	KdTexture bulletTex;

	C_EnemyBullet m_enemybullet;
	KdTexture enemybulletTex;
	//=========== 敵 ================
	C_Enemy m_enemy;
	KdTexture enemyTex;

	//========= ゲーム画面 ==========
	C_GameScreen m_gamescreen;
	KdTexture gamescreenTex;

	C_GameScreen m_gamestart;
	KdTexture gamestartTex;

	C_GameScreen m_stageclear;
	KdTexture stageclearTex;

	C_GameScreen m_scenetransition;
	KdTexture scenetransitionTex;

	//========= タイマー ============
	C_Timer m_timer;
	KdTexture timerTex;

	//========= カウント ==========
	C_Count m_count;
	KdTexture countTex;

	//=========　キャラ共通用 =======
	C_CharaBase m_charabase;

	//========= 弾エフェクト用 =========
	C_BulletEffect m_bulleteffect[BulletEffect_NUM];
	KdTexture bulleteffectTex;
	
public:

	// 初期設定
	void Init();

	void StageInit(SceneType NowStage);    //各ステージごとの初期化

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	// GUI処理
	void ImGuiUpdate();

	//=============== ゲッター ================
	C_Player* GetPlayer() { return &m_player; }

	C_PlayerBullet* GetBullet() { return &m_playerbullet; }

	C_Enemy* GetEnemy() { return &m_enemy; }

	C_EnemyBullet* GetEnemyBullet() { return &m_enemybullet; }

	C_GameScreen* GetGameScreen() { return &m_gamescreen; }

	C_Timer* GetTimer() { return &m_timer; }

	C_CharaBase* GetCharaBase() { return &m_charabase; }

	C_Count* GetCount() { return &m_count; }

	//C_BulletEffect* GetBulletEffect() { return &m_bulleteffect[BulletEffect_NUM]; }

	//=============== セッター ================
	void SetAnimationScene(SceneType a_scene) { AnimationScene = a_scene; }
	

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
