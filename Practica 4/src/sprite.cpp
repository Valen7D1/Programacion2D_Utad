#include "sprite.h"


inline Sprite::~Sprite()
{
    delete m_Texture;
}

void Sprite::setTexture(ltex_t* tex, int hframes, int vframes)
{
    m_Texture = tex;
    m_HFrames = hframes;
    m_VFrames = vframes;
}

void Sprite::update(float deltaTime)
{
    
}


void Sprite::draw() const
{
    
}
