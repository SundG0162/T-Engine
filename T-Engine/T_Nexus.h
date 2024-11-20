#pragma once
#include "Nexus.h"
class Domain;
class T_Nexus : public Nexus
{
public:
	T_Nexus();
	~T_Nexus();
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
	Domain* _domain;
	HDC _hMainDC;
	HDC _hBackDC;
	HBITMAP _hBitmap;
};

