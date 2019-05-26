#include "InertiaTensorScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include "R3D/Utility/Random.h"

#include <iostream>


InertiaTensorScene::InertiaTensorScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window) {
	m_camera->setTranslation(0.0, 0.0, 25.0);

	// Get a previously created drawable
	auto reg = window->getDrawableRegistry();
	cuboidDrawable = reg.getResource("cube");

	auto rbnWorld = m_physicsEngine.getRigidBodyNodeWorld();
	auto rbWorld = rbnWorld->getWorld();

	connectPoint = glm::vec3(1.35, 0.75, 1.1);
	anchor = glm::vec3(0.0f, 5.0f, 0.0f);

	// Init scene graph node and add it to the scene graph
	cuboidNode = new ec::Node();
	cuboidNode->addDrawable(cuboidDrawable);
	cuboidNode->setScale(connectPoint);
	m_root->addChild(cuboidNode);

	// Init Rigidbody
	cuboidRB = new r3::RigidBody();
	cuboidRB->setMass(75.0f);
	cuboidRB->getTransform().setPosition(anchor);
	//cuboidRB->setRotation() & addRotation() add "consistent" rotation? why?
	//cuboidRB->getTransform().setRotation(glm::quat(glm::vec3(0.0f, 10.0f, 0.0f)));
	cuboidRB->setInertiaTensor(
		r3::InertiaTensorGenerator::generateCubeTensor(
			cuboidRB->getMass(),
			cuboidNode->getScaleX() / 2.0f,
			cuboidNode->getScaleY() / 2.0f,
			cuboidNode->getScaleZ() / 2.0f
		)
	);
	rbWorld->addRigidBody(cuboidRB);
	

	// Init RigidBodyNode
	cuboidRBN = new RigidBodyNode(cuboidRB, cuboidNode);
	rbnWorld->addRigidBodyNode(cuboidRBN);

	//Init Forces
	gravity = new r3::Gravity(glm::vec3(0.0f, -2.0f, 0.0f));
	rbWorld->getForceRegistry().registerForce(cuboidRB, gravity);

	spring = new r3::AnchoredSpring(glm::vec3(anchor),
									glm::vec3(connectPoint),
									50.0f,
									5.0f);
	rbWorld->getForceRegistry().registerForce(cuboidRB, spring);
}


InertiaTensorScene::~InertiaTensorScene()
= default;

void InertiaTensorScene::tick(const float timeDelta)
{
	SimulationScene::tick(timeDelta);
	
}

void InertiaTensorScene::reset()
{
	SimulationScene::reset();
}
