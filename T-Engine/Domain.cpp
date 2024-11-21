#include "pch.h"
#include "Domain.h"
#include "Layer.h"
#include "RenderSetupLayer.h"
#include "RenderLayer.h"
#include "EntityRenderLayer.h"
#include "UpdateLayer.h"
#include "Entity.h"
#include "RenderCore.h"

Domain::Domain()
{
	setup();
}

Domain::~Domain()
{
}

void Domain::setup()
{
	_renderCore = new RenderCore;
	{
		UpdateLayer* layer = new UpdateLayer;
		layer->init(this);
		addLayer(layer, UPDATE_PRIORITY);
	}
	{
		RenderSetupLayer* layer = new RenderSetupLayer;
		layer->init(this);
		addLayer(layer, RENDERSETUP_PRIORITY);
	}
	{
		EntityRenderLayer* layer = new EntityRenderLayer;
		layer->init(this);
		addLayer(layer, ENTITYRENDER_PRIORITY);
	}
	{
		RenderLayer* layer = new RenderLayer;
		layer->init(this);
		addLayer(layer, RENDER_PRIORITY);
	}
}

void Domain::update()
{
	for (Layer* layer : _layers) 
	{
		if (layer->isActive())
			layer->update();
	}
}

void Domain::release()
{
	for (Entity* entity : _entities)
	{
		SAFE_DELETE(entity);
	}
	_entities.clear();
	for (Layer* layer : _layers)
	{
		SAFE_DELETE(layer);
	}
	_layers.clear();
	SAFE_DELETE(_renderCore);
}

void Domain::addLayer(Layer* layer, int priority)
{
	_layers.push_back(layer);
	layer->setPriority(priority);
	sort(_layers.begin(), _layers.end());
}

void Domain::removeLayer(Layer* layer)
{
}

void Domain::cleanUp()
{
	
}
