#include "Uebung3.h"

#include "R3D/ParticleEngine/ParticleDef.h"

Uebung3::Uebung3(const std::string& name, SimulationWindow* window)
	: SimulationScene(name, window)
{
	//Create Cave
	m_nMain = new ec::Node();

	m_cave = new Cave(window);
	m_nMain->addChild(m_cave->getCave());

	//Create Cannonball
	//m_cannonball = new CannonBall(window);
	//m_nMain->addChild(m_cannonball->getNode());
	m_cannon = new Cannon(window);
	m_nMain->addChild(m_cannon->getNode());

	//m_shoot = false;


	m_nMain->setTranslationZ(5.0f);
	m_root->addChild(m_nMain);
}

Uebung3::~Uebung3() {
	delete m_cave;
	//delete m_cannonball;
	delete m_cannon;
	delete m_nMain;
}

void Uebung3::tick(const float timeDelta) {
	__super::tick(timeDelta);

	/*	if(m_mouse->isKeyDown(ec::Mouse::MOUSE_1)) {
		m_shoot = true;
	}
	if(m_shoot == false) return;*/
	
	if(m_mouse->isKeyDown(ec::Mouse::MOUSE_1)) {
		//shoot cannonballs
		m_cannon->addCannonball();

	}
	m_cannon->update(timeDelta);

	//m_cannonball->getParticle()->integrate(timeDelta);
	//m_cannonball->getParticleNode()->update();


}
