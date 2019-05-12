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

class GroundScene : public SimulationScene
{
public:
	explicit GroundScene(const std::string& name, SimulationWindow* window);
	~GroundScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	Cave* m_cave;

	ec::Node* m_ballNode;
	ec::Node* m_cableNode;
	ec::Drawable* m_ballDrawable;

	r3::Particle* m_ballParticle;
	ParticleNode* m_ballParticleNode;

	r3::Particle* m_cableStartParticle;
	ParticleNode* m_cableStartParticleNode;

	r3::ParticleGravity* m_particleGravity;
	r3::ParticleCable* m_particleCable;
};
