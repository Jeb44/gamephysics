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

	//outside "liquid"
	if(depth > m_liquidHeight + halfMaxDepth) {
		particle->addForce(m_windStrength);
		std::cout 
			<< "Added wind Force: (" 
			<< m_windStrength.x << ", " 
			<< m_windStrength.y << ", " 
			<< m_windStrength.z << ")" 
		<< std::endl;
		return;
	} 
	//inside "liquid"
	else {
		std::cout << "Added no Force" << std::endl;
		return;
	}	
	
}
