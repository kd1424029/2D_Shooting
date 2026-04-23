#pragma once
#include "GameScreenBase.h"

class C_GameScreen :public C_GameScreenBase
{
public:

	C_GameScreen() {}
	~C_GameScreen() {}

	void Init();

	void Stage1Action();

	void Stage2Action();

	void Stage3Action();

	void Update();

	void Draw();

	void SceneTransitionDraw();  //シーン遷移用描画関数

	void GameScreenImGui();

	void ProductionDraw();  //演出用描画関数

	//=========== セッター =================
	void SetGameScreenTex(KdTexture* tex) { GameScreen.m_tex = tex; }

	void SetGameStartTex(KdTexture* tex) { GameStart.m_tex = tex; }

	void SetStageClearTex(KdTexture* tex) { StageClear.m_tex = tex; }

	void SetGameOverTex(KdTexture* tex) { GameOver.m_tex = tex; }

	void SetSceneTransitionTex(KdTexture* tex) { SceneTransition.m_tex = tex; }

	void SetStageClearFlg(bool clearFlg) { StageClearFlg = clearFlg; }

	void SetGameOverFlg(bool gameoverFlg) { GameOverFlg = gameoverFlg; }

	//=========== ゲッター =================
	bool GetGameStartFlg() { return GameStartFlg; }

	bool GetGameOverFlg() { return GameOverFlg; }

	bool GetStageClearFlg() { return StageClearFlg; }

private:

	bool GameStartFlg;   //ゲームスタートフラグ
	int  StartTimer;     

	bool StageClearFlg;  //ステージクリアフラグ
	int StageClearTimer;

	bool GameOverFlg;  //ゲームオーバーフラグ
	int GameOverTimer;

};