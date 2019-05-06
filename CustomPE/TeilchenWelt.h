#pragma once

#include <vector>
#include <algorithm> //std::remove
#include "Teilchen.h"
#include "TeilchenEngineCI.h"

class TeilchenEngineCI;

class TeilchenWelt {
public:
	TeilchenWelt();
	~TeilchenWelt();

	void setCompInterface(TeilchenEngineCI* compInterface);
	TeilchenEngineCI* getCompInterface() const;

	std::vector<Teilchen*> getParticles() const;
	void addParticle(Teilchen* particle);
	bool removeParticle(Teilchen* particle);

private:
	TeilchenEngineCI* m_compInterface {}; //call constructor m_particleWorld = nullptr
	std::vector<Teilchen*> m_particles;
};

