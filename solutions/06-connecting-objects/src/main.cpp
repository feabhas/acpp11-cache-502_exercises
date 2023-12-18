// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <iostream>
#include "Pipe.h"
#include "Display.h"
#include "Generator.h"
#include "AlarmFilter.h"

int main()
{
  Pipe        pipe1{};
  Pipe        pipe2{};
  Generator   generator{ pipe1 }; // associate by construction
  // generator.associate(pipe1);  // associate by member function
  // associate(generator, pipe1); // associate by free (friend) function
  AlarmFilter filter{ Alarm::Type::warning, pipe1, pipe2 };
  Display     display{ pipe2 };

  for (auto i = 0; i < 3; ++i) {
    generator.execute();
    filter.execute();
    display.execute();
  }

  std::cout << "Completed OK" << '\n';
}

