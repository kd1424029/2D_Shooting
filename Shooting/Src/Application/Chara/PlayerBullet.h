#pragma once
#include"CharaBase.h"
#include "BulletEffect.h"

using namespace std;

class Scene;


class C_PlayerBullet
{
public:


	C_PlayerBullet() {}
	~C_PlayerBullet() {}

	void Init();

	void Action();

	void Stage2Action();

	void Update();

	void Draw();

	float Rnd();

	//=========== ゲッター =================
	float GetPlayerBulletNum() { return PlayerBulletNum; }
	
	//=========== セッター =================
	void SetTex(KdTexture* tex) { m_tex = tex; }
	
private:

	const float ScreenTop = 350;
	const float ScreenBottom = -350;
	const float ScreenLeft = -405;
	const float ScreenRight = 405;

	static const int PlayerBulletNum = 10; //弾数
	float PlayerBulletCnt; //弾発射間隔 (1秒)

	float StageClearTimer;  //敵を倒してすぐ演出しないようにするためのタイマー

	const float PlayerBulletRadius = 8.0f;    //半径

	float PlayerBulletX[PlayerBulletNum];
	float PlayerBulletY[PlayerBulletNum];
	float PlayerBulletRadiusX[PlayerBulletNum];
	float PlayerBulletRadiusY[PlayerBulletNum];
	float PlayerBulletDirectionX[PlayerBulletNum];    //Bullet発射後の方向固定用
	float PlayerBulletDirectionY[PlayerBulletNum];    //Bullet発射後の方向固定用
	float PlayerBulletMoveX[PlayerBulletNum];
	float PlayerBulletMoveY[PlayerBulletNum];
	float PlayerBulletMoveSpeed[PlayerBulletNum];
	float PlayerBulletAlive[PlayerBulletNum]; //生存状態

	KdTexture* m_tex;			//画像のポインタ
	Math::Matrix m_scaleMat[PlayerBulletNum];	//拡大行列
	Math::Matrix m_transMat[PlayerBulletNum];	//移動行列
	Math::Matrix m_mat[PlayerBulletNum];			//合成行列

};