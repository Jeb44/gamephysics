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

void FireworkParticle::initPayloads(const FireworkDefintion* defArray, int length) {
	/*m_payload = new Payload[m_count];
	for(size_t i = 0; i < m_count; i++) {
		m_payload[i].structurePayload(defArray, length);
	}*/
	if(m_count > 0) {
		m_payload = new Payload(defArray, length, this->getPosition());
		m_count--;
	}
}

void FireworkParticle::integrate(float duration) {
	__super::integrate(duration);

	m_time += duration;
	if(m_time >= m_age) {
		m_isDead = true;
	}
}

FireworkParticle* FireworkParticle::getPayloadParticles() {
	return m_payload->getParticles;
}

FireworkParticle::Payload::Payload() {}

FireworkParticle::Payload::Payload(const FireworkDefintion* defArray, const int length, const glm::vec3& parentPos) {
	initPayload(defArray, length, parentPos);
}

FireworkParticle::Payload::~Payload() = default;

void FireworkParticle::Payload::initPayload(const FireworkDefintion* defArray, const int length, const glm::vec3& parentPos) {
	assert(defArray != nullptr);
	assert(length >= 0);

	m_length = length;
	m_particles = new FireworkParticle[length * 2];
	
	for(size_t i = 0, iLen = length * 2; i < iLen; i++) {
		
		int modulo = i % m_length;

		//General Data
		m_particles[i].m_position = parentPos;
		m_particles[i].m_acceleration = defArray[modulo].acceleration;
		m_particles[i].m_forceAccumulator = defArray[modulo].forceAccumulator;
		m_particles[i].m_damping = defArray[modulo].damping;
		m_particles[i].m_inverseMass = defArray[modulo].inverseMass;
		m_particles[i].m_isDead = defArray[modulo].isDead;

		m_particles[i].m_age = r3::Random::randomFloat(defArray[modulo].ageMin, defArray[modulo].ageMax);
		m_particles[i].m_count = defArray[modulo].count;
	}

	for(size_t i = 0, iLen = length; i < iLen; i++) {
		//Randomized velocity
		//take every defArray, duplicate them and multiple their copies with -1.0f
		m_particles[i].m_velocity = r3::Random::randomVec3(defArray[i].velocityMin, defArray[i].velocityMax);
		m_particles[i+length].m_velocity = (-1.0f) * r3::Random::randomVec3(defArray[i].velocityMin, defArray[i].velocityMax);
		//m_particles[i + length].m_velocity *= -1;
	}
}

FireworkParticle* FireworkParticle::Payload::getParticles() {
	return m_particles;
}

int FireworkParticle::Payload::getLength() {
	return m_length;
}
