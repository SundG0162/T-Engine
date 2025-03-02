#pragma once
#include "ILayerFunction.h"
class IProtoLayerFunction
{
public:
	IProtoLayerFunction() {};
	virtual ~IProtoLayerFunction() {};
public:
	virtual void executeProto() abstract;
};