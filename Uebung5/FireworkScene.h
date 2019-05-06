#pragma once
#include "SimulationScene.h"

#include "EC3D/Core/Node.h"
#include "Cave.h"
#include "FireworkParticle.h"
#include "FireworkDefintion.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleWorld.h"
#include "PhysicInterfaces/ParticleNode.h"
#include "PhysicInterfaces/ParticleNodeWorld.h"

class FireworkScene : public SimulationScene {
public:
	FireworkScene(const std::string& name, SimulationWindow* window);
	~FireworkScene();

	void tick(const float timeDelta);


private:
	void addFirework();
	FireworkDefintion m_defMain;
	FireworkDefintion* m_defPayloads;

	float m_resetTime;
	float m_countingTime;

	ParticleNodeWorld* m_particleNodeWorld;
	r3::ParticleWorld* m_particleWorld;

	Cave* m_cave;
	ec::Node* m_main;
	ec::Drawable* m_drawable;

};

