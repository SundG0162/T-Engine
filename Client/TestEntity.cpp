#include "pchClient.h"
#include "TestEntity.h"
#include "T_Nexus.h"

TestEntity::TestEntity()
{
	//Texture* texture = new Texture;
	//fs::path path = fs::current_path();
	//texture->loadBMP();
	//TextureRenderer* renderer = addComponent<TextureRenderer>();
	//renderer->setTexture();
}

TestEntity::~TestEntity()
{
}

void TestEntity::update()
{
	MessageBox(nexus->getHWnd(), L"asfaf", L"ASFASFF", 0);
}
