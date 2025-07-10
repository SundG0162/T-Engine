#pragma once
#include "FunctionalLayer.h"
#include "IUpdateLayer.h"
namespace TEngine
{
	class UpdateLayer : public FunctionalLayer<IUpdateLayer>
	{
	public:
		UpdateLayer();
		~UpdateLayer();

	public:
		void initialize(Domain* domain) override;
	};
}