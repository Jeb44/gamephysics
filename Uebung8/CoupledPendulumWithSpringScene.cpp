#include "CoupledPendulumWithSpringScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include <iostream>

// https://www.youtube.com/watch?v=LY1d0hkKJUU

CoupledPendulumWithSpringScene::CoupledPendulumWithSpringScene(const std::string& name, SimulationWindow* window)
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
	m_firstBallNode->setTranslation(-3.5, 0.5, 0);
	m_firstBallNode->addDrawable(m_ballDrawable);

	m_secondBallNode = new ec::Node();
	m_secondBallNode->setTranslation(6, 1, 0);
	m_secondBallNode->addDrawable(m_ballDrawable);

	m_root->addChild(m_cave->getCave());
	m_root->addChild(m_firstBallNode);
	m_root->addChild(m_secondBallNode);

	// Init particle
	m_firstBallParticle = new r3::Particle();
	m_firstBallParticle->setPosition(-3.5, 0.5, 0); // Rest Pos: -4, 0, 0
	m_firstBallParticle->setMass(1.0f);

	m_secondBallParticle = new r3::Particle();
	m_secondBallParticle->setPosition(6, 1, 0); // Rest Pos: 4, 0, 0
	m_secondBallParticle->setMass(1.0f);

	particleWorld->addParticle(m_firstBallParticle);
	particleWorld->addParticle(m_secondBallParticle);

	m_firstCableParticle = new r3::Particle();
	m_firstCableParticle->setPosition(-4, 5, 0);
	m_secondCableParticle = new r3::Particle();
	m_secondCableParticle->setPosition(4, 5, 0);

	// Init particle node and register it
	m_firstBallParticleNode = new ParticleNode(m_firstBallParticle, m_firstBallNode);
	particleNodeWorld->addParticleNode(m_firstBallParticleNode);

	m_secondBallParticleNode = new ParticleNode(m_secondBallParticle, m_secondBallNode);
	particleNodeWorld->addParticleNode(m_secondBallParticleNode);

	// Init force generator and register it
	m_particleGravity = new r3::ParticleGravity(glm::vec3(0.0f, -1.0f, 0.0f));
	particleWorld->getParticleForceRegistry().add(m_firstBallParticle, m_particleGravity);
	particleWorld->getParticleForceRegistry().add(m_secondBallParticle, m_particleGravity);

	m_particleSpring = new r3::ParticleBidirectionalSpring(m_secondBallParticle, 1.0, 8.0);
	particleWorld->getParticleForceRegistry().add(m_firstBallParticle, m_particleSpring);

	m_firstParticleCable = new r3::ParticleCable(5.0f, 0.2f);
	m_firstParticleCable->setParticles(m_firstCableParticle, m_firstBallParticle);
	particleWorld->getContactGeneratorRegistry().registerContactGenerator(m_firstParticleCable);

	m_secondParticleCable = new r3::ParticleCable(5.0f, 0.2f);
	m_secondParticleCable->setParticles(m_secondCableParticle, m_secondBallParticle);
	particleWorld->getContactGeneratorRegistry().registerContactGenerator(m_secondParticleCable);


}


CoupledPendulumWithSpringScene::~CoupledPendulumWithSpringScene()
= default;

void CoupledPendulumWithSpringScene::tick(const float timeDelta)
{
	SimulationScene::tick(timeDelta);
}

void CoupledPendulumWithSpringScene::reset()
{
	m_firstBallParticle->reset();
}
