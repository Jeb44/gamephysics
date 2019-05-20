#include "RotatingCuboid.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include "R3D/Utility/Random.h"

#include <iostream>


RotatingCuboid::RotatingCuboid(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window) {
	m_camera->setTranslation(0.0, 0.0, 5.0);

	// Get a previously created drawable
	auto reg = window->getDrawableRegistry();
	cuboidDrawable = reg.getResource("cube");

	auto particleNodeWorld = m_physicsEngine.getParticleNodeWorld();
	auto particleWorld = particleNodeWorld->getWorld();

	// Init scene graph node and add it to the scene graph
	cuboidNode = new ec::Node();
	cuboidNode->addDrawable(cuboidDrawable);
	cuboidNode->setScale(1.35f, 0.75f, 1.1f);
	m_root->addChild(cuboidNode);

	//Init Particles
	cuboidParticle = new r3::Particle();
	cuboidParticle->setMass(1.0f);
	particleWorld->addParticle(cuboidParticle);

	//Init ParticleNodes
	cuboidPN = new ParticleNode(cuboidParticle, cuboidNode);
	particleNodeWorld->addParticleNode(cuboidPN);

	//Init Cables
	gravity = new r3::ParticleGravity(glm::vec3(0.0f, -1.0f, 0.0f));	
	particleWorld->getParticleForceRegistry().add(cuboidParticle, gravity);
}


RotatingCuboid::~RotatingCuboid()
= default;

void RotatingCuboid::tick(const float timeDelta)
{
	SimulationScene::tick(timeDelta);

	cuboidNode->rotateXLocal(2.5f * timeDelta);
	cuboidNode->rotateYLocal(3.75f * timeDelta);
}

void RotatingCuboid::reset()
{
	SimulationScene::reset();
}
