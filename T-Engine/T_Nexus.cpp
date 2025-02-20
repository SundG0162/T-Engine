#include "pch.h"
#include "T_Nexus.h"
#include "Domain.h"
namespace TEngine
{
	T_Nexus::T_Nexus()
		: _hMainDC(nullptr)
		, _hBackDC(nullptr)
		, _hBitmap(nullptr)
	{
	}

	T_Nexus::~T_Nexus()
	{
	}

	void T_Nexus::startUp()
	{
		nexus = shared_from_this();
		_hMainDC = GetDC(_hWnd);
		_hBackDC = CreateCompatibleDC(_hMainDC);
		_hBitmap = CreateCompatibleBitmap(_hMainDC, _width, _height);
		SelectObject(_hBackDC, _hBitmap);
		init();
	}

	void T_Nexus::mainUpdate()
	{
		update();
	}

	//void T_Nexus::mainRender()
	//{
	//	PatBlt(_hBackDC, 0, 0, _width, _height, WHITENESS);
	//	//여기서 렌더링해야함.
	//	BitBlt(_hMainDC, 0, 0, _width, _height, _hBackDC, 0, 0, SRCCOPY);
	//}

	void T_Nexus::cleanUp()
	{
		DeleteObject(_hBitmap);
		DeleteDC(_hBackDC);
		ReleaseDC(_hWnd, _hMainDC);
		release();
	}

	void T_Nexus::init()
	{
	}

	void T_Nexus::update()
	{
	}

	void T_Nexus::release()
	{
	}
}
