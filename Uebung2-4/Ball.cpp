#include "Ball.h"


Ball::Ball(ec::Drawable* drawable) {
	initDrawableNode(drawable);
	initParticle();
}

Ball::~Ball() = default;

void Ball::initDrawableNode(ec::Drawable* drawable) {
	//Drawable
	m_drawable = drawable;

	//Node
	m_node = new ec::Node();
	m_node->addDrawable(m_drawable);
	m_node->scale(0.15f);
}

void Ball::initParticle() {
	m_particle = new Teilchen();
	m_particle->setVelocity(m_initVelocity);
	m_particle->setAcceleration(m_initAcceleration);
	m_particle->setMass(1.0f);
}

ec::Node * Ball::getNode() {
	return m_node;
}

Teilchen * Ball::getParticle() {
	return m_particle;
}
