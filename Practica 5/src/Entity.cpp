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

My_Bee::My_Bee() : Entity()
{
    EData* BeeData = new EData(vec2(300.f, 300.f), vec2(150.f, 150.f));
    
    m_Sprite = new Sprite(Sprite::loadImage("data/bee_anim.png"), BeeData, 8, 1, 8, Color::White());
    m_Data = BeeData;
    m_Collider = new PixelsCollider(BeeData);
}

My_Bee::~My_Bee()
{
     
}


void My_Bee::Update(float DeltaTime)
{
    if (m_Sprite)
    {
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
}
