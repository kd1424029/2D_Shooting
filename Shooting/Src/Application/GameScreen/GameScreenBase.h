#pragma once

//構造体（各ギミック制御用）
struct Object
{
	Math::Vector2 m_pos;		//現在の座標
	Math::Vector2 m_move;		//移動量
	Math::Matrix m_transMat;	//移動行列
	Math::Matrix m_scaleMat;	//拡縮行列
	Math::Matrix m_mat;			//合成行列
	Math::Rectangle m_rect;

	KdTexture* m_tex = nullptr; //テクスチャ
	
	float m_radiusX;			//X軸方向の半径
	float m_radiusY;			//Y軸方向の半径
	float m_scale;				//拡大
	bool m_alive;				//表示・非表示
	float alpha;                //透明度
	
};

class C_GameScreenBase
{
public:
	C_GameScreenBase() {}
	~C_GameScreenBase() {}
	//Glass glass[20];

	//==================== セッター ======================


	//==================== ゲッター ======================


protected:

	Object Timer;
	Object Colon;
	Object GameScreen;
	Object Cnt;
	Object GameStart;
	Object StageClear;
	Object SceneTransition;
	Object Block;
	Object GameOver;
};
