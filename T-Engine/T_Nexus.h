#pragma once
#include "Nexus.h"
namespace TEngine
{
	class Domain;
	class T_Nexus : public Nexus, public std::enable_shared_from_this<T_Nexus>
	{
	public:
		T_Nexus();
		virtual ~T_Nexus();
	protected:
		virtual void startUp() override;
		virtual void mainUpdate() override;
		virtual void cleanUp() override;
	public:
		virtual void init();
		virtual void update();
		virtual void release();
	public:
		const HDC& getMainDC() const { return _hMainDC; }
	protected:
		HDC _hMainDC;
		HDC _hBackDC;
		HBITMAP _hBitmap;
	};
}

