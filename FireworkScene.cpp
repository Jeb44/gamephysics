#include "FireworkScene.h"



FireworkScene::FireworkScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window)
{
	m_main = new ec::Node();

	m_particleNodeWorld = m_physicsEngine.getParticleNodeWorld();
	m_particleWorld = m_particleNodeWorld->getWorld();

	auto& reg = window->getDrawableRegistry();
	m_drawable = reg.getResource("sphere");

	m_defMain.ageMin = 1.0f;
	m_defMain.ageMax = 2.0f;
	m_defMain.velocityMin = glm::vec3(0.0f, 0.5f, 0.0f);
	m_defMain.velocityMax = glm::vec3(0.0f, 1.0f, 0.0f);

	m_defPayload.ageMin = 1.0f;
	m_defPayload.ageMax = 2.0f;
	m_defPayload.velocityMin = glm::vec3(0.5f, 0.5f, 0.5f);
	m_defPayload.velocityMax = glm::vec3(1.0f, 1.0f, 1.0f);

	m_defMain.count = 1;
	m_defPayload.count = 0;

	m_defMain.drawable = m_drawable;
	m_defPayload.drawable = m_drawable;

	m_resetTime = 0.5f;
	m_countingTime = 0.0f;

	//Cave
	m_cave = new Cave(window);
	m_main->addChild(m_cave->getCave());

	//
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

	//ParticleEngine updated all particles that are in ParticleWorld
	/* m_particleWorld->getComputationInterface();
	m_particleWorld->getComputationInterface()->integrate(timeDelta);
	m_particleNodeWorld->update();*/

	m_countingTime += timeDelta;

	auto particles = m_particleWorld->getParticles();
	for(size_t i = 0, iLen = particles.size(); i < iLen; i++) {
		if(particles[i]->isDead()) {
			//add removal
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
