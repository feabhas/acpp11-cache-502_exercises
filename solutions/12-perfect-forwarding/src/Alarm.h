// Alarm.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ALARM_H
#define ALARM_H

#include <string>

class Alarm {
public:
  enum class Type { invalid, advisory, caution, warning };

  Alarm() = default;
  explicit Alarm(Type alarm_init);
  Alarm(Type alarm_init, std::string_view str);

  Alarm(Alarm const& rhs) = delete;
  Alarm& operator=(Alarm const& rhs) = delete;

  Alarm(Alarm&& rhs) noexcept;
  Alarm& operator=(Alarm&& rhs) noexcept;
  friend void swap(Alarm& lhs, Alarm& rhs);

  std::string_view as_string() const;
  Type        type() const;
  std::string_view what() const;

private:
  Type value{ Type::invalid };
  std::string description{};
};

std::ostream& operator<<(std::ostream& os, Alarm const& alarm);
void  print_alarm(Alarm const& alarm);
Alarm make_alarm(Alarm::Type type);

#endif
