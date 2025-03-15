#include "pch.h"
#include "MyNexus.h"
#include "Domain.h"
#include "DomainManager.h"
#include "TestDomain.h"

MyNexus::MyNexus()
{
}

MyNexus::~MyNexus()
{
}

void MyNexus::init()
{
	//todo : 각종 초기화들
	GET_SINGLETON(DomainManager)->registerDomain(L"TestDomain", new TestDomain);
	GET_SINGLETON(DomainManager)->loadDomain(L"TestDomain");
}

void MyNexus::update()
{
	GET_SINGLETON(DomainManager)->update();
}
void MyNexus::release()
{
}
