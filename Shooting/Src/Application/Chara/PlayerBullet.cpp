#include"PlayerBullet.h"
#include"../Scene.h"

void C_PlayerBullet::Init()
{
	for (int i = 0; i < PlayerBulletNum; i++)
	{
		PlayerBulletX[i] = 0;
		PlayerBulletY[i] = 0;


		PlayerBulletDirectionX[i] = 0;
		PlayerBulletDirectionY[i] = 0;

		PlayerBulletAlive[i] = false;

		PlayerBulletMoveSpeed[i] = 3;

		PlayerBulletCnt = 0;
	}


	StageClearTimer = 600;
}

void C_PlayerBullet::Action()
{
	C_Player* player = SCENE.GetPlayer();

	C_Enemy* enemy = SCENE.GetEnemy();

	C_CharaBase* charabase = SCENE.GetCharaBase();

	C_Count* cnt = SCENE.GetCount();

	C_GameScreen* gamescreen = SCENE.GetGameScreen();

	for (int i = 0; i < PlayerBulletNum; i++)
	{
		//発射処理(スペースキーを押したときかつスタートフラグが立っているときかつステージクリアフラグが立っていないとき)
		if (GetAsyncKeyState(VK_SPACE) & 0x8000 && gamescreen->GetGameStartFlg() == true && cnt->GetStageClearFlg() == false)
		{
			if (PlayerBulletCnt == 0)
			{
				if (PlayerBulletAlive[i] == false)
				{
					PlayerBulletAlive[i] = true;  //発射フラグ

					//弾を上方向から出るようにする
					if (player->GetRectUpFlg() == true)
					{
						PlayerBulletX[i] = player->GetPos().x;
						PlayerBulletY[i] = player->GetPos().y + player->GetRadius().y;

						//発射時の方向を保存
						PlayerBulletDirectionX[i] = 0;
						PlayerBulletDirectionY[i] = 1;
					}

					//弾を下方向から出るようにする
					else if (player->GetRectDownFlg() == true)
					{
						PlayerBulletX[i] = player->GetPos().x;
						PlayerBulletY[i] = player->GetPos().y - player->GetRadius().y;

						//発射時の方向を保存
						PlayerBulletDirectionX[i] = 0;
						PlayerBulletDirectionY[i] = -1;
					}

					//弾を左方向から出るようにする
					else if (player->GetRectLeftFlg() == true)
					{
						PlayerBulletX[i] = player->GetPos().x - player->GetRadius().x;
						PlayerBulletY[i] = player->GetPos().y;

						//発射時の方向を保存
						PlayerBulletDirectionX[i] = -1;
						PlayerBulletDirectionY[i] = 0;
					}

					//弾を右方向から出るようにする
					else if (player->GetRectRightFlg() == true)
					{
						PlayerBulletX[i] = player->GetPos().x + player->GetRadius().x;
						PlayerBulletY[i] = player->GetPos().y;

						//発射時の方向を保存
						PlayerBulletDirectionX[i] = 1;
						PlayerBulletDirectionY[i] = 0;
					}

					PlayerBulletCnt = 600; //1秒間隔で打てるようにする

					break;
				}
			}
		}

		//弾移動(プレイヤーの弾が生存状態でかつ敵が生存状態でかつプレイヤーが生存状態のとき))
		if (PlayerBulletAlive[i] == true && enemy->GetAlive() == true && player->GetAlive() == true)
		{
			PlayerBulletX[i] += PlayerBulletDirectionX[i] * PlayerBulletMoveSpeed[i];
			PlayerBulletY[i] += PlayerBulletDirectionY[i] * PlayerBulletMoveSpeed[i];

			//弾が画面外に出たら消滅状態にする
			if (PlayerBulletY[i] > ScreenTop || PlayerBulletY[i] < ScreenBottom || PlayerBulletX[i] > ScreenRight || PlayerBulletX[i] < ScreenLeft)
			{
				PlayerBulletAlive[i] = false;

				for (int count = 0; count < BulletEffectNUM; count++)
				{
					//エフェクトの発生
					SCENE.GetEffectManager()->Add(
						{ PlayerBulletX[i], PlayerBulletY[i] }, // 発生場所
						{ Rnd() * 3 - 1,Rnd() * 3 - 1 },       // 飛び散る方向
						2.0f,                                   // サイズ
						{ 1, 1, 1, 1 },                         // 色
						60                                      // 寿命
					);

				}

			}

			//自機の弾と敵の当たり判定処理
			float Bottom = enemy->GetPos().x - PlayerBulletX[i];     //底辺(X座標の差)
			float Height = enemy->GetPos().y - PlayerBulletY[i];     //高さ(Y座標の差)
			float Hypotenuse = sqrt(Bottom * Bottom + Height * Height);  //斜辺(距離)

			if (Hypotenuse < PlayerBulletRadius + charabase->GetRadius()) //衝突していたら(プレイヤーの弾半径＋敵の半径(プレイヤーと同じ半径だから共通ゲッター使用))
			{
				enemy->SetAlive(false);  //敵を倒す

				PlayerBulletAlive[i] = false;  //プレイヤーの弾も消す


				for (int count = 0; count < BulletEffectNUM; count++)
				{
					//エフェクトの発生
					SCENE.GetEffectManager()->Add(
						{ PlayerBulletX[i], PlayerBulletY[i] }, // 発生場所
						{ Rnd() * 3 - 1,Rnd() * 3 - 1 },       // 飛び散る方向
						2.0f,                                   // サイズ
						{ 1, 1, 1, 1 },                         // 色
						60                                      // 寿命
					);
				}

			}
		}

		//カウント処理
		PlayerBulletCnt--;
		if (PlayerBulletCnt < 0)
		{
			PlayerBulletCnt = 0;
		}

		if (enemy->GetAlive() == false)
		{
			StageClearTimer--;  //敵を倒してすぐ演出しないようにするためのタイマーをカウント

			//1.0秒後くらいからステージクリアフラグを立てる
			if (StageClearTimer < 0)
			{
				gamescreen->SetStageClearFlg(true);  //ステージ1クリア
			}
		}
	}

}

void C_PlayerBullet::Update()
{
	C_Count* cnt = SCENE.GetCount();

	//ステージクリアフラグが立っていないときのみプレイヤー弾の更新を受け付ける
	if (cnt->GetStageClearFlg() == false)
	{

		for (int i = 0; i < PlayerBulletNum; i++)
		{
			if (PlayerBulletAlive[i] == true)
			{
				m_transMat[i] = Math::Matrix::CreateTranslation(PlayerBulletX[i], PlayerBulletY[i], 0);
				m_mat[i] = m_transMat[i];
			}
		}
	}
}

void C_PlayerBullet::Draw()
{
	for (int i = 0; i < PlayerBulletNum; i++)
	{
		if (PlayerBulletAlive[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(m_mat[i]);
			SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
		}
	}

}

float C_PlayerBullet::Rnd()
{
	return rand() / (float)RAND_MAX;
}
