#include "Entity.h"

#include "sprite.h"
#include "manager.h"
#include "utils.h"
#include "collider.h"


Entity::~Entity()
{
     delete m_Sprite;
     delete m_Data;
}

#pragma region MyBee

My_Bee::My_Bee() : Entity()
{
    EData* BeeData = new EData(vec2(300.f, 300.f), vec2(150.f, 150.f));
    ltex_t* BeeTex = Sprite::loadImage("data/bee_anim.png");
    m_Sprite = new Sprite(BeeTex, BeeData, 8, 1, 8, Color::White());
    m_Data = BeeData;
    m_Collider = new PixelsCollider(BeeData);
}


void My_Bee::Update(float DeltaTime)
{
    // movement control
    vec2 const Target = Manager::getInstance()->GetMousePosition();
    vec2 const Speed = m_MoveSpeed * DeltaTime;
    m_Data->Location = Utils::Lerp(m_Data->Location, Target, Speed);

    // direction control (todo: a better direction control for both axis)
    if (m_Data->Location.x < Target.x && m_Data->Scale.x < 0.f)
    {
        m_Data->Scale.x *= -1.f;
        m_RotationTarget *= -1.f;
        m_RotationSpeed *= -1.f;
    }
    if (m_Data->Location.x > Target.x && m_Data->Scale.x > 0.f)
    {
        m_Data->Scale.x *= -1.f;
        m_RotationTarget *= -1.f;
        m_RotationSpeed *= -1.f;
    }
        
    if ( m_Data->Location != Target)
    {
            
        m_Data->Angle = Utils::Lerp(m_Data->Angle, m_RotationTarget, m_RotationSpeed * DeltaTime);
    }
    
    m_Sprite->update(DeltaTime);
    
}

#pragma endregion


#pragma region My_Circle

My_Cursor::My_Cursor()
{
    EData* CircleData = new EData(vec2(300.f, 300.f), vec2(50.f, 50.f));
    ltex_t* CircleTex = Sprite::loadImage("data/circle.png");
    m_Sprite = new Sprite(CircleTex, CircleData, 1, 1, 1, Color::White());
    m_Data = CircleData;
    m_Collider = new CircleCollider(CircleData, CircleTex);
}

void My_Cursor::Update(float DeltaTime)
{
    vec2 const Target = Manager::getInstance()->GetMousePosition();
    m_Data->Location = Target;
    m_Sprite->update(DeltaTime);
}

#pragma endregion