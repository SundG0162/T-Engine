#pragma once
#include "Layer.h"
class RenderLayer : public Layer
{
public:
	RenderLayer();
	~RenderLayer();
public:
	void update() override;
private:
	HDC _hMainDC;
	HDC _hBackDC;
	HBITMAP _hBitmap;
};

