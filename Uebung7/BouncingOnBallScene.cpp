#include "BouncingOnBallScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include <iostream>

BouncingOnBallScene::BouncingOnBallScene(const std::string& name, SimulationWindow* window)
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

	m_heavyBallNode = new ec::Node();
	m_heavyBallNode->setTranslation(0.0, 8.0, 0.0);
	m_heavyBallNode->addDrawable(m_ballDrawable);

	m_lightBallNode = new ec::Node();
	m_lightBallNode->setTranslation(0.0, 10.0, 0.0);
	m_lightBallNode->addDrawable(m_ballDrawable);

	m_root->addChild(m_cave->getCave());
	m_root->addChild(m_heavyBallNode);
	m_root->addChild(m_lightBallNode);

	// Init particle
	m_heavyBallParticle = new r3::Particle();
	m_heavyBallParticle->setVelocity(0.0f, 0.0, 0.0);
	m_heavyBallParticle->setPosition(0, 8, 0);
	m_heavyBallParticle->setMass(2.0f);

	m_lightBallParticle = new r3::Particle();
	m_lightBallParticle->setVelocity(0.0f, 0.0, 0.0);
	m_lightBallParticle->setPosition(0, 10, 0);
	m_lightBallParticle->setMass(1.0f);

	m_anchorParticle = new r3::Particle();
	m_anchorParticle->setPosition(0.0f, 10.0f, 0.0f);

	// Init particle node and register it
	m_heavyBallParticleNode = new ParticleNode(m_heavyBallParticle, m_heavyBallNode);
	particleNodeWorld->addParticleNode(m_heavyBallParticleNode);

	m_lightBallParticleNode = new ParticleNode(m_lightBallParticle, m_lightBallNode);
	particleNodeWorld->addParticleNode(m_lightBallParticleNode);

	// Init force generator and register it
	m_particleGravity = new r3::ParticleGravity(glm::vec3(0.0f, -9.8f, 0.0f));
	particleWorld->getParticleForceRegistry().add(m_heavyBallParticle, m_particleGravity);
	particleWorld->getParticleForceRegistry().add(m_lightBallParticle, m_particleGravity);

	m_particleDrag = new r3::ParticleDrag(4, 0.2, 0.8); //6.283, 0.469, 1.225
	particleWorld->getParticleForceRegistry().add(m_heavyBallParticle, m_particleDrag);
	particleWorld->getParticleForceRegistry().add(m_lightBallParticle, m_particleDrag);

	m_particleCableToHeavy = new r3::ParticleCable(10.0f, 0.99f);
	m_particleCableToHeavy->setParticles(m_heavyBallParticle, m_anchorParticle);

	m_particleCableToLight = new r3::ParticleCable(10.0f, 0.99f);
	m_particleCableToLight->setParticles(m_lightBallParticle, m_anchorParticle);
	
	m_particleCollision = new r3::ParticleCollision(0.99, 2.0, 0.0);
	m_particleCollision->setParticles(m_lightBallParticle, m_heavyBallParticle);

	particleWorld->getContactGeneratorRegistry().registerContactGenerator(m_particleCableToHeavy);
	particleWorld->getContactGeneratorRegistry().registerContactGenerator(m_particleCableToLight);
	particleWorld->getContactGeneratorRegistry().registerContactGenerator(m_particleCollision);
}

BouncingOnBallScene::~BouncingOnBallScene()
= default;

void BouncingOnBallScene::tick(const float timeDelta)
{
	SimulationScene::tick(timeDelta);/*
	m_heavyBallParticle->setPosition(glm::vec3(0.0f,
										  m_heavyBallParticle->getPosition().y,
										  0.0f));*/
	std::cout << "Heavy (" <<
		m_heavyBallParticle->getPosition().x << ", " <<
		m_heavyBallParticle->getPosition().y << ", " <<
		m_heavyBallParticle->getPosition().z <<
		") Light (" <<
		m_lightBallParticle->getPosition().x << ", " <<
		m_lightBallParticle->getPosition().y << ", " <<
		m_lightBallParticle->getPosition().z << ")" <<
		std::endl;

}

void BouncingOnBallScene::reset()
{
	m_heavyBallParticle->reset();
}
