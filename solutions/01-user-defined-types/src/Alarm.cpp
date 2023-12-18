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

// invalid, advisory, caution, warning
static const char* lookup_str[] = {
  "invalid",
  "advisory",
  "caution",
  "warning",
};

const char* Alarm::as_string()
{
  return lookup_str[value];
}

Alarm::Type Alarm::type()
{
  return value;
}

std::ostream& operator<<(std::ostream& os, Alarm const& alarm)
{
  os << static_cast<int>(alarm.value);
  // os << static_cast<int>(alarm.type());  // won't compile
  return os;
}
