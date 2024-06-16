#include "manager.h"

#include "Components/Entity.h"

Manager* Manager::instance = nullptr;


Manager* Manager::getInstance() 
{   
    // if not created already then create it
    if (instance == nullptr)
    {
        instance = new Manager();
    }
    return instance;
}


void Manager::Update(float DeltaTime)
{
    // mouse location store (should go in manager)
    double mouseX;
    double mouseY;
    glfwGetCursorPos(m_Window, &mouseX, &mouseY);
    SetMousePosition(mouseX, mouseY);

    for (Entity* _entity : m_Entities)
    {
        _entity->Update(DeltaTime); 
    }
}


void Manager::AddEntity(Entity* _entity)
{
    m_Entities.push_back(_entity);
}


void Manager::SetMousePosition(double _x, double _y)
{
    m_MousePosition.x = static_cast<float>(_x);
    m_MousePosition.y = static_cast<float>(_y);
}