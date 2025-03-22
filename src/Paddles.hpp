#ifndef PADDLES_H
#define PADDLES_H

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class Paddles
{
	private:
		sf::Texture		paddleTex;
		sf::Sprite		paddleA;
		sf::Sprite		paddleB;

		float speed;

		int pointsA;
		int pointsB;

	public:
		Paddles();

		void loadTex(const std::string& path);

		void drawPaddles(sf::RenderWindow& win);
		void updatePaddles(const sf::RenderWindow& win);

		void moveAR();
		void moveAL();
		void moveBR();
		void moveBL();

		int getPointsA() const;
		int getPointsB() const;
		void addPointToA();
		void addPointToB();

		//getters
		const sf::Sprite& getPaddleA() const;
		const sf::Sprite& getPaddleB() const;
		void resetPoints();
};

#endif