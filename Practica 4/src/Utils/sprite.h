#pragma once
#include "litegfx.h"
#include "Vec2.h"


class Color
{
public:
    Color(float _r, float _g, float _b, float _a) :
    r(_r), g(_g), b(_b), a(_a) {}
    
public:
    float getRed() const { return r; }
    float getGreen() const { return g; }
    float getBlue() const { return b; }
    float getAlpha() const { return a; }
    
private:
    float r, g, b, a; 
};


class Sprite
{
    Sprite(ltex_t* tex, float _angle = 0.f, int hframes = 1, int vframes = 1, int fps = 1, Color _color, vec2 _position):
        m_Texture(tex),
        m_Angle(_angle),
        m_HFrames(hframes),
        m_VFrames(vframes),
        m_FPS(fps),
        m_color(_color) {}

    ~Sprite();

private:
    ltex_t* m_Texture;
    lblend_t m_Blend = BLEND_ALPHA;
    vec2 m_Position;
    vec2 m_Scale;
    vec2 m_Pivot = vec2(0.5f, 0.5f);
    
    float m_Angle;

    int m_HFrames;
    int m_VFrames;
    int m_FPS;
    int m_CurrentFrame = 0;
    
    Color m_color;
    
public:
    // typedef void (* CallbackFunc)(Sprite&, float);
    // void setCallback(CallbackFunc func);
    // void* getUserData();

#pragma region Setters/Getters
    const ltex_t* getTexture() const { return m_Texture; }
    void setTexture(ltex_t* tex, int hframes = 1, int vframes = 1)
    {
        m_Texture = tex; m_HFrames = hframes; m_VFrames = vframes;
    }
    
    lblend_t getBlend() const { return m_Blend; }
    void setBlend(lblend_t mode) { m_Blend = mode;}
    
    const vec2& getPosition() const { return m_Position; }
    void setPosition(const vec2& pos) { m_Position = pos; }
    
    float getAngle() const { return m_Angle; }
    void setAngle(float angle) { m_Angle = angle; }

    const vec2& getScale() const { return m_Scale; }
    void setScale(const vec2& scale) { m_Scale = scale; }

    const vec2& getPivot() const { return m_Pivot; }
    void setPivot(const vec2& pivot) { m_Pivot = pivot; }

    int getHframes() const { return m_HFrames; }
    int getVframes() const { return m_VFrames; }

    int getFps() const { return m_FPS; }
    void setFps(int fps) { m_FPS = fps; }

    int getCurrentFrame() const { return m_CurrentFrame; }
    void setCurrentFrame(int frame) { m_CurrentFrame = frame; }

    Color getColor() const { return m_color; }
    void setColor(Color _color) { m_color = _color; }

    
    void update(float deltaTime);
    void draw() const;

#pragma endregion
    
};