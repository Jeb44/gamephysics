#pragma once

#include "SimulationScene.h"

class Cave {
public:
	Cave(SimulationWindow* window);
	~Cave();

	ec::Node* getCave();

private:
	void init(SimulationWindow* window);

	ec::Node* m_nodeMain;
	ec::Node* m_nodeGround;
	ec::Node* m_nodeSidewall1;
	ec::Node* m_nodeSidewall2;
	ec::Node* m_nodeBackwall;

	ec::Drawable* m_ground;
	ec::Drawable* m_sidewall1;
	ec::Drawable* m_sidewall2;
	ec::Drawable* m_backwall;
};

