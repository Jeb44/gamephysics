#include "TeilchenWelt.h"


TeilchenWelt::TeilchenWelt() = default;

TeilchenWelt::~TeilchenWelt() = default;

void TeilchenWelt::setCompInterface(TeilchenEngineCI* compInterface) {
	m_compInterface = compInterface;
}

TeilchenEngineCI* TeilchenWelt::getCompInterface() const {
	return m_compInterface;
}

std::vector<Teilchen*> TeilchenWelt::getParticles() const {
	return m_particles;
}

void TeilchenWelt::addParticle(Teilchen* particle) {
	//todo: check if element is already in vector
	m_particles.push_back(particle);
}

bool TeilchenWelt::removeParticle(Teilchen* particle) {
	//remove doesn't "remove" the particle, it only shows where it is (iterator)
	//since it's iterating over m_particles it stops at .end() and returns therefore it
	const auto particleToRemove = std::remove(m_particles.begin(), m_particles.end(), particle);
	const bool isFound = particleToRemove != m_particles.end();
	if (isFound) {
		m_particles.erase(particleToRemove);
	}
	return isFound;
}
