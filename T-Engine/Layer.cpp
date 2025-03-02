#include "pch.h"
#include "Layer.h"
namespace TEngine
{
	Layer::Layer()
		: _isActive(true),
		_layerType(LayerType::Repeat),
		_domain(nullptr)
	{

	}

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