#pragma once

#include <cstdint>
#include <unordered_map>

namespace rhess 
{

using byte_t = std::uint8_t;
using hash_t = std::uint64_t;
using board_t = std::uint64_t;

using locstr_t = const char [3];
using mapping_t = std::unordered_map<locstr_t, byte_t>;

struct location 
{
  constexpr location (byte_t _x, byte_t _y)
  : x (_x), y (_y)
  {

  }
  byte_t x;
  byte_t y;
};

constexpr byte_t map_location (locstr_t loc)
{
  
  return ('8' - loc[1]) + (loc[0] - 'a') * 8;
}

}
