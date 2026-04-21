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

	void Stage1Update();
	void Stage2Update();

	void Stage1Draw();
	void Stage2Draw();

	//=========== セッター =================
	void SetTex(KdTexture* tex) { Cnt.m_tex = tex; }

	//========== ゲッター =================
	bool GetStageClearFlg() { return StageClearFlg; }
	
private:

	vector<Object> m_CntList;

	bool StageClearFlg;   //ステージクリアフラグ

};