#pragma once

#include "glm/glm.hpp"
#include "TeilchenDef.h"

//real?

class Teilchen {
public:
	Teilchen(const TeilchenDef& definition);
	~Teilchen();

	void init(const TeilchenDef& definition);

	void setPosition(const glm::vec3& position);
	glm::vec3 getPosition() const;

	void setVelocity(const glm::vec3& velocity);
	glm::vec3 getVelocity() const;

	void setAcceleration(const glm::vec3& acceleration);
	glm::vec3 getAcceleration() const;

	void setMass(const float mass);
	void setInverseMass(const float mass);
	float getMass() const;

	void clearAccumulator();
	void addForce(const glm::vec3& force);
	virtual void integrate(const float duration);

	void setDead(const bool died);
	bool isDead() const;

protected:
	glm::vec3 m_position;
	glm::vec3 m_velocity;
	glm::vec3 m_acceleration;
	
	glm::vec3 m_forceAccumulator;
	float m_damping;

	float m_inverseMass;

	bool m_isDead;
};

