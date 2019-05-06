#include "Uebung2.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"
#include "R3D/ParticleEngine/ParticleDef.h"
#include <iostream>

Uebung2::Uebung2(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window) {
	auto reg = window->getDrawableRegistry();

	m_main = new ec::Node();
	cave = new Cave(window);
	m_main->addChild(cave->getCave());

	//Falling Spheres
	m_sphere1 = reg.getResource("sphere");
	m_sphere2 = reg.getResource("sphere");
	m_nodeSphere1 = new ec::Node();
	m_nodeSphere1->addDrawable(m_sphere1);
	m_nodeSphere2 = new ec::Node();
	m_nodeSphere2->addDrawable(m_sphere2);
	m_nodeSphere1->setScale(0.15f);
	m_nodeSphere2->setScale(0.15f);

	m_main->addChild(m_nodeSphere1);
	m_main->addChild(m_nodeSphere2);

	TeilchenDef def;
	glm::vec3 velocity(0.0f, -0.0f, 0.0f);
	glm::vec3 velocity2(0.0f, -0.0f, 0.0f);
	glm::vec3 acceleration(0.0f, -1.0f, 0.0f);
	glm::vec3 acceleration2(0.0f, -5.0f, 0.0f);
	glm::vec3 pos1(0.25f, 1.0f, 0.0f);
	glm::vec3 pos2(-0.25f, 1.0f, 0.0f);

	def.velocity = velocity;
	def.acceleration = acceleration;

	pos1.x = 0.25f;
	def.position = pos1;
	def.setMass(1.0f);
	particle1 = new Teilchen(def);

	def.position = pos2;
	def.setMass(1.0f); //mass is irrelevant for pure speed calculations w/o resistance
	def.velocity = velocity2;
	def.acceleration = acceleration2;
	pos2.x = -0.25f;
	particle2 = new Teilchen(def);

	particle1->setPosition(pos1);
	particle2->setPosition(pos2);
	m_nodeSphere1->setTranslation(particle1->getPosition());
	m_nodeSphere2->setTranslation(particle2->getPosition());


	m_root->addChild(m_main);

	startProcessing = false;
	count = 0;
}


Uebung2::~Uebung2() {
	delete cave;
	delete m_main;

	delete m_nodeSphere1;
	delete m_nodeSphere2;

	delete m_sphere1;
	delete m_sphere2;

	delete particle1;
	delete particle2;
}

void Uebung2::tick(const float timeDelta) {
	__super::tick(timeDelta);

	if(m_mouse->isKeyDown(ec::Mouse::MOUSE_1)) {
		startProcessing = true;
	}

	if(startProcessing == false) return;

	particle1->integrate(timeDelta);
	particle2->integrate(timeDelta);

	m_nodeSphere1->setTranslation(particle1->getPosition());
	m_nodeSphere2->setTranslation(particle2->getPosition());

	//std::string posY = std::to_string(particle1->getPosition().y);
	//std::cout << "Frame " << count++ << ": Sphere1(" << posY << ")" << std::endl;
}
