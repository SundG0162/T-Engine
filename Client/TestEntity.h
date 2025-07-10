#pragma once

//#pragma comment(lib, "T-Engine.lib")

#include "Entity.h"
#include "IUpdateLayer.h"
class TestEntity : public Entity, public IUpdateLayer
{
public:
	TestEntity();
	~TestEntity();

public:
	void update() override;
};

