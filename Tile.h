#ifndef TILE_H
#define TILE_H

struct Tile {
	int id;
	char label[3];
};

void initTile(struct Tile*, int, const char*);
void showTile(struct Tile);

#endif