#pragma once

#include "glm/common.hpp"

//R3D_DECLSPEC ?
struct TeilchenDef {
	glm::vec3 position {0};
	glm::vec3 velocity {0};
	glm::vec3 acceleration {0};
	glm::vec3 forceAccumulator{0};
	float damping {static_cast<float>(0.999)};

	float inverseMass {0};
	void setMass(float mass) {
		inverseMass = 1 / mass;
	}
	void setInfiniteMass() {
		inverseMass = 0;
	}

	bool isDead {false};
};
