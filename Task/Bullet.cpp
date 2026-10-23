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
		bulletT2.scaled(sizeB).drawAt(bulletPos);
	}

	else//通常弾の描画
	{
		bulletT1.scaled(sizeB).drawAt(bulletPos);
	}
}


double Bullet::GetbulletDet() const
{
	return bulletDet;
}
