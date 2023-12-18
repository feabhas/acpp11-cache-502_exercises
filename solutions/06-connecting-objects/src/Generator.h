// Generator.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H

class Pipe;

class Generator {
public:
  Generator(Pipe& pipe);
  void execute();
  void associate( Pipe& pipe);
private:
  Pipe* output{};
  friend void associate(Generator& gen, Pipe& pipe);
};

#endif
