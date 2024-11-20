#pragma once
#include "Entity.h"
class TestEntity : public Entity
{
public:
	TestEntity();
	~TestEntity();
public:
	void update() override;
};

