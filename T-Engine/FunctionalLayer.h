#pragma once
#include "pch.h"
#include "Layer.h"
#include "Entity.h"
#include <concepts>
#include <functional>
namespace TEngine
{
	template <typename T>
	concept LayerFunction = std::is_class_v<T>;

	template<LayerFunction T>
	class FunctionalLayer : public Layer
	{
		typedef Function void (T::* func)();
	public: 
		FunctionalLayer(LayerType layerType);
		virtual ~FunctionalLayer();
	public:
		void perform();
		void setFunction(Function func) { _function = func; }
	private:
		std::vector<Entity*> _targetEntityVector;
		Function _function;
	};

	template<LayerFunction T>
	inline FunctionalLayer<T>::FunctionalLayer(LayerType layerType) : Layer(layerType)
	{
	}

	template<LayerFunction T>
	inline FunctionalLayer<T>::~FunctionalLayer()
	{
	}
	template<LayerFunction T>
	inline void FunctionalLayer<T>::perform()
	{
		for (Entity* entity : _targetEntityVector)
		{
			auto bindedFunc = std::bind(_function, entity);
			bindedFunc();
		}
	}
}
