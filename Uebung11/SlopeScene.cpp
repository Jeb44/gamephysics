#include "SlopeScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include "R3D/Utility/Random.h"

#include <iostream>


SlopeScene::SlopeScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window) {
	m_camera->setTranslation(0.0, 0.0, 25.0);

	// Get a previously created drawable
	auto reg = window->getDrawableRegistry();
	dSlope = reg.getResource("cube");
	dSphere = reg.getResource("sphere");

	rbnWorld = m_physicsEngine.getRigidBodyNodeWorld();
	rbWorld = rbnWorld->getWorld();

	r3::Random::seed();

	// Init scene graph node and add it to the scene graph
	nSlope = new ec::Node();
	nSlope->addDrawable(dSlope);
	nSlope->setScaleX(10.0f);
	nSlope->setScaleY(0.5f);
	nSlope->setScaleZ(10.0f);
	m_root->addChild(nSlope);

	// Init Rigidbodies
	rbSlope = new r3::RigidBody();
	rbSlope->getTransform().setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	rbSlope->getTransform().setRotation(glm::quat(glm::vec3(0.3f, 0.3f, 0.1f)));
	glm::vec3 halfSizes(nSlope->getScaleX() / 2.0f,
						nSlope->getScaleY() / 2.0f,
						nSlope->getScaleZ() / 2.0f);
	auto* cbCube = new r3::CollisionBox(rbSlope, halfSizes);
	rbSlope->setCollisionPrimitive(cbCube);
	rbWorld->addRigidBody(rbSlope);

	defSphere.setMass(100.0f);

	// Init RigidBodyNode
	rbnSlope = new RigidBodyNode(rbSlope, nSlope);
	rbnWorld->addRigidBodyNode(rbnSlope);

	//Init Forces
	fGravity = new r3::Gravity(glm::vec3(0.0f, -2.0f, 0.0f));
}


SlopeScene::~SlopeScene()
= default;

void SlopeScene::tick(const float timeDelta)
{
	
	if(m_keyboard->isKeyDown(ec::Keyboard::ENTER) &&
	   timeCount >= cooldown) {
		spawnFallingSphere();
		timeCount = 0.0f;
	}
	timeCount += timeDelta;

	auto rbns = rbnWorld->getRigidBodyNodes();

	/*for(auto rbn : rbns){
		if(rbn->getRigidBody()->getTransform().getPosition().y <= -1.0f){
			removeSphere(rbn);
		}
	}*/

	for(size_t i = 0, iLen = rbns.size(); i < iLen; i++){
		if(rbns[i]->getRigidBody()->getTransform().getPosition().y <= -1.0f) {
			removeSphere(rbns[i]);
		}
	}

	SimulationScene::tick(timeDelta);
}

void SlopeScene::reset()
{
	SimulationScene::reset();
}

void SlopeScene::spawnFallingSphere() {
	// Init Node
	ec::Node* nSphere = new ec::Node();
	nSphere->addDrawable(dSphere);
	nSphere->setScale(1.0f);
	m_root->addChild(nSphere);

	// Set Randoms
	float x = r3::Random::randomFloat(-(nSlope->getScaleX() / 2.0f) + randBuffer,
									  nSlope->getScaleX() / 2.0f - randBuffer);
	float z = r3::Random::randomFloat(-(nSlope->getScaleZ() / 2.0f) + randBuffer,
									  nSlope->getScaleZ
									  () / 2.0f - randBuffer);

	// Init Rigidbody
	r3::RigidBody* rbSphere = new r3::RigidBody(defSphere);
	rbSphere->getTransform().setPosition(glm::vec3(x, 5.0f, z));
	rbSphere->setInertiaTensor(
		r3::InertiaTensorGenerator::generateSphereTensor(
		rbSphere->getMass(),
		1.0f
		)
	);
	auto csSphere = new r3::CollisionSphere(rbSphere, 1.0f);
	rbSphere->setCollisionPrimitive(csSphere);
	rbWorld->addRigidBody(rbSphere);

	// Init RigidbodyNode
	RigidBodyNode* rbnSphere = new RigidBodyNode(rbSphere, nSphere);
	rbnWorld->addRigidBodyNode(rbnSphere);

	// Init Gravity
	rbWorld->getForceRegistry().registerForce(rbSphere, fGravity);
}

void SlopeScene::removeSphere(RigidBodyNode* rbn){
	/*m_root->removeChild(rbn->getNode());
	delete rbn->getNode();

	rbWorld->getForceRegistry().unregisterForce(rbn->getRigidBody(), fGravity);
	delete rbn->getRigidBody()->getCollisionPrimitive();
	rbWorld->removeRigidBody(rbn->getRigidBody());
	delete rbn->getRigidBody();

	rbnWorld->removeRigidBodyNode(rbn);
	delete rbn;*/
}