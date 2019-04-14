#include "TeilchenNodeWelt.h"

#include <iostream>

TeilchenNodeWelt::TeilchenNodeWelt() {
	m_particleWorld = new TeilchenWelt();
	const auto compInterface = new DefaultTeilchenEngineCI(m_particleWorld);
	m_particleWorld->setCompInterface(compInterface);
}

TeilchenNodeWelt::~TeilchenNodeWelt() = default;

void TeilchenNodeWelt::update() {
	for (auto& it : m_particleNodes) {
		it->update();
	}
}

void TeilchenNodeWelt::addParticleNode(TeilchenNode* particleNode) {
	//Add ParticleNode to ParticleNodeWorld
	m_particleNodes.emplace_back(particleNode);
	//Add Particle To ParticleWorld
	m_particleWorld->addParticle(particleNode->getParticle());
}

bool TeilchenNodeWelt::removeParticleNode(TeilchenNode * node) {
	//same code as in TeilchenWelt::removeParticleNode
	auto particleToRemove = std::remove(m_particleNodes.begin(), m_particleNodes.end(), node);
	const bool isFound = particleToRemove != m_particleNodes.end();
	if (isFound) {
		m_particleNodes.erase(particleToRemove);
	}
	return isFound;
}

TeilchenWelt * TeilchenNodeWelt::getWorld() const {
	return m_particleWorld;
}
