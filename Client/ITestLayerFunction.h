#pragma once
#include "ILayerFunction.h"
class ITestLayerFunction
{
public:
	ITestLayerFunction() {};
	virtual ~ITestLayerFunction() {};
public:
	virtual void executeTest() = 0;
};

