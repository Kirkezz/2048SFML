#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Renderer.h"
using namespace std;
using namespace sf;

int main() {
	RenderWindow window(VideoMode(768, 768), "2048");
	Renderer game(window, 4);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                switch (event.key.code) { // 22 0 18 3
                case Keyboard::W:
                    game.move(game.UP);
                    break;
                case Keyboard::S:
                    game.move(game.DOWN);
                    break;
                case Keyboard::D:
                    game.move(game.RIGHT);
                    break;
                case Keyboard::A:
                    game.move(game.LEFT);
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
        
    }
}