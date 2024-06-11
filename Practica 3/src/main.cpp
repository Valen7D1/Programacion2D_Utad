#define LITE_GFX_IMPLEMENTATION

#include <glfw3.h>
#include <iostream>
#include "Utils/Vec2.h"
#include <string>
#include <iostream>
#include "Utils/texture.h"
#include <vector>

using namespace std;

	
const int width = 600.f;
const int height = 600.f;

int main() {

	double time = glfwGetTime();
	glfwInit();

	Font* newFont = Font::load("data/Orange.ttf", 60);
	
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
		
		newFont->draw("hello world", vec2(200, 200));
		
		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);
		
		glfwSwapBuffers(window);
		glfwPollEvents();

		glfwSetWindowTitle(window, ("GV-> Mouse: (" + std::to_string(2) + ")").c_str());
		
	}

	glfwTerminate();

	return 0;
}
