#pragma once

#include <string>
#include <optional>

struct Person {
  Person(std::string name, std::string address, bool allowedToDrive);

  void print() const;

  std::string name;
  std::string address;
  bool allowedToDrive;
};


std::optional<Person> personFromStdio();