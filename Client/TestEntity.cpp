#include "pch.h"
#include "TestEntity.h"
#include "Texture.h"
#include "TextureRenderer.h"
#include "T_Nexus.h"

TestEntity::TestEntity()
{
	Texture* texture = new Texture;
	fs::path path = fs::current_path();
	MessageBox(nexus->getHWnd(), path.wstring().c_str(), L"ASD", MB_OK);
	//texture->loadBMP();
	TextureRenderer* renderer = addComponent<TextureRenderer>();
	//renderer->setTexture();
}

TestEntity::~TestEntity()
{ 
}

void TestEntity::update()
{
}
