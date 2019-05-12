#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"
#include "PhysicInterfaces/ParticleNode.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"
#include "R3D/ParticleEngine/ParticleBuoyancy.h"

#include "EC3D/Core/Node.h"

#include <string>
#include "../Uebung7/ParticleWind.h"

class WindScene : public SimulationScene
{
public:
	explicit WindScene(const std::string& name, SimulationWindow* window);
	~WindScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	ec::Node* m_ballNode;
	ec::Drawable* m_ballDrawable;

	r3::Particle* m_ballParticle;
	ParticleNode* m_ballParticleNode;

	r3::ParticleGravity* m_particleGravity;
	r3::ParticleBuoyancy* m_particleBuoyancy;
	ParticleWind* m_particleWind;
};
