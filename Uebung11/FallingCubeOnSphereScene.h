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

#include "R3D/RigidBodyEngine/BoundingBox.h"

#include "EC3D/Core/Node.h"

#include "glm/matrix.hpp"
#include <string>

class FallingCubeOnSphereScene : public SimulationScene
{
public:
	explicit FallingCubeOnSphereScene(const std::string& name, SimulationWindow* window);
	~FallingCubeOnSphereScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	ec::Drawable* dCube;
	ec::Drawable* dSphere;

	ec::Node* nCube;
	r3::RigidBody* rbCube;
	RigidBodyNode* rbnCube;

	ec::Node* nSphere;
	r3::RigidBody* rbSphere;
	RigidBodyNode* rbnSphere;

	r3::Gravity* fGravity;

	r3::BoundingBox* bbCube;
};