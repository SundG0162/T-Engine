#pragma once
#include "Entity.h"
#include "ITestLayerFunction.h"
#include "IProtoLayerFunction.h"
class TestEntity : public Entity, public ITestLayerFunction, public IProtoLayerFunction
{
public:
	TestEntity();
	~TestEntity();
public:
	void update() override;
	void executeTest() override;
	void executeProto() override;
};

