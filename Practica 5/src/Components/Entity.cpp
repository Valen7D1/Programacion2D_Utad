#include "Entity.h"

#include "sprite.h"
#include "../manager.h"
#include "../utils.h"
#include "collider.h"
#include "movement.h"


Entity::~Entity()
{
     delete m_Sprite;
     delete m_Data;
}

#pragma region FollowCursor

FollowCursor::FollowCursor() : Entity()
{
    EData* BeeData = new EData(vec2(300.f, 300.f), vec2(150.f, 150.f));
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
}

#pragma endregion


#pragma region My_Circle

My_Cursor::My_Cursor()
{
    EData* CircleData = new EData(vec2(300.f, 300.f), vec2(50.f, 50.f));
    ltex_t* CircleTex = Sprite::loadImage("data/circle.png");
    m_Data = CircleData;
    
    m_Sprite = new Sprite(CircleTex, CircleData, 1, 1, 1, Color::White());
    m_Collider = Collider::CreateCollider(CollisionType::COLLISION_CIRCLE, CircleTex, CircleData);
    m_Movement = new MyCursorMovement(this, CircleData);
}

void My_Cursor::Update(float DeltaTime)
{
    m_Movement->Update(DeltaTime);
    m_Sprite->update(DeltaTime);
}

#pragma endregion


#pragma region FollowCursor

StaticEntity::StaticEntity(const char* FileName, CollisionType CollisionType) : Entity()
{
    EData* BeeData = new EData(vec2(300.f, 300.f), vec2(50.f, 50.f));
    ltex_t* BeeTex = Sprite::loadImage(FileName);
    m_Data = BeeData;
    
    m_Sprite = new Sprite(BeeTex, BeeData, 1, 1, 1, Color::White());
    m_Collider = Collider::CreateCollider(CollisionType, BeeTex, BeeData);
}


void StaticEntity::Update(float DeltaTime)
{
    m_Sprite->update(DeltaTime);
}

#pragma endregion