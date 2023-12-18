// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include "Buffer.h"
#include <algorithm>
#include <cassert>
#include <iostream>

namespace {
  constexpr std::size_t sz{ 16 };
}

int main()
{
  Alarm a1;                          //
  Alarm a2 {};                       // Value-initialised
  Alarm a3 { Alarm::Type::warning }; // Explicitly initialised

  std::array<Alarm, sz> local {
    Alarm{ Alarm::Type::caution },  Alarm{ Alarm::Type::caution },
    Alarm{ Alarm::Type::advisory }, Alarm{ Alarm::Type::caution },
    Alarm{ Alarm::Type::warning }, // (1)
    Alarm{ Alarm::Type::caution },  Alarm{ Alarm::Type::caution },
    Alarm{ Alarm::Type::advisory }, Alarm{ Alarm::Type::advisory },
    Alarm{ Alarm::Type::caution },  Alarm{ Alarm::Type::warning }, // (2)
    Alarm{ Alarm::Type::caution },  Alarm{ Alarm::Type::warning }, // (3)
    Alarm{ Alarm::Type::caution },  Alarm{ Alarm::Type::warning }, // (4)
    Alarm{ Alarm::Type::caution }
  };

  assert(std::none_of(std::begin(local), std::end(local),
                      [](auto a) {
                        return a.type() == Alarm::Type::invalid;
                      }));

  auto warnings = [](const auto& a) {
    return a.type() == Alarm::Type::warning;
  };

  auto warn_count = std::count_if(std::begin(local), std::end(local),
                                  warnings);
  assert(warn_count == 4);

  auto remove_it = std::remove_if(std::begin(local), std::end(local),
                                   warnings);

  // fill end of array with invalid objects
  std::fill(remove_it,  std::end(local), Alarm{});

  auto count = std::count_if(std::begin(local), std::end(local),
                            warnings);
  assert(count == 0);

  count = std::count_if(std::begin(local), std::end(local),
                        [](const auto& e) {
                          return e.type() == Alarm::Type::invalid;
                        });
  assert(count == 4);

  std::cout << "Completed OK" << '\n';
}
