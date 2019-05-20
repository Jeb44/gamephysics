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

class SpaceshipScene : public SimulationScene
{
public:
	explicit SpaceshipScene(const std::string& name, SimulationWindow* window);
	~SpaceshipScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	int planetCount;

	ec::Drawable* spaceshipDrawable;
	ec::Drawable* planetDrawable;

	ec::Node* spaceshipNode;
	ec::Node** planetNodes;

	r3::Particle* spaceshipParticle;
	r3::Particle** planetParticles;

	ParticleNode* spaceShipPN;
	ParticleNode** planetPNs;

	PlanetGravityGenerator** planetGravities;
	
};
