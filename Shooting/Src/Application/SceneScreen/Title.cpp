#include"Title.h"
#include"../Scene.h"

void C_Title::Init()
{
	m_TitleList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> TitlePosList = {
	{0.0f, 0.0f},
	{(64.0f * 10.0f) - 640,(-64.0f * 1.5f) + 360},
	{(64.0f * 10.0f) - 640,(-64.0f * 7.0f) + 360},
	{0.0f, 0.0f},
	};


	//============= 背景 ===========
	Math::Vector2 m_pos1 = TitlePosList[0];

	ObjectParam newBlock;
	newBlock.m_pos = { m_pos1.x , m_pos1.y };
	newBlock.m_scale = 1.0f;
	newBlock.m_alpha = 0.9f;
	newBlock.m_rect = { 0,0,1280,720 };
	newBlock.m_tex = TitleBack.m_tex;

	m_TitleList.push_back(newBlock);

	//============= タイトル名 ===========
	Math::Vector2 m_pos2 = TitlePosList[1];

	ObjectParam newBlock2;
	newBlock2.m_pos = { m_pos2.x , m_pos2.y };
	newBlock2.m_scale = 3.0f;
	newBlock2.m_alpha = 1.0f;
	newBlock2.m_rect =  { 0, 64, 320, 64 };
	newBlock2.m_tex = TitleName.m_tex;

	m_TitleList.push_back(newBlock2);

	//============= スタートボタン ===========
	Math::Vector2 m_pos3 = TitlePosList[2];

	ObjectParam newBlock3;
	newBlock3.m_pos = { m_pos3.x , m_pos3.y };
	newBlock3.m_scale = 2.0f;
	newBlock3.m_alpha = 1.0f;
	newBlock3.m_addAlpha = 0.02f;
	newBlock3.m_rect = { 0,0,256,64 };
	newBlock3.m_tex = TitleStart.m_tex;

	m_TitleList.push_back(newBlock3);

	//============= シーン遷移用 ===========
	Math::Vector2 m_pos4 = TitlePosList[3];

	ObjectParam newBlock4;
	newBlock4.m_pos = { m_pos4.x , m_pos4.y };
	newBlock4.m_scale = 1.0f;
	newBlock4.m_alpha = 0.0f;
	newBlock4.m_addAlpha = 0.02f;
	newBlock4.m_rect = { 0,0,1280,720 };
	newBlock4.m_tex = TitleSceneTransition.m_tex;

	m_TitleList.push_back(newBlock4);

	SceneFlg = false;

	//=======================================

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

		float red = (float)(rand() % 56 + 45) * 0.01f;
		float green = (float)(rand() % 56 + 45) * 0.01f;
		float blue = (float)(rand() % 56 + 45) * 0.01f;

		object.m_color = { red, green, blue, 1.0f };

		//ランダムな移動方向
		angle = (float)(rand() % 360) * (3.14159f / 180.0f);
		object.m_moveDir = { cosf(angle), sinf(angle) };

		// ランダムな回転速度
		object.m_addRot = (float)(rand() % 5 + 1) * 0.01f;

		object.m_tex = ObjectStar.m_tex;

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

		float red = (float)(rand() % 56 + 45) * 0.01f;
		float green = (float)(rand() % 56 + 45) * 0.01f;
		float blue = (float)(rand() % 56 + 45) * 0.01f;

		object2.m_color = { red, green, blue, 1.0f };

		//ランダムな移動方向
		angle2 = (float)(rand() % 360) * (3.14159f / 180.0f);
		object2.m_moveDir = { cosf(angle), sinf(angle) };

		// ランダムな回転速度
		object2.m_addRot = (float)(rand() % 5 + 1) * 0.01f;

		object2.m_tex = ObjectDiamond.m_tex;

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

		float red = (float)(rand() % 56 + 45) * 0.01f;
		float green = (float)(rand() % 56 + 45) * 0.01f;
		float blue = (float)(rand() % 56 + 45) * 0.01f;

		object3.m_color = { red, green, blue, 1.0f };

		//ランダムな移動方向
		angle = (float)(rand() % 360) * (3.14159f / 180.0f);
		object3.m_moveDir = { cosf(angle), sinf(angle) };

		// ランダムな回転速度
		object3.m_addRot = (float)(rand() % 5 + 1) * 0.01f;

		object3.m_tex = ObjectCircle.m_tex;

		m_ObjectList.push_back(object3);
	}
	//======================================
}

void C_Title::Action()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		SceneFlg = true;
	}


	for (int i = 0; i < m_TitleList.size(); i++)
	{
		auto& title = m_TitleList[i];

		if (i == 2)
		{
			title.m_alpha += title.m_addAlpha;

			if (title.m_alpha > 1.0f)
			{
				title.m_alpha = 1.0f;
				title.m_addAlpha *= -1;
			}

			else if (title.m_alpha <= 0.0f)
			{
				title.m_alpha = 0.0f;
				title.m_addAlpha *= -1;
			}
		}

		if (i == 3 && SceneFlg == true)
		{
			title.m_alpha += title.m_addAlpha;

			if (title.m_alpha > 1.5f)
			{
				SceneFlg = false;

				SCENE.SetAnimationScene(SceneType::Stage1); //ステージ1へ遷移
			}

		}

	}

	//============ Object関連 =====================
	for (int i = 0; i < m_ObjectList.size(); i++)
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

void C_Title::Update()
{
	for (auto& title : m_TitleList)
	{

		title.m_transMat = Math::Matrix::CreateTranslation(title.m_pos.x, title.m_pos.y, 0);
		title.m_scaleMat = Math::Matrix::CreateScale(title.m_scale, title.m_scale, 0);
		title.m_mat = title.m_scaleMat * title.m_transMat;

	}

	for (auto& object : m_ObjectList)
	{
		auto rotateMat = Math::Matrix::CreateRotationZ(object.m_rot); // Z軸回転
		auto scaleMat = Math::Matrix::CreateScale(object.m_scale, object.m_scale, 0);
		auto transMat = Math::Matrix::CreateTranslation(object.m_pos.x, object.m_pos.y, 0);
		object.m_mat = scaleMat * rotateMat * transMat;
	}
}

void C_Title::Draw()
{

	for (int i = 0; i < m_TitleList.size(); i++)
	{
		auto& title = m_TitleList[i];

		// i == 3 はシーン遷移用なのでここでは描画しない
		if (i == 3) continue;

		SHADER.m_spriteShader.SetMatrix(title.m_mat);
		SHADER.m_spriteShader.DrawTex(title.m_tex, title.m_rect, title.m_alpha);
	}

	for (auto& object : m_ObjectList)
	{
		SHADER.m_spriteShader.SetMatrix(object.m_mat);
		SHADER.m_spriteShader.DrawTex(object.m_tex, &object.m_rect, object.m_color);
	}

	//シーン遷移用を一番最後に描画
	auto& transition = m_TitleList[3];
	SHADER.m_spriteShader.SetMatrix(transition.m_mat);
	SHADER.m_spriteShader.DrawTex(transition.m_tex, transition.m_rect, transition.m_alpha);
}

