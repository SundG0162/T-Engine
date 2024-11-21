#include "pch.h"
#include "RenderCore.h"
#include "T_Nexus.h"

RenderCore::RenderCore()
	: _hMainDC(nullptr)
	, _hBackDC(nullptr)
	, _hBitmap(nullptr)
{
	_hMainDC = GetDC(nexus->getHWnd());
	_hBackDC = CreateCompatibleDC(_hMainDC);
	_hBitmap = CreateCompatibleBitmap(_hMainDC, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(_hBackDC, _hBitmap);
}

RenderCore::~RenderCore()
{
	ReleaseDC(nexus->getHWnd(), _hMainDC);
	DeleteDC(_hBackDC);
	DeleteObject(_hBitmap);
}

void RenderCore::renderSetup()
{
	PatBlt(_hBackDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);
}

void RenderCore::render()
{
	BitBlt(_hMainDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, _hBackDC, 0, 0, SRCCOPY);
}