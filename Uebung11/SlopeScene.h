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

class SlopeScene : public SimulationScene
{
public:
	explicit SlopeScene(const std::string& name, SimulationWindow* window);
	~SlopeScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	void spawnFallingSphere();
	void removeSphere(RigidBodyNode* rbn);

	float cooldown = 0.5f;
	float timeCount = 0.0f;
	float randBuffer = 0.25f;

	RigidBodyNodeWorld* rbnWorld;
	r3::RigidBodyWorld* rbWorld;

	ec::Drawable* dSlope;
	ec::Drawable* dSphere;

	ec::Node* nSlope;
	r3::RigidBody* rbSlope;
	RigidBodyNode* rbnSlope;	

	r3::RigidBodyDef defSphere;
	r3::Gravity* fGravity;
};