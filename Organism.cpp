#include "Organism.h"
#include <iostream>
using namespace std;

Organism::Organism(char name, int strength, int initiative, int x, int y, World* world) {
	this->name = name;
	this->strength = strength;
	this->initiative = initiative;
	this->age = 1;
	this->position = vector<int>(2);
	this->position[0] = x;
	this->position[1] = y;
	this->world = world;
}

Organism::~Organism() = default;

char Organism::getName() {
	return this->name;
}

int Organism::getStrength() {
	return this->strength;
}

int Organism::getInitiative() {
	return this->initiative;
}

int Organism::getAge() {
	return this->age;
}

vector<int> Organism::getPosition() {
	return this->position;
}

World* Organism::getWorld() {
	return this->world;
}

void Organism::increaseStrength(int value) {
	this->strength += value;
}

void Organism::incrementAge() {
	this->age++;
}

void Organism::changePosition(int x, int y) {
	this->position[0] += x;
	this->position[1] += y;
}
