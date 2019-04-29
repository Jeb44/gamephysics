#pragma once

#include "glm/glm.hpp"
#include "R3D/Utility/Random.h"
#include "R3D/ParticleEngine/Particle.h"
#include "FireworkDefintion.h"

class FireworkParticle : public r3::Particle {

	class Payload {
	public:
		Payload();
		Payload(const FireworkDefintion* defArray, const int length, const glm::vec3& parentPos);
		~Payload();

		void initPayload(const FireworkDefintion* defArray, const int length, const glm::vec3& parentPos);

		FireworkParticle* getParticles();
		int getLength();

	private:
		FireworkParticle* m_particles;
		int m_length;
	};


public:
	FireworkParticle();
	FireworkParticle(const FireworkDefintion& definition);
	~FireworkParticle();

	void init(const FireworkDefintion& definition);
	void initPayloads(const FireworkDefintion* defArray, int lenght);

	void integrate(float duration) override;
	FireworkParticle* getPayloadParticles();

protected:
	float m_age;
	float m_time;

	Payload* m_payload;
	int m_count;
};

