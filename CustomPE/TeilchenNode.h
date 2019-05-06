#pragma once

#include "Teilchen.h"
#include "EC3D/Core/Node.h"

class TeilchenNode {
public:
	TeilchenNode(Teilchen* particle, ec::Node* node);
	~TeilchenNode();

	void update() const;

	Teilchen* getParticle() const;
	 ec::Node* getNode() const;

private:
	ec::Node* m_node;
	Teilchen* m_particle;
};

