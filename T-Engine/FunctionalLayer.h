#pragma once
#include "pch.h"
#include "Layer.h"
#include "Domain.h"
#include "Entity.h"
#include <concepts>
#include <functional>
namespace TEngine
{
	template <typename ComponentType>
	concept ValidComponent = std::is_class_v<ComponentType>;

	template<ValidComponent ComponentType>
	class FunctionalLayer : public Layer
	{
		typedef std::function<void(ComponentType*)> ComponentFunction;
	public: 
		FunctionalLayer(LayerType layerType);
		virtual ~FunctionalLayer();
	public:
		virtual void initialize(Domain* domain) override;
		void perform();
		void setFunction(ComponentFunction func) { _function = func; }
	public:
		void handleOnEntityAddedEvent(Entity* entity);
	private:
		std::vector<ComponentType*> _targetEntityVector;
		ComponentFunction _function;
		size_t _entityAddedEventHandleID;
	};

	template<ValidComponent ComponentType>
	inline FunctionalLayer<ComponentType>::FunctionalLayer(LayerType layerType) : Layer(layerType)
	{
	}

	template<ValidComponent ComponentType>
	inline FunctionalLayer<ComponentType>::~FunctionalLayer()
	{
	}

	template<ValidComponent ComponentType>
	inline void FunctionalLayer<ComponentType>::initialize(Domain* domain)
	{
		Layer::initialize(domain);
		_entityAddedEventHandleID = domain->OnEntityAddedEvent.addCallback<FunctionalLayer<ComponentType>>(this, &FunctionalLayer<ComponentType>::handleOnEntityAddedEvent);
	}

	template<ValidComponent ComponentType>
	inline void FunctionalLayer<ComponentType>::perform()
	{
		for (ComponentType* comp : _targetEntityVector)
		{
			auto bindedFunc = std::bind(_function, comp);
			bindedFunc();
		}
	}

	template<ValidComponent ComponentType>
	inline void FunctionalLayer<ComponentType>::handleOnEntityAddedEvent(Entity* entity)
	{
		ComponentType* layerFunc = dynamic_cast<ComponentType*>(entity);
		if (layerFunc)
		{
			_targetEntityVector.push_back(layerFunc);
		}
	}
}
