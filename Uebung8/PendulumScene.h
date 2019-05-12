#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"
#include "PhysicInterfaces/ParticleNode.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"
#include "R3D/ParticleEngine/ParticleCable.h"

#include "EC3D/Core/Node.h"

#include <string>
#include "../Cave.h"

class PendulumScene : public SimulationScene
{
public:
	explicit PendulumScene(const std::string& name, SimulationWindow* window);
	~PendulumScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	Cave* m_cave;

	ec::Node* m_ballNode;
	ec::Drawable* m_ballDrawable;

	r3::Particle* m_ballParticle;
	ParticleNode* m_ballParticleNode;

	r3::Particle* m_cableStartParticle;

	r3::ParticleGravity* m_particleGravity;
	r3::ParticleCable* m_particleCable;
};
