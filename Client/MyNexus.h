#pragma once
#include "T_Nexus.h"
class MyNexus : public T_Nexus
{
public:
	MyNexus();
	~MyNexus();
public:
    virtual void init() override;
    virtual void update() override;
    virtual void render(HDC hdc) override;
    virtual void release() override;
};

