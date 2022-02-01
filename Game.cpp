#include "Game.h"

Game::Game(short size) : size(size), field(size), score(0) {
	for (auto& i : field)
		i.resize(size);
	generate();
	generate();
}
bool Game::valid(coords c) {
	return c.x < size && c.y < size && c.x >= 0 && c.y >= 0;
}
void Game::generate() {
	short t = (gen() % 10 < 9) ? 2 : 4;
	coords c;
	do {
		c.x = gen() % size, c.y = gen() % size;
	} while (field[c.x][c.y] != 0);
	field[c.x][c.y] = t;
}
short& Game::operator()(coords c) {
	assert(valid(c));
	return field[c.x][c.y];
}
void Game::update(coords dir) {
	bool f, f1 = false;
	do {
		f = false;
		for (short x = 0; x < size; ++x) {
			for (short y = 0; y < size; ++y) {
				short i = dir.x == 1 ? size - x - 1 : x, j = dir.y == 1 ? size - y - 1 : y;
				if (field[i][j] != 0 && valid({ i + dir.x, j + dir.y }) && (field[i + dir.x][j + dir.y] == field[i][j] || field[i + dir.x][j + dir.y] == 0)) {
					if (field[i + dir.x][j + dir.y])
						score += field[i + dir.x][j + dir.y] * 2;
					field[i + dir.x][j + dir.y] += field[i][j];
					field[i][j] = 0;
					f = true;
					f1 = true;
				}
			}
		}
	} while (f);
	if (f1)
		generate();
}
std::mt19937 Game::gen{ std::random_device{}() };
Game::coords const Game::UP = { 0, -1 }, Game::DOWN = { 0, 1 }, Game::RIGHT = { 1, 0 }, Game::LEFT = { -1, 0 };