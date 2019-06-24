#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"

#include "R3D/RigidBodyEngine/RigidBodyWorld.h"
#include "PhysicInterfaces/RigidBodyNodeWorld.h"
#include "PhysicInterfaces/RigidBodyNode.h"
#include "R3D/Utility/InertiaTensorGenerator.h"
#include "R3D/RigidBodyEngine/Gravity.h"
#include "R3D/RigidBodyEngine/CollisionSphere.h"
#include "R3D/RigidBodyEngine/CollisionBox.h"
#include "R3D/RigidBodyEngine/RigidBodyDef.h"
#include "R3D/Utility/Random.h"

#include "EC3D/Core/Node.h"

#include "glm/matrix.hpp"
#include <string>

class SphereInBoxScene : public SimulationScene {
public:
	explicit SphereInBoxScene(const std::string& name, SimulationWindow* window);
	~SphereInBoxScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	void spawnFallingSphere();

	float cooldown = 0.25f;
	float timeCount = 0.0f;
	float randBuffer = 0.1f;

	RigidBodyNodeWorld* rbnWorld;
	r3::RigidBodyWorld* rbWorld;

	ec::Drawable* dSphere;
	ec::Drawable* dSideWall;
	ec::Drawable* dBotWall;
	ec::Drawable* dBackWall;

	ec::Node* nCave[4]; //front wall is "transparent", ceiling not required
	r3::RigidBody* rbCave[5];
	RigidBodyNode* rbnCave[4];

	r3::RigidBodyDef defSphere;
	r3::Gravity* fGravity;
};