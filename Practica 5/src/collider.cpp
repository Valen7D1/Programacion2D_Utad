#include "collider.h"

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


bool CircleCollider::collides(const Collider& other) const
{
    return false;
}

bool RectCollider::collides(const Collider& other) const
{
    return false;
}

bool PixelsCollider::collides(const Collider& other) const
{
    return false;
}
