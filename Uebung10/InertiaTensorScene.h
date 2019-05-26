#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"

#include "R3D/RigidBodyEngine/RigidBodyWorld.h"
#include "PhysicInterfaces/RigidBodyNodeWorld.h"
#include "PhysicInterfaces/RigidBodyNode.h"
#include "R3D/Utility/InertiaTensorGenerator.h"
#include "R3D/RigidBodyEngine/Gravity.h"
#include "R3D/RigidBodyEngine/Spring.h"
#include "R3D/RigidBodyEngine/AnchoredSpring.h"

#include "EC3D/Core/Node.h"

#include "glm/matrix.hpp"
#include <string>

class InertiaTensorScene : public SimulationScene
{
public:
	explicit InertiaTensorScene(const std::string& name, SimulationWindow* window);
	~InertiaTensorScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	ec::Drawable* cuboidDrawable;

	ec::Node* cuboidNode;
	r3::RigidBody* cuboidRB;
	RigidBodyNode* cuboidRBN;
	r3::Gravity* gravity;
	r3::AnchoredSpring* spring;

	glm::vec3 connectPoint;
	glm::vec3 anchor;
};