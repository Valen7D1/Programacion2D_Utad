#include <string>

#include "Components/Entity.h"
#include "Components/collider.h"
#include "World.h"
#include "Components/camera.h"


using namespace std;



int main() {
	
	glfwInit();
	
	World* manager = World::GetWorld();
	const char* title = "P2_Gonzalo_Valenti";
	
	GLFWwindow* window = glfwCreateWindow(static_cast<int>(manager->Width), static_cast<int>(manager->Height), title, nullptr, nullptr);
	glfwMakeContextCurrent(window);
	lgfx_setup2d(static_cast<int>(manager->Width), static_cast<int>(manager->Height));

	// Entities creation
	manager->m_Window = window;
	
	Camera* FollowCamera = new Camera(vec2(300.f, 300.f), vec2(600.f, 300.f), vec2(300.f, 300.f));
	manager->SetCamera(FollowCamera);
	
	manager->AddEntity(new StaticEntity("data/ball.png", COLLISION_CIRCLE, vec2(300.f, 100.f)));
	manager->AddEntity(new StaticEntity("data/box.png", COLLISION_RECT, vec2(300.f, 300.f)));
	manager->AddEntity(new StaticEntity("data/bee.png", COLLISION_PIXELS, vec2(300.f, 500.f)));
	
	manager->AddEntity(new FollowCursor());
	
	double time = glfwGetTime();
	while (!glfwWindowShouldClose(window))
	{
		lgfx_clearcolorbuffer(0, 0, 0);
		double const currentTime = glfwGetTime();
		double const DeltaTime = currentTime - time;
		time = currentTime;

		manager->Update(static_cast<float>(DeltaTime));
		
		glfwSwapBuffers(window);
		glfwPollEvents();
		//glfwSetWindowTitle(window, ("Mouse: (" + std::to_string(manager->GetMousePosition().x) + ", "+ std::to_string(manager->GetMousePosition().y) + ")").c_str());
		
	}

	glfwTerminate();

	return 0;
}
