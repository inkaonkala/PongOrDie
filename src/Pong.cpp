
#include "Pong.hpp"
#include "Paddles.hpp"
#include "TheBall.hpp"

Pong::Pong()
{
	this->init_var();
	this->init_win();
}

Pong::~Pong()
{
	delete this->win;
}

const bool Pong::whilstRunning() const
{
	return this->win->isOpen();
}

void Pong::init_var()
{
	this->points = 0;
	this->menuSelect = 0;
	this->state = GameState::Menu;

	if (!this->font.loadFromFile("assets/font.ttf"))
		std::cerr << "Failed to download the font\n";

	this->menuText.setFont(this->font);
	this->menuText.setCharacterSize(32);
	this->menuText.setFillColor(sf::Color::White);
	this->menuText.setString("Choose game mode:\n> AI\n 2-Player");
	this->menuText.setPosition(100.f, 100.f);

	scoreTextA.setFont(this->font);
	scoreTextA.setCharacterSize(24);
	scoreTextA.setFillColor(sf::Color::White);
	scoreTextA.setPosition(10.f, 10.f);

	scoreTextB.setFont(this->font);
	scoreTextB.setCharacterSize(24);
	scoreTextB.setFillColor(sf::Color::White);
	scoreTextB.setPosition(730.f, 10.f); // adjust for text width
	
	paddles.loadTex("assets/bone.png");
	TheBall.loadTex("assets/skull.png");
}

void Pong::init_win()
{
	this->videoMode.width = 800;
	this->videoMode.height = 600;
	this->win = new sf::RenderWindow(this->videoMode, "Pong or Die", sf::Style::Titlebar | sf::Style::Close);
	this->win->setFramerateLimit(60);

}

void Pong::pollEvents()
{
	while (this->win->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->win->close();

		if(this->ev.type == sf::Event::KeyPressed)
		{
			if (this->state == GameState::Menu)
			{
				if (ev.key.code == sf::Keyboard::Up || ev.key.code == sf::Keyboard::W)
					this->menuSelect = 0;
				else if (ev.key.code == sf::Keyboard::Down || ev.key.code == sf::Keyboard::S)
					this->menuSelect = 1;
				else if (ev.key.code == sf::Keyboard::Enter)
				{
					this->state = GameState::Playing;
					// START THE GAME!! But to test:
					if (menuSelect == 0)
						std::cout << "AI Mode Selected" << std::endl;
					else
						std::cout << "2-Playeer Mode Selected" << std::endl;
				}
			}
			if (this->state == GameState::GameOver)
			{
				if (ev.key.code == sf::Keyboard::Enter)
				{
					this->state = GameState::Menu;
					this->menuSelect = 0;
					paddles.resetPoints();
					TheBall.reset();
				}
			}
		}
	}
}

void Pong::update()
{
	this->pollEvents();

	if (this->state == GameState::Menu)
	{
		if (menuSelect == 0)
			this->menuText.setString("Choose Mode:\n> AI\n  2-Player");
		else
			this->menuText.setString("Choose Mode:\n  AI\n> 2-Player");
	}
	if (this->state == GameState::Playing)
	{
		paddles.updatePaddles(*win);
		TheBall.update();
		sf::Vector2f pos = TheBall.getPosition();

		// Collision with paddles
		if (TheBall.getBounds().intersects(paddles.getPaddleA().getGlobalBounds()))
			TheBall.bounceY();

		if (TheBall.getBounds().intersects(paddles.getPaddleB().getGlobalBounds()))
			TheBall.bounceY();

		if (pos.x <= 0 || pos.x + TheBall.getBounds().height >= 800)
			TheBall.bounceX();

		//TEXT STUFF

		scoreTextA.setString(std::to_string(paddles.getPointsA()));
		scoreTextB.setString(std::to_string(paddles.getPointsB()));	
		if (pos.y < 0) {
			paddles.addPointToB();
			TheBall.reset();
		}
		if (pos.y > 800) {
			paddles.addPointToA();
			TheBall.reset();
		}

		// Win check
		if (paddles.getPointsA() >= 5 || paddles.getPointsB() >= 5)
		{
			state = GameState::GameOver;

			std::string winner = (paddles.getPointsA() >= 5) ? "Top Player Wins!" : "Bottom Player Wins!";
			endText.setFont(font);
			endText.setCharacterSize(36);
			endText.setFillColor(sf::Color::Red);
			endText.setString(winner + "\nPress Enter to return to menu");
			endText.setPosition(200.f, 250.f);
		}
	}
}

void Pong::render()
{
	this->win->clear();

	if (this->state == GameState::Menu)
		this->win->draw(this->menuText);
	else if (this->state == GameState::Playing)
	{
		paddles.drawPaddles(*win);
		TheBall.draw(*win);
		win->draw(scoreTextA);
		win->draw(scoreTextB);
	}
	else if (this->state == GameState::GameOver)
	{
		win->draw(endText);
	}
	this->win->display();
}