#pragma once

#include <vector>
#include <algorithm>
#include "TeilchenWelt.h"
#include "TeilchenNode.h"
#include "DefaultTeilchenEngineCI.h"

class TeilchenNodeWelt {
public:
	explicit TeilchenNodeWelt();
	~TeilchenNodeWelt();

	void update();

	void addParticleNode(TeilchenNode* node);
	bool removeParticleNode(TeilchenNode* node);

	TeilchenWelt* getWorld() const;

private:
	std::vector<TeilchenNode*> m_particleNodes;
	TeilchenWelt* m_particleWorld;

};

