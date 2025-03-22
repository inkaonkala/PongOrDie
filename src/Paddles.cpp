#include "Paddles.hpp"

Paddles::Paddles()
{
	this->speed = 2.5f;
	this->pointsA = 0;
	this->pointsB = 0;
}

void Paddles::loadTex(const std::string& path)
{
	if (!paddleTex.loadFromFile(path))
		std::cerr << "Error loading paddle texture" << std::endl;

	paddleA.setTexture(paddleTex);
	paddleB.setTexture(paddleTex);

	paddleA.setPosition(350.f, 30.f);
	paddleB.setPosition(350.f, 560.f);
}

void Paddles::updatePaddles(const sf::RenderWindow& win)
{
	//boudaty check!
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		moveAL();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		moveAR();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		moveBL();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		moveBR();
		
}

void Paddles::drawPaddles(sf::RenderWindow& win)
{
	win.draw(paddleA);
	win.draw(paddleB);
}

void Paddles::moveAL()
{
    if (paddleA.getPosition().x > 0)
        paddleA.move(-speed, 0.f);
}

void Paddles::moveAR()
{
    if (paddleA.getPosition().x + paddleA.getGlobalBounds().height < 710)
        paddleA.move(speed, 0.f);
}

void Paddles::moveBL()
{
    if (paddleB.getPosition().x > 0)
        paddleB.move(-speed, 0.f);
}

void Paddles::moveBR()
{
    if (paddleB.getPosition().x + paddleB.getGlobalBounds().height < 710)
        paddleB.move(speed, 0.f);
}

int Paddles::getPointsA() const
{
    return pointsA;
}

int Paddles::getPointsB() const
{
    return pointsB;
}

void Paddles::addPointToA()
{
    pointsA++;
}

void Paddles::addPointToB()
{
    pointsB++;
}

const sf::Sprite& Paddles::getPaddleA() const
{
	return paddleA;
}

const sf::Sprite& Paddles::getPaddleB() const
{
	return paddleB;
}

void Paddles::resetPoints()
{
	pointsA = 0;
	pointsB = 0;
}
