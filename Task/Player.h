#pragma once
#include <Siv3D.hpp>
#include"Bullet.h"	
#include"Enemy.h"
#include "Difficulty.h"

class Player
{
public:

	void Update();
	void Draw()const;

	Vec2 GetplayerPos()const;
	double GetplayerDet()const;

	Player(Difficulty difficulty);

	// 弾の配列を取得
	Array<Bullet>& GetBullets()
	{
		return bullets;
	}


	//体力関連
	int GetCurretLife()const;
	int GetMaxLife()const;

	void TakeDamage();
	bool IsDead();

private:

	Texture playerImage;
	Texture playerT1Image{ U"Image/PlayerT1.png" };
	Texture playerT2Image{ U"Image/PlayerT2.png" };
	Texture lifeImage{ U"Image/Life.png" };

	double sizeP1 = 0.07;//画像の大きさ
	double sizeP2 = 0.07;//画像の大きさ

	Vec2  playerPos{ 150,360 };//プレイヤーの位置
	Vec2  Coordinates{0,0 };//移動用

	double playerSpeed = 500;//プレイヤースピード
	double playerDet = 50;//プレイヤーあたり判定

	//体力設定
	static constexpr int MaxLife = 3;
	int currentLife = MaxLife;

	// ライフ表示設定
	static constexpr double LifePosX = 30.0;
	static constexpr double LifePosY = 30.0;
	static constexpr double LifeReset = 0;

	static constexpr double  LifeSize = 40.0;
	static constexpr double  LifeSpacing = 10.0;

	//{移動方向定数}
	static constexpr double moveDirNo = 0;
	static constexpr double moveDirMinus = -1;
	static constexpr double moveDirPlus = 1;
	
	
	//{Bullet関連}
	Array<Bullet> bullets;//弾の配列
	static constexpr double timerReset = 0;
	Vec2 bulletLaunchPos{ 100,0};//弾の発射位置

	bool onCharging = false;//チャージ中かどうか

	double chargeTime = 0.5;//チャージ時間
	double chargeTimer = 0;//チャージ経過時間	
	double rapidFireRate = 0.2; // 連射の発射間隔
	double rapidFireTimer = 0; // 連射のタイマー

};

