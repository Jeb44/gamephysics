#include "TeilchenEngineCI.h"


TeilchenEngineCI::TeilchenEngineCI(TeilchenWelt * particleWorld) {
	m_particleWorld = particleWorld;
}

TeilchenEngineCI::~TeilchenEngineCI() = default;

void TeilchenEngineCI::setParticleWorld(TeilchenWelt* particleWorld) {
	m_particleWorld = particleWorld;
}

TeilchenWelt * TeilchenEngineCI::getParticleWorld() const{
	return m_particleWorld;
}

