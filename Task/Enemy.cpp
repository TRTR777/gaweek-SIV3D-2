#include "stdafx.h"
#include "Enemy.h"

void Enemy::Update()
{
}

void Enemy::Draw()const
{
	if (BossType1)
	{
		BossT1.scaled(sizeBoosT1).drawAt(bossPos);
	}

	else if(BossType2)
	{
		BossT2.scaled(sizeBoosT2).drawAt(bossPos);
	}

	// 当たり判定を表示（デバッグ用）
	GetCollision().drawFrame(1.0, Palette::Red);
}

void Enemy::onDamage(int damage)
{
	//HP最低を０に設定
	onHealth -= damage;

	if (onHealth < minHealth)
	{
		onHealth = minHealth;
	}
}

RectF Enemy::GetCollision() const
{
	//画像に合わせた当たり判定
	if (BossType1)
	{
		const Vec2 imageSize = BossT1.size() * sizeBoosT1;//画像計算Boss1

		return RectF{ bossPos.x - imageSize.x / Division,bossPos.y - imageSize.y / Division,imageSize.x,imageSize.y };
	}

	if (BossType2)
	{
		const Vec2 imageSize = BossT2.size() * sizeBoosT2;//画像計算Boss2

		return RectF{ bossPos.x - imageSize.x / Division,bossPos.y - imageSize.y / Division,imageSize.x,imageSize.y };
	}
	
	return RectF{ bossPos,Vec2{Reset,Reset} };
}


bool Enemy::onDead() const
{
	return (onHealth <= minHealth);
}

