#include "pch.h"
#include "TestDomain.h"
#include "TestLayer.h"
#include "TestEntity.h"
#include "T_Nexus.h"

TestDomain::TestDomain()
{
}

TestDomain::~TestDomain()
{
}

void TestDomain::setup()
{
	Domain::setup();
	TestLayer* layer = new TestLayer;
	layer->setFunction(&ITestLayerFunction::executeTest);
	addLayer(layer, 10);
}

void TestDomain::init()
{
	MessageBox(nexus->getHWnd(), std::to_wstring(_layers[0]->getPriority()).c_str(), L"ASD", MB_OK);
	TestEntity* entity = new TestEntity;
	_entities.push_back(entity);
}
