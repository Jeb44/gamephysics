#pragma once

#include <vector>
#include "Teilchen.h"

class TeilchenWelt {
public:
	TeilchenWelt();
	~TeilchenWelt();

	std::vector<Teilchen*> getParticles();
	void addParticles(Teilchen* particle);
	Teilchen* removeParticles(Teilchen* particle);

private:
	std::vector<Teilchen*> m_particles;
};

