#pragma once

#include "glm/common.hpp"
#include "EC3D/Core/Drawable.h"

struct FireworkDefintion {
	//Random Particle Defintion
	float ageMin;
	float ageMax;

	glm::vec3 velocityMin;
	glm::vec3 velocityMax;

	//General Particle Defintion
	glm::vec3 initalPosition{0};
	glm::vec3 acceleration{0};
	glm::vec3 forceAccumulator{0};
	float damping{static_cast<float>(0.999)};
	float inverseMass{1};
	float size{1};
	bool isDead{false};

	//Firework Defintion
	int count{0}; //how many times the payload can explode

	//Drawable (needed in Scene)
	ec::Drawable* drawable;
};
