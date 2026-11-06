#pragma once
#include <Siv3D.hpp>
#include "Player.h"
#include"Enemy.h"

class Game
{
public:

	Game();

	void Update();
	void Draw()const;
	void CheckCollision();

private:

	//敵、プレイヤーのデータ管理
	Player player{ Difficulty::Normal };
	Array<Enemy>enemies;

	static constexpr double bulletDamage = 1;//弾のダメージ
};

