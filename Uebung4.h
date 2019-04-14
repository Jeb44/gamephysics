#pragma once
#include "SimulationScene.h"

#include "EC3D/Core/Node.h"
#include "Cave.h"
#include "DefaultTeilchenEngineCI.h"
#include "TeilchenNodeWelt.h"
#include "TeilchenWelt.h"
#include "Ball.h"
#include "Cannon.h"

class Uebung4 :
	public SimulationScene {
public:
	Uebung4(const std::string& name, SimulationWindow* window);
	~Uebung4();

	void tick(const float timeDelta);


private:

	void addBall();


	Cave* m_cave;
	Cannon* m_cannon;
	ec::Node* m_main;

	ec::Drawable* m_drawableBall;

	TeilchenNodeWelt* m_particleNodeWorld;
	TeilchenWelt* m_particleWorld;
	//DefaultTeilchenEngineCI* m_particleEngine;
};

