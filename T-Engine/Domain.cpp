#include "pch.h"
#include "Domain.h"
#include "Layer.h"
#include "RenderSetupLayer.h"
#include "RenderLayer.h"
#include "EntityRenderLayer.h"
#include "UpdateLayer.h"
#include "Entity.h"
#include "RenderCore.h"
#include "T_Nexus.h"
namespace TEngine
{
	Domain::Domain()
	{
	}

	Domain::~Domain()
	{
	}

	void Domain::setup()
	{
		
	}

	void Domain::update()
	{
		for (Layer* layer : _layers)
		{
			if (layer->isActive())
			{
				layer->perform();
			}
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
}