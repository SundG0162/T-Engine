#pragma once
#include "Layer.h"
namespace TEngine
{
	class RenderCore;
	class RenderSetupLayer : public Layer
	{
	public:
		RenderSetupLayer();
		~RenderSetupLayer();
	public:
		void initialize(Domain* domain) override;
		void perform() override;
	private:
		RenderCore* _renderCore;
	};
}