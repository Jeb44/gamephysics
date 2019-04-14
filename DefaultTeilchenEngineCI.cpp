#include "DefaultTeilchenEngineCI.h"



DefaultTeilchenEngineCI::DefaultTeilchenEngineCI(TeilchenWelt* particleWorld) 
	: TeilchenEngineCI(particleWorld)
{}


DefaultTeilchenEngineCI::~DefaultTeilchenEngineCI() {}

void DefaultTeilchenEngineCI::integrate(const float timeDelta) {
	assert(m_particleWorld != nullptr);

	// w/o const: error "initial value of reference to non-const must be an lvalue
	const auto& particles = m_particleWorld->getParticles();
	for (int i = 0; i < particles.size(); i++) {
		particles[i]->integrate(timeDelta);
	}
}

void DefaultTeilchenEngineCI::onBegin() {}

void DefaultTeilchenEngineCI::onEnd() {}

void DefaultTeilchenEngineCI::step(const float timeDelta) {}

void DefaultTeilchenEngineCI::reset() {}
