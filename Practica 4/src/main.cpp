#define LITE_GFX_IMPLEMENTATION

#include <glfw3.h>
#include "texture.h"

using namespace std;

	
const int width = 600.f;
const int height = 600.f;

int main() {

	double time = glfwGetTime();
	glfwInit();
	
	
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
		
		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);
		
		glfwSwapBuffers(window);
		glfwPollEvents();

		//glfwSetWindowTitle(window, ("GV-> Mouse: (" + std::to_string(2) + ")").c_str());
		
	}

	glfwTerminate();

	return 0;
}
