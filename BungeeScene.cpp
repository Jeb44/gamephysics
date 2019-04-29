#include "BungeeScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include <iostream>

BungeeScene::BungeeScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window)
{
    m_camera->setTranslation(0.0, 0.0, 25.0);

	// Get a previously created drawable
	auto reg = window->getDrawableRegistry();
	m_ballDrawable = reg.getResource("sphere");

	auto particleNodeWorld = m_physicsEngine.getParticleNodeWorld();
	auto particleWorld = particleNodeWorld->getWorld();

	// Init scene graph node and add it to the scene graph
	m_ballNode = new ec::Node();
	m_ballNode->addDrawable(m_ballDrawable);

	m_root->addChild(m_ballNode);

	// Init particle
	m_anchorParticle = new r3::Particle();
	m_anchorParticle->setPosition(0.0, 1.0, 0.0);

	m_ballParticle = new r3::Particle();
	m_ballParticle->setVelocity(0.5, 0, 0);
	m_ballParticle->setMass(1.0f);

	// Init particle node and register it
	m_ballParticleNode = new ParticleNode(m_ballParticle, m_ballNode);
	particleNodeWorld->addParticleNode(m_ballParticleNode);

	// Init force generator and register it
	m_particleGravity = new r3::ParticleGravity(glm::vec3(0.0f, -9.8f, 0.0f));
	m_particleBungee = new r3::ParticleBungee(m_anchorParticle, 0.7, 1.0);

	particleWorld->getParticleForceRegistry().add(m_ballParticle, m_particleGravity);
	particleWorld->getParticleForceRegistry().add(m_ballParticle, m_particleBungee);


	//cave
	m_cave = new Cave(window);
	m_root->addChild(m_cave->getCave());
}

BungeeScene::~BungeeScene()
= default;

void BungeeScene::tick(const float timeDelta)
{
	SimulationScene::tick(timeDelta);
}

void BungeeScene::reset()
{
	m_ballParticle->reset();
}
