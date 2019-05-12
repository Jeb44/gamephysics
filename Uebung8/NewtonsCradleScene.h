#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"
#include "PhysicInterfaces/ParticleNode.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"
#include "R3D/ParticleEngine/ParticleCable.h"
#include "R3D/ParticleEngine/ParticleSpring.h"
#include "R3D/ParticleEngine/ParticleBidirectionalSpring.h"

#include "EC3D/Core/Node.h"

#include <string>
#include "../Cave.h"
#include "NewtonsCradle.h"

class NewtonsCradleScene : public SimulationScene
{
public:
	explicit NewtonsCradleScene(const std::string& name, SimulationWindow* window);
	~NewtonsCradleScene();

	void tick(float timeDelta) override;
	void reset() override;

private:
	Cave* m_cave;
	ec::Drawable* m_ballDrawable;
	NewtonsCradle* m_newtonsCradle;
	
};
