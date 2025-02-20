#pragma once
namespace TEngine
{
	class RenderCore
	{
	public:
		RenderCore();
		~RenderCore();
	public:
		void renderSetup();
		void render();
	public:
		const HDC& getMainDC() { return _hMainDC; }
		const HDC& getBackDC() { return _hBackDC; }
	private:
		HDC _hMainDC;
		HDC _hBackDC;
		HBITMAP _hBitmap;
	};
}