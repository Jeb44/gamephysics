#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"

#include "DefaultTeilchenEngineCI.h"
#include "TeilchenWelt.h"
#include "TeilchenNode.h"
#include "TeilchenDef.h"
#include "Teilchen.h"
#include "Cave.h"
#include "CannonBall.h"

class Uebung3 :
	public SimulationScene {
public:
	Uebung3(const std::string& name, SimulationWindow* window);
	~Uebung3();

	void tick(const float timeDelta);

private:
	Cave* m_cave;
	ec::Node* m_nMain;

	CannonBall* m_cannonball;

	bool m_shoot;
};

