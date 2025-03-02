#include "pch.h"
#include "TestEntity.h"
#include "Texture.h"
#include "TextureRenderer.h"
#include "T_Nexus.h"

TestEntity::TestEntity()
{
	Texture* texture = new Texture;
	fs::path path = fs::current_path();
	//texture->loadBMP();
	TextureRenderer* renderer = addComponent<TextureRenderer>();
	//renderer->setTexture();
}

TestEntity::~TestEntity()
{
}

void TestEntity::update()
{
	MessageBox(nexus->getHWnd(), L"Update", L"ASD", MB_OK);
}

void TestEntity::executeProto()
{
	MessageBox(nexus->getHWnd(), L"ProtoLayer", L"ASD", MB_OK);
}

void TestEntity::executeTest()
{
	MessageBox(nexus->getHWnd(), L"TestLayer", L"ASD", MB_OK);
}
