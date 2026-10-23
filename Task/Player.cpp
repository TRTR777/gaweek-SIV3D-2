#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"



void Player::Update()
{
	
	const double deltaTime = Scene::DeltaTime();

	Coordinates = Vec2{ moveDirNo, moveDirNo };


	//上下移動入力
	if (KeyW.pressed())
	{
		Coordinates.y += moveDirMinus;
	}

	if (KeyS.pressed())
	{
		Coordinates.y += moveDirPlus;
	}

	//左右移動入力
	if (KeyD.pressed())
	{
		Coordinates.x += moveDirPlus;
	}

	if (KeyA.pressed())
	{
		Coordinates.x += moveDirMinus;
	}

	if (Coordinates.lengthSq() > 0)Coordinates = Coordinates.normalized();//斜め移動の速度制限

	playerPos += Coordinates * playerSpeed * deltaTime;//キャラ移動

	//画面外に出ないよう
	playerPos.x = Clamp(playerPos.x, playerDet, Scene::Width() - playerDet);
	playerPos.y = Clamp(playerPos.y, playerDet, Scene::Height() - playerDet);


	//{Bullet関連}

	//マウス右クリックを押している間はチャージしない
	if (MouseR.pressed())
	{
		onCharging = false;
		chargeTimer=timerReset;

		//マウス右クリックを押している間は連射
		if (MouseL.pressed())
		{
			rapidFireTimer += deltaTime;

			if (rapidFireTimer >= rapidFireRate)//連射の発射間隔を超えたら弾を発射
			{
				bullets << Bullet(playerPos + bulletLaunchPos);
				rapidFireTimer=timerReset;//タイマーリセット
			}
		}
		else//マウス左クリックを押していない場合はタイマーリセット
		{
			rapidFireTimer = rapidFireRate;
		}
	}

	else
	{
		if (MouseL.pressed()&&!MouseR.pressed())//マウス左クリックを押している間チャージ
		{
			onCharging = true;
			rapidFireTimer = timerReset;
			
		}

		if(onCharging&&MouseL.pressed()&&!MouseR.pressed())//マウス右クリックを押している間チャージしない
		{
			chargeTimer += deltaTime;
		}

		if(onCharging&&MouseL.up())//マウス左クリックを離したら弾発射
		{
			Print << U"114514";
			if (chargeTimer >= chargeTime)//チャージ弾
			{
				Print << U"チャージ攻撃";
				bullets << Bullet{playerPos + bulletLaunchPos, true};
			}

			else//通常弾
			{
				Print << U"攻撃";
				bullets << Bullet{ playerPos + bulletLaunchPos};
			}
		}
		

		else//マウス左クリックを押していない場合はタイマーリセット
		{
			onCharging = false;
			chargeTimer = timerReset;
		}
	}
	for (auto& bullet : bullets)
	{
		bullet.Update();
	}
}


void Player::Draw()const
{
	playerImage.scaled(sizeP).drawAt(playerPos);//プレイヤーの描画


	for (const auto& bullet : bullets)//弾の描画
	{
		bullet.Draw();
	}
}


Vec2 Player::GetplayerPos()const
{
	return playerPos;
}

double Player::GetplayerDet()const
{
	return playerDet;
}
