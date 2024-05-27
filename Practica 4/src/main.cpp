#include <glfw3.h>
#include <iostream>
#include "Utils/Vec2.h"
#include <string>
#include "Utils/draw.h"
#include "Utils/Font.h"

using namespace std;


int main() {

	double time = glfwGetTime();
	glfwInit();

	stbtt_bakedchar* AlphaBuffer = SetFont("data/Orange.ttf");

	
	
	float width = 600.f;
	float height = 600.f;
	const char* title = "P2_Gonzalo_Valenti";
	GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(window);
	lgfx_setup2d(width, height);
	

	while (!glfwWindowShouldClose(window))
	{
		double currentTime = glfwGetTime();
		double DeltaTime = currentTime - time;
		time = currentTime;

		lgfx_clearcolorbuffer(0, 0, 0); //Clear
		

		// get the blend add and draw the fire in the mouse
		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);


		
		glfwSwapBuffers(window);
		glfwPollEvents();

		glfwSetWindowTitle(window, ("GV-> Mouse: (" + std::to_string(2) + ")").c_str());
		
	}

	glfwTerminate();

	//Sleep(10000);


	return 0;
}