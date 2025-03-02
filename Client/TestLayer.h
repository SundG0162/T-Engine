#pragma once
#include "FunctionalLayer.h"
#include "ITestLayerFunction.h"
class TestLayer : public FunctionalLayer<ITestLayerFunction>
{
public:
	TestLayer();
	~TestLayer();
};

