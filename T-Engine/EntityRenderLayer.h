#pragma once
#include "Layer.h"
namespace TEngine
{
	class RenderCore;
	class RenderCore;
	class EntityRenderLayer : public Layer
	{
	public:
		EntityRenderLayer();
		~EntityRenderLayer();
	public:
		void initialize(Domain* domain) override;
		void perform() override;
	private:
		RenderCore* _renderCore;

	};
}

