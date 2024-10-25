#pragma once

#include "core.hpp"
#include <cstdlib>

namespace rhess::moves 
{

static inline bool x_line (location from, location to)
{
  return from.y == to.y && from.x != to.x;
}

static inline bool y_line (location from, location to)
{
  return from.x == to.x && from.y != to.y;
}

static inline bool x_line_limited (location from, location to, byte_t lim)
{
  return from.y == to.y && from.x != to.x && (to.x - from.x) <= lim;
}

static inline bool y_line_limited (location from, location to, byte_t lim)
{
  return from.x == to.x && from.y != to.y && (to.y - from.y) <= lim;
}

static inline bool diagonal (location from, location to)
{
  return (from.x - to.x) == (from.y - to.y);
}

static inline bool diagonal_limited (location from, location to, byte_t lim)
{
  return (from.x - to.x) == (from.y - to.y) && abs(from.x - to.x) <= lim;
}

}
