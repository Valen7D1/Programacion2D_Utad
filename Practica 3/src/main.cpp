#define LITE_GFX_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include <glfw3.h>
#include <iostream>
#include "Vec2.h"
#include <string>
#include "math.h"
#include "../lib/stb_image.h"
#include "draw.h"

using namespace std;


int main() {

	double time = glfwGetTime();
	glfwInit();


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
