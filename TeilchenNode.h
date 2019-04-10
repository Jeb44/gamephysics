#pragma once

#include "Teilchen.h"
#include "EC3D/Core/Node.h"

class TeilchenNode {
public:
	TeilchenNode(Teilchen* particle, ec::Node* node);
	~TeilchenNode();

	void update() const;

	auto getNode();
	auto getParticle();

private:
	ec::Node* m_node;
	Teilchen* m_particle;
};

