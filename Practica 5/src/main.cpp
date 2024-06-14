#include <string>

#include "Components/Entity.h"
#include "Components/sprite.h"
#include "manager.h"
#include "Components/collider.h"

using namespace std;

	
const int width = 600.f;
const int height = 600.f;

int main() {
	
	glfwInit();
	
	
	const char* title = "P2_Gonzalo_Valenti";
	GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(window);
	lgfx_setup2d(width, height);

	// Entities creation
	Manager* manager = Manager::getInstance();
	manager->m_Window = window;
	manager->AddEntity(new My_Cursor());
	manager->AddEntity(new FollowCursor());
	manager->AddEntity(new StaticEntity("data/ball.png", COLLISION_CIRCLE));

	
	double time = glfwGetTime();
	while (!glfwWindowShouldClose(window))
	{
		lgfx_clearcolorbuffer(0, 0, 0);
		double const currentTime = glfwGetTime();
		double const DeltaTime = currentTime - time;
		time = currentTime;

		//MyBee->Update(static_cast<float>(DeltaTime));
		manager->Update(static_cast<float>(DeltaTime));
		
		glfwSwapBuffers(window);
		glfwPollEvents();
		glfwSetWindowTitle(window, ("GV-> Mouse: (" + std::to_string(2) + ")").c_str());
		
	}

	glfwTerminate();

	return 0;
}
