#include "FireworkParticle.h"

FireworkParticle::FireworkParticle() {
	init(FireworkDefintion());
}

FireworkParticle::FireworkParticle(const FireworkDefintion& definition) {
	init(definition);
}

FireworkParticle::~FireworkParticle() = default;

void FireworkParticle::init(const FireworkDefintion& definition) {
	//General Particle Def
	m_position = definition.initalPosition;
	m_acceleration = definition.acceleration;
	m_forceAccumulator = definition.forceAccumulator;
	m_damping = definition.damping;
	m_inverseMass = definition.inverseMass;
	m_isDead = definition.isDead;
	
	//Firework (Particle) Def
	m_velocity = r3::Random::randomVec3(definition.velocityMin, definition.velocityMax);
	m_age = r3::Random::randomFloat(definition.ageMin, definition.ageMax);
	m_count = definition.count;

	m_time = 0.0f;
}

void FireworkParticle::integrate(float duration) {
	__super::integrate(duration);

	m_time += duration;
	if(m_time >= m_age) {
		m_isDead = true;
	}
}

FireworkParticle::Payload::Payload(const FireworkDefintion & definition) {

}

FireworkParticle::Payload::~Payload() {}
