#include "CoupledPendulumScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include <iostream>

CoupledPendulumScene::CoupledPendulumScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window)
{
    m_camera->setTranslation(0.0, 0.0, 25.0);

	// Get a previously created drawable
	auto reg = window->getDrawableRegistry();
	m_ballDrawable = reg.getResource("sphere");

	auto particleNodeWorld = m_physicsEngine.getParticleNodeWorld();
	auto particleWorld = particleNodeWorld->getWorld();

	// Init scene graph node and add it to the scene graph
	m_cave = new Cave(window);

	m_firstBallNode = new ec::Node();
	m_firstBallNode->setTranslation(6, 2, 0);
	m_firstBallNode->addDrawable(m_ballDrawable);

	m_secondBallNode = new ec::Node();
	m_secondBallNode->setTranslation(6, 4, 0);
	m_secondBallNode->addDrawable(m_ballDrawable);

	m_root->addChild(m_cave->getCave());
	m_root->addChild(m_firstBallNode);
	m_root->addChild(m_secondBallNode);

	// Init particle
	m_firstBallParticle = new r3::Particle();
	m_firstBallParticle->setVelocity(0.0f, 0.0, 0.0);
	m_firstBallParticle->setPosition(6, 2, 0);
	m_firstBallParticle->setMass(1.0f);

	m_secondBallParticle = new r3::Particle();
	m_secondBallParticle->setVelocity(0.0f, 0.0, 0.0);
	m_secondBallParticle->setPosition(6, 4, 0);
	m_secondBallParticle->setMass(1.0f);

	m_cableStartParticle = new r3::Particle();
	m_cableStartParticle->setPosition(0, 10, 0);

	particleWorld->addParticle(m_firstBallParticle);
	particleWorld->addParticle(m_secondBallParticle);

	// Init particle node and register it
	m_firstBallParticleNode = new ParticleNode(m_firstBallParticle, m_firstBallNode);
	particleNodeWorld->addParticleNode(m_firstBallParticleNode);

	m_secondBallParticleNode = new ParticleNode(m_secondBallParticle, m_secondBallNode);
	particleNodeWorld->addParticleNode(m_secondBallParticleNode);

	// Init force generator and register it
	m_particleGravity = new r3::ParticleGravity(glm::vec3(0.0f, -1.0f, 0.0f));
	particleWorld->getParticleForceRegistry().add(m_firstBallParticle, m_particleGravity);
	particleWorld->getParticleForceRegistry().add(m_secondBallParticle, m_particleGravity);

	m_particleSpringFirstToSecond = new r3::ParticleSpring(m_secondBallParticle, 1.0, 1.0);
	particleWorld->getParticleForceRegistry().add(m_firstBallParticle, m_particleSpringFirstToSecond);
	
	m_particleSpringSecondToFirst = new r3::ParticleSpring(m_firstBallParticle, 1.0, 1.0);
	particleWorld->getParticleForceRegistry().add(m_secondBallParticle, m_particleSpringSecondToFirst);


	m_particleCable = new r3::ParticleCable(10.0f, 0.2f);
	m_particleCable->setParticles(m_cableStartParticle, m_firstBallParticle);
	particleWorld->getContactGeneratorRegistry().registerContactGenerator(m_particleCable);
}

CoupledPendulumScene::~CoupledPendulumScene()
= default;

void CoupledPendulumScene::tick(const float timeDelta)
{
	SimulationScene::tick(timeDelta);
}

void CoupledPendulumScene::reset()
{
	m_firstBallParticle->reset();
}
