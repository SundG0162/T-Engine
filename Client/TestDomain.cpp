#include "pch.h"
#include "TestDomain.h"
#include "TestEntity.h"

TestDomain::TestDomain()
{
}

TestDomain::~TestDomain()
{
}

void TestDomain::init()
{
	TestEntity* entity = new TestEntity;
	addEntity(entity);
}
