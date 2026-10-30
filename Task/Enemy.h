#pragma once
#include <Siv3D.hpp>

class Enemy
{
public:

	void Update();
	void Draw()const;
	void onDamage(int damage);

	RectF GetCollision() const;

	bool onDead()const;

private:

	Texture BossT1{ U"Image/BossT1.png" };
	Texture BossT2{ U"Image/BossT2.png" };

	Vec2 bossPos{ 1000,400 };//Bossの位置

	static constexpr double Division = 2.0;//当たり判定計算用

	int maxHealth=100;
	int onHealth=100;

	double bossDet = 100;
	double sizeBoosT1 = 0.4;//ボスサイズ
	double sizeBoosT2 = 0.4;//2体目のボスサイズ
};

