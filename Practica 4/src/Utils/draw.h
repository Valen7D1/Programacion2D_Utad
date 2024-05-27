#pragma once

#include <litegfx.h>
class vec2;

double deg2rad(double degrees);
ltex_t* loadImg(const char* filename);
void drawFullScreen(float width, float height, ltex_t* tex);
void drawFillingGaps(float width, float height, vec2 mouseLocation, ltex_t* tex);
void drawInLocation(vec2 location, ltex_t* tex);
void drawRotatedSized(vec2 location, ltex_t* tex, float angleOfFire, float scale);