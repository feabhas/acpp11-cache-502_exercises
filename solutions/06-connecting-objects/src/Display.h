// Display.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H

class Pipe;

class Display {
public:
  Display(Pipe& pipe);
  void execute();

private:
  Pipe* input{};
  // friend void connect(Display& display, Pipe& pipe);
};

#endif
