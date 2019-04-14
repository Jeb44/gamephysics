#pragma once
#include "ICompInterface.h"
#include "TeilchenWelt.h"

class TeilchenWelt; //circular inclusion?

class TeilchenEngineCI : public ICompInterface {
public:
	~TeilchenEngineCI();

	void setParticleWorld(TeilchenWelt* particleWorld);
	TeilchenWelt* getParticleWorld() const;

protected:
	explicit TeilchenEngineCI(TeilchenWelt* particleWorld = nullptr);
	TeilchenWelt* m_particleWorld;
};

