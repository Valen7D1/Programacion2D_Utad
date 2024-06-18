#include "Entity.h"

#include "sprite.h"
#include "../World.h"
#include "collider.h"
#include "movement.h"
#include "../World.h"


Entity::~Entity()
{
     delete m_Sprite;
     delete m_Data;
}

void Entity::SetSprite(Sprite* _sprite)
{
    delete m_Sprite;
    m_Sprite = _sprite;
}

void Entity::SetCollider(Collider* _collider)
{
    delete m_Collider;
    m_Collider = _collider;
}

#pragma region FollowCursor

FollowCursor::FollowCursor()
{
    EData* BeeData = new EData(vec2(300.f, 300.f), vec2(100.f, 100.f));
    ltex_t* BeeTex = Sprite::loadImage("data/bee_anim.png");
    m_Data = BeeData;
    
    m_Sprite = new Sprite(BeeTex, BeeData, 8, 1, 8, Color::White());
    m_Collider = Collider::CreateCollider(CollisionType::COLLISION_PIXELS, BeeTex, BeeData);
    m_Movement = new FollowCursorMovement(this, BeeData);
}


void FollowCursor::Update(float DeltaTime)
{
    m_Movement->Update(DeltaTime);
    m_Sprite->update(DeltaTime);
    World::GetWorld()->SetCameraLocation(m_Data->Location);
}

#pragma endregion


#pragma region My_Cursor

My_Cursor::My_Cursor()
{
    EData* CursorData = new EData(vec2(300.f, 300.f), vec2(100.f, 100.f));
    ltex_t* CursorTex = Sprite::loadImage("data/circle.png");
    m_Data = CursorData;
    
    m_Sprite = new Sprite(CursorTex, CursorData, 1, 1, 1, Color::White());
    m_Collider = Collider::CreateCollider(CollisionType::COLLISION_CIRCLE, CursorTex, CursorData);
    m_Movement = new MyCursorMovement(this, CursorData);
}

void My_Cursor::Update(float DeltaTime)
{
    m_Movement->Update(DeltaTime);
    m_Sprite->update(DeltaTime);

    bool const HasCollided = m_Collider->CheckCollision();
    m_Sprite->setColor(HasCollided ? Color::Red() : Color::White());
}

#pragma endregion


#pragma region StaticEntity

StaticEntity::StaticEntity(const char* FileName, CollisionType CollisionType, vec2 Location, vec2 Size)
{
    EData* EntityData = new EData(Location, Size);
    ltex_t* EntityTex = Sprite::loadImage(FileName);
    m_Data = EntityData;
    
    m_Sprite = new Sprite(EntityTex, EntityData, 1, 1, 1, Color::White());
    m_Collider = Collider::CreateCollider(CollisionType, EntityTex, EntityData);
}


void StaticEntity::Update(float DeltaTime)
{
    m_Sprite->update(DeltaTime);
}

#pragma endregion