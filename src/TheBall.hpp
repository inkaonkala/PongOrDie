#ifndef THEBALL_H
#define THEBALL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class TheBall
{
	private:
		sf::Texture		ballTex;
		sf::Sprite		skull;
		sf::Vector2f 	velocity;

		float			speed;

	public:
		TheBall();

		void loadTex(const std::string& path);
		void reset();
		void update();
		void draw(sf::RenderWindow& win);

		// collision
		const sf::FloatRect getBounds() const;
		void bounceX();
		void bounceY();

		sf::Vector2f getPosition() const;
		void setVelocity(sf::Vector2f vel);
		sf::Vector2f getVelocity() const;
};

#endif