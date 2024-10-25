#include "include/board.hpp"
#include "include/configureation.hpp"
#include "include/core.hpp"
#include "include/piece_moves.hpp"
#include "include/registry.hpp"

#include <cstdlib>
#include <iostream>
#include <raylib.h>
#include <string>

int main (void)
{
  constexpr rhess::piece_registry
  <
  rhess::piece_info<'p', "Pawn">([](rhess::location from, rhess::location to)
  {
    return rhess::moves::y_line_limited(from, to, 1);
  }),
  rhess::piece_info<'b', "Bishop">([](rhess::location from, rhess::location to)
  {
    return rhess::moves::diagonal(from, to);
  }),
  rhess::piece_info<'k', "Knight">([](rhess::location from, rhess::location to)
  {
    return false; //rhess::moves::diagonal(from, to);
  }),
  rhess::piece_info<'r', "Rook">([](rhess::location from, rhess::location to)
  {
    return rhess::moves::x_line(from, to) || rhess::moves::y_line(from, to);
  }),
  rhess::piece_info<'Q', "Queen">([](rhess::location from, rhess::location to)
  {
    return rhess::moves::x_line(from, to) || rhess::moves::y_line(from, to)
    || rhess::moves::diagonal(from, to);
  }),
  rhess::piece_info<'K', "King">([](rhess::location from, rhess::location to)
  {
    return rhess::moves::x_line_limited(from, to, 1) || rhess::moves::y_line_limited(from, to, 1)
    || rhess::moves::diagonal_limited(from, to, 1);
  })
  >
  Registry;

  rhess::placement<
  rhess::default_colors(),
  "rkbQBbkr",
  "pppppppp",
  "        ",
  "        ",
  "        ",
  "        ",
  "pppppppp",
  "rkbQBbkr"
  > Placement;

  rhess::configuration<Registry, Placement> Configuration;

  rhess::board<Configuration> Board;

  InitWindow(800, 800, "Chess");
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);
    for (int x = 0; x < 8; x++)
    {
      for (int y = 0; y < 8; y++)
      {
        if (((x % 2) && !(y % 2)) || ((y % 2) && !(x % 2)))
        {
          DrawRectangle(x * 100, y * 100, 100, 100, BLACK);
        }
        
      }
    }
    DrawFPS(10, 10);
    EndDrawing();
  }
  CloseWindow();

  std::cout << "Mapped `h1` to " << (int)rhess::map_location("h1") << '\n';

}
