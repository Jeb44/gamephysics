#include "TeilchenEngineCI.h"



TeilchenEngineCI::TeilchenEngineCI() {}


TeilchenEngineCI::~TeilchenEngineCI() {}

void TeilchenEngineCI::setParticleWorld(TeilchenWelt* particleWorld) {
	m_particleWorld = particleWorld;
}


TeilchenWelt * TeilchenEngineCI::getParticleWorld() {
	return nullptr;
}
