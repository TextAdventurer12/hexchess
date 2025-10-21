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
    // create a piece at the position specified on the hexgrid
    Piece(unsigned int type, int q, int r, Hexagon &gridOrigin);
    // converts the (x, y) position of this piece to a (q, r) position snapped to the given Hexagon's grid
    int q(Hexagon &gridOrigin);
    int r(Hexagon &gridOrigin);
    void GridSnap(std::vector<Hexagon> &grid);
    void Draw();
};
