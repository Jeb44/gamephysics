#pragma once

#include "SimulationWindow.h"
#include "Teilchen.h"
#include "TeilchenNode.h"
#include "TeilchenDef.h"
#include "glm/common.hpp"

class CannonBall {
public:
	CannonBall(SimulationWindow* window);
	CannonBall(SimulationWindow* window, const glm::vec3& pos);
	~CannonBall();

	ec::Node* getNode();
	Teilchen* getParticle();
	TeilchenNode* getParticleNode();

private:
	void initDrawableNode(SimulationWindow* window);
	void initParticle();
	void initParticle(const glm::vec3& pos);
	void initParticleNode();

	glm::vec3 position {2.5f, 0.0f, 0.0f};
	glm::vec3 velocity {-1.0f, 3.0f, 0.0f};
	glm::vec3 acceleration {0.0f, -2.5f, 0.0f};

	ec::Node* m_node;
	ec::Drawable* m_drawable;
	Teilchen* m_particle;
	TeilchenNode* m_particleNode;
};