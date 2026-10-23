#pragma once
#include <Siv3D.hpp>

class Bullet
{
public:

	void Update();
	void Draw()const;

	double GetbulletDet()const;

	Bullet(Vec2 launchPos,  bool charge=false);//弾発射受け取り
	

private:

	Texture bulletT1{ U"Image/BulletT1.png" };
	Texture bulletT2{ U"Image/BulletT2.png" };

	Vec2 bulletPos;//弾の位置
	

	bool onChargeBullet = false;// チャージ弾かどうか
	
	double bulletSpeed = 2000;//弾の速さ
	double bulletDet = 5;//弾の大きさ
	double chargeBullet = 3000;//チャージ弾の速さ
	double sizeB = 0.7;//弾の描写サイズ

};

