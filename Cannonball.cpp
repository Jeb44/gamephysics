#include "CannonBall.h"

CannonBall::CannonBall(SimulationWindow* window) {
	initDrawableNode(window);
	initParticle();
	initParticleNode();
}

CannonBall::CannonBall(SimulationWindow* window, const glm::vec3& pos) {
	initDrawableNode(window);
	initParticle(pos);
	initParticleNode();
}

CannonBall::~CannonBall() = default;

ec::Node* CannonBall::getNode() {
	return m_node;
}

Teilchen* CannonBall::getParticle() {
	return m_particle;
}

TeilchenNode* CannonBall::getParticleNode() {
	return m_particleNode;
}

void CannonBall::update(const float timeDelta) {

	//m_cannonball->getParticle()->integrate(timeDelta);
	//m_cannonball->getParticleNode()->update();

	m_particle->integrate(timeDelta);
	m_particleNode->update();

	timeToDie -= timeDelta;
	if (timeToDie <= 0.0f) {
		m_particle->setDead(true);
	}

}

void CannonBall::initDrawableNode(SimulationWindow* window) {
	//Drawable
	auto& reg = window->getDrawableRegistry();
	m_drawable = reg.getResource("sphere");

	//Node
	m_node = new ec::Node();
	m_node->addDrawable(m_drawable);
	m_node->scale(0.15f);
}

void CannonBall::initParticle() {
	TeilchenDef def;
	def.velocity = velocity;
	def.acceleration = acceleration;
	def.position = position;
	def.setMass(1.0f);
	m_particle = new Teilchen(def);
}

void CannonBall::initParticle(const glm::vec3& pos) {
	TeilchenDef def; 
	def.velocity = velocity;
	def.acceleration = acceleration;
	def.position = pos;
	def.setMass(1.0f);
	m_particle = new Teilchen(def);	
}

void CannonBall::initParticleNode() {
	m_particleNode = new TeilchenNode(m_particle, m_node);
	m_node->setTranslation(m_particle->getPosition());
}
