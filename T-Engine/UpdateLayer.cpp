#include "pch.h"
#include "UpdateLayer.h"
#include "Domain.h"
#include "Entity.h"
namespace TEngine
{
	UpdateLayer::UpdateLayer() : Layer(LayerType::Repeat)
	{
	}

	UpdateLayer::~UpdateLayer()
	{
	}

	void UpdateLayer::initialize(Domain* domain)
	{
		Layer::initialize(domain);
	}

	void UpdateLayer::perform()
	{
		const vector<Entity*>& entities = _domain->getEntities();
		for (Entity* entity : entities)
		{
			entity->update();
		}
	}
}