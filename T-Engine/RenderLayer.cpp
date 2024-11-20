#include "pch.h"
#include "RenderLayer.h"
#include "Domain.h"
#include "Entity.h"
#include "Renderer.h"
#include "T_Nexus.h"

RenderLayer::RenderLayer()
	: _hMainDC(nullptr)
	, _hBackDC(nullptr)
	, _hBitmap(nullptr)
{
	_hMainDC = GetDC(nexus->getHWnd());
	_hBackDC = CreateCompatibleDC(_hMainDC);
	_hBitmap = CreateCompatibleBitmap(_hMainDC, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(_hBackDC, _hBitmap);
}

RenderLayer::~RenderLayer()
{
}

void RenderLayer::update()
{
	PatBlt(_hBackDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);

	const vector<Entity*>& entities = _domain->getEntities();
	for (Entity* entity : entities)
	{
		Renderer* renderer = entity->getComponent<Renderer>();
		if (renderer != nullptr)
		{
			renderer->render(_hBackDC);
		}
	}
	//·»´õ¸µ

	BitBlt(_hMainDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, _hBackDC, 0, 0, SRCCOPY);
}
