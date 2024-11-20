#include "pch.h"
#include "Nexus.h"

Nexus::Nexus()
	: _hInstance(NULL)
	, _hWnd(NULL)
	, _width(SCREEN_WIDTH)
	, _height(SCREEN_HEIGHT)
{
}

Nexus::~Nexus()
{
}

int Nexus::ignite(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	_hInstance = _hInstance;
	registerWndClass();
	createWindow();
	showWindow(nCmdShow);
	return messageLoop();
}

LRESULT Nexus::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void Nexus::registerWndClass()
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = Nexus::wndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = _hInstance;
	wcex.hIcon = LoadIcon(_hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"T-Engine";
	wcex.hIconSm = LoadIcon(_hInstance, IDI_APPLICATION);

	RegisterClassExW(&wcex);
}

void Nexus::createWindow()
{
	_hWnd = CreateWindowW(L"T-Engine", _windowName.c_str(), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, SCREEN_WIDTH, SCREEN_HEIGHT, nullptr, nullptr, _hInstance, nullptr);
}

void Nexus::showWindow(int nCmdShow)
{
	ShowWindow(_hWnd, nCmdShow);
}

int Nexus::messageLoop()
{
	MSG msg;
	memset(&msg, 0, sizeof(MSG));
	startUp();
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			mainUpdate();
		}
	}
	cleanUp();
	return (int)msg.wParam;
}
