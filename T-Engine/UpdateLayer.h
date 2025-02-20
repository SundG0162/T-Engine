#pragma once
#include "Layer.h"
class UpdateLayer : public Layer
{
public:
	UpdateLayer();
	~UpdateLayer();
public:
	void initialize(Domain* domain) override;
	void perform() override;
};

