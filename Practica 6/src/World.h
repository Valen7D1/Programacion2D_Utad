#pragma once
#include <vector>
#include <queue>
#include <glfw3.h>

#include "litegfx.h"
#include "Vec2.h"


class Camera;
class ParalaxBackground;
class Entity;

# pragma region DataManagement

struct EData {
    EData(vec2 _loc, vec2 _size, vec2 _scale = vec2(1,1), vec2 _pivot = vec2(0.5, 0.5), float angle = 0.f) :
    Location(_loc),
    Scale(_scale),
    Pivot(_pivot),
    Size(_size),
    Angle(angle){}

    ~EData() = default;

    vec2 TempLocation = vec2();
    vec2 Location;
    vec2 Scale;
    vec2 Pivot;
    vec2 Size;
    float Angle;
    
};

#pragma endregion


class World {
    
private:
    static World* instance;
    vec2 m_MousePosition = vec2();
    
    std::vector<Entity*> m_Entities;
    std::vector<ParalaxBackground*> m_BackGround;

    const float m_Red = 0.f;
    const float m_Green = 0.f;
    const float m_Blue = 0.f;

    Camera* m_FollowCamera = nullptr;


public:
    GLFWwindow* m_Window;
    float const Height = 600.f;
    float const Width = 600.f;
    
public:
    static World* GetWorld();
    vec2 GetMousePosition() { return m_MousePosition; }
    std::vector<Entity*>& GetEntities() { return m_Entities; }

    void Update(float DeltaTime);
    void SetMousePosition(double _x, double _y);

    void SetBackGround(std::vector<ltex_t*> _backgrounds);
    ltex_t GetBackGround(size_t _layer) const;
    
    void AddEntity(Entity* _entity);
    void RemoveEntity(Entity* _entity);

    void SetCamera(Camera* _newCamera);
    void SetCameraLocation(vec2 _newLocation);
    vec2 GetCameraLocation() const;
    
};
