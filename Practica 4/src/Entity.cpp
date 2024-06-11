#include "Entity.h"

#include "sprite.h"
#include "manager.h"
#include "utils.h"


// Entity::~Entity()
// {
//      delete m_Sprite;
//      delete m_Data;
// }

My_Bee::My_Bee() : Entity()
{
    EData* BeeData = new EData(vec2(300.f, 300.f), vec2(150.f, 150.f));
    
    m_Sprite = new Sprite(Sprite::loadImage("data/bee_anim.png"), BeeData, 8, 1, 8, Color::White());
    m_Data = BeeData;
}

// My_Bee::~My_Bee()
// {
//      
// }


void My_Bee::Update(float DeltaTime)
{
    if (m_Sprite)
    {
        vec2 const Target = Manager::getInstance()->GetMousePosition();
        m_Data->Location = Utils::Lerp(m_Data->Location, Target,  m_MoveSpeed * DeltaTime);
        
        m_Sprite->update(DeltaTime);
    }
}
