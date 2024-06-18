#pragma once
#include "../Vec2.h"

enum CollisionType : int;
class Movement;
class Sprite;
class Collider;

struct EData;

class Entity
{
public:
    Entity() = default;
    virtual ~Entity();
    virtual void Update(float DeltaTime) = 0;

    Collider* GetCollider() const { return m_Collider; }
    EData* GetData() const { return m_Data; }
    
    void SetSprite(Sprite* _sprite);
    void SetCollider(Collider* _collider);

    
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
    StaticEntity(const char* FileName, CollisionType CollisionType, vec2 Location, vec2 Size = vec2(100.f, 100.f));
    virtual ~StaticEntity() override = default;
    virtual void Update(float DeltaTime) override;
};