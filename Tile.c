#include <stdio.h>
#include <string.h>

#include "Tile.h"

void initTile(struct Tile *tile, int id, const char *label) {
	(*tile).id = id;
	strcpy((*tile).label, label);
}

void showTile(struct Tile tile) {
	printf("%s", tile.label);
}
