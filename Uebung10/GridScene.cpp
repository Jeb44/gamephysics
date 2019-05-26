#include "GridScene.h"

#include "PhysicInterfaces/ParticleNodeWorld.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "EC3D/Core/ResourceRegistry.h"
#include "EC3D/Core/Drawable.h"

#include "R3D/Utility/Random.h"

#include <iostream>


GridScene::GridScene(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window),
	dimensions(2), count(10){
	assert(dimensions > 0 && dimensions <= 3);
	assert(count > 0);

	m_camera->setTranslation(0.0, 0.0, 25.0);

	// Get a previously created drawable
	auto reg = window->getDrawableRegistry();
	cuboidDrawable = reg.getResource("cube");

	auto rbnWorld = m_physicsEngine.getRigidBodyNodeWorld();
	auto rbWorld = rbnWorld->getWorld();

	// Init scene graph node and add it to the scene graph
	float width = 1.0f;
	float distBtw = 1.0f;
	glm::vec3 offset((width * count + distBtw * (count - 1)) / 2,
					(dimensions >= 1) ? (width * count + distBtw * (count - 1)) / 2 : 0.0f,
					(dimensions >= 2) ? (width * count + distBtw * (count - 1)) / 2 : 0.0f);

	cuboidNode = new ec::Node*[dimensions, count];
	for(size_t i = 0, iLen = dimensions; i < iLen; i++) {
		float x = (width + distBtw);
		float y = (dimensions >= 1) ? (width + distBtw) : 0.0f;
		for(size_t j = 0, jLen = count; j < jLen; j++) {
			cuboidNode[i, j] = new ec::Node();
			cuboidNode[i, j]->addDrawable(cuboidDrawable);


			cuboidNode[i, j]->setTranslation(
					glm::vec3((width + distBtw) * j, 
					(width + distBtw) * j,
					0.0f
				) 
				- offset
			);

			m_root->addChild(cuboidNode[i, j]);
		}
	}
	