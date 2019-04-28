#pragma once

#include "glm/glm.hpp"
#include "R3D/Utility/Random.h"
#include "R3D/ParticleEngine/Particle.h"
#include "FireworkDefintion.h"

class FireworkParticle : public r3::Particle {

	class Payload {
		Payload(const FireworkDefintion& definition);
		~Payload();
	};


public:
	FireworkParticle();
	FireworkParticle(const FireworkDefintion& definition);
	~FireworkParticle();

	void init(const FireworkDefintion& definition);

	void integrate(float duration) override;

protected:
	float m_age;
	float m_time;

	int m_count;
};

