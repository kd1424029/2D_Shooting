#pragma once
#include <vector>
#include "SceneBase.h"

using namespace std;

class C_Result :public C_SceneBase
{
public:

	C_Result() {}
	~C_Result() {}

	void GameClearInit();
	void GameOverInit();

	void Action();

	void GameClearAction();

	void Update();

	void Draw();

	void GameClearDraw();

	//=========== ゲッター =================


	//=========== セッター =================
	void SetResultBackTex(KdTexture* tex) { ResultBack.m_tex = tex; }
	void SetResultGameOverTex(KdTexture* tex) { ResultGameOver.m_tex = tex; }
	void SetResultSceneBackTex(KdTexture* tex) { ResultSceneBack.m_tex = tex; }
	void SetResultSceneTransitionTex(KdTexture* tex) { ResultSceneTransition.m_tex = tex; }
	void SetResultTimeTex(KdTexture* tex) { ResultTime.m_tex = tex; }

	void SetObjectResultStarTex(KdTexture* tex) { ObjectResultStar.m_tex = tex; }
	void SetObjectResultDiamondTex(KdTexture* tex) { ObjectResultDiamond.m_tex = tex; }
	void SetObjectResultCircleTex(KdTexture* tex) { ObjectResultCircle.m_tex = tex; }

private:

	vector<ObjectParam> m_ResultList;
	vector<ObjectParam> m_ObjectList;

	const float ScreenTop = 370;
	const float ScreenBottom = -370;
	const float ScreenLeft = -650;
	const float ScreenRight = 650;

	bool SceneFlg;

	bool ResultStartFlg;

	//計算後に二度と使わないから構造体に入れない
	float angle;  //移動する角度
	float angle2;  //移動する角度
	float angle3;  //移動する角度
};