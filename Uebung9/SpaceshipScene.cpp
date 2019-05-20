#include "SpaceshipScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include "R3D/Utility/Random.h"

#include <iostream>

SpaceshipScene::SpaceshipScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window) {
	m_camera->setTranslation(0.0, 5.0, 25.0);
	m_camera->rotateX(-0.5f);

	// Get a previously created drawable
	auto reg = window->getDrawableRegistry();
	spaceshipDrawable = reg.getResource("cube");
	planetDrawable = reg.getResource("sphere");

	auto particleNodeWorld = m_physicsEngine.getParticleNodeWorld();
	auto particleWorld = particleNodeWorld->getWorld();

	planetCount = 5;

	// Init scene graph node and add it to the scene graph
	spaceshipNode = new ec::Node();
	spaceshipNode->addDrawable(spaceshipDrawable);
	m_root->addChild(spaceshipNode);

	planetNodes = new ec::Node*[planetCount];
	for(size_t i = 0, iLen = planetCount; i < iLen; i++) {
		planetNodes[i] = new ec::Node();
		planetNodes[i]->addDrawable(planetDrawable);
		m_root->addChild(planetNodes[i]);
	}

	//Init Particles
	spaceshipParticle = new r3::Particle();
	spaceshipParticle->setMass(500.0f);
	spaceshipParticle->setVelocity(0.0f, 0.0f, 0.5f);
	particleWorld->addParticle(spaceshipParticle);

	planetParticles = new r3::Particle*[planetCount];
	for(size_t i = 0, iLen = planetCount; i < iLen; i++) {
		planetParticles[i] = new r3::Particle();
		particleWorld->addParticle(planetParticles[i]);
	} //list of planet positions
	planetParticles[0]->setPosition(glm::vec3(2.0f, 0.0f, 0.0f));
	planetParticles[0]->setMass(100000.0f);
	planetParticles[1]->setPosition(glm::vec3(-3.0f, 1.0f, 3.0f));
	planetParticles[1]->setMass(1000000.0f);
	planetParticles[2]->setPosition(glm::vec3(3.0f, -2.0f, 10.0f));
	planetParticles[2]->setMass(7500000000.0f);
	planetParticles[3]->setPosition(glm::vec3(1.0f, 3.0f, 4.0f));
	planetParticles[3]->setMass(7500000000.0f);
	planetParticles[4]->setPosition(glm::vec3(-1.0f, -2.0f, 2.0f));
	planetParticles[4]->setMass(1000000000.0f);

	//Init ParticleNodes
	spaceShipPN = new ParticleNode(spaceshipParticle, spaceshipNode);
	particleNodeWorld->addParticleNode(spaceShipPN);

	planetPNs = new ParticleNode*[planetCount];
	for(size_t i = 0, iLen = planetCount; i < iLen; i++) {
		planetPNs[i] = new ParticleNode(planetParticles[i], planetNodes[i]);
		particleNodeWorld->addParticleNode(planetPNs[i]);
	}

	//Init Gravity
	planetGravities = new PlanetGravityGenerator*[planetCount];
	for(size_t i = 0, iLen = planetCount; i < iLen; i++) {
		planetGravities[i] = new PlanetGravityGenerator(planetParticles[i]);
		particleWorld->getParticleForceRegistry().add(spaceshipParticle, planetGravities[i]);
	}
}

SpaceshipScene::~SpaceshipScene()
= default;

void SpaceshipScene::tick(const float timeDelta)
{
	SimulationScene::tick(timeDelta);
	std::cout << "[Particle Pos]" <<
		" x: " << spaceshipParticle->getPosition().x <<
		" | y: " << spaceshipParticle->getPosition().y <<
		" | z: " << spaceshipParticle->getPosition().z <<
	std::endl;
}

void SpaceshipScene::reset()
{
	SimulationScene::reset();
}
