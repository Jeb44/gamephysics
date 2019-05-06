#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"
#include "PhysicInterfaces/ParticleNode.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"
#include "R3D/ParticleEngine/ParticleBungee.h"

#include "EC3D/Core/Node.h"

#include <string>


#include "Cave.h"

class BungeeScene : public SimulationScene
{
public:
	explicit BungeeScene(const std::string& name, SimulationWindow* window);
	~BungeeScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	ec::Node* m_ballNode;
	ec::Drawable* m_ballDrawable;

	Cave* m_cave;

	r3::Particle* m_anchorParticle;
	r3::Particle* m_ballParticle;
	ParticleNode* m_ballParticleNode;

	r3::ParticleGravity* m_particleGravity;
	r3::ParticleBungee* m_particleBungee;
};
