#pragma once
#include "Component.h"
namespace TEngine
{
	class Renderer : public Component
	{
	public:
		Renderer();
		~Renderer();
	public:
		virtual void render(HDC hdc) = 0;
	};
}

