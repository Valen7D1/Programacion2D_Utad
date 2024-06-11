#include "Font.h"

#define STB_TRUETYPE_IMPLEMENTATION

#include "stb_truetype.h"
#include <cstdio>
#include <stb_image.h>
#include <litegfx.h>


Font::Font():
    tex(new ltex_t()),
    fontdata(new stbtt_bakedchar[256])
{
}


Font::~Font()
{
    delete[] fontdata;
    delete tex;
}


Font* Font::load(const char* filename, float height)
{
    FILE* fontFile = nullptr;
    errno_t error = fopen_s(&fontFile, filename, "rb");

    if (!fontFile)
    {
        return nullptr;
    }
    
    fseek(fontFile, 0, SEEK_END);
    unsigned long const FileSize = ftell(fontFile);
    fseek(fontFile, 0, SEEK_SET);

    // create Font obj
    Font* newFont = new Font();
    newFont->m_height = height;

    // Allocate memory to hold the font data
    unsigned char* fontBuffer = new unsigned char[sizeof(char) * FileSize];

    // Read the font data into the buffer
    size_t bytesRead = fread_s(fontBuffer, FileSize, sizeof(char), FileSize, fontFile);
    fclose(fontFile);

    // Ruben values Todo: Ask Juan
    const unsigned int alphaSize = 512 * 512;
    unsigned char* alphaBuffer = new unsigned char[alphaSize];
	
    stbtt_BakeFontBitmap(fontBuffer, 0, 56, alphaBuffer, 512, 512, 32, 255, newFont->fontdata);

	// create color buffer (4x rgb + alpha)
	const unsigned int colorSize = alphaSize * 4;
	unsigned char* colorBuffer = new unsigned char[colorSize];
	
	
    //Random color (thx ruben)
	unsigned int* colorRGB = new unsigned int[3];
	newFont->r = colorRGB[0] = rand() % 255u / 255u;
	newFont->g = colorRGB[1] = rand() % 255u / 255u;
	newFont->b = colorRGB[2] = rand() % 255u / 255u;

	int AlphaIndex = 0; // id for alpha values
	for (size_t i = 0; i < colorSize; i++)
	{
		if (i % 4 == 3) 
		{
			// if (int temp =  alphaBuffer[AlphaIndex] != 0)
			// {
			// 	temp ++;
			// }
			colorBuffer[i] =  alphaBuffer[AlphaIndex++];
		}
		else
		{
			colorBuffer[i] = colorRGB[i % 4];
		}
	}
	
	//again ruben values todo: Ask juan
	newFont->tex = ltex_alloc(512, 512, 0);
	ltex_setpixels(newFont->tex, colorBuffer);

	// clean memory
	delete[] fontBuffer;
	delete[] alphaBuffer;
	delete[] colorBuffer;
	delete[] colorRGB;

	return newFont;
}

vec2 Font::getTextSize(const char* text) const
{
	return vec2(tex->height, tex->width);
}

void Font::draw(const char* text, const vec2& pos) const
{
	float posX = pos.x;
	float posY = pos.y;
	stbtt_aligned_quad* q = new stbtt_aligned_quad;
	lgfx_setblend(BLEND_ALPHA);
	for (const char* character = text; *character != '\0'; ++character) {
		stbtt_GetBakedQuad(fontdata, 512, 512, *character - 32, &posX, &posY, q, true);
		lgfx_setcolor(0.5, 1, 1, 1);
		ltex_drawrotsized(tex, q->x0, q->y0, 0, 0, 0, q->x1 - q->x0, q->y1 - q->y0, q->s0, q->t0, q->s1, q->t1);
	}
}
