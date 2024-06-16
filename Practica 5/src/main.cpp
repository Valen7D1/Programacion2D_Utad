#include <string>

#include "Components/Entity.h"
#include "Components/sprite.h"
#include "manager.h"
#include "Components/collider.h"

using namespace std;

	
const int width = 600;
const int height = 600;

int main() {
	
	glfwInit();
	
	
	const char* title = "P2_Gonzalo_Valenti";
	GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(window);
	lgfx_setup2d(width, height);

	// Entities creation
	Manager* manager = Manager::getInstance();
	manager->m_Window = window;
	//manager->AddEntity(new FollowCursor());
	manager->AddEntity(new StaticEntity("data/ball.png", COLLISION_CIRCLE, vec2(300.f, 100.f)));
	manager->AddEntity(new StaticEntity("data/box.png", COLLISION_RECT, vec2(300.f, 300.f)));
	manager->AddEntity(new StaticEntity("data/bee.png", COLLISION_PIXELS, vec2(300.f, 500.f)));

	My_Cursor* cursor = new My_Cursor();
	manager->AddEntity(cursor);

	
	double time = glfwGetTime();
	while (!glfwWindowShouldClose(window))
	{
		lgfx_clearcolorbuffer(0, 0, 0);
		double const currentTime = glfwGetTime();
		double const DeltaTime = currentTime - time;
		time = currentTime;

		//MyBee->Update(static_cast<float>(DeltaTime));
		manager->Update(static_cast<float>(DeltaTime));

		// p5 mouse control
		if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT))
		{
			ltex_t* EntityTex = Sprite::loadImage("data/circle.png");
			cursor->SetSprite(new Sprite(EntityTex, cursor->GetData(), 1, 1, 1, Color::White()));
			cursor->GetData()->Size = vec2(100.f, 100.f);
			cursor->SetCollider(Collider::CreateCollider(CollisionType::COLLISION_CIRCLE, EntityTex, cursor->GetData()));
		}
		else if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT))
		{
			ltex_t* EntityTex = Sprite::loadImage("data/rect.png");
			cursor->SetSprite(new Sprite(EntityTex, cursor->GetData(), 1, 1, 1, Color::White()));
			cursor->GetData()->Size = vec2(100.f, 100.f);
			cursor->SetCollider(Collider::CreateCollider(COLLISION_RECT, EntityTex, cursor->GetData()));
		}
		else if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE))
		{
			ltex_t* EntityTex = Sprite::loadImage("data/bee.png");
			cursor->SetSprite(new Sprite(EntityTex, cursor->GetData(), 1, 1, 1, Color::White()));
			cursor->GetData()->Size = vec2(100.f, 100.f);
			cursor->SetCollider(Collider::CreateCollider(COLLISION_PIXELS, EntityTex, cursor->GetData()));
		}
		
		glfwSwapBuffers(window);
		glfwPollEvents();
		glfwSetWindowTitle(window, ("P5 Gonzalo Valenti"));
		
	}

	glfwTerminate();

	return 0;
}
