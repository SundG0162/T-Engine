#pragma once
#include "Layer.h"
class UpdateLayer : public Layer
{
public:
	UpdateLayer();
	~UpdateLayer();
	void update() override;
};

