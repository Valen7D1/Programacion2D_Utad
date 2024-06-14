#include "movement.h"

#include "collider.h"
#include "Entity.h"
#include "../manager.h"
#include "../utils.h"


void FollowCursorMovement::Update(float DeltaTime)
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
}

void MyCursorMovement::Update(float DeltaTime)
{
    vec2 const Target = Manager::getInstance()->GetMousePosition();
    m_Data->Location = Target;
}