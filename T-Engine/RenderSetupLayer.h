#pragma once
#include "Layer.h"
class RenderCore;
class RenderSetupLayer : public Layer
{
public:
	RenderSetupLayer();
	~RenderSetupLayer();
public:
	void init(Domain* domain) override;
	void update() override;
private:
	RenderCore* _renderCore;
};

