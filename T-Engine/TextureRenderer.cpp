#include "pch.h"
#include "TextureRenderer.h"
#include "Texture.h"
#include "T_Nexus.h"
namespace TEngine
{
	TextureRenderer::TextureRenderer()
		: _texture(nullptr)
	{
	}

	TextureRenderer::~TextureRenderer()
	{
	}

	void TextureRenderer::update()
	{
	}

	void TextureRenderer::render(HDC hdc)
	{
		Rectangle(hdc, 10, 10, 100, 100);
		//int width = _texture->getWidth();
		//int height = _texture->getHeight();
		//TransparentBlt(hdc, 50, 50, width, height, _texture->getTextureDC(), 0, 0, width, height, _texture->getTransparentColor());
	}
}