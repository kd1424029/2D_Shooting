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

	for (int i = 0; i < BulletEffect_NUM; i++)
	{
		//m_bulleteffect->Init();
	}
}

void C_PlayerBullet::Action()
{
	C_Player* player = SCENE.GetPlayer();

	C_Enemy* enemy = SCENE.GetEnemy();
	
	C_CharaBase* charabase = SCENE.GetCharaBase();

	C_Count* cnt = SCENE.GetCount();

	C_GameScreen* gamescreen = SCENE.GetGameScreen();

	//ステージクリアフラグが立っていないときまたはスタートフラグが立っているときプレイヤー弾の更新を受け付ける
	if (cnt->GetStageClearFlg() == false || gamescreen->GetGameStartFlg() == true)
	{

		for (int i = 0; i < PlayerBulletNum; i++)
		{
			//発射処理
			if (GetAsyncKeyState(VK_SPACE) & 0x8000)
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

			//弾移動
			if (PlayerBulletAlive[i] == true)
			{
				PlayerBulletX[i] += PlayerBulletDirectionX[i] * PlayerBulletMoveSpeed[i];
				PlayerBulletY[i] += PlayerBulletDirectionY[i] * PlayerBulletMoveSpeed[i];

				//弾が画面外に出たら消滅状態にする
				if (PlayerBulletY[i] > ScreenTop || PlayerBulletY[i] < ScreenBottom || PlayerBulletX[i] > ScreenRight || PlayerBulletX[i] < ScreenLeft)
				{
					PlayerBulletAlive[i] = false;

				}

				//自機の弾と敵の当たり判定処理
				float Bottom = enemy->GetPos().x - PlayerBulletX[i];     //底辺(X座標の差)
				float Height = enemy->GetPos().y - PlayerBulletY[i];     //高さ(Y座標の差)
				float Hypotenuse = sqrt(Bottom * Bottom + Height * Height);  //斜辺(距離)

				if (Hypotenuse < PlayerBulletRadius + charabase->GetRadius()) //衝突していたら(プレイヤーの弾半径＋敵の半径(プレイヤーと同じ半径だから共通ゲッター使用))
				{
					enemy->SetAlive(false);  //敵を倒す

					PlayerBulletAlive[i] = false;  //プレイヤーの弾も消す

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
			else
			{
				for (int e = 0; i < BulletEffect_NUM; e++)
				{
					//m_bulleteffect[e].Update(Math::Vector2(PlayerBulletX[i], PlayerBulletY[i]), true);
				}
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

	for (int e = 0; e < BulletEffect_NUM; e++)
	{
		//m_bulleteffect[e].Draw();
	}
}
