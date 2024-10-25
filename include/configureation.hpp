#pragma once

#include "core.hpp"
#include "registry.hpp"
#include <algorithm>
#include <array>

namespace rhess 
{

struct LineLiteral 
{
  consteval LineLiteral (const char (&str)[9])
  {
      std::copy_n(str, 8, CString);
  }

  char CString [9] = {};
};

static inline constexpr board_t default_colors ()
{
  return 0b1111'1111'1111'1111'0000'0000'0000'0000;
} 

template <board_t Colors, LineLiteral... Literals>
class placement 
{
using placement_initializer_t = std::array<const char *, 9>;

public:
  consteval placement ()
  {
    static_assert(sizeof...(Literals) == 8, "A placement definition must be 8 strings of 8+null terminator each");
  }

  constexpr auto raw_placements() const noexcept
  {
    return Placements;
  }

  constexpr std::array<char, 64> data () const noexcept 
  {
    std::array<char, 64> retval;
    placement_initializer_t plac = raw_placements();
    for (byte_t i = 0; i < 8; i++)
    {
      for (byte_t j = 0; j < 8; j++)
      {
        retval[i * 8 + j] = plac[i][j];
      }
    }
    return retval;
  }

private:
  static constexpr placement_initializer_t Placements = {{Literals.CString...}};
};

template <piece_registry TRegistry, placement TPlacement>
class configuration
{

public:
  constexpr auto registry () const noexcept
  {
    return Registry;
  }

  constexpr auto placement () const noexcept
  {
    return Placement;
  }

private:
  static constexpr auto Registry = TRegistry;
  static constexpr auto Placement = TPlacement;
};

}
