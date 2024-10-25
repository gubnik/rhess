#pragma once

#include "configureation.hpp"
#include "core.hpp"
namespace rhess 
{

template<size_t N>
using board_data_t = std::array<board_t, N>;

template <configuration Configuration>
class board
{
public:
  board ()
  {

  }

private:
  board_t m_WData;
  board_t m_BData;
  board_data_t<Configuration.registry().size()> m_PiecesData;
};

}
