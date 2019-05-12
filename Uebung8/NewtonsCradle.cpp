#include "NewtonsCradle.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include <iostream>


NewtonsCradle::NewtonsCradle(int numOfPendulums,
							 ec::Drawable* drawable,
							 glm::vec3 startPosBall,
							 ParticleNodeWorld* particleNodeWorld,
							 ec::Node* baseNode,
							 float cableHeight){
	if(numOfPendulums < 2) {
		numOfPendulums = 2;
	}
	this->numOfPendulums = numOfPendulums;
	this->cableHeight = cableHeight;

	buffer = 0.0f;

	nodes = new ec::Node*[numOfPendulums];
	particles = new r3::Particle*[numOfPendulums];
	anchors = new r3::Particle*[numOfPendulums];
	particleNodes = new ParticleNode*[numOfPendulums];

	cables = new r3::ParticleCable*[numOfPendulums];
	collisions = new r3::ParticleCollision*[numOfPendulums - 1];

	gravity = new r3::ParticleGravity(glm::vec3(0, -9.81, 0));

	//Inizialize
	for(size_t i = 0, max = numOfPendulums; i < max; i++) {
		nodes[i] = new ec::Node();
		nodes[i]->addDrawable(drawable);
		baseNode->addChild(nodes[i]);

		particles[i] = new r3::Particle();
		particles[i]->setPosition(startPosBall + glm::vec3((buffer + 2) * i, 0.0f, 0.0f));
		particles[i]->setMass(1000.0f);
		particleNodeWorld->getWorld()->addParticle(particles[i]);

		anchors[i] = new r3::Particle();
		anchors[i]->setPosition(startPosBall + glm::vec3((buffer + 2) * i, cableHeight, 0.0f));

		particleNodes[i] = new ParticleNode(particles[i], nodes[i]);
		particleNodeWorld->addParticleNode(particleNodes[i]);

		particleNodeWorld->getWorld()->getParticleForceRegistry().add(particles[i], gravity);

		cables[i] = new r3::ParticleCable(cableHeight, 0.1f);
		cables[i]->setParticles(particles[i], anchors[i]);
		particleNodeWorld->getWorld()
			->getContactGeneratorRegistry().registerContactGenerator(cables[i]);
	}

	for(size_t i = 0, max = numOfPendulums - 1; i < max; i++) {
		collisions[i] = new r3::ParticleCollision(1.0, 2.0, 0.0f);
		collisions[i]->setParticles(particles[i], particles[i + 1]);
		particleNodeWorld->getWorld()
			->getContactGeneratorRegistry().registerContactGenerator(collisions[i]);
	}

	particles[0]->setPosition(startPosBall + glm::vec3(-3.0f, 1.0f, 0));

}

NewtonsCradle::~NewtonsCradle()
= default;
