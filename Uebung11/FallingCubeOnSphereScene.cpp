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

	auto rbnWorld = m_physicsEngine.getRigidBodyNodeWorld();
	auto rbWorld = rbnWorld->getWorld();

	// Init scene graph node and add it to the scene graph
	nCube = new ec::Node();
	nCube->addDrawable(dCube);
	m_root->addChild(nCube);

	// Init Rigidbody
	rbCube = new r3::RigidBody();
	rbCube->setMass(75.0f);
	//cuboidRB->getTransform().setPosition(anchor);
	rbCube->setInertiaTensor(
		r3::InertiaTensorGenerator::generateCubeTensor(
			rbCube->getMass(),
			nCube->getScaleX() / 2.0f,
			nCube->getScaleY() / 2.0f,
			nCube->getScaleZ() / 2.0f
		)
	);
	rbWorld->addRigidBody(rbCube);
	
	


	// Init RigidBodyNode
	rbnCube = new RigidBodyNode(rbCube, nCube);
	rbnWorld->addRigidBodyNode(rbnCube);

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
}
