#pragma once
#include "Organism.h"

class Animal : public Organism {

public:
	Animal();
	~Animal();
	void action() override;
	void collision() override;
	void draw() override;
};

