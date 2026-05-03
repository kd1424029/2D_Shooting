#include"EnemyBullet.h"
#include"../Scene.h"

void C_EnemyBullet::Init()
{
	for (int i = 0; i < EnemyBulletNum; ++i)
	{
		EnemyBulletX[i] = 0;
		EnemyBulletY[i] = 0;

		EnemyBulletAlive[i] = false;

		EnemyBulletRadiusX[i] = 8;
		EnemyBulletRadiusY[i] = 8;

		EnemyBulletDirX[i] = 0;
		EnemyBulletDirY[i] = 0;

		EnemyBulletMoveX[i] = 2;
		EnemyBulletMoveY[i] = 2;

		EnemyBulletRect[i] = { 16,0,16,16 };

		EnemyBulletHomingCnt[i] = 0;
	}

	EnemyBulletSpeed = 0;
}

void C_EnemyBullet::HardInit()
{
	for (int i = 0; i < EnemyBulletNum; ++i)
	{
		EnemyBulletX[i] = 0;
		EnemyBulletY[i] = 0;

		EnemyBulletAlive[i] = false;

		EnemyBulletRadiusX[i] = 8;
		EnemyBulletRadiusY[i] = 8;

		EnemyBulletDirX[i] = 0;
		EnemyBulletDirY[i] = 0;

		EnemyBulletMoveX[i] = 3;
		EnemyBulletMoveY[i] = 3;

		EnemyBulletRect[i] = { 16,0,16,16 };

		EnemyBulletHomingCnt[i] = 0;
	}
	EnemyBulletSpeed = 0;
}

void C_EnemyBullet::Action()
{
	C_Enemy* enemy = SCENE.GetEnemy();

	C_Player* player = SCENE.GetPlayer();

	C_CharaBase* charabase = SCENE.GetCharaBase();

	C_GameScreen* gamescreen = SCENE.GetGameScreen();

	C_Title* title = SCENE.GetTitle();

	C_Sound* sound = SCENE.GetSound();

	//ステージクリアフラグが立っていないときかつスタートフラグが立っているときかつ
	//ゲームオーバーフラグが立っていないときかつプレイヤーが生存しているとき敵の弾の更新を受け付ける
	if (gamescreen->GetStageClearFlg() == false && gamescreen->GetGameStartFlg() == true && gamescreen->GetGameOverFlg() == false)
	{
		auto& Enemy = enemy->GetEnemyList();

		for (int enemy = 0; enemy <Enemy.size(); ++enemy)
		{
			//カウント処理
			Enemy[enemy].m_BulletTimer--;
			if (Enemy[enemy].m_BulletTimer < 0)
			{
				Enemy[enemy].m_BulletTimer = 0;
			}
			for (int EnemyBullet = 0; EnemyBullet < EnemyBulletNum; EnemyBullet++)
			{
				//敵1体目
				if (enemy == 0)
				{
					if (Enemy[enemy].m_BulletTimer == 0)
					{
						if (EnemyBulletAlive[EnemyBullet] == false && Enemy[enemy].m_alive == true)
						{
							//弾を銃器の前から出るようにする
							EnemyBulletX[EnemyBullet] = Enemy[enemy].m_pos.x;
							EnemyBulletY[EnemyBullet] = Enemy[enemy].m_pos.y + Enemy[enemy].m_radius.y;
							EnemyBulletAlive[EnemyBullet] = true;
		
							EnemyBulletDirX[EnemyBullet] = 0.0f;  //Xは動かない
							EnemyBulletDirY[EnemyBullet] = 2.0f;  //上へ直進

							EnemyBulletRect[EnemyBullet] = { 16,0,16,16 };

							Enemy[enemy].m_BulletTimer = 120;   //2秒間隔で打つようにする
							EnemyBulletHomingCnt[EnemyBullet] = 0;  //ホーミングカウントをリセット

							sound->BulletSE();

							break;
						}
					}
				}

				//敵2体目と5体目
				if (enemy == 1 || enemy == 4)
				{
					if (Enemy[enemy].m_BulletTimer == 0)
					{
						if (EnemyBulletAlive[EnemyBullet] == false && Enemy[enemy].m_alive == true)
						{
							//弾を銃器の前から出るようにする
							EnemyBulletX[EnemyBullet] = Enemy[enemy].m_pos.x + Enemy[enemy].m_radius.x;
							EnemyBulletY[EnemyBullet] = Enemy[enemy].m_pos.y;
							EnemyBulletAlive[EnemyBullet] = true;

							EnemyBulletDirX[EnemyBullet] = 2.0f;  //右へ直進
							EnemyBulletDirY[EnemyBullet] = 0.0f;  //Yは動かない

							EnemyBulletRect[EnemyBullet] = { 32,0,16,16 };

							Enemy[enemy].m_BulletTimer = 120;   //2秒間隔で打つようにする
							EnemyBulletHomingCnt[EnemyBullet] = 0;  //ホーミングカウントをリセット

							sound->BulletSE();

							break;
						}
					}
				}

				//敵3体目
				if (enemy == 2)
				{
					if (Enemy[enemy].m_BulletTimer == 0)
					{
						if (EnemyBulletAlive[EnemyBullet] == false && Enemy[enemy].m_alive == true)
						{
							//弾を銃器の前から出るようにする
							EnemyBulletX[EnemyBullet] = Enemy[enemy].m_pos.x;
							EnemyBulletY[EnemyBullet] = Enemy[enemy].m_pos.y - Enemy[enemy].m_radius.y;
							EnemyBulletAlive[EnemyBullet] = true;

							EnemyBulletDirX[EnemyBullet] = 0.0f;  //Xは動かない
							EnemyBulletDirY[EnemyBullet] = -2.0f;  //下へ直進

							EnemyBulletRect[EnemyBullet] = { 48,0,16,16 };

							Enemy[enemy].m_BulletTimer = 120;   //2秒間隔で打つようにする
							EnemyBulletHomingCnt[EnemyBullet] = 0;  //ホーミングカウントをリセット

							sound->BulletSE();

							break;
						}
					}
				}

				//敵4体目と6体目
				if (enemy == 3 || enemy == 5)
				{
					if (Enemy[enemy].m_BulletTimer == 0)
					{
						if (EnemyBulletAlive[EnemyBullet] == false && Enemy[enemy].m_alive == true)
						{
							//弾を銃器の前から出るようにする
							EnemyBulletX[EnemyBullet] = Enemy[enemy].m_pos.x - Enemy[enemy].m_radius.x;
							EnemyBulletY[EnemyBullet] = Enemy[enemy].m_pos.y;
							EnemyBulletAlive[EnemyBullet] = true;

							EnemyBulletDirX[EnemyBullet] = -2.0f; //左へ直進
							EnemyBulletDirY[EnemyBullet] = 0.0f;  //Yは動かない

							EnemyBulletRect[EnemyBullet] = { 64,0,16,16 };

							Enemy[enemy].m_BulletTimer = 120;       //2秒間隔で打つようにする
							EnemyBulletHomingCnt[EnemyBullet] = 0;  //ホーミングカウントをリセット

							sound->BulletSE();

							break;
						}
					}
				}
			}
		}


		//弾の追尾処理と当たり判定処理
		for (int i = 0; i < EnemyBulletNum; i++)
		{

			//弾の更新処理
			if (EnemyBulletAlive[i] == true)
			{
				EnemyBulletHomingCnt[i]++;

				//直進中
				if (EnemyBulletHomingCnt[i] < EnemyBulletStraightLimitCnt) 
				{
					EnemyBulletX[i] += EnemyBulletDirX[i];
					EnemyBulletY[i] += EnemyBulletDirY[i];
				}
				else if (EnemyBulletHomingCnt[i] < EnemyBulletHomingLimitCnt) //追尾開始
				{
					//弾からプレイヤーへの距離と方向を計算
					float DistanceX = player->GetPos().x - EnemyBulletX[i];

					float DistanceY = player->GetPos().y - EnemyBulletY[i];

					//atan2を使って、プレイヤーがいる方向の角度を求める
					float EnemyBulletAngle = atan2f(DistanceY, DistanceX);

					if (title->GetTitleModeFlg() == false)
					{
						//弾のスピード(固定値)を決める
						EnemyBulletSpeed = 2.0f;
					}

					if (title->GetTitleModeFlg() == true)
					{
						//弾のスピード(固定値)を決める
						EnemyBulletSpeed = 3.0f;
					}

					//角度から新しい移動量を計算する
					EnemyBulletMoveX[i] = cosf(EnemyBulletAngle) * EnemyBulletSpeed;

					EnemyBulletMoveY[i] = sinf(EnemyBulletAngle) * EnemyBulletSpeed;

					EnemyBulletX[i] += EnemyBulletMoveX[i];
					EnemyBulletY[i] += EnemyBulletMoveY[i];
				}
				else //追尾終了後の移動
				{
					EnemyBulletX[i] += EnemyBulletMoveX[i];
					EnemyBulletY[i] += EnemyBulletMoveY[i];
				}

				//ブロックとの当たり判定
				C_GameScreenBlock* block = SCENE.GetGameScreenBlock();
				if (block->ObjectBulletHit(EnemyBulletX[i], EnemyBulletY[i]))
				{
					EnemyBulletAlive[i] = false;

					sound->WallHitBurstSE();

					for (int count = 0; count < BulletEffectNUM; ++count)
					{
						SCENE.GetEffectManager()->Add(
							{ EnemyBulletX[i],EnemyBulletY[i] },
							{ Rnd() * 4 - 1,Rnd() * 5 - 1 },
							2.0f, { 1, 1, 1, 1 }, 60
						);
					}
					continue; // 弾が消えたので以降の判定はスキップ
				}

				//弾が画面外に出たら消滅状態にする
				if (EnemyBulletY[i] > ScreenTop || EnemyBulletY[i] < ScreenBottom || EnemyBulletX[i] > ScreenRight || EnemyBulletX[i] < ScreenLeft)
				{
					EnemyBulletAlive[i] = false;

					sound->WallHitBurstSE();

					for (int count = 0; count < BulletEffectNUM; count++)
					{
						//エフェクトの発生
						SCENE.GetEffectManager()->Add(
							{ EnemyBulletX[i],EnemyBulletY[i] }, // 発生場所
							{ Rnd() * 4 - 1,Rnd() * 5 - 1 },       // 飛び散る方向
							2.0f,                                   // サイズ
							{ 1, 1, 1, 1 },                         // 色
							60                                      // 寿命

						);
					}
					continue;
				}

				//敵の弾とプレイヤーの当たり判定処理
				float Bottom = player->GetPos().x - EnemyBulletX[i];     //底辺(X座標の差)
				float Height = player->GetPos().y - EnemyBulletY[i];     //高さ(Y座標の差)
				float Hypotenuse = sqrt(Bottom * Bottom + Height * Height);  //斜辺(距離)

				if (Hypotenuse < EnemyBulletRadius + charabase->GetRadius() && player->GetAlive() == true) //衝突していたら(敵の弾半径＋共通の半径(プレイヤーと同じ半径だから共通ゲッター使用))
				{
					player->SetAlive(false);  //プレイヤーを倒す

					EnemyBulletAlive[i] = false;  //敵の弾も消す

					sound->BurstSE();

					for (int count = 0; count < BulletEffectNUM; ++count)
					{
						//エフェクトの発生
						SCENE.GetEffectManager()->Add(
							{ EnemyBulletX[i],EnemyBulletY[i] },    // 発生場所
							{ Rnd() * 4 - 1,Rnd() * 5 - 1 },        // 飛び散る方向
							2.0f,                                   // サイズ
							{ 1, 1, 1, 1 },                         // 色
							60                                      // 寿命
						);
					}
					continue;
				}
			}
		}
	}
}

void C_EnemyBullet::Update()
{
	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	C_Enemy* enemy = SCENE.GetEnemy();

	////ステージクリアフラグが立っていないときのみプレイヤー弾の更新を受け付ける
	//if (gameScreen->GetStageClearFlg() == false)
	//{

		for (int i = 0; i < EnemyBulletNum; ++i)
		{
			if (EnemyBulletAlive[i] == true)
			{
				m_transMat[i] = Math::Matrix::CreateTranslation(EnemyBulletX[i], EnemyBulletY[i], 0);
				m_mat[i] = m_transMat[i];
			}
		}

	//}
}

void C_EnemyBullet::Draw()
{
	C_Enemy* enemy = SCENE.GetEnemy();

	for (int i = 0; i < EnemyBulletNum; ++i)
	{
		if (EnemyBulletAlive[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(m_mat[i]);
			SHADER.m_spriteShader.DrawTex(m_tex, EnemyBulletRect[i], 1.0f);
		}
	}

}

float C_EnemyBullet::Rnd()
{
	return rand() / (float)RAND_MAX;
}