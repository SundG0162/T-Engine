#pragma once
#include "Delegate.h"
namespace TEngine
{
	class Entity;
	class Layer;
	class RenderCore;
	class Domain
	{
	public:
		Domain();
		virtual ~Domain();
	public:
		virtual void setup(); //생성됏을때 
		virtual void init() = 0; //로드됐을때
		virtual void update();
		virtual void release();
	public:
		void addLayer(Layer* layer, int priority);
		void removeLayer(Layer* layer);
		inline void addEntity(Entity* entity)
		{
			_entities.push_back(entity);
			OnEntityAddedEvent.invoke(entity);
		}
		void removeEntity(Entity* entity);
		void cleanUp();
	public:
		RenderCore* getRenderCore() { return _renderCore; }
		const std::vector<Entity*>& getEntities() { return _entities; }
		template<typename T>
		T* getLayer()
		{
			T* layer = nullptr;
			for (Layer* layer : _layers)
			{
				layer = dynamic_cast<T*>(layer);
				if (layer)
					break;
			}
			return layer;
		}
	public:
		Delegate<Entity*> OnEntityAddedEvent;
	protected:
		RenderCore* _renderCore;
	private:
		std::vector<Entity*> _entities;
		std::vector<Layer*> _layers;
	};
}