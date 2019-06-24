#include "FallingCubeOnSphereScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include "R3D/Utility/Random.h"

#include <iostream>


FallingCubeOnSphereScene::FallingCubeOnSphereScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window) {
	m_camera->setTranslation(0.0, 0.0, 25.0);

	// Get a previously created drawable
	auto reg = window->getDrawableRegistry();
	dCube = reg.getResource("cube");
	dSphere = reg.getResource("sphere");

	auto rbnWorld = m_physicsEngine.getRigidBodyNodeWorld();
	auto rbWorld = rbnWorld->getWorld();

	// Init scene graph node and add it to the scene graph
	nCube = new ec::Node();
	nCube->addDrawable(dCube);
	nCube->setScale(3.0f);
	m_root->addChild(nCube);

	nSphere = new ec::Node();
	nSphere->addDrawable(dSphere);
	nSphere->setScale(1.0f);
	m_root->addChild(nSphere);

	// Init Rigidbodies
	rbCube = new r3::RigidBody();
	rbCube->setMass(1000.0f);
	rbCube->getTransform().setPosition(glm::vec3(0.0f, 5.0f, 0.0f));
	rbCube->getTransform().setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
	rbCube->setInertiaTensor(
		r3::InertiaTensorGenerator::generateCubeTensor(
			rbCube->getMass(),
			nCube->getScaleX() / 2.0f,
			nCube->getScaleY() / 2.0f,
			nCube->getScaleZ() / 2.0f
		)
	);
	glm::vec3 halfSizes(nCube->getScaleX() / 2.0f,
						nCube->getScaleY() / 2.0f,
						nCube->getScaleZ() / 2.0f);
	auto* cbCube = new r3::CollisionBox(rbCube, halfSizes);
	rbCube->setCollisionPrimitive(cbCube);
	//rbWorld->addRigidBody(rbCube);

	rbSphere = new r3::RigidBody();
	rbSphere->getTransform().setPosition(glm::vec3(1.5f, 0.0f, 1.5f));
	auto* csSphere = new r3::CollisionSphere(rbSphere, 1.0f);
	rbSphere->setCollisionPrimitive(csSphere);
	//rbWorld->addRigidBody(rbSphere);

	// Init RigidBodyNode
	rbnCube = new RigidBodyNode(rbCube, nCube);
	rbnWorld->addRigidBodyNode(rbnCube);
	rbnSphere = new RigidBodyNode(rbSphere, nSphere);
	rbnWorld->addRigidBodyNode(rbnSphere);

	//Init Forces
	fGravity = new r3::Gravity(glm::vec3(0.0f, -2.0f, 0.0f));
	rbWorld->getForceRegistry().registerForce(rbCube, fGravity);
}


FallingCubeOnSphereScene::~FallingCubeOnSphereScene()
= default;

void FallingCubeOnSphereScene::tick(const float timeDelta)
{
	SimulationScene::tick(timeDelta);
}

void FallingCubeOnSphereScene::reset()
{
	SimulationScene::reset();

	rbCube->reset(glm::vec3(0.0f, 5.0f, 0.0f));
}