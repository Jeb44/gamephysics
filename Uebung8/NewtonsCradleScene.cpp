#include "NewtonsCradleScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include <iostream>


NewtonsCradleScene::NewtonsCradleScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window)
{
    m_camera->setTranslation(0.0, 0.0, 25.0);

	// Get a previously created drawable
	auto reg = window->getDrawableRegistry();
	m_ballDrawable = reg.getResource("sphere");

	auto particleNodeWorld = m_physicsEngine.getParticleNodeWorld();
	auto particleWorld = particleNodeWorld->getWorld();

	// Init scene graph node and add it to the scene graph
	m_cave = new Cave(window);
	//m_root->addChild(m_cave->getCave());

	m_newtonsCradle = new NewtonsCradle(5, m_ballDrawable,
										glm::vec3(-20, 0, 0), particleNodeWorld,
										m_root.get());
	
}


NewtonsCradleScene::~NewtonsCradleScene()
= default;

void NewtonsCradleScene::tick(const float timeDelta)
{
	SimulationScene::tick(timeDelta);
}

void NewtonsCradleScene::reset()
{
	SimulationScene::reset();
}
