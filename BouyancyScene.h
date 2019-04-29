#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"
#include "PhysicInterfaces/ParticleNode.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"
#include "R3D/ParticleEngine/ParticleBuoyancy.h"

#include "EC3D/Core/Node.h"

#include <string>
#include "Cave.h"

class BouyancyScene : public SimulationScene
{
public:
	explicit BouyancyScene(const std::string& name, SimulationWindow* window);
	~BouyancyScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	ec::Node* m_ballNode;
	ec::Node* m_cubeNode;
	ec::Drawable* m_ballDrawable;
	ec::Drawable* m_cubeDrawable;

	r3::Particle* m_ballParticle;
	r3::Particle* m_cubeParticle;
	ParticleNode* m_ballParticleNode;
	ParticleNode* m_cubeParticleNode;

	r3::ParticleGravity* m_particleGravity;
	r3::ParticleBuoyancy* m_particleBuoyancy;
};
