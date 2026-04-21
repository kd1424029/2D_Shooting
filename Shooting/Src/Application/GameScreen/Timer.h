#pragma once
#include <vector>
#include "GameScreenBase.h"

using namespace std;

class C_Timer :public C_GameScreenBase
{
public:

	C_Timer() {}
	~C_Timer() {}

	void Stage1Init();  //ステージ1の時だけ初期化するタイマー

	void Init();

	void Action();

	void Update();

	void Draw();

	//=========== セッター =================
	void SetTex(KdTexture* tex) { Timer.m_tex = tex; }

private:

	vector<Object> m_TimerList;

	float ElapsedTime;       //経過時間
	float TimerDigitCnt;             //桁数カウント

	const float ScreenTop = 360;
	const float ScreenBottom = -360;
	const float ScreenLeft = -640;
	const float ScreenRight = 640;

	//タイマー保存用
	float ClearTime;   
	bool SaveFlg;	//保存フラグ

};