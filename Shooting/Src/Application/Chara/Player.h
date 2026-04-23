#pragma once
#include"CharaBase.h"

class C_Player :public C_CharaBase
{
public:

	C_Player() {}
	~C_Player() {}

	void Init();

	void Action();

	void Update();

	void Draw();

	// GUI処理
	void PlayerImGui();

	//=========== ゲッター =================
	Math::Vector2 GetPos() { return Player.m_pos; }
	Math::Vector2 GetRadius() { return Player.m_radius; }
	bool GetRectUpFlg() { return m_RectUpFlg; }
	bool GetRectDownFlg() { return m_RectDownFlg; }
	bool GetRectLeftFlg() { return m_RectLeftFlg; }
	bool GetRectRightFlg() { return m_RectRightFlg; }

	bool GetAlive() { return Player.m_alive; }

	//=========== セッター =================
	void SetTex(KdTexture* tex) { Player.m_tex = tex; }

	void SetAlive(bool alive) { Player.m_alive = alive; }

private:

	const int MaxPlayerMoveLeft = -372;
	const int MaxPlayerMoveRight = 372;
	const int MaxPlayerMoveTop = 316;
	const int MaxPlayerMoveBottom = -316;

	// ↑キー用
	bool m_NowKeyUp= false;
	bool m_BeforeKeyUp = false;
	bool m_RectUpFlg = false;     //Rect切り替えフラグ (Bulletクラスで必要)
	// →キー用
	bool m_NowKeyRight = false;
	bool m_BeforeKeyRight = false;
	bool m_RectRightFlg = false;     //Rect切り替えフラグ (Bulletクラスで必要)

	// ↓キー用
	bool m_NowKeyDown = false;
	bool m_BeforeKeyDown = false;
	bool m_RectDownFlg = false;     //Rect切り替えフラグ (Bulletクラスで必要)
	// ←キー用
	bool m_NowKeyLeft = false;
	bool m_BeforeKeyLeft = false;
	bool m_RectLeftFlg = false;     //Rect切り替えフラグ (Bulletクラスで必要)


	float GameOverTimer;   //プレイヤーが死んですぐ演出しないようにするためのタイマー
};