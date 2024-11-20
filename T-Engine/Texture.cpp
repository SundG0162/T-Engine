#include "pch.h"
#include "Texture.h"
#include "T_Nexus.h"

Texture::Texture()
	: _hDC(nullptr)
	, _hBitmap(nullptr)
	, _bitInfo{}
	, _transparentColor(RGB(255,0,255))
{
}

Texture::~Texture()
{
	DeleteDC(_hDC);
	DeleteObject(_hBitmap);
}

void Texture::loadBMP(const wstring& path)
{
	_hBitmap = (HBITMAP)LoadImage(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	if (_hBitmap == nullptr)
		MessageBox(nexus->getHWnd(), path.c_str(), L"Fail to Load Image", MB_OK);
	_hDC = CreateCompatibleDC(nexus->getMainDC());
	SelectObject(_hDC, _hBitmap);
	GetObject(_hBitmap, sizeof(BITMAP), &_bitInfo);
}