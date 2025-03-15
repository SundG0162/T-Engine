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
	//todo : ���� �ʱ�ȭ��
	Domain* domain = new TestDomain;
	domain->setup();
	GET_SINGLETON(DomainManager)->registerDomain(L"TestDomain", domain);
	GET_SINGLETON(DomainManager)->loadDomain(L"TestDomain");
}

void MyNexus::update()
{
	GET_SINGLETON(DomainManager)->update();
}
void MyNexus::release()
{
}
