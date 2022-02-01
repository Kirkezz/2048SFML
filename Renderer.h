#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>
class Renderer : public Game {
private:
	unsigned tSize, thickness = 7;
	sf::RenderWindow& window;
	void draw();
	sf::Color getColor(unsigned color);
	sf::Font font;
public:
	Renderer(sf::RenderWindow& window, short size);
	void move(coords m);
};

