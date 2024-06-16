#pragma once

#include "../Vec2.h"

class Entity;

struct EData;

class Movement
{
public:
    Movement(Entity* _entity,  EData* _data) : m_Entity(_entity), m_Data(_data) {}
    virtual ~Movement() = default;    
    virtual void Update(float DeltaTime) = 0;
    
protected:
    Entity* m_Entity = nullptr;
    EData* m_Data = nullptr;
};


class FollowCursorMovement : public Movement
{
public:
    FollowCursorMovement(Entity* _entity, EData* _data) :  Movement(_entity, _data){}
    ~FollowCursorMovement() override = default;

    virtual void Update(float DeltaTime) override;

private:
    vec2 m_MoveSpeed = vec2(128.f, 128.f);
    float m_RotationSpeed = -32.f;
    float m_RotationTarget = -15.f;
};


class MyCursorMovement : public Movement
{
public:
    MyCursorMovement(Entity* _entity, EData* _data) :  Movement(_entity, _data){}
    ~MyCursorMovement() override = default;

    virtual void Update(float DeltaTime) override;
};



