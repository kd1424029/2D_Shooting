#pragma once

class  C_Sound
{
private:


	// SE用
	std::shared_ptr<KdSoundEffect>		PickMove;
	std::shared_ptr<KdSoundInstance>	PickMoveInst;

	std::shared_ptr<KdSoundEffect>		Click;
	std::shared_ptr<KdSoundInstance>	ClickInst;

	std::shared_ptr<KdSoundEffect>		Bullet;
	std::shared_ptr<KdSoundInstance>	BulletInst;
	
	std::shared_ptr<KdSoundEffect>		Start;
	std::shared_ptr<KdSoundInstance>	StartInst;

	std::shared_ptr<KdSoundEffect>		Burst;
	std::shared_ptr<KdSoundInstance>	BurstInst;

	std::shared_ptr<KdSoundEffect>		Clear;
	std::shared_ptr<KdSoundInstance>	ClearInst;

	//BGM用
	std::shared_ptr<KdSoundEffect>		Titlebgm;		// 音データ
	std::shared_ptr<KdSoundInstance>TitlebgmInst;	// 音を鳴らす為の変数(イメージ的にはスピーカー)

	std::shared_ptr<KdSoundEffect>		Gamebgm;	
	std::shared_ptr<KdSoundInstance>GamebgmInst;

	std::shared_ptr<KdSoundEffect>  GameOverbgm;
	std::shared_ptr<KdSoundInstance>GameOverbgmInst;
	

	// 音量調節用
	float vol;
	float SEvol; // SE用音量
	
	bool chenge;
public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	void PickMoveSE();

	void ClickSE();

	void BulletSE();

	void StartSE();

	void BurstSE();

	void ClearSE();

	void TitleBGMPlay();
	
	void TitleBGMStop();

	void GameBGMPlay();
	
	void GameBGMStop();

	void GameOverBGMPlay();

	void GameOverBGMStop();

	// GUI処理
	void ImGuiUpdate();

	//========== セッター ===========
	void SetVol(float a_vol) { vol = a_vol; }
	void SetSEVol(float a_SEvol) { SEvol = a_SEvol; }

};