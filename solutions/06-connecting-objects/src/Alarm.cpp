// Alarm.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include <array>
#include <iostream>

Alarm::Alarm(Type alarm_init) : value{ alarm_init }
{ }

constexpr std::array<const char*, 4> lookup_str{ "invalid",
                                                 "advisory",
                                                 "caution",
                                                 "warning" };

const char* Alarm::as_string() const
{
  return lookup_str[unsigned(value)];
}

Alarm::Type Alarm::type(/* Alarm  const * const this */) const
{
  return value;
}

std::ostream& operator<<(std::ostream& os, Alarm const& alarm)
{
  return os << alarm.as_string();
}

Alarm make_alarm(Alarm::Type type)
{
  return Alarm{ type };
}

void print_alarm(Alarm const& alarm)
{
  std::cout << static_cast<int>(alarm.type()) << ':'
            << alarm.as_string()
            << '\n';
}
