// Alarm.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include <iostream>

Alarm::Alarm()
{
  std::clog << "Alarm default ctor\n";
}

Alarm::Alarm(Type alarm_init) : value{ alarm_init }
{
  std::clog << "Alarm non-default ctor\n";
}

Alarm::~Alarm()
{
  std::clog << "Alarm dtor\n";
}

static const char* lookup_str[] = { "invalid",
                                    "advisory",
                                    "caution",
                                    "warning" };

const char* Alarm::as_string() const
{
  return lookup_str[value];
}

Alarm::Type Alarm::type() const
{
  return value;
}

std::ostream& operator<<(std::ostream& os, Alarm const& alarm)
{
  return os << static_cast<int>(alarm.type());
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
