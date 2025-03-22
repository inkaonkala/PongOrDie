#include "TheBall.hpp"

TheBall::TheBall()
{
	speed = 2.0f;
	reset();
}

void TheBall::loadTex(const std::string& path)
{
	if (!ballTex.loadFromFile(path))
		std::cerr << "Error loading theBall texture\n";
	skull.setTexture(ballTex);
	skull.setOrigin(ballTex.getSize().x / 2.f, ballTex.getSize().y / 2);
	skull.setPosition(400.f, 300.f);
}

void TheBall::reset()
{
	skull.setPosition(400.f, 300.f); // center of 800x600 screen

	velocity.x = (rand() % 2 == 0) ? -1.f : 1.f;
	velocity.y = (rand() % 2 == 0) ? -1.f : 1.f;
	velocity *= speed;
}

void TheBall::update()
{
	skull.move(velocity);
}

void TheBall::draw(sf::RenderWindow& window)
{
	window.draw(skull);
}

const sf::FloatRect TheBall::getBounds() const
{
	return skull.getGlobalBounds();
}

void TheBall::bounceX()
{
	velocity.x = -velocity.x;
}

void TheBall::bounceY()
{
	velocity.y = -velocity.y;
}

sf::Vector2f TheBall::getPosition() const
{
	return skull.getPosition();
}

void TheBall::setVelocity(sf::Vector2f vel)
{
	velocity = vel;
}

sf::Vector2f TheBall::getVelocity() const
{
	return velocity;
}