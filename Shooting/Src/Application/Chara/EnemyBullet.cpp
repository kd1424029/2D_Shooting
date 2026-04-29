#include"EnemyBullet.h"
#include"../Scene.h"

void C_EnemyBullet::Init()
{
	for (int i = 0; i < EnemyBulletNum; i++)
	{
		EnemyBulletX[i] = 0;
		EnemyBulletY[i] = 0;

		EnemyBulletAlive[i] = false;

		EnemyBulletRadiusX[i] = 8;
		EnemyBulletRadiusY[i] = 8;

		EnemyBulletMoveX[i] = 0;
		EnemyBulletMoveY[i] = 0;

		EnemyBulletRect[i] = { 16,0,16,16 };

		EnemyBulletHomingCnt[i] = 0;
	}

	EnemyBulletSpeed = 0;
}

void C_EnemyBullet::HardInit()
{
	for (int i = 0; i < EnemyBulletNum; i++)
	{
		EnemyBulletX[i] = 0;
		EnemyBulletY[i] = 0;

		EnemyBulletAlive[i] = false;

		EnemyBulletRadiusX[i] = 8;
		EnemyBulletRadiusY[i] = 8;

		EnemyBulletMoveX[i] = 0;
		EnemyBulletMoveY[i] = 0;

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

	//ステージクリアフラグが立っていないときかつスタートフラグが立っているときかつ
	//ゲームオーバーフラグが立っていないときかつプレイヤーが生存しているとき敵の弾の更新を受け付ける
	if (gamescreen->GetStageClearFlg() == false && gamescreen->GetGameStartFlg() == true && gamescreen->GetGameOverFlg() == false)
	{
		auto& Enemy = enemy->GetEnemyList();

		for (int enemy = 0; enemy <Enemy.size(); enemy++)
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

							EnemyBulletRect[EnemyBullet] = { 16,0,16,16 };

							Enemy[enemy].m_BulletTimer = 120;   //2秒間隔で打つようにする
							EnemyBulletHomingCnt[EnemyBullet] = 0;  //ホーミングカウントをリセット

							break;
						}
					}
				}

				//敵2体目
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

							EnemyBulletRect[EnemyBullet] = { 32,0,16,16 };

							Enemy[enemy].m_BulletTimer = 120;   //2秒間隔で打つようにする
							EnemyBulletHomingCnt[EnemyBullet] = 0;  //ホーミングカウントをリセット

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

							EnemyBulletRect[EnemyBullet] = { 48,0,16,16 };

							Enemy[enemy].m_BulletTimer = 120;   //2秒間隔で打つようにする
							EnemyBulletHomingCnt[EnemyBullet] = 0;  //ホーミングカウントをリセット

							break;
						}
					}
				}

				//敵4体目
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

							EnemyBulletRect[EnemyBullet] = { 64,0,16,16 };

							Enemy[enemy].m_BulletTimer = 120;   //2秒間隔で打つようにする
							EnemyBulletHomingCnt[EnemyBullet] = 0;  //ホーミングカウントをリセット

							break;
						}
					}
				}
			}
		}


		for (int i = 0; i < EnemyBulletNum; i++)
		{

			//弾の更新処理
			if (EnemyBulletAlive[i] == true)
			{
				EnemyBulletHomingCnt[i]++;

				if (EnemyBulletHomingCnt[i] < EnemyBulletHomingLimitCnt)
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
				}

				//実際に座標を更新する
				EnemyBulletX[i] += EnemyBulletMoveX[i];
				EnemyBulletY[i] += EnemyBulletMoveY[i];

				//ブロックとの当たり判定
				C_GameScreenBlock* block = SCENE.GetGameScreenBlock();
				if (block->ObjectBulletHit(EnemyBulletX[i], EnemyBulletY[i]))
				{
					EnemyBulletAlive[i] = false;

					for (int count = 0; count < BulletEffectNUM; count++)
					{
						SCENE.GetEffectManager()->Add(
							{ EnemyBulletX[i],EnemyBulletY[i] },
							{ Rnd() * 3 - 1, Rnd() * 3 - 1 },
							2.0f, { 1, 1, 1, 1 }, 60
						);
					}
					continue; // 弾が消えたので以降の判定はスキップ
				}

				//弾が画面外に出たら消滅状態にする
				if (EnemyBulletY[i] > ScreenTop || EnemyBulletY[i] < ScreenBottom || EnemyBulletX[i] > ScreenRight || EnemyBulletX[i] < ScreenLeft)
				{
					EnemyBulletAlive[i] = false;

					for (int count = 0; count < BulletEffectNUM; count++)
					{
						//エフェクトの発生
						SCENE.GetEffectManager()->Add(
							{ EnemyBulletX[i],EnemyBulletY[i] }, // 発生場所
							{ Rnd() * 3 - 1,Rnd() * 3 - 1 },       // 飛び散る方向
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

					for (int count = 0; count < BulletEffectNUM; count++)
					{
						//エフェクトの発生
						SCENE.GetEffectManager()->Add(
							{ EnemyBulletX[i],EnemyBulletY[i] }, // 発生場所
							{ Rnd() * 3 - 1,Rnd() * 3 - 1 },       // 飛び散る方向
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

	//ステージクリアフラグが立っていないときのみプレイヤー弾の更新を受け付ける
	if (gameScreen->GetStageClearFlg() == false)
	{

		for (int i = 0; i < EnemyBulletNum; i++)
		{
			if (EnemyBulletAlive[i] == true)
			{
				m_transMat[i] = Math::Matrix::CreateTranslation(EnemyBulletX[i], EnemyBulletY[i], 0);
				m_mat[i] = m_transMat[i];
			}
		}

	}
}

void C_EnemyBullet::Draw()
{
	C_Enemy* enemy = SCENE.GetEnemy();

	for (int i = 0; i < EnemyBulletNum; i++)
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