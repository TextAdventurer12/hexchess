#include "Piece.h"

Texture2D Piece::sprites[14]; 

void Piece::LoadSprites()
{
  sprites[T_WHITE | T_PAWN  ] = LoadTextureFromImage(LoadImage("Pieces/pawnWhite.png"));
  sprites[T_WHITE | T_BISHOP] = LoadTextureFromImage(LoadImage("Pieces/bishopWhite.png"));
  sprites[T_WHITE | T_KNIGHT] = LoadTextureFromImage(LoadImage("Pieces/knightWhite.png"));
  sprites[T_WHITE | T_ROOK  ] = LoadTextureFromImage(LoadImage("Pieces/rookWhite.png"));
  sprites[T_WHITE | T_QUEEN ] = LoadTextureFromImage(LoadImage("Pieces/queenWhite.png"));
  sprites[T_WHITE | T_KING  ] = LoadTextureFromImage(LoadImage("Pieces/kingWhite.png"));

  sprites[T_BLACK | T_PAWN  ] = LoadTextureFromImage(LoadImage("Pieces/pawnBlack.png"));
  sprites[T_BLACK | T_BISHOP] = LoadTextureFromImage(LoadImage("Pieces/bishopBlack.png"));
  sprites[T_BLACK | T_KNIGHT] = LoadTextureFromImage(LoadImage("Pieces/knightBlack.png"));
  sprites[T_BLACK | T_ROOK  ] = LoadTextureFromImage(LoadImage("Pieces/rookBlack.png"));
  sprites[T_BLACK | T_QUEEN ] = LoadTextureFromImage(LoadImage("Pieces/queenBlack.png"));
  sprites[T_BLACK | T_KING  ] = LoadTextureFromImage(LoadImage("Pieces/kingBlack.png"));
  for (Texture2D &tex : sprites)
  {
    tex.height = size;
    tex.width = size;
  }
}

Piece::Piece() {}

Piece::Piece(unsigned int type, Vector2 pos)
{
  this->type = type;
  this->pos = pos;
}


void Piece::Draw()
{
  DrawCircle(pos.x, pos.y, size / 2 + 2.f, BLACK);
  DrawCircle(pos.x, pos.y, size/2, WHITE);
  DrawTexture(sprites[type], pos.x - size/2, pos.y - size/2, WHITE);
}

void Piece::GridSnap(std::vector<Hexagon> &grid)
{
  // minimum distance squared to a hexagon
  float min2 = 1.f / 0.f;
  Vector2 nearest;
  for (int i = 0; i < grid.size(); i++)
  {
    float d2 = (pos.x - grid[i].centerPx().x) * (pos.x - grid[i].centerPx().x) + (pos.y - grid[i].centerPx().y) * (pos.y - grid[i].centerPx().y);
    min2 = std::min(min2, d2);
    if (min2 == d2) nearest = grid[i].centerPx();
  }
  pos = nearest;
}

Piece::Piece(unsigned int type, int q, int r, Hexagon &gridOrigin)
{
  this->type = type;
  Hexagon base = Hexagon(q, r, gridOrigin.origin, gridOrigin.radius, BLANK);
  this->pos = base.centerPx();
}

