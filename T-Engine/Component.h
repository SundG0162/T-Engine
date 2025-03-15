#pragma once
namespace TEngine
{
	class Entity;
	class Component
	{
	public:
		Component();
		virtual ~Component();
	public:
		virtual void update() abstract;
	public:
		void setOwner(Entity* owner) { _owner = owner; }
		Entity* getOwner() { return _owner; }
	protected:
		Entity* _owner;
	};
}