#pragma once
class Layer
{
public:
	Layer(int priority);
	virtual ~Layer();
public:
	bool operator <(const Layer& other)
	{
		return _priority < other.getPriority();
	}
public:
	virtual void update() abstract;
public:
	const bool& IsActive() const { return _isActive; }
	const int& getPriority() const { return _priority; }
protected:
	int _priority;
	bool _isActive;
};