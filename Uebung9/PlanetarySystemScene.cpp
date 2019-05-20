#include "PlanetarySystemScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include "R3D/Utility/Random.h"

#include <iostream>


PlanetarySystemScene::PlanetarySystemScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window) {
	m_camera->setTranslation(0.0, 0.0, 25.0);

	// Get a previously created drawable
	auto reg = window->getDrawableRegistry();
	planetDrawable = reg.getResource("sphere");

	auto particleNodeWorld = m_physicsEngine.getParticleNodeWorld();
	auto particleWorld = particleNodeWorld->getWorld();

	planetCount = 5;

	// Init scene graph node and add it to the scene graph
	sunNode = new ec::Node();
	sunNode->addDrawable(planetDrawable);
	m_root->addChild(sunNode);

	planetNodes = new ec::Node*[planetCount];
	for(size_t i = 0, iLen = planetCount; i < iLen; i++) {
		planetNodes[i] = new ec::Node();
		planetNodes[i]->addDrawable(planetDrawable);
		m_root->addChild(planetNodes[i]);
	}

	//Init Particles
	sunParticle = new r3::Particle();
	particleWorld->addParticle(sunParticle);

	planetParticles = new r3::Particle*[planetCount];
	for(size_t i = 0, iLen = planetCount; i < iLen; i++) {
		planetParticles[i] = new r3::Particle();

		planetParticles[i]->setPosition(glm::vec3(3.0f * i, 0.0f, 0.0f));
		planetParticles[i]->setMass(1000.0f);
		planetParticles[i]->setVelocity(0.0f, 2.5f, 0.0f);

		particleWorld->addParticle(planetParticles[i]);
	}

	//Init ParticleNodes
	sunPN = new ParticleNode(sunParticle, sunNode);
	particleNodeWorld->addParticleNode(sunPN);

	planetPNs = new ParticleNode*[planetCount];
	for(size_t i = 0, iLen = planetCount; i < iLen; i++) {
		planetPNs[i] = new ParticleNode(planetParticles[i], planetNodes[i]);
		particleNodeWorld->addParticleNode(planetPNs[i]);
	}

	//Init Cables
	planetCables = new r3::ParticleCable*[planetCount];
	for(size_t i = 0, iLen = planetCount; i < iLen; i++) {
		planetCables[i] = new r3::ParticleCable(3.0f * i);
		planetCables[i]->setParticles(planetParticles[i], sunParticle);
		particleWorld->getContactGeneratorRegistry().registerContactGenerator(planetCables[i]);
	}	
}


PlanetarySystemScene::~PlanetarySystemScene()
= default;

void PlanetarySystemScene::tick(const float timeDelta)
{
	SimulationScene::tick(timeDelta);

	/*for(size_t i = 0, iLen = planetCount; i < iLen; i++){
		glm::vec3 pos = planetParticles[i]->getPosition();
		if(pos.x >= 3.0f && pos.y > 0.0f){
			planetCables[i]->setMaxLength(3.0f * i);
		} else if(pos.x >= 3.0f && pos.y > 0.0f){
			planetCables[i]->setMaxLength(4.0f * i);
		}
	}*/
}

void PlanetarySystemScene::reset()
{
	SimulationScene::reset();
}
