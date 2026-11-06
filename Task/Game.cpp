#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	enemies.emplace_back();
}

void Game::Update() 
{

	//プレイヤー状態更新
	player.Update();

	//敵の状態更新
	for (auto& enemy : enemies)
	{
		enemy.Update();
	}

	// HPが0になった敵を削除
	enemies.remove_if([](const Enemy& enemy)
	{
		return enemy.onDead();
	});
}

void Game::Draw()const
{

	//プレイヤー描写
	player.Draw();

	//敵の描写
	for (const auto& enemy : enemies)
	{
		enemy.Draw();
	}
}

void Game::CheckCollision()
{
	for (auto& enemy : enemies)
	{
		for (auto& bullet : player.GetBullets())
		{
			//弾と敵のあたり判定
			if (bullet.GetCollision().intersects(enemy.GetCollision()))
			{
				//敵にダメージ
				enemy.onDamage(bulletDamage);

				//ヒット時弾消去
				bullet.SetDead();
			}
		}
	}

	// 命中した弾を削除
	player.GetBullets().remove_if([](const Bullet& bullet)
	{
		return bullet.IsDead();
	});
}
