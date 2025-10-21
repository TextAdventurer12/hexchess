#pragma once

#include "raylib.h"
#include <string>

class Hexagon
{
  public:
    float q;
    float r;
    float radius;
    Vector2 origin;
    Color col;
    std::string label;
    static constexpr float sqrt3 = 1.73205080757;

    Hexagon();
    Hexagon(float q, float r, Vector2 origin, float radius, Color col);
    Hexagon(float q, float r, Vector2 origin, float radius, Color col, std::string label);
    Vector2 centerPx();
    float s();
    void Draw();
};
