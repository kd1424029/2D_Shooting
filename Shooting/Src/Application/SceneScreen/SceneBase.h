#pragma once

//構造体
struct ObjectParam
{
	Math::Vector2 m_pos;		//現在の座標
	Math::Vector2 m_move;		//移動量
	Math::Matrix m_transMat;	//移動行列
	Math::Matrix m_scaleMat;	//拡縮行列
	Math::Matrix m_mat;			//合成行列
	Math::Rectangle m_rect;
	Math::Vector2 m_moveDir;//移動方向
	Math::Color m_color;

	KdTexture* m_tex = nullptr; //テクスチャ

	float m_radiusX;			//X軸方向の半径
	float m_radiusY;			//Y軸方向の半径
	float m_scale;				//拡大
	bool m_alive;				//表示・非表示
	float m_alpha;                //透明度
	float m_addAlpha;             //透明度する速度
	float m_moveSpeed;           //移動速度

	float m_rot = 0.0f;                     //現在の回転角
	float m_addRot = 0.0f;                  // 毎フレームの回転量

};

class C_SceneBase
{
public:
	C_SceneBase() {}
	~C_SceneBase() {}

	//==================== セッター ======================


	//==================== ゲッター ======================


protected:

	ObjectParam TitleName;
	ObjectParam TitleStart;
	ObjectParam TitleBack;
	ObjectParam TitleSceneTransition;
	ObjectParam ObjectStar;
	ObjectParam ObjectDiamond;
	ObjectParam ObjectCircle;
	ObjectParam Result;
};
