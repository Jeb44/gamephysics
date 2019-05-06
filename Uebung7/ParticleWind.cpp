#include "ParticleWind.h"

#include <iostream>

ParticleWind::ParticleWind(real maxDepth, real liquidHeight, glm::vec3 windStrength)
{
	m_maxDepth = maxDepth;
	m_liquidHeight = liquidHeight;
	m_windStrength = windStrength;
}

ParticleWind::~ParticleWind() = default;

void ParticleWind::updateForce(Particle * particle, real duration) {
/*
 * f =	{ 0 when d > 0
 *		{ windStrength when d <= 0
 */

	const auto depth = particle->getPosition().y;
	const auto halfMaxDepth = m_maxDepth / 2.0f;

	glm::vec3 force(real(0.0f));

	//inside "liquid"
	if(depth > m_liquidHeight + halfMaxDepth) {
		force = m_windStrength;
		particle->addForce(force);
		std::cout << "Added wind Force: (" 
			<< force.x << ", " << force.y << ", " << force.z << ")" << std::endl;
		return;
	} 
	//outside "liquid"
	else {
		std::cout << "Added no Force" << std::endl;
		return;
	}	
	
}
