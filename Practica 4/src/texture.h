#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include "Vec2.h"
#include "../lib/stb_image.h"
#include "Font.h"


double deg2rad(double degrees) {
    return degrees ;
}

ltex_t* loadImg(const char* filename)
{
    // carga de imagen
    int imgX;
    int imgY;
    unsigned char* pixels = stbi_load(filename, &imgX, &imgY, nullptr, 4);

    // seteo de tex
    ltex_t* tex = ltex_alloc(imgX, imgY, 1);

    // crea la representaciona  pixeles de tex
    ltex_setpixels(tex, pixels);

    return tex;
}



void drawFullScreen(float width, float height, ltex_t* tex)
{
    // perdon por estas dos lineas de aqui
    int contX = std::ceil(width/ static_cast<float>(tex->width));
    int contY = std::ceil(height/ static_cast<float>(tex->height));

    for (int x = 0; x < contX; ++x)
    {
        for (int y = 0; y < contX; ++y)
        {
            ltex_draw(tex, x* tex->width, y* tex->height);
        }
    }
}


void drawFillingGaps(float width, float height, vec2 mouseLocation, ltex_t* tex)
{
    float Ysize = mouseLocation.y - static_cast<float>(tex->height) / 2.f;
    float Xsize = mouseLocation.x - static_cast<float>(tex->width) / 2.f;
 
    lgfx_setblend(BLEND_SOLID);
    lgfx_setcolor(0, 0, 0, 1);
    lgfx_drawrect(0, 0, Xsize, height);
    lgfx_drawrect(0, 0, width, Ysize);
    lgfx_drawrect(width, 0, -(width - (mouseLocation.x + tex->width / 2.f)), height);
    lgfx_drawrect(0, height, width, -(height - (mouseLocation.y + tex->height / 2.f)));
 
    lgfx_setcolor(1, 1, 1, 1);
}


void drawInLocation(vec2 location, ltex_t* tex)
{
    // get mid location so that texture spawns in location and not with offset
    location.x -= tex->width / 2.f;
    location.y -= tex->height / 2.f;
    // straight up draw
    ltex_draw(tex, location.x, location.y);
}

void drawRotatedSized(vec2 location, ltex_t* tex, float angleOfFire, float scale)
{
    ltex_drawrotsized(tex, location.x, location.y, angleOfFire, 0.5, 0.5, tex->width * scale, tex->height * scale, 0, 0, 1, 1);
}