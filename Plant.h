#pragma once
#include "Organism.h"

class Plant : public Organism {

public:
	Plant(char name, int strength, int x, int y, World* world);
	~Plant();
	void action() override;
	void collision() override;
	void draw() override;
};

