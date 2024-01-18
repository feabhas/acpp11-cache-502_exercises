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

  constexpr unsigned num_of_strings{ 6 };
  constexpr std::array<const char*, num_of_strings> alarm_strings {
    "Panic!",
    "Run away!",
    "Ignore this alarm.",
    "Oooops!",
    "Things are going horribly wrong.",
    "Please fix immediately."
  };

  const char* random_string()
  {
    return (alarm_strings[static_cast<size_t>(rand()) % alarm_strings.size()]);
  }
} // namespace

void Generator::execute()
{
  auto num_to_add = (rand() % 3) + 2;
  for (auto i = 0; i < num_to_add; ++i) {
    auto alarm = std::make_unique<Alarm>(random_alarm(), random_string());
    std::cout << ">>> Generate : " << *alarm << '\n';
    output->push(std::move(alarm));
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
