#pragma once
#include "Component.h"
class Renderer : public Component
{
public:
	Renderer();
	~Renderer();
public:
	void update() override;
	virtual void render(HDC hdc);
};

