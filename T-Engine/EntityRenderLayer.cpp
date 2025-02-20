#include "pch.h"
#include "EntityRenderLayer.h"
#include "Domain.h"
#include "Entity.h"
#include "Renderer.h"
#include "T_Nexus.h"
#include "RenderCore.h"
namespace TEngine
{
	EntityRenderLayer::EntityRenderLayer()
	{
	}

	EntityRenderLayer::~EntityRenderLayer()
	{
	}

	void EntityRenderLayer::initialize(Domain* domain)
	{
		_domain = domain;
		_renderCore = _domain->getRenderCore();
	}

	void EntityRenderLayer::perform()
	{
		const vector<Entity*>& entities = _domain->getEntities();
		for (Entity* entity : entities)
		{
			Renderer* renderer = entity->getComponent<Renderer>();
			if (renderer != nullptr)
			{
				renderer->render(_renderCore->getBackDC());
			}
		}
	}
}