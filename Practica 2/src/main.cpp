
#define LITE_GFX_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include "Vec2.h"
#include <string>
#include "math.h"
#include "../lib/stb_image.h"

using namespace std;

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


int main() {

	double time = glfwGetTime();
	glfwInit();


	float width = 600.f;
	float height = 600.f;
	const char* title = "P2_Gonzalo_Valenti";
	GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(window);
	lgfx_setup2d(width, height);

	float angleOfFire = 0.f;
	float angleRate = 10.f;

	float scaleOfFire = 1.f;
	float scaleRate = 0.2f;
	
	ltex_t* wall = loadImg("data/wall.jpg");
	ltex_t* grille = loadImg("data/grille.png");
	ltex_t* fire = loadImg("data/fire.png");
	ltex_t* lightMap = loadImg("data/light.png");
	ltex_t* filler = loadImg("data/filler.png");


	while (!glfwWindowShouldClose(window))
	{
		double currentTime = glfwGetTime();
		double DeltaTime = currentTime - time;
		time = currentTime;

		lgfx_clearcolorbuffer(0, 0, 0); //Clear
	
		// draw the wall
		lgfx_setblend(BLEND_SOLID);
		drawFullScreen(width, height, wall);

		// get the blend add and draw the fire in the mouse
		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);
		lgfx_setblend(BLEND_ADD);
		drawRotatedSized(vec2(mouseX, mouseY), fire, angleOfFire, scaleOfFire);
		//drawInLocation(vec2(mouseX, mouseY), fire); //fire looks a little bit offseted but its because of the original img

		// get the blend to alpha and draw the grille
		lgfx_setblend(BLEND_ALPHA);
		drawFullScreen(width, height, grille);

		// get the blend mul and draw the light
		lgfx_setblend(BLEND_MUL);
		drawInLocation(vec2(mouseX, mouseY), lightMap);

		drawFillingGaps(width, height, vec2(mouseX, mouseY), lightMap);

		angleOfFire += angleRate * DeltaTime;
		if (angleOfFire < -10.f || angleOfFire > 10.f)
		{
			angleRate *= -1.f;
			angleOfFire += angleRate * DeltaTime;
		}

		scaleOfFire += scaleRate * DeltaTime;
		if (scaleOfFire < 0.8f || scaleOfFire > 1.f)
		{
			scaleRate *= -1.f;
			scaleOfFire += scaleRate * DeltaTime;
		}

		glfwSwapBuffers(window);
		glfwPollEvents();

		//glfwSetWindowTitle(window, ("GV-> Mouse: (" + std::to_string(mouseX) + std::to_string(mouseY) + ")").c_str());
		glfwSetWindowTitle(window, ("GV-> Mouse: (" + std::to_string(scaleOfFire) + ")").c_str());
		
	}

	glfwTerminate();

	//Sleep(10000);


	return 0;
}
