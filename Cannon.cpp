#include "Cannon.h"

#include <iostream>

Cannon::Cannon(SimulationWindow* window) {
	m_window = window;
	initDrawableNode(m_window);
	m_cannonballs.reserve(200);
}

Cannon::Cannon(SimulationWindow* window, const glm::vec3& spawnPoint) {
	m_window = window;
	this->spawnPoint = spawnPoint;
	initDrawableNode(m_window);
}


Cannon::~Cannon() {
	for (auto& p : m_cannonballs) {
		delete p;
	}

	delete m_node;
	delete m_drawable;
	delete m_window;
}

void Cannon::addCannonball() {
	CannonBall* newCannonBall = new CannonBall(m_window, spawnPoint);
	m_node->addChild(newCannonBall->getNode());
	m_cannonballs.push_back(newCannonBall);
}

bool Cannon::removeCannonball(CannonBall* cannonball) {
	bool isRemoved = m_node->removeChild(cannonball->getNode());
	return isRemoved;
}

void Cannon::update(const float timeDelta) {
	
	//std::cout << "Current Vector Size: " << m_cannonballs.size() << std::endl;
	//std::cout << std::endl;
	for (int i = m_cannonballs.size() - 1; i >= 0; i--) {
		//std::cout << "Pos i: " << i << std::endl;
		m_cannonballs[i]->update(timeDelta);
		if (m_cannonballs[i]->getParticle()->isDead()) {
			removeCannonball(m_cannonballs[i]);
			m_cannonballs.erase(m_cannonballs.begin() + i);
		}
	}
}

ec::Node * Cannon::getNode() {
	return m_node;
}

void Cannon::initDrawableNode(SimulationWindow * window) {
	//Drawable
	auto& reg = window->getDrawableRegistry();
	m_drawable = reg.getResource("cannon");

	//Node
	m_node = new ec::Node();
	m_node->addDrawable(m_drawable);
	m_node->scale(0.5f);
	m_node->setTranslation(spawnPoint);
}