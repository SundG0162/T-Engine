#include "pch.h"
#include "RenderSetupLayer.h"
#include "Domain.h"
#include "RenderCore.h"

RenderSetupLayer::RenderSetupLayer()
{
}

RenderSetupLayer::~RenderSetupLayer()
{
}

void RenderSetupLayer::init(Domain* domain)
{
	_domain = domain;
	_renderCore = _domain->getRenderCore();
}

void RenderSetupLayer::update()
{
	_renderCore->renderSetup();
}