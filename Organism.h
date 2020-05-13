#pragma once
#include <vector>
using namespace std;
// #include "World.h"

class World;

class Organism {
	char name;
	int strength;
	int initiative;
	int age;
	vector<int> position;
	World* world;
public:
	Organism(char name, int strength, int initiative, int x, int y, World* world);
	virtual ~Organism();
	virtual char getName();
	virtual int getStrength();
	virtual int getInitiative();
	virtual int getAge();
	virtual vector<int> getPosition();
	virtual World* getWorld();
	virtual void increaseStrength(int value);
	virtual void incrementAge();
	virtual void changePosition(int x, int y);
	virtual void action() = 0;
	virtual void collision() = 0;
	virtual void draw() = 0;
};

