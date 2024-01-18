// Alarm.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include <array>
#include <iostream>
#include <cstring>
#include <utility>

Alarm::Alarm(Type alarm_init) : value{ alarm_init }
{ }

Alarm::Alarm(Type alarm_init, char const* str)
: value{ alarm_init }
{
  if (str) {
    description = new char[strlen(str) + 1];
    strcpy(description, str);
  }
}

Alarm::~Alarm()
{
  delete[] description;
}

Alarm::Alarm(Alarm&& rhs) noexcept
:  value { std::exchange(rhs.value, Type::invalid) },
  description { std::exchange(rhs.description, nullptr)  }
{
    std::cout << "Alarm move ctr " << rhs.as_string() << '\n';
}

Alarm& Alarm::operator=(Alarm&& rhs) noexcept
{
  std::cout << "Alarm move = " << rhs.as_string() << '\n';
  swap(*this, rhs);
  return *this;
}

void swap(Alarm& lhs, Alarm& rhs)
{
  using std::swap;
  swap(lhs.value, rhs.value);
  swap(lhs.description, rhs.description);
}

constexpr std::array<const char*, 4> lookup_str{ "invalid",
                                                 "advisory",
                                                 "caution",
                                                 "warning" };

const char* Alarm::as_string() const
{
  return lookup_str[unsigned(value)];
}

Alarm::Type Alarm::type() const
{
  return value;
}

char const* Alarm::what() const
{
  return (description != nullptr ? description : "");
}

std::ostream& operator<<(std::ostream& os, Alarm const& alarm)
{
  return os << alarm.as_string() << " - " << alarm.what();
}

Alarm make_alarm(Alarm::Type type)
{
  return Alarm{ type };
}

void print_alarm(Alarm const& alarm)
{
  std::cout << static_cast<int>(alarm.type()) << ':'
            << alarm.as_string()
            << alarm.what()
            << '\n';
}
