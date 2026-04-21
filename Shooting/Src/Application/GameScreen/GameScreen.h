#pragma once
#include "GameScreenBase.h"

class C_GameScreen :public C_GameScreenBase
{
public:

	C_GameScreen() {}
	~C_GameScreen() {}

	void Init();

	void Action();

	void Update();

	void Draw();

	void ProductionDraw();  //演出用描画関数

	//=========== セッター =================
	void SetGameScreenTex(KdTexture* tex) { GameScreen.m_tex = tex; }

	void SetGameStartTex(KdTexture* tex) { GameStart.m_tex = tex; }

	void SetStageClearTex(KdTexture* tex) { StageClear.m_tex = tex; }

	void SetSceneTransitionTex(KdTexture* tex) { SceneTransition.m_tex = tex; }

	void SetStageClearFlg(bool clearFlg) { StageClearFlg = clearFlg; }

	//=========== ゲッター =================
	bool GetGameStartFlg() { return GameStartFlg; }

private:

	bool GameStartFlg;   //ゲームスタートフラグ
	int  StartTimer;     

	bool StageClearFlg;  //ステージクリアフラグ
	int StageClearTimer;

};