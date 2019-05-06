#pragma once

#include <vector>
#include <list>
#include "Teilchen.h"
#include "TeilchenNode.h"
#include "Cannonball.h"
#include "glm/common.hpp"

#include "SimulationWindow.h"

class Cannon {
public:
	Cannon(SimulationWindow* window);
	Cannon(SimulationWindow* window, const glm::vec3& spawnPoint);
	~Cannon();

	glm::vec3 spawnPoint {0.0f, 0.0f, 0.0f};
	
	ec::Node* getNode();

	//Uebung 3
	void addCannonball();
	bool removeCannonball(CannonBall* cannonball);
	void update(const float timeDelta);

private:
	ec::Node* m_node;
	ec::Drawable* m_drawable;
	void initDrawableNode(SimulationWindow* window);

	SimulationWindow* m_window; //better solution?
	std::vector<CannonBall*> m_cannonballs;
};

