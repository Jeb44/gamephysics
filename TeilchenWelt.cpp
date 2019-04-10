#include "TeilchenWelt.h"


TeilchenWelt::TeilchenWelt() {}

TeilchenWelt::~TeilchenWelt() {}

std::vector<Teilchen*> TeilchenWelt::getParticles() {
	return m_particles;
}

void TeilchenWelt::addParticles(Teilchen * particle) {
	//todo: chech if element is already in vector
	m_particles.push_back(particle);
}

Teilchen* TeilchenWelt::removeParticles(Teilchen * particle) {
	//todo: remove elements
	return nullptr;
}
