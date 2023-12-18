// Generator.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <cstdlib>
#include <iostream>
#include "Generator.h"
#include "Pipe.h"

namespace
{
  Alarm::Type random_alarm()
  {
    return (static_cast<Alarm::Type>((rand() % 3) + 1));
  }
} // namespace

void Generator::execute()
{
  auto num_to_add = (rand() % 3) + 2;
  for (auto i = 0; i < num_to_add; ++i) {
    Alarm alarm{ random_alarm() };
    std::cout << ">>> Generate : " << alarm << '\n';
    output->push(alarm);
  }
  std::cout << '\n';
}

// Different options for binding
//
// Constructor
Generator::Generator(Pipe& pipe) : output{ &pipe } {}

// member function
void Generator::associate(Pipe& Buffer)
{
  output = &Buffer;
}

//  free (friend) function
void associate(Generator& gen, Pipe& Buffer)
{
  gen.output = &Buffer;
}
