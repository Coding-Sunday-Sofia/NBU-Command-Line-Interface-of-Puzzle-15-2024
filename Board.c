#include <stdio.h>
#include <string.h>

#include "Board.h"

void initBoard(struct Board *board) {
	for(int j=0, k=1; j<BOARD_SIZE; j++) {
		for(int i=0; i<BOARD_SIZE; i++, k++) {
			char label[10];
			sprintf(label, "%02d\0", k);
			initTile(&((*board).tiles[i][j]), k, label);
		}
	}

	initTile(&((*board).tiles[BOARD_SIZE-1][BOARD_SIZE-1]), 0, "  ");
}

void swap(struct Board* board, int x1, int y1, int x2, int y2) {
	struct Tile buffer = (*board).tiles[x2][y2];
	(*board).tiles[x2][y2] = (*board).tiles[x1][y1];
	(*board).tiles[x1][y1] = buffer;
}

void tryToMove(struct Board* board, enum Direction direction, int x, int y) {
	if(direction==LEFT && x == 0) {
		return;
	}

	if(direction==RIGHT && x == BOARD_SIZE-1) {
		return;
	}

	if(direction==UP && y == 0) {
		return;
	}

	if(direction==DOWN && y == BOARD_SIZE-1) {
		return;
	}

	switch( direction ) {
		case LEFT:
			swap(board, x, y, x-1, y);
			break;
		case UP:
			swap(board, x, y, x, y-1);
			break;
		case RIGHT:
			swap(board, x, y, x+1, y);
			break;
		case DOWN:
			swap(board, x, y, x, y+1);
			break;
	};
}

void moveEmpty(struct Board* board, enum Direction direction) {
	for(int j=0; j<BOARD_SIZE; j++) {
		for(int i=0; i<BOARD_SIZE; i++) {
			if((*board).tiles[i][j].id == 0) {
				tryToMove(board, direction, i, j);
				return;
			}
		}
	}
}

void showBoard(struct Board board) {
	for(int j=0; j<BOARD_SIZE; j++) {
		for(int i=0; i<BOARD_SIZE; i++) {
			showTile( board.tiles[i][j] );
			printf(" ");
		}
		printf("\n\n");
	}
}