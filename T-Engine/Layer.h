#pragma once
class Domain;
class Layer
{
public:
	Layer();
	virtual ~Layer();
public:
	virtual void update() abstract;
public:
	void setDomain(Domain* domain) { _domain = domain; }
	const bool& IsActive() const { return _isActive; }
protected:
	Domain* _domain;
	bool _isActive;
};