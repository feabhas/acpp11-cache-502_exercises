// AlarmFilter.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <iostream>
#include "AlarmFilter.h"
#include "Pipe.h"

AlarmFilter::AlarmFilter(Alarm::Type remove_this)
: value{ remove_this }
{ }

AlarmFilter::AlarmFilter(Alarm::Type remove_this, Pipe& in, Pipe& out)
: value{ remove_this }, input{ &in }, output{ &out }
{ }

void AlarmFilter::execute()
{
  unsigned count{};
  while (auto alarm = input->pull()) {
    if (alarm->type() != this->value) {
      output->push(*alarm);
    }
    else {
      ++count;
    }
  }
  if (count > 0) {
    std::cout << "<=>Filter: " << count << " alarm";
    std::cout << ((count != 1) ? "s" : "") << "\n\n";
  }
}

void connect(AlarmFilter& filter, Pipe& in, Pipe& out)
{
  filter.input  = &in;
  filter.output = &out;
}
