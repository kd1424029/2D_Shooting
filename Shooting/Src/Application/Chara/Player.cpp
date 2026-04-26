#include"Player.h"
#include"../Scene.h"

void C_Player::Init()
{
	Player.m_pos.x = 0;
	Player.m_pos.y = 100;

	Player.m_move.x = 2;   //移動スピード
	Player.m_move.y = 2;   //移動スピード

	Player.m_radius.x = 32;
	Player.m_radius.y = 32;

	Player.m_rect = { 0,0,64,64 };

	Player.m_alive = true;

	// ↑キー用
	m_NowKeyUp = false;
	m_BeforeKeyUp = false;
	m_RectUpFlg = true;     //Rect切り替えフラグ (Bulletクラスで必要) 最初は上向きなのでtrue
	// →キー用
	m_NowKeyRight = false;
	m_BeforeKeyRight = false;
	m_RectRightFlg = false;     //Rect切り替えフラグ (Bulletクラスで必要)

	// ↓キー用
	m_NowKeyDown = false;
	m_BeforeKeyDown = false;
	m_RectDownFlg = false;     //Rect切り替えフラグ (Bulletクラスで必要)
	// ←キー用
	m_NowKeyLeft = false;
	m_BeforeKeyLeft = false;
	m_RectLeftFlg = false;     //Rect切り替えフラグ (Bulletクラスで必要)


	GameOverTimer = 30;
}

void C_Player::Action()
{
	C_GameScreen* gamescreen= SCENE.GetGameScreen();

	C_Enemy* enemy = SCENE.GetEnemy();
	
	//ステージクリアフラグが立っていないときかつスタートフラグが立っているときプレイヤーの操作を受け付ける
	if (gamescreen->GetStageClearFlg() == false && gamescreen->GetGameStartFlg() == true)
	{
		if (Player.m_alive == true)
		{

			//============ 左右移動 ====================
			if (GetAsyncKeyState('A') & 0x8000)
			{
				Player.m_pos.x -= Player.m_move.x;
			}

			if (GetAsyncKeyState('D') & 0x8000)
			{
				Player.m_pos.x += Player.m_move.x;
			}


			//=========================================


			//============ 上下移動 ====================
			if (GetAsyncKeyState('W') & 0x8000)
			{
				Player.m_pos.y += Player.m_move.y;
			}

			if (GetAsyncKeyState('S') & 0x8000)
			{
				Player.m_pos.y -= Player.m_move.y;
			}
			//========================================== 

			if (Player.m_pos.x < MaxPlayerMoveLeft)
			{
				Player.m_pos.x = MaxPlayerMoveLeft;
			}
			if (Player.m_pos.x > MaxPlayerMoveRight)
			{
				Player.m_pos.x = MaxPlayerMoveRight;
			}
			if (Player.m_pos.y < MaxPlayerMoveBottom)
			{
				Player.m_pos.y = MaxPlayerMoveBottom;
			}
			if (Player.m_pos.y > MaxPlayerMoveTop)
			{
				Player.m_pos.y = MaxPlayerMoveTop;
			}


			//============= 左右銃口位置 ==============
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				if (!m_BeforeKeyLeft) {

					m_BeforeKeyLeft = true;
					m_RectLeftFlg = true;
					Player.m_rect = { 192,0,64,64 };


					m_RectUpFlg = false;
					m_RectDownFlg = false;
					m_RectRightFlg = false;
				}
			}
			else {
				m_BeforeKeyLeft = false;
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				if (!m_BeforeKeyRight) {

					m_BeforeKeyRight = true;
					m_RectRightFlg = true;
					Player.m_rect = { 64,0,64,64 };


					m_RectUpFlg = false;
					m_RectDownFlg = false;
					m_RectLeftFlg = false;
				}
			}
			else {
				m_BeforeKeyRight = false;
			}


			//===========================================


			//============= 上下銃口位置 ==============
			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				if (!m_BeforeKeyUp) {

					m_BeforeKeyUp = true;
					m_RectUpFlg = true;
					Player.m_rect = { 0,0,64,64 };


					m_RectDownFlg = false;
					m_RectRightFlg = false;
					m_RectLeftFlg = false;
				}
			}
			else {
				m_BeforeKeyUp = false;
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				if (!m_BeforeKeyDown) {

					m_BeforeKeyDown = true;
					m_RectDownFlg = true;
					Player.m_rect = { 128,0,64,64 };


					m_RectUpFlg = false;
					m_RectRightFlg = false;
					m_RectLeftFlg = false;
				}
			}
			else {
				m_BeforeKeyDown = false;
			}

			//============================================

		}
	}

	if (Player.m_alive == false && gamescreen->GetStageClearFlg() == false)
	{
		GameOverTimer--;

		if (GameOverTimer < 0)
		{
			//ゲームオーバーにする
			gamescreen->SetGameOverFlg(true);
		}
	}
}

void C_Player::Update()
{

	if (Player.m_alive == true)
	{
		Player.m_transMat = Math::Matrix::CreateTranslation(Player.m_pos.x, Player.m_pos.y, 0);
		Player.m_mat = Player.m_transMat;
	}

}

void C_Player::Draw()
{
	if (Player.m_alive == true)
	{
		SHADER.m_spriteShader.SetMatrix(Player.m_mat);
		SHADER.m_spriteShader.DrawTex(Player.m_tex, Player.m_rect, 1.0f);
	}
}

void C_Player::PlayerImGui()
{
	ImGui::Text("X:%lf", Player.m_pos.x);
	ImGui::Text("Y:%lf", Player.m_pos.y);
}
