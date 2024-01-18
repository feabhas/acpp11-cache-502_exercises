// Generator.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H

#include "Filter.h"

class Pipe;

class Generator : public Filter {
public:
  Generator(Pipe& pipe);
  ~Generator() override = default;
  void associate( Pipe& pipe);

protected:
  void execute() override;

private:
  Pipe* output{};
  friend void associate(Generator& gen, Pipe& pipe);
};

#endif
