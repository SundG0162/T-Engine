#pragma once
#include "Layer.h"
class RenderCore;
class RenderCore;
class EntityRenderLayer : public Layer
{
public:
	EntityRenderLayer();
	~EntityRenderLayer();
public:
	void init(Domain* domain) override;
	void perform() override;
private:
	RenderCore* _renderCore;

};

