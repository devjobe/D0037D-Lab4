#include <iostream>
#include <iomanip>

#include "Person.h"

using namespace std;
using namespace util;


Person::Person(std::string name, std::string address, bool allowedToDrive)
    : name(name), address(address), allowedToDrive(allowedToDrive) {}

void Person::print() const {
  cout << "The vehicle is registered to " << this->name << " at the address "
       << this->address << ".\n";
  cout << (this->allowedToDrive ? "The owner is allowed to drive.\n"
                                : "The owner is not allowed to drive.\n");
}

std::optional<Person> personFrom(util::Input& input) {
  auto name = input.prompt("Owner: ").line();
  if (!name.size()) {
    return {};
  }
  auto address = input.prompt("Owner address: ").line();
  if (!address.size()) {
    return {};
  }

  auto allowedToDrive = input.prompt("Licenced driver (yes/no): ").only<bool>();
  if (!allowedToDrive.has_value()) {
    return {};
  }
  return Person{std::move(name), std::move(address), *allowedToDrive};
}
