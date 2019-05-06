#pragma once
#include "TeilchenEngineCI.h"
#include "TeilchenWelt.h"

class DefaultTeilchenEngineCI :	public TeilchenEngineCI {

public:
	explicit DefaultTeilchenEngineCI(TeilchenWelt* particleWorld = nullptr);
	~DefaultTeilchenEngineCI();

	void integrate(const float timeDelta) override;
	void onBegin() override;
	void onEnd() override;
	void step(const float timeDelta) override;
	void reset() override;
};

