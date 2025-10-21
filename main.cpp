#include "raylib.h"
#include "hexagon.h"
#include "Piece.h"
#include <stdlib.h>
#include <math.h>
#include <sstream>

int main()
{
  const int width = 1920;
  const int height = 1080;
  
  InitWindow(width, height, "Hex-Chess");
  Piece::LoadSprites();

  std::vector<Hexagon> board;
  Color palette[3] = {WHITE, LIGHTGRAY, DARKGRAY};
  float size = 80.f;
  float boardWidth = 11 * size;
  Piece p = Piece(Piece::T_WHITE | Piece::T_KNIGHT, (Vector2){600, 400});

  float leftBorder = (width - boardWidth) / 2;
  float topBorder = (height - boardWidth) / 2;

  // for (int i = 0; i < 11; i++)
  // {
  //   float x1 = leftBorder + fmax(0.f, i - 5) * size * Hexagon::sqrt3 / 2;
  //   float y1 = topBorder + size / 2 * 6 + (i < 6 ? i * size : 6 * size + (i-7) * size / 2); 
  //   for (int j = 0; j < 11 - abs(i - 5); j++)
  //   {
  //     float x = x1 + size * Hexagon::sqrt3 / 2 * j;
  //     float y = y1 - size / 2 * j;
  //     int c_ind = (y - topBorder) / (size / 4) + 1;
  //     board.push_back( Hexagon((Vector2){x, y}, size / 2, palette[c_ind % 3]));
  //   }
  // }

  int c_ind = 0;
  Vector2 origin = {leftBorder, 0};
  for (int q = 0; q < 11; q++)
  {
    c_ind = q <= 5 ? q % 3 : (10 - q) % 3;
    for (int r = std::max(0, 5 - q); r <= (q <= 5 ? 10 : 15 - q); r++)
    {
      board.push_back(Hexagon(q, r, origin, size / 2, palette[c_ind % 3]));
      c_ind++;
    }
  }

  while (!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(DARKGREEN);
      for (int i = 0; i < 91; i++)
        board[i].Draw();
      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && CheckCollisionCircles(p.pos, p.size / 2, GetMousePosition(), 2.f))
        p.pos = GetMousePosition();
      else p.GridSnap(board);
      p.Draw();
    EndDrawing();
  }
}
