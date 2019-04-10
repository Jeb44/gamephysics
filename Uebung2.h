#pragma once
#include "SimulationScene.h"
#include "SimulationWindow.h"

#include "Teilchen.h"
#include "TeilchenDef.h"
#include "Cave.h"

class Uebung2 :	public SimulationScene {
public:
	explicit Uebung2(const std::string& name, SimulationWindow* window);
	~Uebung2();

	void tick(const float timeDelta);

private:
	Cave* cave;
	ec::Node* m_main;

	ec::Node* m_nodeSphere1;
	ec::Node* m_nodeSphere2;

	ec::Drawable* m_sphere1;
	ec::Drawable* m_sphere2;

	Teilchen* particle1;
	Teilchen* particle2;

	bool startProcessing;
	int count;
};

