#include "pch.h"
#include "Domain.h"
#include "Layer.h"

Domain::Domain()
{
	for (int i = (int)LAYER_PRIORITY::START + 1; i < (int)LAYER_PRIORITY::END; i++)
	{
		_layers[i] = nullptr;
	}
}

Domain::~Domain()
{
}

void Domain::update()
{
	for (Layer* layer : _layers)
	{
		if (layer->IsActive())
			layer->update();
	}
}

void Domain::addLayer(Layer* layer, LAYER_PRIORITY priority)
{
	_layers[(int)priority] = layer;
}

void Domain::removeLayer(Layer* layer)
{
}

void Domain::cleanUp()
{
	for (Layer* layer : _layers)
	{
		SAFE_DELETE(layer);
	}
}
