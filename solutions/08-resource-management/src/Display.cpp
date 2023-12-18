// Display.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <iostream>
#include "Display.h"
#include "Pipe.h"

Display::Display(Pipe& pipe) : input{ &pipe } {}

void Display::execute()
{
  if (input->is_empty()) return;

  while (auto alarm = input->pull()) {
    std::cout << "<<< Display: " << *alarm << '\n';
  }
  std::cout << '\n';
}

// void connect(Display& display, Pipe& pipe)
// {
//   display.input = &pipe;
// }
