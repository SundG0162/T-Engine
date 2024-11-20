#pragma once
#include "LayerPriority.h"
class Layer;
class Domain
{
public:
	Domain();
	~Domain();
public:
	virtual void update();
public:
	void addLayer(Layer* layer, LAYER_PRIORITY priority);
	void removeLayer(Layer* layer);
	void cleanUp();
public:
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
	Layer* _layers[(int)LAYER_PRIORITY::END];
};