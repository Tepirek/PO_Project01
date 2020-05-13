#include "World.h"
#include "random"
#include "Grass.h"
#include "time.h"

World::World(int height, int width) {
	this->height = height + 2;
	this->width = width + 2;
	this->map = vector<vector<char>>(this->height);
	for(int i = 0; i < this->height; i++) {
		this->map[i] = vector<char>(this->width);
	}
	for(int i = 0; i < this->height; i++) {
		for(int j = 0; j < this->width; j++) {
			if(i == 0 || i == this->height - 1 || j == 0 || j == this->width - 1) {
				this->map[i][j] = '#';
			}
			else {
				this->map[i][j] = ' ';
			}
		}
	}
}

World::~World() = default;

void World::init() {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++) {
		int posX = rand() % (this->width - 2) + 1;
		int posY = rand() % (this->height - 2) + 1;
		 
		this->organisms.push_back(new Grass('G', posX, posY, this));
		this->map[posX][posY] = this->organisms.back()->getName();
	}
}

void World::nextTurn() {
	updatePrev(); 
	for(int i = 0; i < 5; i++) {
		this->organisms[i]->changePosition(1, 1);
	}
	updateAfter();
}

void World::updatePrev() {
	for (int i = 0; i < 5; i++) {
		this->map[this->organisms[i]->getPosition()[0]][this->organisms[i]->getPosition()[1]] = ' ';
	}
}

void World::updateAfter() {
	for(int i = 0; i < 5; i++) {
		this->map[this->organisms[i]->getPosition()[0]][this->organisms[i]->getPosition()[1]] = this->organisms.back()->getName();
	}
}

void World::drawMap() {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			cout << this->map[i][j] << ' ';
		}
		cout << endl;
	}
}

void World::newOrganism(Organism* organism) {
	this->map[organism->getPosition()[0]][organism->getPosition()[1]] = organism->getName();
}

