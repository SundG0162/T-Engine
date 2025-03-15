#pragma once
#include "Layer.h"
#include "ILayerFunction.h"
#include "Domain.h"
#include <concepts>
namespace TEngine
{
	template <typename T>
	concept LayerFunction = std::derived_from<T, ILayerFunction>;

	template<typename T>
		requires LayerFunction<T>
	class FunctionalLayer : public Layer
	{
	public:
		void initialize(Domain* domain) override;
		void perform() override;
	private:
		std::vector<T*> _targetEntityVector;
	};

	template<typename T>
		requires LayerFunction<T>
	inline void FunctionalLayer<T>::initialize(Domain* domain)
	{
		const std::vector<Entity*> entities = domain->getEntities();
		for (int i = 0; i < entities.size(); i++)
		{
			T* layerFunction = dynamic_cast<T*>(entities[i]);
			_targetEntityVector.push_back(layerFunction);
		}
	}

	template<typename T>
		requires LayerFunction<T>
	inline void FunctionalLayer<T>::perform()
	{
		for (int i = 0; i < _targetEntityVector.size(); i++)
		{
			_targetEntityVector[i].execute();
		}
	}
}

