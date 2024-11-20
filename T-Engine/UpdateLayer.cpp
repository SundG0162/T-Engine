#include "pch.h"
#include "UpdateLayer.h"
#include "Domain.h"
#include "Entity.h"

UpdateLayer::UpdateLayer()
{
}

UpdateLayer::~UpdateLayer()
{
}

void UpdateLayer::update()
{
	const vector<Entity*>& entities = _domain->getEntities();
	for (Entity* entity : entities)
	{
		entity->update();
	}
}
