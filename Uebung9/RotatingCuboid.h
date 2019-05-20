#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"
#include "PhysicInterfaces/ParticleNode.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"
#include "R3D/ParticleEngine/ParticleCable.h"
#include "R3D/ParticleEngine/ParticleSpring.h"
#include "R3D/ParticleEngine/ParticleBidirectionalSpring.h"

#include "EC3D/Core/Node.h"

#include "glm/matrix.hpp"
#include <string>

class RotatingCuboid : public SimulationScene
{
public:
	explicit RotatingCuboid(const std::string& name, SimulationWindow* window);
	~RotatingCuboid();

	void tick(float timeDelta) override;
	void reset() override;

private:
	ec::Drawable* cuboidDrawable;

	ec::Node* cuboidNode;
	r3::Particle* cuboidParticle;
	ParticleNode* cuboidPN;
	r3::ParticleGravity* gravity;
};