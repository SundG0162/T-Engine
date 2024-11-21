#include "pch.h"
#include "RenderLayer.h"
#include "Domain.h"
#include "RenderCore.h"

RenderLayer::RenderLayer()
{
}

RenderLayer::~RenderLayer()
{
}

void RenderLayer::init(Domain* domain)
{
	_domain = domain;
	_renderCore = _domain->getRenderCore();
}

void RenderLayer::update()
{
	_renderCore->render();
}
