#pragma once

namespace TEngine
{
	class Nexus
	{
	public:
		Nexus();
		virtual ~Nexus();
	public:
		int ignite(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow);
		static LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	private:
		void registerWndClass();
		void createWindow();
		void showWindow(int nCmdShow);
		int messageLoop();
	protected:
		virtual void startUp() = 0;
		virtual void mainUpdate() = 0;
		virtual void cleanUp() = 0;

	public:
		const wstring& setWindowName(const wstring& name) { _windowName = name; }
		const HINSTANCE& getHInstance() { return _hInstance; }
		const HWND& getHWnd() { return _hWnd; }
	protected:
		HINSTANCE _hInstance;
		HWND      _hWnd;
		wstring _windowName;
		UINT      _width;
		UINT      _height;
	};
}