#pragma once
#include "litegfx.h"
#include "Vec2.h"


class Color
{
public:
    Color(float _r, float _g, float _b, float _a = 1.f) :
    r(_r), g(_g), b(_b), a(_a) {}
    
public:
    float getRed() const { return r; }
    float getGreen() const { return g; }
    float getBlue() const { return b; }
    float getAlpha() const { return a; }

    static Color White()    { return Color(1.0f, 1.0f, 1.0f); }
    static Color Black()    { return Color(0.0f, 0.0f, 0.0f); }
    static Color Gray()     { return Color(0.5f, 0.5f, 0.5f); }
    
private:
    float r, g, b, a; 
};


class Sprite
{
    Sprite(ltex_t* tex, float _angle, int hframes, int vframes, int fps, Color _color, vec2 _position):
        m_Texture(tex),
        m_Angle(_angle),
        m_HFrames(hframes),
        m_VFrames(vframes),
        m_FPS(fps),
        m_FrameVSize(m_Texture->height/m_VFrames),
        m_FrameHSize(m_Texture->width/m_HFrames),
        m_color(_color) {}
    
    ~Sprite();

private:
    typedef void (*CallbackFunc)(Sprite&, float);

    CallbackFunc m_callback = nullptr;
    void* m_data = nullptr;
    
    ltex_t* m_Texture = nullptr;
    lblend_t m_Blend = BLEND_ALPHA;
    vec2 m_Position = vec2();
    vec2 m_Scale = vec2(1.f, 1.f);
    vec2 m_Pivot = vec2(0.5f, 0.5f);
    
    float m_Angle = 0.f;

    int m_HFrames = 0;
    int m_VFrames = 0;
    int m_FPS = 1;
    int m_CurrentFrame = 0;

    float m_FrameVSize;
    float m_FrameHSize;
    
    Color m_color = Color::White();
    
public:
    void SetCallback(CallbackFunc _func) { m_callback = _func; }
    void SetUserData(void* _data) { m_data = _data; }
    void* GetUserData() { return m_data; }
    
    void update(float deltaTime);
    void draw() const;

#pragma region Setters/Getters
    // getters
    const ltex_t* getTexture() const { return m_Texture; }
    lblend_t getBlend() const { return m_Blend; }
    const vec2& getPosition() const { return m_Position; }
    float getAngle() const { return m_Angle; }
    const vec2& getScale() const { return m_Scale; }
    const vec2& getPivot() const { return m_Pivot; }
    int getHframes() const { return m_HFrames; }
    int getVframes() const { return m_VFrames; }
    int getFps() const { return m_FPS; }
    int getCurrentFrame() const { return m_CurrentFrame; }
    Color getColor() const { return m_color; }

    // setters
    void setTexture(ltex_t* tex, int hframes = 1, int vframes = 1);
    void setBlend(lblend_t mode) { m_Blend = mode;}
    void setPosition(const vec2& pos) { m_Position = pos; }
    void setAngle(float angle) { m_Angle = angle; }
    void setScale(const vec2& scale) { m_Scale = scale; }
    void setPivot(const vec2& pivot) { m_Pivot = pivot; }
    void setFps(int fps) { m_FPS = fps; }
    void setCurrentFrame(int frame) { m_CurrentFrame = frame; }
    void setColor(Color _color) { m_color = _color; }

#pragma endregion
    
};