#pragma once
#include <vector>
#include <random>
#include <cassert>


class Game {
public:
	Game(short size);
	struct coords {
		short x, y;
	};
	static const coords UP, DOWN, RIGHT, LEFT;
	const short size;
	short& operator()(coords c);
private:
	static std::mt19937 gen;
	void generate();
	bool valid(coords c);
	unsigned long long score;
protected:
	void update(coords dir);
	std::vector<std::vector<short>> field;
};
