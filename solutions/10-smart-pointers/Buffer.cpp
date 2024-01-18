// Buffer.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Buffer.h"

bool Buffer::add(std::unique_ptr<Alarm>&& in)
{
  if (num_elems == sz) return false;

  *write_pos = std::move(in);
  ++num_elems;
  ++write_pos;
  if (write_pos == std::end(elems)) write_pos = std::begin(elems);

  return true;
}

bool Buffer::get(std::unique_ptr<Alarm>&  out)
{
  if (num_elems == 0) return false;

  out = std::move(*read_pos);
  --num_elems;
  ++read_pos;
  if (read_pos == std::end(elems)) read_pos = std::begin(elems);

  return true;
}

bool Buffer::is_empty() const
{
  return (num_elems == 0);
}
