#pragma once
#include <iostream>
#include <vector>
#include "Organism.h"
using namespace std;

class World {
	int width;
	int height;
	vector<vector<char>> map;
	vector<Organism*> organisms;
public:
	World(int height, int width);
	~World();
	void init();
	void nextTurn();
	void updatePrev();
	void updateAfter();
	void drawMap();
	void newOrganism(Organism* organism);
};
