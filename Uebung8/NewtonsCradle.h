#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"
#include "PhysicInterfaces/ParticleNode.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"
#include "R3D/ParticleEngine/ParticleCable.h"
#include "R3D/ParticleEngine/ParticleSpring.h"
#include "R3D/ParticleEngine/ParticleBidirectionalSpring.h"
#include "R3D/ParticleEngine/ParticleCollision.h"
#include "R3D/ParticleEngine/ParticleConstraint.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/Node.h"

#include <string>
#include "../Cave.h"

class NewtonsCradle
{
public:
	explicit NewtonsCradle(int numOfPendulums,
						   ec::Drawable* drawable,
						   glm::vec3 startPosBall,
						   ParticleNodeWorld* particleNodeWorld,
						   ec::Node* baseNode,
						   float cableHeight = 5.0f);
	~NewtonsCradle();

private:
	int numOfPendulums;
	float cableHeight;
	float buffer;

	ec::Node** nodes;
	r3::Particle** particles;
	r3::Particle** anchors;
	ParticleNode** particleNodes;

	r3::ParticleCable** cables;
	r3::ParticleCollision** collisions;

	r3::ParticleGravity* gravity;
};

