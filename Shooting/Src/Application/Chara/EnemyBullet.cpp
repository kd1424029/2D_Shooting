#include"EnemyBullet.h"
#include"../Scene.h"

void C_EnemyBullet::Init()
{
	for (int i = 0; i < EnemyBulletNum; i++)
	{
		EnemyBulletX[i] = 0;
		EnemyBulletY[i] = 0;

		EnemyBulletAlive[i] = false;

		EnemyBulletMoveX[i] = 3;
		EnemyBulletMoveY[i] = 3;

		EnemyBulletCnt = 0;

		EnemyBulletHomingCnt[i] = 0;
	}
}

void C_EnemyBullet::Action()
{
	C_Enemy* enemy = SCENE.GetEnemy();

	C_Player* player = SCENE.GetPlayer();

	C_CharaBase* charabase = SCENE.GetCharaBase();

	C_Count* cnt = SCENE.GetCount();

	C_GameScreen* gameScreen = SCENE.GetGameScreen();

	//ステージクリアフラグが立っていないときかつスタートフラグが立っているとき敵の弾の更新を受け付ける
	if (cnt->GetStageClearFlg() == false && gameScreen->GetGameStartFlg() == true)
	{

		for (int i = 0; i < EnemyBulletNum; i++)
		{
			if (EnemyBulletCnt == 0)
			{
				if (EnemyBulletAlive[i] == false)
				{
					//弾を銃器の前から出るようにする
					EnemyBulletX[i] = enemy->GetPos().x;
					EnemyBulletY[i] = enemy->GetPos().y + enemy->GetRadius().y;

					EnemyBulletAlive[i] = true;

					EnemyBulletCnt = 1800;   //3秒間隔で打つようにする

					EnemyBulletHomingCnt[i] = 0;  //ホーミングカウントをリセット

					break;
				}
			}


			//カウント処理
			EnemyBulletCnt--;

			if (EnemyBulletCnt < 0)
			{
				EnemyBulletCnt = 0;
			}

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

					//弾のスピード(固定値)を決める
					float EnemyBulletSpeed = 2.0f;

					//角度から新しい移動量を計算する
					EnemyBulletMoveX[i] = cosf(EnemyBulletAngle) * EnemyBulletSpeed;
					EnemyBulletMoveY[i] = sinf(EnemyBulletAngle) * EnemyBulletSpeed;

				}

				//実際に座標を更新する
				EnemyBulletX[i] += EnemyBulletMoveX[i];
				EnemyBulletY[i] += EnemyBulletMoveY[i];


				//弾が画面外に出たら消滅状態にする
				if (EnemyBulletY[i] > ScreenTop || EnemyBulletY[i] < ScreenBottom || EnemyBulletX[i] > ScreenRight || EnemyBulletX[i] < ScreenLeft)
				{
					EnemyBulletAlive[i] = false;
				}

				//敵の弾とプレイヤーの当たり判定処理
				float Bottom = player->GetPos().x - EnemyBulletX[i];     //底辺(X座標の差)
				float Height = player->GetPos().y - EnemyBulletY[i];     //高さ(Y座標の差)
				float Hypotenuse = sqrt(Bottom * Bottom + Height * Height);  //斜辺(距離)

				if (Hypotenuse < EnemyBulletRadius + charabase->GetRadius()) //衝突していたら(敵の弾半径＋共通の半径(プレイヤーと同じ半径だから共通ゲッター使用))
				{
					player->SetAlive(false);  //プレイヤーを倒す

					EnemyBulletAlive[i] = false;  //敵の弾も消す
				}
			}
		}
	}
}

void C_EnemyBullet::Update()
{
	C_Count* cnt = SCENE.GetCount();

	C_Enemy* enemy = SCENE.GetEnemy();

	//ステージクリアフラグが立っていないときのみプレイヤー弾の更新を受け付ける
	if (cnt->GetStageClearFlg() == false)
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
			SHADER.m_spriteShader.DrawTex(m_tex, Math::Rectangle{ 16,0,16,16 }, 1.0f);
		}
	}

}
