
#include "vec2.h"
#include <cmath>

//x * value.y - value.x * y
float vec2::Length()
{
	return sqrt((x * x) + (y * y));
}

vec2& vec2::VAbs()
{
	x = abs(x);
	y = abs(y);
	return *this;
}

float vec2::Dot(const vec2& value) const
{
	return x * value.x + y * value.y;
}

vec2 vec2::operator+(const vec2& value)
{
	return vec2(x + value.x, y + value.y);
}

vec2& vec2::operator+=(const vec2& v)
{
	x += v.x;  y += v.y;
	return *this;
}

vec2 vec2::operator-(const vec2& value)
{
	return vec2(x - value.x, y - value.y);
}

vec2 vec2::operator*(const vec2& value)
{
	return vec2(x * value.x, y * value.y);
}

vec2 vec2::operator*(const float value)
{
	return vec2(x * value, y * value);
}

vec2 vec2::operator/(const vec2& value)
{
	return vec2(x / value.x, y / value.y);
}

vec2 vec2::operator/(const float value)
{
	return vec2(x / value, y / value);
}

bool vec2::operator==(const vec2& value)
{
	return  x == value.x && y == value.y;
}

bool vec2::operator!=(const vec2& value)
{
	return x != value.x || y != value.y;
}
