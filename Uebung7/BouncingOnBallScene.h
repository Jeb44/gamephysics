#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"
#include "PhysicInterfaces/ParticleNode.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"
#include "R3D/ParticleEngine/ParticleCable.h"
#include "R3D/ParticleEngine/ParticleDrag.h"
#include "R3D/ParticleEngine/ParticleCollision.h"

#include "EC3D/Core/Node.h"

#include <string>
#include "../Cave.h"

class BouncingOnBallScene : public SimulationScene
{
public:
	explicit BouncingOnBallScene(const std::string& name, SimulationWindow* window);
	~BouncingOnBallScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	Cave* m_cave;

	ec::Node* m_heavyBallNode;
	ec::Node* m_lightBallNode;
	ec::Drawable* m_ballDrawable;

	r3::Particle* m_heavyBallParticle;
	ParticleNode* m_heavyBallParticleNode;

	r3::Particle* m_lightBallParticle;
	ParticleNode* m_lightBallParticleNode;

	r3::Particle* m_anchorParticle;

	r3::ParticleGravity* m_particleGravity;
	r3::ParticleCable* m_particleCableToHeavy;
	r3::ParticleCable* m_particleCableToLight;
	r3::ParticleDrag* m_particleDrag;
	r3::ParticleCollision* m_particleCollision;
};
