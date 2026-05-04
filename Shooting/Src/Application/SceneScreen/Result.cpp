#include "Result.h"
#include "../Scene.h"

void C_Result::GameClearInit()
{
	m_ResultList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> ResultPosList = {
	{0.0f, 0.0f},
	{(64.0f * 10.0f) - 640,(-64.0f * 2.0f) + 360},
	{(64.0f * 10.0f) - 640,(-64.0f * 9.0f) + 360},
	{(64.0f * 8.1f) - 640,(-64.0f * 6.5f) + 360},
	{0.0f, 0.0f},
	};


	//============= 背景 ===========
	Math::Vector2 m_pos1 = ResultPosList[0];

	ObjectParam newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };
	newBlock.m_scale = 1.0f;
	newBlock.m_alpha = 0.9f;
	newBlock.m_rect = { 0,0,1280,720 };
	newBlock.m_tex = ResultBack.m_tex;

	m_ResultList.push_back(newBlock);

	//============= ゲームクリアー ===========
	Math::Vector2 m_pos2 = ResultPosList[1];

	ObjectParam newBlock2;
	newBlock2.m_pos = { m_pos2.x , m_pos2.y };
	newBlock2.m_scale = 3.5f;
	newBlock2.m_alpha = 1.0f;
	newBlock2.m_rect = { 128, 128, 256, 64 };
	newBlock2.m_tex = ResultGameOver.m_tex;

	m_ResultList.push_back(newBlock2);

	//============= タイトルボタン ===========
	Math::Vector2 m_pos3 = ResultPosList[2];

	ObjectParam newBlock3;
	newBlock3.m_pos = { m_pos3.x , m_pos3.y };
	newBlock3.m_scale = 2.0f;
	newBlock3.m_alpha = 1.0f;
	newBlock3.m_addAlpha = 0.02f;
	newBlock3.m_rect = { 384, 128, 384, 64 };
	newBlock3.m_tex = ResultSceneBack.m_tex;

	m_ResultList.push_back(newBlock3);

	//============= タイム ===========
	Math::Vector2 m_pos4 = ResultPosList[3];

	ObjectParam newBlock4;
	newBlock4.m_pos = { m_pos4.x , m_pos4.y };
	newBlock4.m_scale = 2.2f;
	newBlock4.m_alpha = 1.0f;
	newBlock4.m_addAlpha = 0.02f;
	newBlock4.m_rect = { 512, 0, 256, 64 };
	newBlock4.m_tex = ResultTime.m_tex;

	m_ResultList.push_back(newBlock4);

	//============= シーン遷移用 ===========
	Math::Vector2 m_pos5 = ResultPosList[4];

	ObjectParam newBlock5;
	newBlock5.m_pos = { m_pos5.x , m_pos5.y };
	newBlock5.m_scale = 1.0f;
	newBlock5.m_alpha = 1.0f;
	newBlock5.m_addAlpha = 0.02f;
	newBlock5.m_rect = { 0,0,1280,720 };
	newBlock5.m_tex = ResultSceneTransition.m_tex;

	m_ResultList.push_back(newBlock5);

	SceneFlg = false;

	ResultStartFlg = false;


	//============= オブジェクト系 =============
	m_ObjectList.clear();

	//=========== 星の画像 ==================
	for (int i = 0; i < 15; ++i)
	{
		ObjectParam object;

		object.m_pos = { (float)(rand() % 1280 - 640), (float)(rand() % 720 - 360) }; // ランダム位置
		object.m_moveSpeed = (float)(rand() % 100 + 50) * 0.01f; // スピードにバラつきを持たせる
		object.m_scale = 1.5f;
		object.m_rect = { 16,0,16,16 };

		float red   = (float)(rand() % 21 + 80) * 0.01f;
		float green = (float)(rand() % 31 + 70) * 0.01f;
		float blue  = (float)(rand() % 21) * 0.01f;

		object.m_color = { red, green, blue, 1.0f };

		//ランダムな移動方向
		angle = (float)(rand() % 360) * (3.14159f / 180.0f);
		object.m_moveDir = { cosf(angle), sinf(angle) };

		// ランダムな回転速度
		object.m_addRot = (float)(rand() % 5 + 1) * 0.01f;

		object.m_tex = ObjectResultStar.m_tex;

		m_ObjectList.push_back(object);
	}
	//======================================

	//=========== 四角の画像 ==================
	for (int i = 0; i < 15; ++i)
	{
		ObjectParam object2;

		object2.m_pos = { (float)(rand() % 1280 - 640), (float)(rand() % 720 - 360) }; // ランダム位置
		object2.m_moveSpeed = (float)(rand() % 100 + 50) * 0.01f; // スピードにバラつきを持たせる
		object2.m_scale = 1.5f;
		object2.m_rect = { 32,0,16,16 };

		float red   = (float)(rand() % 21 + 80) * 0.01f;
		float green = (float)(rand() % 31 + 70) * 0.01f;
		float blue  = (float)(rand() % 21) * 0.01f;

		object2.m_color = { red, green, blue, 1.0f };

		//ランダムな移動方向
		angle2 = (float)(rand() % 360) * (3.14159f / 180.0f);
		object2.m_moveDir = { cosf(angle2), sinf(angle2) };

		// ランダムな回転速度
		object2.m_addRot = (float)(rand() % 5 + 1) * 0.01f;

		object2.m_tex = ObjectResultDiamond.m_tex;

		m_ObjectList.push_back(object2);
	}
	//======================================

	//=========== 丸の画像 ==================
	for (int i = 0; i < 15; ++i)
	{
		ObjectParam object3;

		object3.m_pos = { (float)(rand() % 1280 - 640), (float)(rand() % 720 - 360) }; // ランダム位置
		object3.m_moveSpeed = (float)(rand() % 100 + 50) * 0.01f; // スピードにバラつきを持たせる
		object3.m_scale = 1.5f;
		object3.m_rect = { 0,0,16,16 };

		float red   = (float)(rand() % 21 + 80) * 0.01f;
		float green = (float)(rand() % 31 + 70) * 0.01f;
		float blue  = (float)(rand() % 21) * 0.01f;

		object3.m_color = { red, green, blue, 1.0f };

		//ランダムな移動方向
		angle3 = (float)(rand() % 360) * (3.14159f / 180.0f);
		object3.m_moveDir = { cosf(angle3), sinf(angle3) };

		// ランダムな回転速度
		object3.m_addRot = (float)(rand() % 5 + 1) * 0.01f;

		object3.m_tex = ObjectResultCircle.m_tex;

		m_ObjectList.push_back(object3);
	}
	//======================================

	m_ClearSeFlg = false;
}

void C_Result::GameOverInit()
{
	m_ResultList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> ResultPosList = {
	{0.0f, 0.0f},
	{(64.0f * 10.0f) - 640,(-64.0f * 2.5f) + 360},
	{(64.0f * 10.0f) - 640,(-64.0f * 7.0f) + 360},
	{0.0f, 0.0f},
	};


	//============= 背景 ===========
	Math::Vector2 m_pos1 = ResultPosList[0];

	ObjectParam newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };
	newBlock.m_scale = 1.0f;
	newBlock.m_alpha = 0.9f;
	newBlock.m_rect = { 0,0,1280,720 };
	newBlock.m_tex = ResultBack.m_tex;

	m_ResultList.push_back(newBlock);

	//============= ゲームオーバー ===========
	Math::Vector2 m_pos2 = ResultPosList[1];

	ObjectParam newBlock2;
	newBlock2.m_pos = { m_pos2.x , m_pos2.y };
	newBlock2.m_scale = 3.0f;
	newBlock2.m_alpha = 1.0f;
	newBlock2.m_rect = { 256, 0, 256, 64 };
	newBlock2.m_tex = ResultGameOver.m_tex;

	m_ResultList.push_back(newBlock2);

	//============= タイトルボタン ===========
	Math::Vector2 m_pos3 = ResultPosList[2];

	ObjectParam newBlock3;
	newBlock3.m_pos = { m_pos3.x , m_pos3.y };
	newBlock3.m_scale = 2.0f;
	newBlock3.m_alpha = 1.0f;
	newBlock3.m_addAlpha = 0.02f;
	newBlock3.m_rect = { 384, 128, 384, 64 };
	newBlock3.m_tex = ResultSceneBack.m_tex;

	m_ResultList.push_back(newBlock3);

	//============= シーン遷移用 ===========
	Math::Vector2 m_pos4 = ResultPosList[3];

	ObjectParam newBlock4;
	newBlock4.m_pos = { m_pos4.x , m_pos4.y };
	newBlock4.m_scale = 1.0f;
	newBlock4.m_alpha = 1.0f;
	newBlock4.m_addAlpha = 0.02f;
	newBlock4.m_rect = { 0,0,1280,720 };
	newBlock4.m_tex = ResultSceneTransition.m_tex;

	m_ResultList.push_back(newBlock4);

	SceneFlg = false;

	ResultStartFlg = false;


	//============= オブジェクト系 =============
	m_ObjectList.clear();

	//=========== 星の画像 ==================
	for (int i = 0; i < 15; ++i)
	{
		ObjectParam object;

		object.m_pos = { (float)(rand() % 1280 - 640), (float)(rand() % 720 - 360) }; // ランダム位置
		object.m_moveSpeed = (float)(rand() % 100 + 50) * 0.01f; // スピードにバラつきを持たせる
		object.m_scale = 1.5f;
		object.m_rect = { 16,0,16,16 };

		float red   = (float)(rand() % 31 + 70) * 0.01f;
		float green = (float)(rand() % 31) * 0.01f;
		float blue  = (float)(rand() % 31) * 0.01f;

		object.m_color = { red, green, blue, 1.0f };

		//ランダムな移動方向
		angle = (float)(rand() % 360) * (3.14159f / 180.0f);
		object.m_moveDir = { cosf(angle), sinf(angle) };

		// ランダムな回転速度
		object.m_addRot = (float)(rand() % 5 + 1) * 0.01f;

		object.m_tex = ObjectResultStar.m_tex;

		m_ObjectList.push_back(object);
	}
	//======================================

	//=========== 四角の画像 ==================
	for (int i = 0; i < 15; ++i)
	{
		ObjectParam object2;

		object2.m_pos = { (float)(rand() % 1280 - 640), (float)(rand() % 720 - 360) }; // ランダム位置
		object2.m_moveSpeed = (float)(rand() % 100 + 50) * 0.01f; // スピードにバラつきを持たせる
		object2.m_scale = 1.5f;
		object2.m_rect = { 32,0,16,16 };

		float red   = (float)(rand() % 31 + 70) * 0.01f;
		float green = (float)(rand() % 31) * 0.01f;
		float blue  = (float)(rand() % 31) * 0.01f;

		object2.m_color = { red, green, blue, 1.0f };

		//ランダムな移動方向
		angle2 = (float)(rand() % 360) * (3.14159f / 180.0f);
		object2.m_moveDir = { cosf(angle2), sinf(angle2) };

		// ランダムな回転速度
		object2.m_addRot = (float)(rand() % 5 + 1) * 0.01f;

		object2.m_tex = ObjectResultDiamond.m_tex;

		m_ObjectList.push_back(object2);
	}
	//======================================

	//=========== 丸の画像 ==================
	for (int i = 0; i < 15; ++i)
	{
		ObjectParam object3;

		object3.m_pos = { (float)(rand() % 1280 - 640), (float)(rand() % 720 - 360) }; // ランダム位置
		object3.m_moveSpeed = (float)(rand() % 100 + 50) * 0.01f; // スピードにバラつきを持たせる
		object3.m_scale = 1.5f;
		object3.m_rect = { 0,0,16,16 };

		float red   = (float)(rand() % 31 + 70) * 0.01f;
		float green = (float)(rand() % 31) * 0.01f;
		float blue  = (float)(rand() % 31) * 0.01f;

		object3.m_color = { red, green, blue, 1.0f };

		//ランダムな移動方向
		angle3 = (float)(rand() % 360) * (3.14159f / 180.0f);
		object3.m_moveDir = { cosf(angle3), sinf(angle3) };

		// ランダムな回転速度
		object3.m_addRot = (float)(rand() % 5 + 1) * 0.01f;

		object3.m_tex = ObjectResultCircle.m_tex;

		m_ObjectList.push_back(object3);
	}
	//======================================
}

void C_Result::Action()
{

	C_Sound* sound = SCENE.GetSound();

	if (GetAsyncKeyState(VK_RETURN) & 0x8000 && ResultStartFlg == true && SceneFlg == false)
	{
		SceneFlg = true;

		sound->ClickSE();
	}


	for (int i = 0; i < m_ResultList.size(); ++i)
	{
		auto& result = m_ResultList[i];

		if (i == 2)
		{
			result.m_alpha += result.m_addAlpha;

			if (result.m_alpha > 1.0f)
			{
				result.m_alpha = 1.0f;
				result.m_addAlpha *= -1;
			}

			else if (result.m_alpha <= 0.3f)
			{
				result.m_alpha = 0.3f;
				result.m_addAlpha *= -1;
			}
		}

		if (i == 3 && SceneFlg == true)
		{
			result.m_alpha += result.m_addAlpha;

			if (result.m_alpha > 1.5f)
			{
				SceneFlg = false;

				SCENE.SetAnimationScene(SceneType::Title); //タイトルへ遷移
			}

		}
		else if(i == 3 && ResultStartFlg == false)
		{
			result.m_alpha -= result.m_addAlpha;

			if (result.m_alpha < 0.0f)
			{
				result.m_alpha = 0.0f;

				ResultStartFlg = true;
			}
		}
	}



	//============ Object関連 =====================
	for (int i = 0; i < m_ObjectList.size(); ++i)
	{
		auto& object = m_ObjectList[i];

		//移動
		object.m_pos.x += object.m_moveDir.x * object.m_moveSpeed;
		object.m_pos.y += object.m_moveDir.y * object.m_moveSpeed;

		//回転
		object.m_rot += object.m_addRot;

		// 画面外に出たらランダム再配置
		if (object.m_pos.x > ScreenRight || object.m_pos.x < ScreenLeft || object.m_pos.y > ScreenTop || object.m_pos.y < ScreenBottom)
		{
			//位置をランダムに選ぶ
			int ObjectPosition = rand() % 4;

			switch (ObjectPosition)
			{
			case 0: //上から出現

				object.m_pos = { (float)(rand() % 1280 - 640), ScreenTop };

				break;
			case 1: //下から出現

				object.m_pos = { (float)(rand() % 1280 - 640), ScreenBottom };

				break;
			case 2: //左から出現

				object.m_pos = { ScreenLeft, (float)(rand() % 720 - 360) };

				break;
			case 3: //右から出現

				object.m_pos = { ScreenRight, (float)(rand() % 720 - 360) };

				break;
			}

			float angle = (float)(rand() % 360) * (3.14159f / 180.0f);

			object.m_moveDir = { cosf(angle), sinf(angle) };

			object.m_rot = 0.0f;
		}
	}

}

void C_Result::GameClearAction()
{
	C_Sound* sound = SCENE.GetSound();

	if (!m_ClearSeFlg)
	{
		sound->ClearSE();
		m_ClearSeFlg = true;
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x8000 && ResultStartFlg == true && SceneFlg == false)
	{
		SceneFlg = true;

		sound->ClickSE();
	}


	for (int i = 0; i < m_ResultList.size(); ++i)
	{
		auto& result = m_ResultList[i];

		if (i == 2)
		{
			result.m_alpha += result.m_addAlpha;

			if (result.m_alpha > 1.0f)
			{
				result.m_alpha = 1.0f;
				result.m_addAlpha *= -1;
			}

			else if (result.m_alpha <= 0.3f)
			{
				result.m_alpha = 0.3f;
				result.m_addAlpha *= -1;
			}
		}

		if (i == 4 && SceneFlg == true)
		{
			result.m_alpha += result.m_addAlpha;

			if (result.m_alpha > 1.5f)
			{
				SceneFlg = false;

				SCENE.SetAnimationScene(SceneType::Title); //タイトルへ遷移

				sound->ClearSEStop();
			}

		}
		else if (i == 4 && ResultStartFlg == false)
		{
			result.m_alpha -= result.m_addAlpha;

			if (result.m_alpha < 0.0f)
			{
				result.m_alpha = 0.0f;

				ResultStartFlg = true;
			}
		}
	}



	//============ Object関連 =====================
	for (int i = 0; i < m_ObjectList.size(); ++i)
	{
		auto& object = m_ObjectList[i];

		//移動
		object.m_pos.x += object.m_moveDir.x * object.m_moveSpeed;
		object.m_pos.y += object.m_moveDir.y * object.m_moveSpeed;

		//回転
		object.m_rot += object.m_addRot;

		//画面外に出たらランダム再配置
		if (object.m_pos.x > ScreenRight || object.m_pos.x < ScreenLeft || object.m_pos.y > ScreenTop || object.m_pos.y < ScreenBottom)
		{
			//位置をランダムに選ぶ
			int ObjectPosition = rand() % 4;

			switch (ObjectPosition)
			{
			case 0: //上から出現

				object.m_pos = { (float)(rand() % 1280 - 640), ScreenTop };

				break;
			case 1: //下から出現

				object.m_pos = { (float)(rand() % 1280 - 640), ScreenBottom };

				break;
			case 2: //左から出現

				object.m_pos = { ScreenLeft, (float)(rand() % 720 - 360) };

				break;
			case 3: //右から出現

				object.m_pos = { ScreenRight, (float)(rand() % 720 - 360) };

				break;
			}

			float angle = (float)(rand() % 360) * (3.14159f / 180.0f);

			object.m_moveDir = { cosf(angle), sinf(angle) };

			object.m_rot = 0.0f;
		}
	}

}

void C_Result::Update()
{
	for (auto& result : m_ResultList)
	{

		result.m_transMat = Math::Matrix::CreateTranslation(result.m_pos.x, result.m_pos.y, 0);
		result.m_scaleMat = Math::Matrix::CreateScale(result.m_scale, result.m_scale, 0);
		result.m_mat = result.m_scaleMat * result.m_transMat;

	}


	for (auto& object : m_ObjectList)
	{
		auto rotateMat = Math::Matrix::CreateRotationZ(object.m_rot); // Z軸回転
		auto scaleMat = Math::Matrix::CreateScale(object.m_scale, object.m_scale, 0);
		auto transMat = Math::Matrix::CreateTranslation(object.m_pos.x, object.m_pos.y, 0);
		object.m_mat = scaleMat * rotateMat * transMat;
	}
}

void C_Result::Draw()
{
	for (int i = 0; i < m_ResultList.size(); ++i)
	{
		auto& result = m_ResultList[i];

		//i == 3 はシーン遷移用なのでここでは描画しない
		if (i == 3) continue;

		SHADER.m_spriteShader.SetMatrix(result.m_mat);
		SHADER.m_spriteShader.DrawTex(result.m_tex, result.m_rect, result.m_alpha);
	}


	for (auto& object : m_ObjectList)
	{
		SHADER.m_spriteShader.SetMatrix(object.m_mat);
		SHADER.m_spriteShader.DrawTex(object.m_tex, &object.m_rect, object.m_color);
	}

	//シーン遷移用を一番最後に描画
	auto& transition = m_ResultList[3];
	SHADER.m_spriteShader.SetMatrix(transition.m_mat);
	SHADER.m_spriteShader.DrawTex(transition.m_tex, transition.m_rect, transition.m_alpha);
}

void C_Result::GameClearDraw()
{
	C_Timer* timer = SCENE.GetTimer();

	for (int i = 0; i < m_ResultList.size(); ++i)
	{
		auto& result = m_ResultList[i];

		// i == 4 はシーン遷移用なのでここでは描画しない
		if (i == 4) continue;

		SHADER.m_spriteShader.SetMatrix(result.m_mat);
		SHADER.m_spriteShader.DrawTex(result.m_tex, result.m_rect, result.m_alpha);
	}


	for (auto& object : m_ObjectList)
	{
		SHADER.m_spriteShader.SetMatrix(object.m_mat);
		SHADER.m_spriteShader.DrawTex(object.m_tex, &object.m_rect, object.m_color);
	}

	timer->Draw();

	//シーン遷移用を一番最後に描画
	auto& transition = m_ResultList[4];
	SHADER.m_spriteShader.SetMatrix(transition.m_mat);
	SHADER.m_spriteShader.DrawTex(transition.m_tex, transition.m_rect, transition.m_alpha);
}
