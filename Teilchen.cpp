#include "Teilchen.h"

Teilchen::Teilchen(const TeilchenDef& definition) {
	init(definition);
}

Teilchen::~Teilchen() = default;

void Teilchen::init(const TeilchenDef& definition) {
	m_position = definition.position;
	m_velocity = definition.velocity;
	m_acceleration = definition.acceleration;
	m_forceAccumulator = definition.forceAccumulator;
	m_damping = definition.damping;
	m_inverseMass = definition.inverseMass;
	m_isDead = definition.isDead;
}

void Teilchen::setPosition(const glm::vec3& position) {
	m_position = position;
}

glm::vec3 Teilchen::getPosition() const {
	return m_position;
}

void Teilchen::setVelocity(const glm::vec3 & velocity) {
	m_velocity = velocity;
}

glm::vec3 Teilchen::getVelocity() const {
	return m_velocity;
}

void Teilchen::setAcceleration(const glm::vec3& acceleration) {
	m_acceleration = acceleration;
}

glm::vec3 Teilchen::getAcceleration() const {
	return m_acceleration;
}

void Teilchen::setMass(float mass) {
	m_inverseMass = 1.0f / mass;
}

void Teilchen::setInverseMass(float inverseMass) {
	m_inverseMass = inverseMass;
}

float Teilchen::getMass() const {
	if(m_inverseMass == 0) {
		return FLT_MAX;
	}
	return (static_cast<float>(1.0f)) / m_inverseMass;
}

void Teilchen::clearAccumulator() {}

void Teilchen::addForce(const glm::vec3& force) {
	m_forceAccumulator += force;
}

void Teilchen::integrate(float duration) {
	if(m_isDead || m_inverseMass <= 0) return;
	assert(duration > 0.0f);

	m_position += m_velocity * duration;

	auto resultingAcceleration = m_acceleration;
	resultingAcceleration += m_forceAccumulator * m_inverseMass;

	m_velocity += resultingAcceleration * duration;

	m_velocity *= pow(m_damping, duration);

	clearAccumulator();
}
