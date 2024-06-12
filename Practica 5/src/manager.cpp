#include "manager.h"

Manager* Manager::instance = nullptr;


Manager* Manager::getInstance() 
{   
    // if not created already then create it
    if (instance == nullptr)
    {
        instance = new Manager();
    }
    return instance;
}

void Manager::SetMousePosition(double _x, double _y)
{
    m_MousePosition.x = static_cast<float>(_x);
    m_MousePosition.y = static_cast<float>(_y);
}
