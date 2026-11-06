#pragma once
#include <Siv3D.hpp>

class Bullet
{
public:

	void Update();
	void Draw()const;

	double GetbulletDet()const;

	RectF GetCollision() const;

	Bullet(Vec2 launchPos,  bool charge=false);//弾発射受け取り
	
	// 弾を削除する
	void SetDead()
	{
		onDead = true;
	}

	// 削除するか確認
	bool IsDead() const
	{
		return onDead;
	}

private:

	Texture bulletT1{ U"Image/BulletT1.png" };
	Texture bulletT2{ U"Image/BulletT2.png" };

	Vec2 bulletPos;//弾の位置
	
	bool onChargeBullet = false;// チャージ弾かどうか

	static constexpr double Division = 2.0;//当たり判定計算用
	

	double bulletSpeed = 2000;//弾の速さ
	double bulletDet = 5;//弾の大きさ
	double chargeBullet = 3000;//チャージ弾の速さ
	double sizeB = 0.15;//弾の描写サイズ
	double sizeBC = 0.3;//チャージ弾の描写サイズ


	bool onDead = false;//

	
};

