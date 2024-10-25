#pragma once

#include "core.hpp"
#include <cstddef>
namespace rhess::hash
{

constexpr hash_t djb2 (const char * str)
{
  hash_t hash = 5381;
  unsigned char c;
  while ((c = *str++)) hash = ((hash << 5) + hash) + c;
  return hash;
}

template <std::size_t N>
struct HashLiteral 
{
  consteval HashLiteral (const char (&str)[N])
  {
    Hash = djb2(str);
  }

  hash_t Hash = 0;
};
}
