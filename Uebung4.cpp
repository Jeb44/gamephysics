#include "Uebung4.h"



Uebung4::Uebung4(const std::string& name, SimulationWindow* window) 
	: SimulationScene(name, window)
{
	m_main = new ec::Node();

	auto& reg = window->getDrawableRegistry();
	m_drawableBall = reg.getResource("sphere");

	m_cave = new Cave(window);
	m_main->addChild(m_cave->getCave());

	m_cannon = new Cannon(window);
	m_main->addChild(m_cannon->getNode());

	//Code for other stuff
	m_particleNodeWorld = new TeilchenNodeWelt();
	m_particleWorld = m_particleNodeWorld->getWorld();

	m_main->setTranslationZ(5.0f);
	m_root->addChild(m_main);
}


Uebung4::~Uebung4() = default;

void Uebung4::tick(const float timeDelta) {
	//Ask: How should i integrate this into the scenegraph?
	//Ask: real vs float? complex numbers for what?
	//Ask: ParticleNodeWorld acts main controller here, but should it create nodeworld & DefaultParticleEngineCI?
	//Ask: where should i delete particles/nodes?

	if (m_mouse->isKeyDown(ec::Mouse::MOUSE_1)) {
		addBall();
	}

	//ParticleEngine updated all particles that are in ParticleWorld
	m_particleWorld->getCompInterface()->integrate(timeDelta);
	//ParticleNodeEngine
	m_particleNodeWorld->update();

	auto particles = m_particleWorld->getParticles();
	for (size_t i = 0, iLen = particles.size(); i < iLen; i++) {
		if (particles[i]->getPosition().y <= -10.0f) {
			particles[i]->setDead(true);
		}
		//deletion happens in particleNode?
	}
}

void Uebung4::addBall() {
	//Ask: initatiate ball without drawable reference -> access registry in ball?

	Ball* ball = new Ball(m_drawableBall);
	m_particleWorld->addParticle(ball->getParticle());
	TeilchenNode* particleNode = new TeilchenNode(ball->getParticle(), ball->getNode());
	m_particleNodeWorld->addParticleNode(particleNode);
	m_main->addChild(ball->getNode());
}
