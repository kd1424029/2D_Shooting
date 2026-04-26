#pragma once
#include "GameScreenBase.h"
#include <vector>

using namespace std;

class C_GameScreenBlock : public C_GameScreenBase
{
public:

	C_GameScreenBlock() {}
	~C_GameScreenBlock() {}

	void Init();

	void Action();

	void Update();

	void Draw();

	void ObjectHit(Object* a_base);  //オブジェクトの当たり判定

	//=========== セッター =================
	void SetTex(KdTexture* tex) { Block.m_tex = tex; }

	//=========== ゲッター =================
	vector<Object>& GetBlockList() { return m_BlockList; }
	
private:

	vector<Object> m_BlockList;
	
};