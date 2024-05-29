#pragma once

#include "../lib/stb_truetype.h"
#include "vec2.h"
#include <litegfx.h>

stbtt_bakedchar* SetFont(const char* Filename);

class Font
{
private:
    Font();

public:
    ~Font();
    
    static Font* load (const char* filename, float height);
    float getHeight () const { return m_height; }
    vec2 getTextSize (const char* text) const;
    void draw (const char* text, const vec2& pos) const;

public:
    ltex_t* tex;
    stbtt_bakedchar* fontdata;

private:
   float m_height;
};
