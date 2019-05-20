#include "PlanetGravityGenerator.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include <iostream>


PlanetGravityGenerator::PlanetGravityGenerator(r3::Particle* centre,
											   const r3::real constant = 1.0f){
	this->centre = centre;
	this->constant = constant;
}

PlanetGravityGenerator::~PlanetGravityGenerator()
= default;

void PlanetGravityGenerator::updateForce(r3::Particle * particle, r3::real duration) {
	// F_G = constant (m1 * m2) / distance
	// distance = centre - particle
	
	//wikipedia bild: m1 cross m2 (? masse ist doch kein vektor)
	glm::length(glm::vec3(0, 0, 0));
	float distance = glm::length(centre->getPosition() - particle->getPosition());
	//constant = 6, 672 * 10 ^ -11
	float force = constant * ((centre->getMass() * particle->getMass()) / glm::pow(distance, 2));

	glm::vec3 forceVector;

	if(centre->hasFiniteMass()) {
		centre->addForce(forceVector);
	}

	particle->addForce(forceVector);
}
