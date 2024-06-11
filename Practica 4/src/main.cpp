#include <glfw3.h>
#include <string>

#include "Entity.h"
#include "sprite.h"
#include "manager.h"

using namespace std;

	
const int width = 600.f;
const int height = 600.f;

int main() {
	
	glfwInit();
	
	
	const char* title = "P2_Gonzalo_Valenti";
	GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(window);
	lgfx_setup2d(width, height);

	My_Bee* MyBee = new My_Bee();

	ltex_t* Test = Sprite::loadImage("data/bee_anim.png");
	Manager* manager = Manager::getInstance();
	double time = glfwGetTime();
	while (!glfwWindowShouldClose(window))
	{
		lgfx_clearcolorbuffer(0, 0, 0);
		double currentTime = glfwGetTime();
		double DeltaTime = currentTime - time;
		time = currentTime;

		// mouse location store (should go in manager)
		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);
		manager->SetMousePosition(mouseX, mouseY);

		MyBee->Update(static_cast<float>(DeltaTime));
		
		glfwSwapBuffers(window);
		glfwPollEvents();
		glfwSetWindowTitle(window, ("GV-> Mouse: (" + std::to_string(2) + ")").c_str());
		
	}

	glfwTerminate();

	return 0;
}
