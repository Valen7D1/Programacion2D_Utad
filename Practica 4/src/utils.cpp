#include "utils.h"

#include <iostream>


float Utils::Dot(vec2 a, vec2 b) {
    return a.x * b.x + a.y * b.y;
}


vec2 Utils::Lerp(vec2 CurrentLocation, vec2 TargetLocation, vec2 Speed)
{
    vec2 Direction = (TargetLocation - CurrentLocation);
    float const Distance = Direction.length();
    float const SpeedLength = Speed.length();
    
    if (Distance <= SpeedLength)
    {
        return TargetLocation;
    }
    Direction.Normalize();
    vec2 NewPosition = CurrentLocation + Direction * Speed;
    return NewPosition;
}


float Utils::Lerp(float CurrentRotation, float TargetRotation, float Speed)
{
    return CurrentRotation;
}
