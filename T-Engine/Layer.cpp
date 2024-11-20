#include "pch.h"
#include "Layer.h"

Layer::Layer(int priority)
{
	_priority = priority;
	_isActive = true;
}

Layer::~Layer()
{
}
