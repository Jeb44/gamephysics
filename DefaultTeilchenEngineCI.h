#pragma once
#include "TeilchenEngineCI.h"
class DefaultTeilchenEngineCI :
	public TeilchenEngineCI {

public:
	DefaultTeilchenEngineCI();
	~DefaultTeilchenEngineCI();

	void integrate(const float timeDelta) override;
	void onBegin() override;
	void onEnd() override;
	void step() override;
};

