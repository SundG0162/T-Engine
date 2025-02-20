#pragma once
#include "Resource.h"
namespace TEngine
{
	class Texture : public Resource
	{
	public:
		Texture();
		~Texture();
	public:
		void loadBMP(const wstring& path);
	public:
		const HDC& getTextureDC() { return _hDC; }
		const int& getWidth() { return _bitInfo.bmWidth; }
		const int& getHeight() { return _bitInfo.bmHeight; }
		void setTransparentColor(COLORREF color) { _transparentColor = color; }
		const COLORREF& getTransparentColor() { return _transparentColor; }
	private:
		HDC _hDC;
		HBITMAP _hBitmap;
		BITMAP _bitInfo;
		COLORREF _transparentColor;
	};
}

