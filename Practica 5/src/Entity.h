#pragma once
#include "Vec2.h"

class Sprite;
class EData;
class Collider;

class Entity
{
public:
    Entity() = default;
    virtual ~Entity();
    virtual void Update(float DeltaTime) = 0;
    
protected:
    Sprite* m_Sprite = nullptr;
    EData* m_Data = nullptr;
    Collider* m_Collider = nullptr;
    
};


class My_Bee : public Entity
{
public:
    My_Bee();
    virtual ~My_Bee() override = default;
    virtual void Update(float DeltaTime) override;

private:
    vec2 m_MoveSpeed = vec2(128.f, 128.f);
    float m_RotationSpeed = -32.f;
    float m_RotationTarget = -15.f;
};

class My_Cursor : public Entity
{
public:
    My_Cursor();
    virtual ~My_Cursor() override = default;
    virtual void Update(float DeltaTime) override;
};
