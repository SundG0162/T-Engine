#include "pch.h"
#include "Layer.h"
namespace TEngine
{
	Layer::Layer(LayerType layerType)
		: _isActive(true),
		_layerType(layerType),
		_domain(nullptr)
	{
	}

	Layer::~Layer()
	{
	}
}