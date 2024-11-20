#pragma once
#include "Domain.h"
class TestDomain : public Domain
{
public:
	TestDomain();
	~TestDomain();
public:
	void init() override;
};