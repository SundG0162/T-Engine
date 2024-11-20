#pragma once
class Layer
{
public:
	Layer();
	virtual ~Layer();
public:
	virtual void update() abstract;
public:
	const bool& IsActive() const { return _isActive; }
protected:
	bool _isActive;
};