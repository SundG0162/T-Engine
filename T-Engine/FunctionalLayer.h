#pragma once
#include "Layer.h"
#include "ILayerFunction.h"
#include "Domain.h"
#include <concepts>
#include <functional>
namespace TEngine
{

	template <typename T>
	concept LayerFunction = std::is_class_v<T>;

	template<typename T>
		requires LayerFunction<T>
	class FunctionalLayer : public Layer
	{
	public:
		FunctionalLayer(LayerType layerType) {}
		virtual ~FunctionalLayer() {}
	public:
		void initialize(Domain* domain) override;
		void perform() override;
		void setFunction(void (T::* func)()) { _function = func; }
	protected:
		std::vector<T*> _targetEntityVector;
		void (T::* _function)();
	};

	template<typename T>
		requires LayerFunction<T>
	inline void FunctionalLayer<T>::initialize(Domain* domain)
	{
		const std::vector<Entity*> entities = domain->getEntities();
		for (int i = 0; i < entities.size(); i++)
		{
			T* layerFunction = (T*)entities[i];
			if(layerFunction != nullptr)
				_targetEntityVector.push_back(layerFunction);
		}
	}

	template<typename T>
		requires LayerFunction<T>
	inline void FunctionalLayer<T>::perform()
	{
		for (int i = 0; i < _targetEntityVector.size(); i++)
		{
			auto func = std::bind(_function, _targetEntityVector[i]);
			func();
		}
	}
}

