#pragma once
#include <vector>
#include <glfw3.h>
#include "Vec2.h"

class Entity;

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

class Manager {
private:
    static Manager* instance;
    vec2 m_MousePosition = vec2();
    std::vector<Entity*> m_Entities;

public:
    GLFWwindow* m_Window;
    
public:
    static Manager* getInstance();
    vec2 GetMousePosition() { return m_MousePosition; }

    void Update(float DeltaTime);
    void AddEntity(Entity* _entity);
    void SetMousePosition(double _x, double _y);
    
};
