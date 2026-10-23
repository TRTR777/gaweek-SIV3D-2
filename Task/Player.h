#pragma once
#include <Siv3D.hpp>
#include"Bullet.h"	
#include"Enemy.h"

class Player
{
public:

	void Update();
	void Draw()const;

	Vec2 GetplayerPos()const;
	double GetplayerDet()const;


private:

	Texture playerImage{ U"Image/Player.png" };
	double sizeP = 0.05;//画像の大きさ

	Vec2  playerPos{ 150,360 };//プレイヤーの位置
	Vec2  Coordinates{0,0 };//移動用

	double playerSpeed = 500;//プレイヤースピード
	double playerDet = 50;//プレイヤーあたり判定


	//{移動方向定数}
	static constexpr double moveDirNo = 0;
	static constexpr double moveDirMinus = -1;
	static constexpr double moveDirPlus = 1;
	
	


	//{Bullet関連}
	Array<Bullet> bullets;//弾の配列
	static constexpr double timerReset = 0;
	Vec2 bulletLaunchPos{ 200,0 };//弾の発射位置

	bool onCharging = false;//チャージ中かどうか

	double chargeTime = 0.5;//チャージ時間
	double chargeTimer = 0;//チャージ経過時間	
	double rapidFireRate = 0.2; // 連射の発射間隔
	double rapidFireTimer = 0; // 連射のタイマー

};

