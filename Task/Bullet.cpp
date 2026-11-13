#include "stdafx.h"
#include "Bullet.h"


//弾の初期位置
Bullet::Bullet(Vec2 launchPos, bool charge) :bulletPos(launchPos), onChargeBullet(charge)
{
}

void Bullet::Update()
{
	const double deltaTime = Scene::DeltaTime();

	if(onChargeBullet)//チャージ弾
	{
		bulletPos.x += chargeBullet*deltaTime;
	}

	else//通常弾
	{
		bulletPos.x += bulletSpeed * deltaTime;
	}
}

void Bullet::Draw()const
{
	if (onChargeBullet)//チャージ弾の描画
	{
		bulletT2.scaled(sizeBC).drawAt(bulletPos);
	}

	else//通常弾の描画
	{
		bulletT1.scaled(sizeB).drawAt(bulletPos);
	}

	// 当たり判定を表示（デバッグ用）
	GetCollision().drawFrame(1.0, Palette::Green);
}

RectF Bullet::GetCollision() const
{
	Vec2 imageSize;

	//弾のあたり判定を画像のサイズに合わせる
	if (onChargeBullet)
	{
		imageSize = bulletT2.size() * sizeBC;
	}

	else
	{
		imageSize = bulletT1.size() * sizeB;
	}

	imageSize *= ReductionMag;
	

	return RectF{ bulletPos.x - imageSize.x / Division,bulletPos.y - imageSize.y / Division,imageSize.x,imageSize.y };
}


