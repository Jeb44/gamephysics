#include "BouyancyScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include <iostream>

BouyancyScene::BouyancyScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window)
{
    m_camera->setTranslation(0.0, 0.0, 25.0);

	// Get a previously created drawable
	auto reg = window->getDrawableRegistry();
	m_ballDrawable = reg.getResource("sphere");
	m_cubeDrawable = reg.getResource("cube");

	auto particleNodeWorld = m_physicsEngine.getParticleNodeWorld();
	auto particleWorld = particleNodeWorld->getWorld();

	// Init scene graph node and add it to the scene graph
	m_ballNode = new ec::Node();
	m_ballNode->setTranslation(0.0, 10.0, 0.0);
	m_ballNode->addDrawable(m_ballDrawable);
//	m_cubeNode = new ec::Node();
//	m_cubeNode->setScale(3);
//	m_cubeNode->addDrawable(m_cubeDrawable);

	m_root->addChild(m_ballNode);

	// Init particle
	m_ballParticle = new r3::Particle();
	m_ballParticle->setVelocity(0.1, 0.0, 0.0);
	m_ballParticle->setPosition(0, 10, 0);
	m_ballParticle->setMass(400.0f);

	// Init particle node and register it
	m_ballParticleNode = new ParticleNode(m_ballParticle, m_ballNode);
	particleNodeWorld->addParticleNode(m_ballParticleNode);

	// Init force generator and register it
	m_particleGravity = new r3::ParticleGravity(glm::vec3(0.0f, -9.8f, 0.0f));
	m_particleBuoyancy = new r3::ParticleBuoyancy(1, 2, 0);

	particleWorld->getParticleForceRegistry().add(m_ballParticle, m_particleGravity);
	particleWorld->getParticleForceRegistry().add(m_ballParticle, m_particleBuoyancy);
}

BouyancyScene::~BouyancyScene()
= default;

void BouyancyScene::tick(const float timeDelta)
{
	SimulationScene::tick(timeDelta);
}

void BouyancyScene::reset()
{
	m_ballParticle->reset();
}
