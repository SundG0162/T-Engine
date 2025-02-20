#pragma once
#include "Layer.h"
class RenderCore;
class RenderLayer : public Layer
{
public:
	RenderLayer();
	~RenderLayer();
public:
	void initialize(Domain* domain) override;
	void perform() override;
private:
	RenderCore* _renderCore;
};

