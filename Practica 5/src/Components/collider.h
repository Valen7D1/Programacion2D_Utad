#pragma once
#include <cstdint>

#include "../vec2.h"
#include "litegfx.h"

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

    static Collider* CreateCollider(CollisionType _type, ltex_t* _tex, EData* _data);
    
protected:
    EData* m_Data = nullptr;
    CollisionType m_CollisionType = COLLISION_NONE;

protected:
    bool checkCircleCircle(const vec2& pos1, float radius1, const vec2& pos2, float radius2);
    bool checkCircleRect(const vec2& circlePos, float circleRadius, const vec2& rectPos, const vec2& rectSize);
    bool checkRectRect(const vec2& rectPos1, const vec2& rectSize1, const vec2& rectPos2, const vec2& rectSize2);
    bool checkCirclePixels(const vec2& circlePos, float circleRadius, const vec2& pixelsPos, const vec2& pixelsSize, const uint8_t* pixels);
    bool checkPixelsPixels( const vec2& pixelsPos1, const vec2& pixelsSize1, const uint8_t* pixels1, const vec2& pixelsPos2, const vec2& pixelsSize2, const uint8_t* pixels2);
    bool checkPixelsRect( const vec2& pixelsPos, const vec2& pixelsSize, const uint8_t* pixels, const vec2& rectPos, const vec2& rectSize);
    
    virtual bool collides(const Collider& other) = 0;
    virtual bool collides(const vec2& circlePos, float circleRadius) = 0;
    virtual bool collides(const vec2& rectPos, const vec2& rectSize) = 0;
    virtual bool collides(const vec2& pixelsPos, const vec2& pixelsSize, const uint8_t* pixels) = 0;

public:
    void setCollisionType (CollisionType _type) { m_CollisionType = _type; }
    CollisionType getCollisionType () const { return m_CollisionType; }
    const Collider* getCollider () const { return this; }
};

class CircleCollider : public Collider
{
public:
    CircleCollider(EData* _data, ltex_t* _tex);
    ~CircleCollider() override = default;
    
    virtual bool collides(const Collider& other) override;
    virtual bool collides(const vec2& circlePos, float circleRadius) override;
    virtual bool collides(const vec2& rectPos, const vec2& rectSize) override;
    virtual bool collides(const vec2& pixelsPos, const vec2& pixelsSize, const uint8_t* pixels) override;

public:
    float m_Radius;
    
};

class RectCollider  : public Collider
{
public:
    RectCollider (EData* _data, ltex_t* _tex) : Collider(_data, COLLISION_RECT) {}
    ~RectCollider () override = default;

    virtual bool collides(const Collider& other) override;
    virtual bool collides(const vec2& circlePos, float circleRadius) override;
    virtual bool collides(const vec2& rectPos, const vec2& rectSize) override;
    virtual bool collides(const vec2& pixelsPos, const vec2& pixelsSize, const uint8_t* pixels) override;

public:
    vec2 m_RectSize;
};


class PixelsCollider : public Collider
{
public:
    PixelsCollider(EData* _data, ltex_t* _tex) : Collider(_data, COLLISION_PIXELS) {}
    ~PixelsCollider() override = default;

    virtual bool collides(const Collider& other) override;
    virtual bool collides(const vec2& circlePos, float circleRadius) override;
    virtual bool collides(const vec2& rectPos, const vec2& rectSize) override;
    virtual bool collides(const vec2& pixelsPos, const vec2& pixelsSize, const uint8_t* pixels) override;
};


