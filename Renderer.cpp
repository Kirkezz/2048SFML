#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window, short size) : window(window), Game(size) {
	tSize = window.getSize().x / size;
	font.loadFromFile("CimeroPro.otf");
	for (auto& i : field)
		i.resize(size);
	draw();
}
void Renderer::draw() {
	window.clear(sf::Color(127, 127, 127));
	sf::RectangleShape square;
	sf::Text text;
	text.setCharacterSize(72);
	text.setFont(font);
	text.setFillColor({ 77, 77, 77 });
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			square.setSize(sf::Vector2f(tSize - thickness, tSize - thickness));
			square.setPosition(thickness / 2 + i * tSize, thickness / 2 + j * tSize);
			if (field[i][j] == 0) {
				square.setFillColor({ 150, 150, 150 });
				window.draw(square);
				continue;
			}
			sf::Color color = getColor(field[i][j]);
			square.setFillColor(color);
			window.draw(square);
			text.setString(sf::String(std::to_string(field[i][j])));
			sf::FloatRect rectBounds = square.getGlobalBounds();
			sf::FloatRect textBounds = text.getLocalBounds();
			text.setOrigin(thickness / 2 + static_cast<int>(textBounds.left + (thickness + textBounds.width) / 2.0f), thickness / 2 + static_cast<int>(textBounds.top + (thickness + textBounds.height) / 2.0f));
			text.setPosition(thickness / 2 + static_cast<int>(rectBounds.left + (thickness + rectBounds.width) / 2), thickness / 2 + static_cast<int>(rectBounds.top + (thickness + rectBounds.height) / 2));
			window.draw(text);
		}
	}
	window.display();
}
void Renderer::move(coords m) {
	update(m);
	draw();
}
sf::Color Renderer::getColor(unsigned color) {
	switch (color) {
	case 2:
		return sf::Color(238, 228, 218);
		break;
	case 4:
		return sf::Color(237, 224, 200);
		break;
	case 8:
		return sf::Color(242, 177, 121);
		break;
	case 16:
		return sf::Color(245, 149, 99);
		break;
	case 32:
		return sf::Color(246, 124, 95);
		break;
	case 64:
		return sf::Color(246, 94, 59);
		break;
	case 128:
		return sf::Color(237, 207, 114);
		break;
	case 256:
		return sf::Color(237, 204, 97);
		break;
	case 512:
		return sf::Color(237, 200, 80);
		break;
	case 1024:
		return sf::Color(237, 197, 63);
		break;
	case 2048:
		return sf::Color(237, 194, 46);
		break;
	default:
		break;
	}
}