#pragma once
#include "ICompInterface.h"

#include "TeilchenWelt.h"

class TeilchenEngineCI :
	public ICompInterface {
public:
	TeilchenEngineCI();
	~TeilchenEngineCI();

	void setParticleWorld(TeilchenWelt* particleWorld);
	TeilchenWelt* getParticleWorld();

protected:
	TeilchenWelt* m_particleWorld;
};

