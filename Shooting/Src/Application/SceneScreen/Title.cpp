#include"Title.h"
#include"../Scene.h"

void C_Title::Init()
{
	m_TitleList.clear();

	//配置したい座標のリスト
	vector<Math::Vector2> TitlePosList = {
	{0.0f, 0.0f},
	{(64.0f * 10.0f) - 640,(-64.0f * 2.5f) + 360},
	{(64.0f * 10.0f) - 640,(-64.0f * 7.0f) + 360},
	{0.0f, 0.0f},
	{ (64.0f * 12.5f) - 640, (-64.0f * 9.0f) + 360 },
	{(64.0f * 8.4f) - 640,(-64.0f * 9.0f) + 360},
	{(64.0f * 9.9f) - 640,(-64.0f * 8.83f) + 360},
	{(64.0f * 10.0f) - 640,(-64.0f * 7.0f) + 360},
	{(64.0f * 16.5f) - 640,(-64.0f * 10.5f) + 360},
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
	newBlock4.m_alpha = 1.0f;
	newBlock4.m_addAlpha = 0.02f;
	newBlock4.m_rect = { 0,0,1280,720 };
	newBlock4.m_tex = TitleSceneTransition.m_tex;

	m_TitleList.push_back(newBlock4);

	SceneFlg = false;

	TitleStartFlg = false;

	//=======================================

	//============= モード ==================
	Math::Vector2 m_pos5 = TitlePosList[4];

	ObjectParam newBlock5;
	newBlock5.m_pos = { m_pos5.x , m_pos5.y };
	newBlock5.m_scale = 2.0f;
	newBlock5.m_alpha = 1.0f;
	newBlock5.m_rect = { 704, 64, 192, 64 };
	newBlock5.m_tex = TitleMode.m_tex;

	TitleModeFlg = false;

	m_TitleList.push_back(newBlock5);
	//=======================================

	//============= ゲームモードUI ==================
	Math::Vector2 m_pos6 = TitlePosList[5];

	ObjectParam newBlock6;
	newBlock6.m_pos = { m_pos6.x , m_pos6.y };
	newBlock6.m_scale = 2.0f;
	newBlock6.m_alpha = 1.0f;
	newBlock6.m_addAlpha = 0.02f;
	newBlock6.m_rect = { 576,64,128,64 };
	newBlock6.m_tex = TitleModeUI.m_tex;

	m_TitleList.push_back(newBlock6);
	//=======================================

	//============= コロン ==================
	Math::Vector2 m_pos7 = TitlePosList[6];

	ObjectParam newBlock7;
	newBlock7.m_pos = { m_pos7.x , m_pos7.y };
	newBlock7.m_scale = 2.5f;
	newBlock7.m_alpha = 1.0f;
	newBlock7.m_rect = { 768,128,64,64 };
	newBlock7.m_tex = TitleModeUI.m_tex;

	m_TitleList.push_back(newBlock7);
	//=======================================

	//============= 選択UI ==================
	Math::Vector2 m_pos8 = TitlePosList[7];

	ObjectParam newBlock8;
	newBlock8.m_pos = { m_pos8.x , m_pos8.y };
	newBlock8.m_scale = 1.85f;
	newBlock8.m_alpha = 1.0f;
	newBlock8.m_rect = { 832,128,256,64 };
	newBlock8.m_tex = TitlePickUI.m_tex;

	m_TitleList.push_back(newBlock8);
	//=======================================

	//============= クレジット ==================
	Math::Vector2 m_pos9 = TitlePosList[8];

	ObjectParam newBlock9;
	newBlock9.m_pos = { m_pos9.x , m_pos9.y };
	newBlock9.m_scale = 1.85f;
	newBlock9.m_alpha = 1.0f;
	newBlock9.m_rect = { 896, 0, 256, 64 };
	newBlock9.m_tex = TitleCreditUI.m_tex;

	m_TitleList.push_back(newBlock9);
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
		object2.m_moveDir = { cosf(angle2), sinf(angle2) };

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
		angle3 = (float)(rand() % 360) * (3.14159f / 180.0f);
		object3.m_moveDir = { cosf(angle3), sinf(angle3) };

		// ランダムな回転速度
		object3.m_addRot = (float)(rand() % 5 + 1) * 0.01f;

		object3.m_tex = ObjectCircle.m_tex;

		m_ObjectList.push_back(object3);
	}
	//======================================

	NowPick = 0;//現在の選択位置

	m_prevEnterKey = false;

	PickMoveSeFlg = false;

	ClickSeFlg = false;
}

void C_Title::Action()
{

	C_Sound* sound = SCENE.GetSound();

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		NowPick = 0;

		if (!PickMoveSeFlg)
		{
			PickMoveSeFlg = true;
			sound->PickMoveSE();
		}
	}
	
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		NowPick = 1;

		if (!PickMoveSeFlg)
		{
			PickMoveSeFlg = true;
			sound->PickMoveSE();
		}
	}
	else
	{
		PickMoveSeFlg = false;
	}
	

	if (GetAsyncKeyState(VK_RETURN) & 0x8000 && TitleStartFlg == true && NowPick == 0 && SceneFlg == false)
	{
		SceneFlg = true;

		if (!ClickSeFlg)
		{
			ClickSeFlg = true;
			sound->ClickSE();
		}
	}
	else
	{
		ClickSeFlg = false;
	}


	for (int i = 0; i < m_TitleList.size(); ++i)
	{
		auto& title = m_TitleList[i];

		if (i == 2 && NowPick == 0)
		{
			title.m_alpha += title.m_addAlpha;

			if (title.m_alpha > 1.0f)
			{
				title.m_alpha = 1.0f;
				title.m_addAlpha *= -1;
			}

			else if (title.m_alpha <= 0.3f)
			{
				title.m_alpha = 0.3f;
				title.m_addAlpha *= -1;
			}
		}
		else if(i == 2 && NowPick == 1)
		{
			title.m_alpha = 1.0f;
		}

		if (i == 3 && SceneFlg == true && NowPick == 0)
		{
			title.m_alpha += title.m_addAlpha;

			if (title.m_alpha > 1.5f)
			{
				SceneFlg = false;

				if (TitleModeFlg == false)
				{
					SCENE.SetAnimationScene(SceneType::Stage1); //ステージ1へ遷移
				}
				else if(TitleModeFlg == true)
				{
					SCENE.SetAnimationScene(SceneType::HardStage1); //ハードステージ1へ遷移
				}
			}

		}
		else if (i == 3 && TitleStartFlg == false)
		{
			title.m_alpha -= title.m_addAlpha;

			if (title.m_alpha < 0.0f)
			{
				title.m_alpha = 0.0f;

				TitleStartFlg = true;
			}
		}

		if (i == 4 && NowPick == 1)
		{
			//キーエッジ検出（毎フレーム1回だけ行う)
			bool enterDown = (GetAsyncKeyState(VK_RETURN) & 0x8000) != 0;
			bool enterTriggered = enterDown && !m_prevEnterKey;  //押した瞬間だけ true
			m_prevEnterKey = enterDown;                          //今フレームの状態を保存

			//条件チェック
			if (enterTriggered && TitleStartFlg && NowPick == 1)
			{
				if (!TitleModeFlg)
				{
					title.m_pos = { (64.0f * 11.9f) - 640, (-64.0f * 9.0f) + 360 };
					title.m_rect = { 768, 0, 128, 64 };
					TitleModeFlg = true;

					sound->ClickSE();
				}
				else
				{
					title.m_pos = { (64.0f * 12.5f) - 640, (-64.0f * 9.0f) + 360 };
					title.m_rect = { 704, 64, 192, 64 };
					TitleModeFlg = false;

					sound->ClickSE();
				}
			}
		}

		if (i == 5 && NowPick == 1)
		{
			title.m_alpha += title.m_addAlpha;

			if (title.m_alpha > 1.0f)
			{
				title.m_alpha = 1.0f;
				title.m_addAlpha *= -1.0;
			}

			else if (title.m_alpha <= 0.3f)
			{
				title.m_alpha = 0.3f;
				title.m_addAlpha *= -1.0;
			}
		}
		else if (i == 5 && NowPick == 0)
		{
			title.m_alpha = 1.0f;
		}

		if (i == 7 && NowPick == 1)
		{
			title.m_rect = { 896,64,128,64 };
			title.m_pos = { (64.0f * 8.0f) - 640,(-64.0f * 9.0f) + 360 };
			title.m_scale = 1.6f;
		}
		else if (i == 7 && NowPick == 0)
		{
			title.m_rect = { 832,128,256,64 };
			title.m_pos = { (64.0f * 10.0f) - 640,(-64.0f * 7.0f) + 360 };
			title.m_scale = 1.85f;
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

	for (int i = 0; i < m_TitleList.size(); ++i)
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

