#pragma once
class ICompInterface {
public:
	virtual void integrate(const float timeDelta) = 0;
	virtual void onBegin() = 0;
	virtual void onEnd() = 0;
	virtual void step() = 0;
};

