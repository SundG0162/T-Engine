#pragma once
#include "LayerPriority.h"
class Entity;
class Layer;
class Domain
{
public:
	Domain();
	virtual ~Domain();
public:
	void setup(); //생성됏을때 
	void init(); //로드됐을때
	void update();
	void release();
public:
	void addLayer(Layer* layer, LAYER_PRIORITY priority);
	void removeLayer(Layer* layer);
	void cleanUp();
public:
	const vector<Entity*>& getEntities() { return _entities; }
	Layer* getLayer(const LAYER_PRIORITY& priority) { return _layers[(int)priority]; }
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
private:
	vector<Entity*> _entities;
	Layer* _layers[(int)LAYER_PRIORITY::END];
};