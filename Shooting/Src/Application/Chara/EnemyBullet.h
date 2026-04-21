#pragma once
#include"CharaBase.h"

class C_EnemyBullet
{
public:

	C_EnemyBullet() {}
	~C_EnemyBullet() {}

	void Init();

	void Action();

	void Update();

	void Draw();

	//=========== セッター =================
	void SetTex(KdTexture* tex) { m_tex = tex; }

private:

	const float ScreenTop = 350;
	const float ScreenBottom = -350;
	const float ScreenLeft = -405;
	const float ScreenRight = 405;

	static const int EnemyBulletNum = 10; //弾数
	float EnemyBulletCnt; //弾発射間隔 (1秒)

	float EnemyBulletHomingCnt[EnemyBulletNum];      //ホーミングカウント
	const float EnemyBulletHomingLimitCnt = 30; //ホーミングする最大時間(1秒間)

	const float EnemyBulletRadius = 8.0f;    //半径

	float EnemyBulletX[EnemyBulletNum];
	float EnemyBulletY[EnemyBulletNum];
	float EnemyBulletMoveX[EnemyBulletNum];
	float EnemyBulletMoveY[EnemyBulletNum];
	float EnemyBulletAlive[EnemyBulletNum]; //生存状態

	KdTexture* m_tex;			//画像のポインタ
	Math::Matrix m_scaleMat[EnemyBulletNum];	//拡大行列
	Math::Matrix m_transMat[EnemyBulletNum];	//移動行列
	Math::Matrix m_mat[EnemyBulletNum];			//合成行列

};