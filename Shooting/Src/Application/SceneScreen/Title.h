#pragma once
#include <vector>
#include "SceneBase.h"

using namespace std;

class C_Title :public C_SceneBase
{
public:

	C_Title() {}
	~C_Title() {}

	void Init();

	void Action();

	void Update();

	void Draw();

	//=========== ゲッター =================
	bool GetTitleModeFlg() { return TitleModeFlg; }

	//=========== セッター =================
	void SetTitleNameTex(KdTexture* tex) { TitleName.m_tex = tex; }
	void SetTitleBackTex(KdTexture* tex) { TitleBack.m_tex = tex; }
	void SetTitleStartTex(KdTexture* tex) { TitleStart.m_tex = tex; }
	void SetTitleSceneTransitionTex(KdTexture* tex) { TitleSceneTransition.m_tex = tex; }
	void SetTitleModeTex(KdTexture* tex) { TitleMode.m_tex = tex; }
	void SetTitleModeUITex(KdTexture* tex) { TitleModeUI.m_tex = tex; }
	void SetTitlePickUITex(KdTexture* tex) { TitlePickUI.m_tex = tex; }

	void SetObjectStarTex(KdTexture* tex) { ObjectStar.m_tex = tex; }
	void SetObjectDiamondTex(KdTexture* tex) { ObjectDiamond.m_tex = tex; }
	void SetObjectCircleTex(KdTexture* tex) { ObjectCircle.m_tex = tex; }
	
	
private:

	const float ScreenTop = 370;
	const float ScreenBottom = -370;
	const float ScreenLeft = -650;
	const float ScreenRight = 650;

	vector<ObjectParam> m_TitleList;
	vector<ObjectParam> m_ObjectList;

	bool SceneFlg;

	bool TitleStartFlg;

	bool TitleModeFlg;

	bool m_prevEnterKey;

	//計算後に二度と使わないから構造体に入れない
	float angle;  //移動する角度
	float angle2;  //移動する角度
	float angle3;  //移動する角度

	int NowPick;
};