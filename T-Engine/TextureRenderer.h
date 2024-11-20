#pragma once
#include "Renderer.h"
class Texture;
class TextureRenderer : public Renderer
{
public:
	TextureRenderer();
	~TextureRenderer();
public:
	void update() override;
	void render(HDC hdc) override;
public:
	void setTexture(Texture* texture) { _texture = texture; }
	Texture* getTexture() { return _texture; }
private:
	Texture* _texture;
};

