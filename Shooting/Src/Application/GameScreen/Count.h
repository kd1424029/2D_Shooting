#pragma once
#include <vector>
#include "GameScreenBase.h"

using namespace std;

class C_Count :public C_GameScreenBase
{
public:

	C_Count() {}
	~C_Count() {}

	void Stage1Init();
	void Stage2Init();

	void Stage1Action();
	void Stage2Action();

	void Update();

	void Draw();

	//=========== セッター =================
	void SetTex(KdTexture* tex) { Cnt.m_tex = tex; }

	//========== ゲッター =================
	
private:

	vector<Object> m_CntList;

	bool StageClearFlg;   //ステージクリアフラグ

	int StageClearTimer;  //ステージクリア演出用タイマー	

};