#pragma once
#include "LayerType.h"
namespace TEngine
{
	class Domain;
	class Layer
	{
	public:
		Layer();
		Layer(LayerType layerType);
		virtual ~Layer();

		bool operator<(const Layer& other)
		{
			return _priority < other.getPriority();
		}
	public:
		virtual void initialize(Domain* domain) abstract;
		virtual void perform() abstract;
	public:
		void setPriority(int& priority) { _priority = priority; }
		const int& getPriority() const { return _priority; }
		const bool& isActive() const { return _isActive; }
	protected:
		LayerType _layerType;
		int _priority;
		Domain* _domain;
		bool _isActive = true;
	};
}