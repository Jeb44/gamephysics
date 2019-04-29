#include "FireworkScene.h"

#include <iostream>

FireworkScene::FireworkScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window)
{
	m_main = new ec::Node();

	m_particleNodeWorld = m_physicsEngine.getParticleNodeWorld();
	m_particleWorld = m_particleNodeWorld->getWorld();

	auto& reg = window->getDrawableRegistry();
	m_drawable = reg.getResource("sphere");

	//Main Firework
	m_defMain.ageMin = 1.0f;
	m_defMain.ageMax = 2.0f;
	m_defMain.velocityMin = glm::vec3(0.0f, 0.5f, 0.0f);
	m_defMain.velocityMax = glm::vec3(0.0f, 1.0f, 0.0f);

	m_defMain.count = 1;
	m_defMain.drawable = m_drawable;

	//Payloads
	m_defPayloads = new FireworkDefintion[3];
	m_defPayloads[0].ageMin = 1.0f;
	m_defPayloads[0].ageMax = 2.0f;
	m_defPayloads[1].ageMin = 1.0f;
	m_defPayloads[1].ageMax = 2.0f;
	m_defPayloads[2].ageMin = 1.0f;
	m_defPayloads[2].ageMax = 2.0f;

	m_defPayloads[0].velocityMin = glm::vec3(0.25f, -0.25f, -0.25f);
	m_defPayloads[0].velocityMax = glm::vec3(0.5f, 0.25f, 0.25f);
	m_defPayloads[1].velocityMin = glm::vec3(-0.25f, 0.25f, -0.25f);
	m_defPayloads[1].velocityMax = glm::vec3(0.25f, 0.5f, 0.25f);
	m_defPayloads[2].velocityMin = glm::vec3(-0.25f, -0.25f, 0.25f);
	m_defPayloads[3].velocityMax = glm::vec3(0.25f, 0.25f, 0.5f);
		
	m_defPayloads[0].count = 0;
	m_defPayloads[1].count = 0;
	m_defPayloads[2].count = 0;

	m_defPayloads[0].drawable = m_drawable;
	m_defPayloads[1].drawable = m_drawable;
	m_defPayloads[2].drawable = m_drawable;

	m_resetTime = 0.5f;
	m_countingTime = 0.0f;

	//Cave
	m_cave = new Cave(window);
	m_main->addChild(m_cave->getCave());

	m_main->setTranslationZ(5.0f);
	m_root->addChild(m_main);
}


FireworkScene::~FireworkScene() = default;

void FireworkScene::tick(const float timeDelta) {
	__super::tick(timeDelta);

	if (m_countingTime >= m_resetTime && m_mouse->isKeyDown(ec::Mouse::MOUSE_1)) {
		addFirework();
		m_countingTime = 0.0f;
	}
	
	m_countingTime += timeDelta;

	auto particleNodes = m_particleNodeWorld->getParticleNodes();
	
	for(int i = particleNodes.size() - 1;  i >= 0; i--) {
		if(particleNodes[i]->getParticle()->isDead()) {
			m_main->removeChild(particleNodes[i]->getNode());
			m_particleNodeWorld->removeParticleNode(particleNodes[i]);
		}
	}
}

void FireworkScene::addFirework() {
	//randomize position

	FireworkParticle* particle = new FireworkParticle(m_defMain);
	m_particleWorld->addParticle(particle);

	ec::Node* node = new ec::Node();
	node->addDrawable(m_defMain.drawable);
	node->scale(0.1f);
	m_main->addChild(node);
	
	ParticleNode* particleNode = new ParticleNode(particle, node);
	m_particleNodeWorld->addParticleNode(particleNode);
}
