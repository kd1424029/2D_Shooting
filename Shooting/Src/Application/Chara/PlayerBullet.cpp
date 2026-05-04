#include"PlayerBullet.h"
#include"../Scene.h"

void C_PlayerBullet::Init()
{
	for (int i = 0; i < PlayerBulletNum; i++)
	{
		PlayerBulletX[i] = 0;
		PlayerBulletY[i] = 0;

		PlayerBulletRadiusX[i] = 8;
		PlayerBulletRadiusY[i] = 8;

		PlayerBulletDirectionX[i] = 0;
		PlayerBulletDirectionY[i] = 0;

		PlayerBulletAlive[i] = false;

		PlayerBulletCnt = 0;
	}


	StageClearTimer = 600;  //コードが重いため600（1秒)
}

void C_PlayerBullet::Action()
{
	C_Player* player = SCENE.GetPlayer();

	C_Enemy* enemy = SCENE.GetEnemy();

	C_CharaBase* charabase = SCENE.GetCharaBase();

	C_GameScreen* gamescreen = SCENE.GetGameScreen();

	C_GameScreenBlock* block = SCENE.GetGameScreenBlock();

	C_Sound* sound = SCENE.GetSound();

	if (gamescreen->GetStageClearFlg() == true || gamescreen->GetGameStartFlg() == false || gamescreen->GetGameOverFlg() == true)
	{
		return;
	}

	for (int i = 0; i < PlayerBulletNum; ++i)
	{
		//==================== 発射処理 ==============================
		if (GetAsyncKeyState(VK_SPACE) & 0x8000 && PlayerBulletCnt == 0)
		{

			if (PlayerBulletAlive[i] == false)
			{
				PlayerBulletAlive[i] = true;  //生存フラグ

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

				sound->BulletSE();

				break;
			}

		}
		//カウント処理
		PlayerBulletCnt--;
		if (PlayerBulletCnt < 0)
		{
			PlayerBulletCnt = 0;
		}
	}

	//============================================================

	//敵が1体でも生きているかを調べるフラグ
	bool EnemyAlive = false;

	for (auto& Enemy : enemy->GetEnemyList())
	{
		if (Enemy.m_alive == true)
		{
			EnemyAlive = true;
			break; // 1体でも見つかればOK
		}
	}

	//==================== 弾の当たり判定系 ==============================
	for (int i = 0; i < PlayerBulletNum; i++)
	{
		//弾が生きていなかったらこの弾の処理は飛ばす
		if (PlayerBulletAlive[i] == false)
		{
			continue;
		}

		PlayerBulletX[i] += PlayerBulletDirectionX[i] * PlayerBulletMoveSpeed;
		PlayerBulletY[i] += PlayerBulletDirectionY[i] * PlayerBulletMoveSpeed;

		//ブロックとの当たり判定
		C_GameScreenBlock* block = SCENE.GetGameScreenBlock();
		if (block->ObjectBulletHit(PlayerBulletX[i], PlayerBulletY[i]))
		{
			PlayerBulletAlive[i] = false;

			sound->WallHitBurstSE();

			for (int count = 0; count < BulletEffectNUM; ++count)
			{
				SCENE.GetEffectManager()->Add(
					{ PlayerBulletX[i], PlayerBulletY[i] },
					{ Rnd() * 4 - 1,Rnd() * 5 - 1 },
					2.0f, { 1, 1, 1, 1 }, 60
				);
			}
			continue; //ブロックは消えないのでcontinue
		}

		//弾が画面外に出たら消滅状態にする
		if (PlayerBulletY[i] > ScreenTop || PlayerBulletY[i] < ScreenBottom || PlayerBulletX[i] > ScreenRight || PlayerBulletX[i] < ScreenLeft)
		{
			PlayerBulletAlive[i] = false;

			sound->WallHitBurstSE();

			for (int count = 0; count < BulletEffectNUM; ++count)
			{
				//エフェクトの発生
				SCENE.GetEffectManager()->Add(
					{ PlayerBulletX[i], PlayerBulletY[i] }, // 発生場所
					{ Rnd() * 4 - 1,Rnd() * 5 - 1 },       // 飛び散る方向
					2.0f,                                   // サイズ
					{ 1, 1, 1, 1 },                         // 色
					60                                      // 寿命
				);

			}

			continue; //画面外は固定なのでcontinue
		}



		for (auto& Enemy : enemy->GetEnemyList())
		{

			if (Enemy.m_alive == false)
			{
				continue;
			}

			//自機の弾と敵の当たり判定処理
			float Bottom = Enemy.m_pos.x - PlayerBulletX[i];
			float Height = Enemy.m_pos.y - PlayerBulletY[i];
			float Hypotenuse = sqrt(Bottom * Bottom + Height * Height);

			if (Hypotenuse < PlayerBulletRadius + charabase->GetRadius())
			{
				Enemy.m_alive = false; // 敵を倒す

				PlayerBulletAlive[i] = false;  //プレイヤーの弾も消す

				sound->BurstSE();

				for (int count = 0; count < BulletEffectNUM; count++)
				{
					//エフェクトの発生
					SCENE.GetEffectManager()->Add(
						{ PlayerBulletX[i], PlayerBulletY[i] }, // 発生場所
						{ Rnd() * 4 - 1,Rnd() * 5 - 1 },       // 飛び散る方向
						2.0f,                                   // サイズ
						{ 1, 1, 1, 1 },                         // 色
						60                                      // 寿命
					);
				}

				break; //弾が消えたのでこの弾の判定は終了

			}
		}

	}
	//============================================================
}

void C_PlayerBullet::Update()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	//ステージクリアフラグが立っていないときのみプレイヤー弾の更新を受け付ける
	if (gameScreen->GetStageClearFlg() == false)
	{

		for (int i = 0; i < PlayerBulletNum; ++i)
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
	for (int i = 0; i < PlayerBulletNum; ++i)
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
