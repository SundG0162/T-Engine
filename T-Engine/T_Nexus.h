#pragma once
#include "Nexus.h"
class T_Nexus : public Nexus
{
public:
	T_Nexus();
	~T_Nexus();
protected:
    virtual void startUp() override;
    virtual void mainUpdate() override;
    virtual void mainRender() override;
    virtual void cleanUp() override;
public:
    virtual void init();
    virtual void update();
    virtual void render(HDC hdc);
    virtual void release();
public:
    const HDC& getMainDC() const { return _hMainDC; }
private:
    HDC _hMainDC;
    HDC _hBackDC;
    HBITMAP _hBitmap;
};

