#pragma once
#define RADIUSX 32		//プレイヤー画像の半径（X軸方向）
#define RADIUSY 32		//プレイヤー画像の半径（Y軸方向）

//構造体（各ギミック制御用）
struct Param
{
	Math::Vector2 m_pos;		//現在の座標
	Math::Vector2 m_move;		//移動量
	Math::Vector2 m_radius;	    //半径
	Math::Rectangle m_rect;		//描画位置
	Math::Matrix m_transMat;	//移動行列
	Math::Matrix m_scaleMat;	//拡大行列
	Math::Matrix m_mat;			//行列の合成
	KdTexture* m_tex;			//画像情報の格納

	float m_scale;				//拡大
	float m_alpha;                //透明度
	bool m_alive;               //生存フラグ

	float		    m_size;
	Math::Color		m_color;
	float			m_lifespan;
	bool			m_bRepeat;
};

class C_CharaBase
{
public:
	C_CharaBase() {}
	~C_CharaBase() {}
	
	//==================== セッター ======================
	

	//==================== ゲッター ======================
	float GetRadius() { return 32.0f; }   //プレイヤー、敵の共通半径

protected:

	Param Player;
	Param Enemy;
	Param BulletEffect;
};
