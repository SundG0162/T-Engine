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

void RenderLayer::initialize(Domain* domain)
{
	_domain = domain;
	_renderCore = _domain->getRenderCore();
}

void RenderLayer::perform()
{
	_renderCore->render();
}
