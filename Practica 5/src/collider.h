#pragma once
#include <cstdint>

#include "vec2.h"

class EData;


enum CollisionType {
    COLLISION_NONE,
    COLLISION_CIRCLE,
    COLLISION_RECT,
    COLLISION_PIXELS
};

class Collider
{
public:
    Collider(EData* _data, CollisionType _type) :
        m_Data(_data), m_CollisionType(_type){}
    virtual ~Collider() = default;
    
protected:
    EData* m_Data = nullptr;
    CollisionType m_CollisionType = COLLISION_NONE;

protected:
    bool checkCircleCircle(const vec2& pos1, float radius1, const vec2& pos2, float radius2);
    bool checkCircleRect(const vec2& circlePos, float circleRadius, const vec2& rectPos, const vec2& rectSize);
    bool checkRectRect(const vec2& rectPos1, const vec2& rectSize1, const vec2& rectPos2, const vec2& rectSize2);
    bool checkCirclePixels(const vec2& circlePos, float circleRadius, const vec2& pixelsPos, const vec2& pixelsSize, const uint8_t* pixels);
    bool checkPixelsPixels( const vec2& pixelsPos1, const vec2& pixelsSize1, const
    uint8_t* pixels1, const vec2& pixelsPos2, const vec2& pixelsSize2, const uint8_t* pixels2);
    bool checkPixelsRect( const vec2& pixelsPos, const vec2& pixelsSize, const uint8_t* pixels, const vec2& rectPos, const vec2& rectSize);
    
    virtual bool collides(const Collider& other) const = 0;
};

class CircleCollider : public Collider
{
public:
    CircleCollider(EData* _data) : Collider(_data, CollisionType::COLLISION_CIRCLE) {}
    ~CircleCollider() override = default;
    
    virtual bool collides(const Collider& other) const override;
};

class RectCollider  : public Collider
{
public:
    RectCollider (EData* _data) : Collider(_data, CollisionType::COLLISION_RECT) {}
    ~RectCollider () override = default;

    virtual bool collides(const Collider& other) const override;
};


class PixelsCollider : public Collider
{
public:
    PixelsCollider(EData* _data) : Collider(_data, CollisionType::COLLISION_PIXELS) {}
    ~PixelsCollider() override = default;

    virtual bool collides(const Collider& other) const override;
};


