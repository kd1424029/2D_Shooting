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

	//=========== セッター =================
	

	//=========== ゲッター =================
	
private:

	vector<ObjectParam> m_TitleList;

};