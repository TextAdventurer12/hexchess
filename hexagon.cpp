#include "hexagon.h"

Hexagon::Hexagon() {}


Hexagon::Hexagon(float q, float r, Vector2 origin, float radius, Color col)
{
  this->q = q;
  this->r = r;
  this->origin = origin;
  this->radius = radius;
  this->col = col;
}

Hexagon::Hexagon(float q, float r, Vector2 origin, float radius, Color col, std::string label)
{
  this->q = q;
  this->r = r;
  this->origin = origin;
  this->radius = radius;
  this->col = col;
  this->label = label;
}

Vector2 Hexagon::centerPx()
{
  float outerRad = radius * 2 / sqrt3;
  float x = 3.f/2 * q;
  float y = sqrt3/2 * q + sqrt3 * r;
  x *= outerRad;
  y *= outerRad;
  return (Vector2){x + origin.x, y + origin.y};
}

float Hexagon::s()
{
  return -q - r;
}

void Hexagon::Draw()
{
  DrawPoly(centerPx(), 6, radius * 2 / sqrt3 + 2.f, 0.f, BLACK);
  DrawPoly(centerPx(), 6, radius * 2 / sqrt3, 0.f, col);
  DrawText(label.c_str(), centerPx().x, centerPx().y, 10, BLACK);
}
