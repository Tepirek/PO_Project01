#include "World.h"
#include "Organism.h"

#include "random"
#include "time.h"
#include <stdio.h>

#define WIDTH 20
#define HEIGHT 20

int main(void) {

	World* world = new World(WIDTH, HEIGHT);
	world->init();
	world->nextTurn();
	world->drawMap();
	
	return 0;
}