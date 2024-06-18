#include "World.h"

#include "Components/camera.h"
#include "Components/Entity.h"
#include "Components/background.h"

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

    lgfx_clearcolorbuffer(m_Red, m_Green, m_Blue);
    
    double mouseX;
    double mouseY;
    glfwGetCursorPos(m_Window, &mouseX, &mouseY);
    SetMousePosition(mouseX, mouseY);

    vec2 const CamLoc = m_FollowCamera->GetCameraLocation();
    lgfx_setorigin(CamLoc.x - static_cast<float>(Width)/2.f , CamLoc.y - static_cast<float>(Height)/2.f);


    for (ParalaxBackground* _bg : m_BackGround)
    {
        _bg->Update(DeltaTime); 
    }
    
    for (Entity* _entity : m_Entities)
    {
        _entity->Update(DeltaTime); 
    }
}


#pragma region Setters / Getters

void World::AddEntity(Entity* _entity)
{
    m_Entities.push_back(_entity);
}

void World::RemoveEntity(Entity* _entityToErase)
{
    auto const Iterator = std::find(m_Entities.begin(), m_Entities.end(), _entityToErase); 
    if (Iterator != m_Entities.end())
    { 
        m_Entities.erase(Iterator); 
    }
    delete _entityToErase;
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

void World::SetBackGround(std::vector<ParalaxBackground*> _backgrounds)
{
    unsigned int Layer = 0;
    m_BackGround.clear();
    
    for (ParalaxBackground* _bg : _backgrounds)
    {
        _bg->SetLayer(Layer);
        m_BackGround.push_back(_bg);
        ++Layer;
    }
}

ParalaxBackground* World::GetBackGround(size_t _layer) const
{
    return m_BackGround[_layer];
}

#pragma endregion