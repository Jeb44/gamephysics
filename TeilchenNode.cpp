#include "TeilchenNode.h"

TeilchenNode::TeilchenNode(Teilchen* particle, ec::Node* node) {
	this->m_particle = particle; 
	this->m_node = node;
}

TeilchenNode::~TeilchenNode() {
	delete m_node;
	delete m_particle;
}

void TeilchenNode::update() const {
	const auto& pos = m_particle->getPosition();
	m_node->setTranslation(pos);
}

auto TeilchenNode::getNode() {
	return m_node;
}

auto TeilchenNode::getParticle() {
	return m_particle;
}
