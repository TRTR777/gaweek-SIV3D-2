# include <Siv3D.hpp> // Siv3D v0.6.16
# include "Game.h"
#include"Player.h"
#include"Bullet.h"


void Main()
{
	Window::Resize(1280, 720);
	

	Player Player;

	while (System::Update())
	{
		Player.Update();
		Player.Draw();


	}
}


