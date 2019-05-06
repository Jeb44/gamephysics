#include "CameraScene.h"

#include <iostream>

CameraScene::CameraScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window) {
	m_main = new ec::Node();

	m_particleNodeWorld = m_physicsEngine.getParticleNodeWorld();
	m_particleWorld = m_particleNodeWorld->getWorld();

	auto& reg = window->getDrawableRegistry();
	m_drawable = reg.getResource("sphere");

	//Cave
	m_cave = new Cave(window);
	m_main->addChild(m_cave->getCave());

	//Particles
	playerParticle = new r3::Particle();
	playerParticle->setMass(1.0f);
	playerParticle->setPosition(glm::vec3(0.0f));
	camParticle = new r3::Particle();
	camParticle->setMass(1.0f);
	camParticle->setPosition(0.0f, 0.0f, 0.5f);

	//Node & ParticleNode
	m_playerNode = new ec::Node();
	m_playerNode->addDrawable(m_drawable);
	m_playerNode->setScale(0.1);
	m_main->addChild(m_playerNode);

	//Registry & Spring
	m_anchor = new glm::vec3(0.0f,0.0f,0.0f);
	m_particleNodeWorld->addParticleNode(new ParticleNode(camParticle, getCamera()));
	m_particleWorld->getParticleForceRegistry()
		.add(camParticle, new r3::ParticleAnchoredSpring(m_anchor, 10.0f, 0.5f));
	m_root->addChild(m_main);
}

CameraScene::~CameraScene() = default;

void CameraScene::tick(const float timeDelta) {
	__super::tick(timeDelta);

	if(m_keyboard->isKeyDown(ec::Keyboard::I)) {
		*m_anchor += glm::vec3(0.0f, 0.0f, -0.01f);
	}
	else if(m_keyboard->isKeyDown(ec::Keyboard::K)) {
		*m_anchor += glm::vec3(0.0f, 0.0f, 0.01f);
	}

	if(m_keyboard->isKeyDown(ec::Keyboard::L)) {
		*m_anchor += glm::vec3(0.01f, 0.0f, 0.0f);
	}
	else if(m_keyboard->isKeyDown(ec::Keyboard::J)) {
		*m_anchor += glm::vec3(-0.01f, 0.0f, 0.0f);
	}	 

	m_playerNode->setTranslation(*m_anchor);

}
