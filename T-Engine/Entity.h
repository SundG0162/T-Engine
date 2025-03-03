#pragma once
namespace TEngine
{
	class Component;
	class Entity
	{
	public:
		Entity();
		virtual ~Entity() = default;
	public:
		virtual void update() = 0;
	public:
		template<typename T>
		T* getComponent()
		{
			T* component = nullptr;
			for (Component* compo : _components)
			{
				component = dynamic_cast<T*>(compo);
				if (component)
					break;
			}
			return component;
		}
		template<typename T>
		T* addComponent()
		{
			if (getComponent<T>() == nullptr)
			{
				T* component = new T;
				_components.push_back(component);
				return component;
			}
			return nullptr;
		}
	private:
		vector<Component*> _components;
	};
}