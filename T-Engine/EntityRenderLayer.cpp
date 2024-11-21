#include "pch.h"
#include "EntityRenderLayer.h"
#include "Domain.h"
#include "Entity.h"
#include "Renderer.h"
#include "T_Nexus.h"
#include "RenderCore.h"

EntityRenderLayer::EntityRenderLayer()
{
}

EntityRenderLayer::~EntityRenderLayer()
{
}

void EntityRenderLayer::init(Domain* domain)
{
	_domain = domain;
	_renderCore = _domain->getRenderCore();
}

void EntityRenderLayer::update()
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

