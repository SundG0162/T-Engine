#pragma once
#include "Resource.h"
class Texture : public Resource
{
public:
	Texture();
	~Texture();
public:
	void loadBMP(const wstring& path);
public:
	const HDC& getTextureDC() { return _hDC; }
	void setTransparentColor(COLORREF color) { _transparentColor = color; }
	const COLORREF& getTransparentColor() { return _transparentColor; }
private:
	HDC _hDC;
	HBITMAP _hBitmap;
	BITMAP _bitInfo;
	COLORREF _transparentColor;
};

