#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"

#define BOARD_SIZE 4

enum Direction {
	LEFT,
	UP,
	RIGHT,
	DOWN
};

struct Board {
	struct Tile tiles[BOARD_SIZE][BOARD_SIZE];
};

void initBoard(struct Board*);
void moveEmpty(struct Board*, enum Direction);
void showBoard(struct Board);

#endif