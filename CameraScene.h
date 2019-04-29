#pragma once
#include "SimulationScene.h"

#include "EC3D/Core/Node.h"
#include "Cave.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleWorld.h"
#include "PhysicInterfaces/ParticleNode.h"
#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleAnchoredSpring.h"
#include "R3D/ParticleEngine/ParticleSpring.h"

class CameraScene : public SimulationScene {
public:
	CameraScene(const std::string& name, SimulationWindow* window);
	~CameraScene();

	void tick(const float timeDelta);

private:
	Cave* m_cave;
	ec::Node* m_main;

	ec::Node* m_playerNode;
	ec::Drawable* m_drawable;

	r3::Particle* playerParticle;
	r3::Particle* camParticle;

	glm::vec3* m_anchor;

	ParticleNodeWorld* m_particleNodeWorld;
	r3::ParticleWorld* m_particleWorld;
};

