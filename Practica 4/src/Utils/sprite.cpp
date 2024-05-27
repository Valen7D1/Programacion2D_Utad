#include "sprite.h"

#include "draw.h"


inline Sprite::~Sprite()
{
    delete m_Texture;
}


void Sprite::update(float deltaTime)
{
}


void Sprite::draw() const
{
}
