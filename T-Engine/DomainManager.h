#pragma once
namespace TEngine
{
	class Domain;
	class DomainManager
	{
		DECLARE_SINGLETON(DomainManager);
	public:
		void update();
		void release();
	public:
		void registerDomain(const wstring& name, Domain* domain);
		void loadDomain(const wstring& name);
	public:
		Domain* getCurrentDomain() { return _currentDomain; }
	private:
		Domain* _currentDomain = nullptr;
		map<wstring, Domain*> _domainMap;
	};
}