#include "utils.h"


float Utils::Dot(vec2 a, vec2 b) {
    return a.x * b.x + a.y * b.y;
}


vec2 Utils::Lerp(vec2 CurrentLocation, vec2 TargetLocation, vec2 Speed)
{
    vec2 Direction = (TargetLocation - CurrentLocation);
    Direction.Normalize();
    vec2 NewLocation = CurrentLocation + Direction * Speed;
    return NewLocation;
}


float Utils::Lerp(float CurrentRotation, float TargetRotation, float Speed)
{
    return CurrentRotation;
}
