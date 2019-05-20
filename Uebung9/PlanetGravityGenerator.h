#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"

#include "glm/common.hpp"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/IParticleForceGenerator.h"

#include <string>

class PlanetGravityGenerator : public r3::IParticleForceGenerator
{
public:
	explicit PlanetGravityGenerator(r3::Particle* centre);
	~PlanetGravityGenerator();

	void updateForce(r3::Particle* particle, r3::real duration) override;

private:
	r3::Particle* centre;
	const r3::real constant = 6.674E-11;
};

