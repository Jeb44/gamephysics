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

#include "R3D/RigidBodyEngine/BoundingBox.h"

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

	RigidBodyNodeWorld* rbnWorld;
	r3::RigidBodyWorld* rbWorld;

	ec::Drawable* dSlope;
	ec::Drawable* dSphere;

	ec::Node* nSlope;
	r3::RigidBody* rbSlope;
	RigidBodyNode* rbnSlope;

	
	
	

	r3::Gravity* fGravity;

	r3::BoundingBox* bbCube;

	r3::RigidBodyDef defSphere;
};