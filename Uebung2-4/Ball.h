#pragma once

#include "SimulationWindow.h"
#include "Teilchen.h"
#include "TeilchenNode.h"
#include "TeilchenDef.h"
#include "glm/common.hpp"

class Ball {
public:
	explicit Ball(ec::Drawable* m_drawable);
	~Ball();

	ec::Node* getNode();
	Teilchen* getParticle();

private:
	void initDrawableNode(ec::Drawable* m_drawable);
	void initParticle();

	glm::vec3 m_initVelocity {-1.0f, 3.0f, 0.0f};
	glm::vec3 m_initAcceleration {0.0f, -2.5f, 0.0f};

	ec::Node* m_node;
	ec::Drawable* m_drawable;
	Teilchen* m_particle;
};

