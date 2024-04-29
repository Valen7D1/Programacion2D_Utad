#define STB_IMAGE_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION

#include "Font.h"
#include <cstdio>
#include "draw.h"
#include "../lib/stb_image.h"


stbtt_bakedchar* SetFont(const char* Filename)
{
    FILE* FontFile;
    errno_t Error = fopen_s(&FontFile, Filename, "r"); // Open in binary mode

    if (FontFile != nullptr)
    {
        fseek(FontFile, 0, SEEK_END);
        unsigned long const FileSize = ftell(FontFile);
        fseek(FontFile, 0, SEEK_SET);

        // Allocate memory to hold the font data
        unsigned char* CharBuffer = new unsigned char[FileSize];
        unsigned char* AlphaBuffer = new unsigned char[FileSize];

        // Read the font data into the buffer
        size_t bytesRead = fread_s(CharBuffer, FileSize, sizeof(char), FileSize, FontFile);
        fclose(FontFile);

        stbtt_bakedchar* FontData = new stbtt_bakedchar[FileSize * sizeof(stbtt_bakedchar)];
        stbtt_BakeFontBitmap(CharBuffer, 0, 56, AlphaBuffer, 512, 512, 32, 255, FontData);
        delete[] CharBuffer;

        unsigned char* ColorBuffer = new unsigned char[FileSize * 4];

        int AlphaIndex = 0;
        for (int i = 0; i < FileSize; ++i)
        {
            if (i % 3 == 0)
            {
                ColorBuffer[i] = AlphaBuffer[AlphaIndex];
                ++AlphaIndex;
            }
            else
            {
                ColorBuffer[i] = 1;
            }
        }

        ltex_t* tex = ltex_alloc(512, 512, 1);
        ltex_setpixels(tex, ColorBuffer);

        stbtt_GetBakedQuad();
        
        return FontData;
    }
    else
    {
        printf("Error opening font file\n");
    }

    return nullptr;
}
