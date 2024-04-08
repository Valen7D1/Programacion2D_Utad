
#define LITE_GFX_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include "vec2.h"
#include <string>

using namespace std;

int main()
{
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(800, 700, "No hay titulo", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	lgfx_setup2d(800, 700);
	int frame = 0;

	double previusTime = glfwGetTime();

	//Circle Variables
	float cSpeed = 2; //1/32;
	float cAngle = 0;
	float cDistance = 100;
	float cRadius = 25;
	vec2 cOffset(cDistance, 0);

	//Main Loop
	while (!glfwWindowShouldClose(window))
	{
		double deltaTime = glfwGetTime() - previusTime;
		previusTime = glfwGetTime();

		++frame;

		// Input
		glfwPollEvents();

		// Update Game Logic
		double xMouse;
		double yMouse;
		glfwGetCursorPos(window, &xMouse, &yMouse);

		lgfx_clearcolorbuffer(1, 1, 1);

		// Background
		lgfx_setcolor(0.1, 0, 0.2, 1);
		lgfx_drawrect(0, 0, 800, 700);

		// Purple Square on Screen Center
		lgfx_setcolor(0.62, 0.12, 0.94, 1);
		lgfx_drawrect(400, 350, 100, 100);

		// Red Square on Mouse
		lgfx_setcolor(0.5, 0, 0.25, 1);
		lgfx_drawrect(xMouse - 25, yMouse - 25, 50, 50);

		// Circle orbiting mouse
		float rotationchange = cSpeed * deltaTime;
		cAngle += rotationchange;
		cOffset = vec2(xMouse +  cDistance * std::cos(cAngle), yMouse +  cDistance * std::sin(cAngle)); //cRadius +

		lgfx_setcolor(1, 0.25, 0.6, 1);
		//cOffset = cOffset;
		lgfx_drawoval(cOffset.x, cOffset.y, 25, 25); //xMouse - cRadius / 2 + cOffset.x, yMouse - cRadius / 2 + cOffset.y

		glfwSetWindowTitle(window, ("PAV - Angulo: " + std::to_string(cAngle) + " DeltaTime: " + std::to_string(deltaTime) + " Rotatacion por segundo: " + std::to_string(1/rotationchange)).c_str());
		// Swap buffers
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}
