#include <stdlib.h>
#include <stdio.h>

#include "Board.h"

int main() {
	struct Board board;

	initBoard( &board );

	for(;;) {
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		showBoard( board );
		int key = getc(stdin);

		if(key == 'q') {
			break;
		} else if(key == 'a') {
			moveEmpty(&board, LEFT);
		} else if(key == 'w') {
			moveEmpty(&board, UP);
		} else if(key == 'd') {
			moveEmpty(&board, RIGHT);
		} else if(key == 's') {
			moveEmpty(&board, DOWN);
		} else if(key == 'r') {
			for(int g=0;g<10000;g++) {
				switch( rand()%4 ) {
					case 0:
						moveEmpty(&board, LEFT);
						break;
					case 1:
						moveEmpty(&board, UP);
						break;
					case 2:
						moveEmpty(&board, RIGHT);
						break;
					case 3:
						moveEmpty(&board, DOWN);
						break;
				}
			}
		}
	}

	return 0;
}
