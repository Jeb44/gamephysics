#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"
#include "PhysicInterfaces/ParticleNode.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"
#include "R3D/ParticleEngine/ParticleCable.h"
#include "R3D/ParticleEngine/ParticleSpring.h"

#include "EC3D/Core/Node.h"

#include <string>
#include "../Cave.h"

class CoupledPendulumScene : public SimulationScene
{
public:
	explicit CoupledPendulumScene(const std::string& name, SimulationWindow* window);
	~CoupledPendulumScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	Cave* m_cave;

	ec::Node* m_firstBallNode;
	ec::Node* m_secondBallNode;
	ec::Drawable* m_ballDrawable;

	r3::Particle* m_firstBallParticle;
	ParticleNode* m_firstBallParticleNode;

	r3::Particle* m_secondBallParticle;
	ParticleNode* m_secondBallParticleNode;

	r3::Particle* m_cableStartParticle;

	r3::ParticleGravity* m_particleGravity;
	r3::ParticleCable* m_particleCable;
	r3::ParticleSpring* m_particleSpringFirstToSecond;
	r3::ParticleSpring* m_particleSpringSecondToFirst;
};
