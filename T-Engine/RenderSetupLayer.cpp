#include "pch.h"
#include "RenderSetupLayer.h"
#include "Domain.h"
#include "RenderCore.h"
namespace TEngine
{
	RenderSetupLayer::RenderSetupLayer() : Layer(LayerType::Repeat)
	{
	}

	RenderSetupLayer::~RenderSetupLayer()
	{
	}

	void RenderSetupLayer::initialize(Domain* domain)
	{
		_domain = domain;
		_renderCore = _domain->getRenderCore();
	}

	void RenderSetupLayer::perform()
	{
		_renderCore->renderSetup();
	}
}