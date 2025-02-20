#pragma once
#include "Layer.h"
class RepeatLayer : public Layer
{
	void init(Domain* domain) override;
	void perform() override;
};

