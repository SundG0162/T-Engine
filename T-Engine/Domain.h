#pragma once
#include "LayerPriority.h"
class Entity;
class Layer;
class RenderCore;
class Domain
{
public:
	Domain();
	virtual ~Domain();
public:
	virtual void setup(); //���������� 
	virtual void init() abstract; //�ε������
	virtual void update();
	virtual void release();
public:
	void addLayer(Layer* layer, int priority);
	void removeLayer(Layer* layer);
	void cleanUp();
public:
	RenderCore* getRenderCore() { return _renderCore; }
	const vector<Entity*>& getEntities() { return _entities; }
	const Layer* getLayer(const LAYER_PRIORITY& priority) { return _layers[(int)priority]; }
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
protected:
	RenderCore* _renderCore;
	vector<Entity*> _entities;
	vector<Layer*> _layers;
};