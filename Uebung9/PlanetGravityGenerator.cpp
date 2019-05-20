#include "PlanetGravityGenerator.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include <iostream>


PlanetGravityGenerator::PlanetGravityGenerator(r3::Particle* centre){
	this->centre = centre;
}

PlanetGravityGenerator::~PlanetGravityGenerator()
= default;

void PlanetGravityGenerator::updateForce(r3::Particle * particle, r3::real duration) {
	//Calculate force
	glm::vec3 distanceVector = centre->getPosition() - particle->getPosition();
	// F_G = constant (m1 * m2) / distance(centre, particle)
	float force = constant * ((centre->getMass() * particle->getMass()) / 
							  glm::pow(glm::length(distanceVector), 2));

	//Apply force to direction between to the particles
	glm::vec3 forceVector;
	forceVector = glm::normalize(distanceVector) * force;

	particle->addForce(forceVector);
}
