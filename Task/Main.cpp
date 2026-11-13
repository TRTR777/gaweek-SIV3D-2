# include <Siv3D.hpp> // Siv3D v0.6.16
# include "Game.h"
#include"Player.h"
#include"Bullet.h"


void Main()
{
	Window::Resize(1920, 1080);
	
	
	Game game;
	

	while (System::Update())
	{
		game.Update();
		game.Draw();
	}
}


