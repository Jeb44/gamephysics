#include "TeilchenNode.h"

TeilchenNode::TeilchenNode(Teilchen* particle, ec::Node* node) {
	this->m_particle = particle; 
	this->m_node = node;
}

TeilchenNode::~TeilchenNode() = default;

void TeilchenNode::update() const {
	const auto& pos = m_particle->getPosition();
	m_node->setTranslation(pos);
}

Teilchen* TeilchenNode::getParticle() const {
	return m_particle;
}

ec::Node* TeilchenNode::getNode() const {
	return m_node;
}
