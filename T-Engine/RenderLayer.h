#pragma once
#include "Layer.h"
class RenderCore;
class RenderLayer : public Layer
{
public:
	RenderLayer();
	~RenderLayer();
public:
	void init(Domain* domain) override;
	void update() override;
private:
	RenderCore* _renderCore;
};

