
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


void drawFullScreen(int width, int height, ltex_t* tex)
{
	// perdon por estas dos lineas de aqui
	int contX = std::ceil(static_cast<float>(width)/ static_cast<float>(tex->width));
	int contY = std::ceil(static_cast<float>(height)/ static_cast<float>(tex->height));

	for (int x = 0; x < contX; ++x)
	{
		for (int y = 0; y < contX; ++y)
		{
			ltex_draw(tex, x* tex->width, y * tex->height);
		}
	}
}


void drawFillingGaps(int width, int height, vec2 location, ltex_t* tex, ltex_t* filler)
{

}


void drawInLocation(vec2 location, ltex_t* tex)
{
	// get mid location so that texture spawns in location and not with offset
	location.x -= tex->width / 2.f;
	location.y -= tex->height / 2.f;
	// straight up draw
	ltex_draw(tex, location.x, location.y);
}


int main() {

	double time = glfwGetTime();
	glfwInit();


	int width = 600;
	int height = 600;
	const char* title = "P2_Gonzalo_Valenti";
	GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(window);
	lgfx_setup2d(width, height);


	ltex_t* wall = loadImg("data/wall.jpg");
	ltex_t* grille = loadImg("data/grille.png");
	ltex_t* fire = loadImg("data/fire.png");
	ltex_t* lightMap = loadImg("data/light.png");


	while (!glfwWindowShouldClose(window))
	{
		double currentTime = glfwGetTime();
		double DeltaTime = currentTime - time;

		lgfx_clearcolorbuffer(0, 0, 0); //Clear
	
		// draw the wall
		lgfx_setblend(BLEND_SOLID);
		drawFullScreen(width, height, wall);

		// get the blend add and draw the fire in the mouse
		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);
		lgfx_setblend(BLEND_ADD);
		drawInLocation(vec2(mouseX, mouseY), fire); //fire looks a little bit offseted but its because of the original img

		// get the blend to alpha and draw the grille
		lgfx_setblend(BLEND_ALPHA);
		drawFullScreen(width, height, grille);

		// get the blend mul and draw the light
		lgfx_setblend(BLEND_MUL);
		drawInLocation(vec2(mouseX, mouseY), lightMap);

		glfwSwapBuffers(window);
		glfwPollEvents();

		glfwSetWindowTitle(window, ("GV-> Mouse: (" + std::to_string(mouseX) + std::to_string(mouseY) + ")").c_str());

		time = glfwGetTime();
	}

	glfwTerminate();

	//Sleep(10000);


	return 0;
}
