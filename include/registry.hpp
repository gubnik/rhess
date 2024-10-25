#pragma once

#include "core.hpp"
#include "hash.hpp"
#include <array>
#include <cstddef>

namespace rhess
{

template <size_t N>
using pieces_t = std::array<char, N>;

using move_f = bool(*)(location, location);

template <size_t N>
using moves_t = std::array<move_f, N>;

template <char C, hash::HashLiteral Literal>
struct piece_info
{
public:
  constexpr piece_info (move_f&& MoveLambda)
  : MoveF(MoveLambda)
  {
    
  }

  constexpr char as_char() const noexcept 
  {
    return DisplayCharacter;
  }

  static constexpr char DisplayCharacter = C;
  move_f MoveF;
};

template <piece_info... Information>
class piece_registry 
{
public:
  constexpr std::size_t size() const noexcept 
  {
    return Size;
  }

  constexpr auto& moves() const noexcept 
  {
    return Moves;
  }

  constexpr char at_id(byte_t id) const noexcept
  {
    if (id >= Size) return 0;
    return Pieces[id];
  }

  constexpr bool is_present (char c)
  {
    for (const auto& it : Pieces) if (c == it ) return true;
    return false;
  }

private:
  static constexpr std::size_t Size = sizeof...(Information);
  static constexpr pieces_t<Size> Pieces = {{Information.as_char()...}};
  static constexpr moves_t<Size> Moves = {{Information.MoveF...}};
};

}
