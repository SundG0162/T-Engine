#pragma once
#include "Component.h"
class Renderer : public Component
{
public:
	Renderer();
	~Renderer();
public:
	virtual void render(HDC hdc) abstract;
};

