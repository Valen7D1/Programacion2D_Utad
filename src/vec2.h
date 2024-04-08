#pragma once

class vec2
{
public:
	//Variables
	float x;
	float y;

	//Methods
	float Length();
	vec2& VAbs();
	float Dot(const vec2& value) const;
	float Angle(const vec2& other) const;
	float Distance(const vec2& other) const;

	//Operators
	vec2 operator + (const vec2& value);
	vec2& operator += (const vec2& v);
	vec2 operator - (const vec2& value);
	vec2 operator * (const vec2& value);
	vec2 operator * (const float value);
	vec2 operator / (const vec2& value);
	vec2 operator / (const float value);
	bool operator == (const vec2& value);
	bool operator != (const vec2& value);


	//Constructor
	inline vec2(float _x, float _y) :
		x(_x),
		y(_y)
	{}
	inline vec2(void) :
		x(0),
		y(0)
	{}
	inline vec2(float f) :
		x(f),
		y(f)
	{}
};