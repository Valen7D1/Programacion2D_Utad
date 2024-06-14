#pragma once
#include "../Vec2.h"

enum CollisionType : int;
class Movement;
class Sprite;
class EData;
class Collider;

class Entity
{
public:
    Entity() = default;
    virtual ~Entity();
    virtual void Update(float DeltaTime) = 0;

    Collider* GetCollider() const { return m_Collider; }
    
protected:
    Sprite* m_Sprite = nullptr;
    Collider* m_Collider = nullptr;
    
    EData* m_Data = nullptr;
    
};


class FollowCursor : public Entity
{
public:
    FollowCursor();
    virtual ~FollowCursor() override = default;
    virtual void Update(float DeltaTime) override;
    
public:
    Movement* m_Movement = nullptr;
};


class My_Cursor : public Entity
{
public:
    My_Cursor();
    virtual ~My_Cursor() override = default;
    virtual void Update(float DeltaTime) override;

public:
    Movement* m_Movement = nullptr;
};


class StaticEntity : public Entity
{
public:
    StaticEntity(const char* FileName, CollisionType CollisionType);
    virtual ~StaticEntity() override = default;
    virtual void Update(float DeltaTime) override;
};