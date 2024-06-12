#include "collider.h"

#include "manager.h"


#pragma region AllColliders

bool Collider::checkCircleCircle(const vec2& pos1, float radius1, const vec2& pos2, float radius2)
{
    return false;
}

bool Collider::checkCircleRect(const vec2& circlePos, float circleRadius, const vec2& rectPos, const vec2& rectSize)
{
    return false;
}

bool Collider::checkRectRect(const vec2& rectPos1, const vec2& rectSize1, const vec2& rectPos2, const vec2& rectSize2)
{
    return false;
}

bool Collider::checkCirclePixels(const vec2& circlePos, float circleRadius, const vec2& pixelsPos,
    const vec2& pixelsSize, const uint8_t* pixels)
{
    return false;
}

bool Collider::checkPixelsPixels(const vec2& pixelsPos1, const vec2& pixelsSize1, const uint8_t* pixels1,
    const vec2& pixelsPos2, const vec2& pixelsSize2, const uint8_t* pixels2)
{
    return false;
}

bool Collider::checkPixelsRect(const vec2& pixelsPos, const vec2& pixelsSize, const uint8_t* pixels,
    const vec2& rectPos, const vec2& rectSize)
{
    return false;
}

#pragma endregion


#pragma region CircleCollider


CircleCollider::CircleCollider(EData* _data, ltex_t* _tex) : Collider(_data, CollisionType::COLLISION_CIRCLE)
{
    if (_tex->height > _tex->width)
    {
        m_Radius = static_cast<float>(_tex->height);
    }
    else
    {
        m_Radius = static_cast<float>(_tex->width);
    }
}

bool CircleCollider::collides(const Collider& other)
{
    return false;
}

bool CircleCollider::collides(const vec2& circlePos, float circleRadius)
{
    return checkCircleCircle(m_Data->Location, m_Radius, circlePos, circleRadius);
}

bool CircleCollider::collides(const vec2& rectPos, const vec2& rectSize)
{
    return checkCircleRect(m_Data->Location, m_Radius, rectPos, rectSize);
}

bool CircleCollider::collides(const vec2& pixelsPos, const vec2& pixelsSize, const uint8_t* pixels)
{
    return checkCirclePixels(m_Data->Location, m_Radius, pixelsPos, pixelsSize, pixels);
}

#pragma endregion


#pragma region RectangleCollider

bool RectCollider::collides(const Collider& other)
{
    return false;
}

bool RectCollider::collides(const vec2& circlePos, float circleRadius)
{
    return checkCircleRect(circlePos, circleRadius, m_Data->Location, m_RectSize);
}

bool RectCollider::collides(const vec2& rectPos, const vec2& rectSize)
{
    return checkRectRect(rectPos, rectSize, m_Data->Location, m_RectSize);
}

bool RectCollider::collides(const vec2& pixelsPos, const vec2& pixelsSize, const uint8_t* pixels)
{
    return checkPixelsRect(pixelsPos, pixelsSize, pixels, m_Data->Location, m_RectSize);
}

#pragma endregion


#pragma region PixelsCollider

bool PixelsCollider::collides(const vec2& circlePos, float circleRadius)
{
    return false; //checkCirclePixels();
}

bool PixelsCollider::collides(const vec2& rectPos, const vec2& rectSize)
{
    return false; //checkPixelsRect();
}

bool PixelsCollider::collides(const vec2& pixelsPos, const vec2& pixelsSize, const uint8_t* pixels)
{
    return false; //checkPixelsPixels();
}

bool PixelsCollider::collides(const Collider& other)
{
    return false;
}

#pragma endregion