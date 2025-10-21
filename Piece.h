#pragma once

#include "raylib.h"
#include "hexagon.h"
#include <vector>

class Piece
{
  public:
    static Texture2D sprites[14];
    enum TYPE
    {
      T_WHITE  = 0b0000,
      T_BLACK  = 0b0001,
      T_PAWN   = 0b0010,
      T_BISHOP = 0b0100,
      T_KNIGHT = 0b0110,
      T_ROOK   = 0b1000,
      T_QUEEN  = 0b1010,
      T_KING   = 0b1100,
    };
    unsigned int type;
    Vector2 pos;
    static constexpr float size = 60.f;

    static void LoadSprites();
    Piece();
    Piece(unsigned int type, Vector2 pos);
    void GridSnap(std::vector<Hexagon> &grid);
    void Draw();
};
