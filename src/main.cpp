
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
	const char* title = "P1_RubenSantos";

	GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(window);

	lgfx_setup2d(width, height);

	while (!glfwWindowShouldClose(window))
	{
		double currentTime = glfwGetTime();
		double DeltaTime = currentTime - time;

		lgfx_clearcolorbuffer(0, 0, 0); //Clear

		lgfx_setcolor(1, 0, 0, 1); 

		//Cuadrado en el centro de la pantalla
		vec2 widthAndHeight = vec2(50, 50);
		lgfx_drawrect(width / 2 - widthAndHeight.x / 2, height / 2 - widthAndHeight.y / 2, widthAndHeight.x, widthAndHeight.y);


		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		//Cuadrado que sigue al raton
		lgfx_setcolor(0, 1, 0, 1);
		lgfx_drawrect(static_cast<float>(mouseX) - widthAndHeight.x/2, static_cast<float>(mouseY) - widthAndHeight.y / 2, widthAndHeight.x, widthAndHeight.y);


		//Circulo que gira sobre el raton
		double angle = 32 * glfwGetTime(); //Grados por segundo

		if (angle > 360) { angle -= 360; }
		if (angle < 0) { angle += 360; }

		double angleInRadians = angle * 3.1415926f / 180.0;

		double circleX = mouseX + 100 * cos(angleInRadians);
		double circleY = mouseY + 100 * sin(angleInRadians);

		lgfx_setcolor(0, 0, 1, 1);
		lgfx_drawoval(static_cast<float>(circleX) - widthAndHeight.x / 2, static_cast<float>(circleY) - widthAndHeight.y / 2, widthAndHeight.x, widthAndHeight.y);


		//Linea
		lgfx_setcolor(1, 1, 1, 1);

		lgfx_drawline(100, 100, 200, 200);

		//Punto
		lgfx_drawpoint(400, 400);

		float Distance = vec2(mouseX, mouseY).Distance(vec2(width/2, height/2));

		glfwSetWindowTitle(window, ("GV-> Angle: " + std::to_string(angle) + " Distance: " + std::to_string(Distance)).c_str());

		glfwSwapBuffers(window);
		glfwPollEvents();

		time = glfwGetTime();
	}

	glfwTerminate();

	//Sleep(10000);


	return 0;
}
