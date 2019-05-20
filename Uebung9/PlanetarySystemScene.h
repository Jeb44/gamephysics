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

#include "PlanetGravityGenerator.h"
#include <string>

class PlanetarySystemScene : public SimulationScene
{
public:
	explicit PlanetarySystemScene(const std::string& name, SimulationWindow* window);
	~PlanetarySystemScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	int planetCount;

	ec::Drawable* planetDrawable;

	ec::Node* sunNode;
	ec::Node** planetNodes;

	r3::Particle* sunParticle;
	r3::Particle** planetParticles;

	ParticleNode* sunPN;
	ParticleNode** planetPNs;
	
	r3::ParticleCable** planetCables;
};