#include "World.h"

#include "Components/camera.h"
#include "Components/Entity.h"

World* World::instance = nullptr;


World* World::GetWorld() 
{   
    // if not created already then create it
    if (instance == nullptr)
    {
        instance = new World();
    }
    return instance;
}


void World::Update(float DeltaTime)
{
    // mouse location store (should go in manager)
    double mouseX;
    double mouseY;
    glfwGetCursorPos(m_Window, &mouseX, &mouseY);
    SetMousePosition(mouseX, mouseY);

    vec2 const CamLoc = m_FollowCamera->GetCameraLocation();
    lgfx_setorigin(CamLoc.x - static_cast<float>(Width)/2.f , CamLoc.y - static_cast<float>(Height)/2.f);

    
    for (Entity* _entity : m_Entities)
    {
        _entity->Update(DeltaTime); 
    }
}


void World::AddEntity(Entity* _entity)
{
    m_Entities.push_back(_entity);
}

void World::RemoveEntity(Entity* _entityToErase)
{
    
}

void World::SetCamera(Camera* _newCamera)
{
    if (_newCamera != m_FollowCamera)
    {
        delete m_FollowCamera;
        m_FollowCamera = _newCamera;
    }
}

vec2 World::GetCameraLocation() const
{
    return m_FollowCamera->GetCameraLocation();
}

void World::SetCameraLocation(vec2 _newLocation)
{
    m_FollowCamera->SetCameraLocation(_newLocation);
}


void World::SetMousePosition(double _x, double _y)
{
    m_MousePosition.x = static_cast<float>(_x);
    m_MousePosition.y = static_cast<float>(_y);
}
