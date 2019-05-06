#pragma once

#include "R3D/Common/Common.h"
#include "R3D/ParticleEngine/IParticleForceGenerator.h"
#include "R3D/ParticleEngine/Particle.h"

#include "glm/common.hpp"

using namespace r3;

class ParticleWind : public IParticleForceGenerator {
public:
	explicit ParticleWind(real maxDepth,
						  real liquidHeight,
						  glm::vec3 windStrength);
	virtual ~ParticleWind();

	void updateForce(Particle* particle, real duration) override;

protected:
	real m_maxDepth;
	real m_liquidHeight;
	glm::vec3 m_windStrength;


};