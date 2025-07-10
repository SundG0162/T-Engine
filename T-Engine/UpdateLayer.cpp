#include "pch.h"
#include "UpdateLayer.h"
#include "Domain.h"
#include "Entity.h"
namespace TEngine
{
	UpdateLayer::UpdateLayer() : FunctionalLayer<IUpdateLayer>(LayerType::Repeat)
	{
	}
	UpdateLayer::~UpdateLayer()
	{
	}

	void UpdateLayer::initialize(Domain* domain)
	{
		FunctionalLayer<IUpdateLayer>::initialize(domain);
		setFunction(&IUpdateLayer::update);
	}
}