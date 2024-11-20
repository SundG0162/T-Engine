#include "pch.h"
#include "Domain.h"
#include "Layer.h"
#include "RenderLayer.h"
#include "UpdateLayer.h"

Domain::Domain()
{
	memset(_layers, 0, sizeof(_layers));
	setup();
}

Domain::~Domain()
{
}

void Domain::setup()
{
	{
		RenderLayer* layer = new RenderLayer;
		layer->setDomain(this);
		addLayer(layer, LAYER_PRIORITY::RENDER);
	}
	{
		UpdateLayer* layer = new UpdateLayer;
		layer->setDomain(this);
		addLayer(layer, LAYER_PRIORITY::UPDATE);
	}
}

void Domain::update()
{
	for (int i = (int)LAYER_PRIORITY::START + 1; i < (int)LAYER_PRIORITY::END; i++)
	{
		if (_layers[i] != nullptr && _layers[i]->isActive())
				_layers[i]->update();
	}
}

void Domain::release()
{
	for (Entity* entity : _entities)
	{
		SAFE_DELETE(entity);
	}
	_entities.clear();
	for (int i = (int)LAYER_PRIORITY::START + 1; i < (int)LAYER_PRIORITY::END; i++)
	{
		SAFE_DELETE(_layers[i]);
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
