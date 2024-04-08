
#define LITE_GFX_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include "Vec2.h"
#include <string>

using namespace std;

double deg2rad(double degrees) {
	return degrees ;
}

int main() {

	double time = glfwGetTime();
	glfwInit();


	int width = 600;
	int height = 600;
	const char* title = "P1_GonzaloValenti";

	GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(window);

	lgfx_setup2d(width, height);

	double angle = 0;

	while (!glfwWindowShouldClose(window))
	{

		double currentTime = glfwGetTime();
		double DeltaTime = currentTime - time;
		time = currentTime;

		lgfx_clearcolorbuffer(0, 0, 0); //Clear

		lgfx_setcolor(1, 0, 0, 1); 

		// Centered Square
		vec2 widthAndHeight = vec2(50, 50);
		lgfx_drawrect(width / 2 - widthAndHeight.x / 2, height / 2 - widthAndHeight.y / 2, widthAndHeight.x, widthAndHeight.y);


		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		// Mouse following square
		lgfx_setcolor(0, 1, 0, 1);
		lgfx_drawrect(static_cast<float>(mouseX) - widthAndHeight.x/2, static_cast<float>(mouseY) - widthAndHeight.y / 2, widthAndHeight.x, widthAndHeight.y);


		// Mouse rotating circle
		angle += 32 * DeltaTime; // Degrees using deltatime

		// cap values in 0 - 360 
		if (angle > 360) { angle -= 360; }
		if (angle < 0) { angle += 360; }

		double angleInRadians = angle * 3.1415926f / 180.0; // set to radians

		double circleX = mouseX + 100 * cos(angleInRadians);
		double circleY = mouseY + 100 * sin(angleInRadians);

		lgfx_setcolor(0, 0, 1, 1);
		lgfx_drawoval(static_cast<float>(circleX) - widthAndHeight.x / 2, static_cast<float>(circleY) - widthAndHeight.y / 2, widthAndHeight.x, widthAndHeight.y);


		// line code
		lgfx_setcolor(1, 1, 0, 1);

		lgfx_drawline(100, 100, 200, 200);

		// point code
		lgfx_drawpoint(400, 400);

		float Distance = vec2(mouseX, mouseY).Distance(vec2(width/2, height/2));

		glfwSetWindowTitle(window, ("GV-> Angle: " + std::to_string(angle) + " Distance: " + std::to_string(Distance)).c_str());

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	//Sleep(10000);


	return 0;
}
