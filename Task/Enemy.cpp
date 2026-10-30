#include "stdafx.h"
#include "Enemy.h"

void Enemy::onDamage(int damage)
{
	onHealth -= damage;

	if (onHealth < 0)
	{
		onHealth = 0;
	}
}

RectF Enemy::GetCollision() const
{
	Vec2 imageSize = BossT1.size() * sizeBoosT1;//画像計算

	//画像に合わせた当たり判定
	return RectF{ bossPos.x - imageSize.x / Division,bossPos.y - imageSize.y / Division,imageSize.x,imageSize.y };

}

bool Enemy::onDead() const
{
	return onHealth <= 0;
}
