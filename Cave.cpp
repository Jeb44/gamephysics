#include "Cave.h"

Cave::Cave(SimulationWindow* window) {
	init(window);
}


Cave::~Cave() {
	delete m_nodeMain;
	delete m_nodeGround;
	delete m_nodeSidewall1;
	delete m_nodeSidewall2;
	delete m_nodeBackwall;

	delete m_ground;
	delete m_sidewall1;
	delete m_sidewall2;
	delete m_backwall;
}

ec::Node* Cave::getCave() {
	return m_nodeMain;
}

void Cave::init(SimulationWindow* window) {
	//Get Resources/Drawables
	auto reg = window->getDrawableRegistry();
	m_ground = reg.getResource("bot_wall");
	m_sidewall1 = reg.getResource("side_wall");
	m_sidewall2 = reg.getResource("side_wall");
	m_backwall = reg.getResource("back_wall");

	//Create Nodes and assign Drawables
	m_nodeMain = new ec::Node();

	m_nodeGround = new ec::Node();
	m_nodeGround->addDrawable(m_ground);

	m_nodeSidewall1 = new ec::Node();
	m_nodeSidewall1->addDrawable(m_sidewall1);

	m_nodeSidewall2 = new ec::Node();
	m_nodeSidewall2->addDrawable(m_sidewall2);

	m_nodeBackwall = new ec::Node();;
	m_nodeBackwall->addDrawable(m_backwall);

	//Add Nodes to main Node
	m_nodeMain->addChild(m_nodeGround);
	m_nodeMain->addChild(m_nodeSidewall1);
	m_nodeMain->addChild(m_nodeSidewall2);
	m_nodeMain->addChild(m_nodeBackwall);

	//Transform Nodes
	m_nodeGround->setTranslationY(-0.5f);
	m_nodeGround->setScaleY(0.01f);

	m_nodeSidewall1->setTranslationX(0.5f);
	m_nodeSidewall1->setScaleX(0.01f);

	m_nodeSidewall2->setTranslationX(-0.5f);
	m_nodeSidewall2->setScaleX(0.01f);

	m_nodeBackwall->setTranslationZ(-0.5f);
	m_nodeBackwall->setScaleZ(0.01f);

	m_nodeMain->setTranslation(glm::vec3(0.0f, 00.0f, 0.0f));
}
