// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

  // -----------------------------------------------------------------------------
// DISCLAIMER:
// Feabhas is furnishing this item "as is". Feabhas does not provide any
// warranty of the item whatsoever, whether express, implied, or statutory,
// including, but not limited to, any warranty of merchantability or fitness
// for a particular purpose or any warranty that the contents of the item will
// be error-free.
// In no respect shall Feabhas incur any liability for any damages, including,
// but limited to, direct, indirect, special, or consequential damages arising
// out of, resulting from, or any way connected to the use of the item, whether
// or not based upon warranty, contract, tort, or otherwise; whether or not
// injury was sustained by persons or property or otherwise; and whether or not
// loss was sustained from, or arose out of, the results of, the item, or any
// services that may be provided by Feabhas.
// -----------------------------------------------------------------------------

#include "Pipe.h"

bool Pipe::push(Alarm&& alarm)
{
    return buffer.add(std::move(alarm));
}

std::optional<Alarm> Pipe::pull()
{
    Alarm alarm{};
    if (buffer.get(alarm)) {
        return alarm;
    }
    return std::nullopt;
}

bool Pipe::is_empty() const
{
    return buffer.is_empty();
}
