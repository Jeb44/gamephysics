#include "SphereInBoxScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include "R3D/Utility/Random.h"

#include <iostream>


SphereInBoxScene::SphereInBoxScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window) {
	m_camera->setTranslation(0.0, 0.5, 2.5);

	// Get a previously created drawable
	auto reg = window->getDrawableRegistry();
	dSphere = reg.getResource("sphere");
	dSideWall = reg.getResource("side_wall");
	dBotWall = reg.getResource("bot_wall");
	dBackWall = reg.getResource("back_wall");

	/*ec::Drawable* transparentDrawable;
	transparentDrawable->setGeometry(window->getGeometryRegistry().getResource("cube"));
	transparentDrawable->setShader(window->getShaderManager().getShader("basic"));
	reg.registerResource(transparentDrawable, "transparentCube");*/

	rbnWorld = m_physicsEngine.getRigidBodyNodeWorld();
	rbWorld = rbnWorld->getWorld();

	r3::Random::seed();

	// Init scene graph node and add it to the scene graph
	for(size_t i = 0, iLen = 4; i < iLen; i++) {
		nCave[i] = new ec::Node();
		m_root->addChild(nCave[i]);
	}
	nCave[0]->addDrawable(dBotWall);
	nCave[0]->setScaleY(0.01f);

	nCave[1]->addDrawable(dSideWall);
	nCave[1]->setScaleX(0.01f);

	nCave[2]->addDrawable(dSideWall);
	nCave[2]->setScaleX(0.01f);

	nCave[3]->addDrawable(dBackWall);
	nCave[3]->setScaleZ(0.01f);

	/*m_nodeGround->setTranslationY(-0.5f);
	m_nodeSidewall1->setTranslationX(0.5f);
	m_nodeSidewall2->setTranslationX(-0.5f);
	m_nodeBackwall->setTranslationZ(-0.5f);
*/
	// Init Rigidbodies

	for(size_t i = 0, iLen = 5; i < iLen; i++) {
		rbCave[i] = new r3::RigidBody();
		glm::vec3 halfSizes;
		if(i != 4) {
			halfSizes = glm::vec3(nCave[i]->getScaleX() / 2.0f,
								nCave[i]->getScaleY() / 2.0f,
								nCave[i]->getScaleZ() / 2.0f);
		}
		else {
			halfSizes = glm::vec3(0.5f, 0.5f, 0.005f); //RB 5 doesn't have a node
		}
		auto* cbCube = new r3::CollisionBox(rbCave[i], halfSizes);
		rbCave[i]->setCollisionPrimitive(cbCube);
		rbWorld->addRigidBody(rbCave[i]);
	}
	rbCave[0]->getTransform().setPosition(glm::vec3(0.0f, -0.5f, 0.0f));
	rbCave[1]->getTransform().setPosition(glm::vec3(0.5f, 0.0f, 0.0f));
	rbCave[2]->getTransform().setPosition(glm::vec3(-0.5f, 0.0f, 0.0f));
	rbCave[3]->getTransform().setPosition(glm::vec3(0.0f, 0.0f, -0.5f));
	rbCave[4]->getTransform().setPosition(glm::vec3(0.0f, 0.0f, 0.5f));

	// Init RigidBodyNode
	for(size_t i = 0, iLen = 4; i < iLen; i++) {
		rbnCave[i] = new RigidBodyNode(rbCave[i], nCave[i]);
		rbnWorld->addRigidBodyNode(rbnCave[i]);
	}

	//Init Forces
	fGravity = new r3::Gravity(glm::vec3(0.0f, -2.0f, 0.0f));

	defSphere.setMass(100.0f); //For spawning spheres
}


SphereInBoxScene::~SphereInBoxScene()
= default;

void SphereInBoxScene::tick(const float timeDelta)
{
	
	if(m_keyboard->isKeyDown(ec::Keyboard::ENTER) &&
	   timeCount >= cooldown) {
		spawnFallingSphere();
		timeCount = 0.0f;
	}
	timeCount += timeDelta;

	auto rbns = rbnWorld->getRigidBodyNodes();

	SimulationScene::tick(timeDelta);
}

void SphereInBoxScene::reset()
{
	SimulationScene::reset();
}

void SphereInBoxScene::spawnFallingSphere() {
	// Init Node
	ec::Node* nSphere = new ec::Node();
	nSphere->addDrawable(dSphere);
	nSphere->setScale(0.1f);
	m_root->addChild(nSphere);

	// Set Randoms
	float x = r3::Random::randomFloat(-(nCave[0]->getScaleX() / 2.0f) + randBuffer,
									  nCave[0]->getScaleX() / 2.0f - randBuffer);
	float z = r3::Random::randomFloat(-(nCave[0]->getScaleZ() / 2.0f) + randBuffer,
									  nCave[0]->getScaleZ() / 2.0f - randBuffer);

	// Init Rigidbody
	r3::RigidBody* rbSphere = new r3::RigidBody(defSphere);
	rbSphere->getTransform().setPosition(glm::vec3(x, 1.0f, z));
	rbSphere->setInertiaTensor(
		r3::InertiaTensorGenerator::generateSphereTensor(
		rbSphere->getMass(),
		nSphere->getScale().x
		)
	);
	auto csSphere = new r3::CollisionSphere(rbSphere, nSphere->getScale().x);
	rbSphere->setCollisionPrimitive(csSphere);
	rbWorld->addRigidBody(rbSphere);

	// Init RigidbodyNode
	RigidBodyNode* rbnSphere = new RigidBodyNode(rbSphere, nSphere);
	rbnWorld->addRigidBodyNode(rbnSphere);

	// Init Gravity
	rbWorld->getForceRegistry().registerForce(rbSphere, fGravity);
}