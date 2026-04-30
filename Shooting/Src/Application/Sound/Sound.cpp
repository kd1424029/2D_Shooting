#include"../Scene.h"
#include"Sound.h"

void C_Sound::Init()
{
	// 初期ボリュームを先に設定
	vol = 0.2f; // MAXは 1.0f
	SEvol = 0.5f;

	
	// SEの読み込み
	//①領域確保
	PickMove = std::make_shared<KdSoundEffect>();
	Click    = std::make_shared<KdSoundEffect>();
	Bullet   = std::make_shared<KdSoundEffect>();
	Start    = std::make_shared<KdSoundEffect>();
	

	//②音データ読み込み
	PickMove->Load("Sound/SE/PickMove.wav");
	Click   ->Load("Sound/SE/Click.wav");
	Bullet  ->Load("Sound/SE/Bullet.wav");
	Start   ->Load("Sound/SE/Start.wav");
	
	//③実体化 (インスタンス化)
	PickMoveInst = PickMove->CreateInstance(false);	//インスタンス化(専用スピーカーの作成)
	ClickInst    = Click   ->CreateInstance(false);
	BulletInst   = Bullet  ->CreateInstance(false);
	StartInst    = Start   ->CreateInstance(false);
	
	
	// ④音量設定(0から1の範囲で)
	if (PickMoveInst) PickMoveInst->SetVolume(SEvol);				//ボリューム調整(セッターで音を渡す)
	if (ClickInst)    ClickInst   ->SetVolume(SEvol);
	if (BulletInst)   BulletInst  ->SetVolume(SEvol);
	if (StartInst)    StartInst    ->SetVolume(SEvol);
	
	// --- BGM 周り (自動再生をしない) ---
	//①領域確保
	Titlebgm = std::make_shared<KdSoundEffect>();
	Gamebgm  = std::make_shared<KdSoundEffect>();

	//②音データ読み込み
	Titlebgm->Load("Sound/BGM/TitleBGM.wav");
	Gamebgm ->Load("Sound/BGM/GameBGM.wav");

	//③実体化 (インスタンス化)(専用スピーカーの作成)
	TitlebgmInst = Titlebgm->CreateInstance(false);	//インスタンス化(専用スピーカーの作成)
	GamebgmInst  = Gamebgm->CreateInstance(false);

	//④音量設定(0から1の範囲で)
	if (TitlebgmInst) TitlebgmInst->SetVolume(vol);				//ボリューム調整(セッターで音を渡す)
	if (GamebgmInst)  GamebgmInst->SetVolume(vol);

}
void C_Sound::Release()
{
	// SEの解放

}
void C_Sound::Update()
{


}
void C_Sound::PickMoveSE()
{
	PickMoveInst->Stop();

	PickMoveInst->Play();
}

void C_Sound::ClickSE()
{
	ClickInst->Stop();

	ClickInst->Play();
}

void C_Sound::BulletSE()
{
	BulletInst->Stop();

	BulletInst->Play();
}

void C_Sound::StartSE()
{
	StartInst->Stop();

	StartInst->Play();
}


void C_Sound::TitleBGMPlay()
{
	if (TitlebgmInst->IsPlay() == false)
	{
		TitlebgmInst->Play();
	}
}

void C_Sound::TitleBGMStop()
{
	if (TitlebgmInst->IsPlay() == true)
	{
		TitlebgmInst->Stop();
	}
}

void C_Sound::GameBGMPlay()
{
	if (GamebgmInst->IsPlay() == false)
	{
		GamebgmInst->Play();
	}
}

void C_Sound::GameBGMStop()
{
	if (GamebgmInst->IsPlay() == true)
	{
		GamebgmInst->Stop();
	}
}

