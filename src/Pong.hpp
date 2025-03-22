
#ifndef PONG_H
# define PONG_H

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#include "Paddles.hpp"
#include "TheBall.hpp"

enum class GameState
{
	Menu,
	Playing,
	GameOver
};

class Pong
{
	private:

		GameState state;
		Paddles paddles;
		TheBall TheBall;

		sf::RenderWindow	*win;
		sf::Event 			ev;
		sf::VideoMode		videoMode;

		sf::Font			font;
		sf::Text			menuText;
		sf::Text			scoreTextA;
		sf::Text			scoreTextB;
		sf::Text			endText;
		
		int					menuSelect;
		int 				points;


	public:

		Pong();
		virtual ~Pong();

		const bool whilstRunning() const;
		void pollEvents();
		void update();
		void render();
		void init_var();
		void init_win();
};


#endif