#pragma once
#include "Layer.h"
class UpdateLayer : public Layer
{
public:
	UpdateLayer();
	~UpdateLayer();
public:
	void init(Domain* domain) override;
	void update() override;
};

