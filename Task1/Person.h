#pragma once

#include <string>
#include "Input.h"

struct Person {
  Person(std::string name, std::string address, bool allowedToDrive);

  void print() const;

  std::string name;
  std::string address;
  bool allowedToDrive;
};


std::optional<Person> personFrom(util::Input& input);