#include "pch.h"
#include "DomainManager.h"
#include "Domain.h"

void DomainManager::update()
{
	_currentDomain->update();
}

void DomainManager::release()
{
}

void DomainManager::registerDomain(const wstring& name, Domain* domain)
{
	_domainMap.insert(_domainMap.end(), std::make_pair(name, domain));
}

void DomainManager::loadDomain(const wstring& name)
{
	if (_currentDomain != nullptr)
	{
		_currentDomain->release();
		_currentDomain = nullptr;
	}
	auto iter = _domainMap.find(name);
	if (iter != _domainMap.end())
	{
		_currentDomain = iter->second;
		_currentDomain->init();
	}
}
