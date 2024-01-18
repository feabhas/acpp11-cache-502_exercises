// Display.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H

#include "Filter.h"

class Pipe;

class Display : public Filter {
public:
  Display(Pipe& pipe);
  ~Display() override = default;

protected:
  void execute() override;

private:
  Pipe* input{};
  // friend void connect(Display& display, Pipe& pipe);
};

#endif
