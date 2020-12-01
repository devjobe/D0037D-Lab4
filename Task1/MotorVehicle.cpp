#include <iomanip>
#include <iostream>
#include <vector>

#include "MotorVehicle.h"
#include "Input.h"

using namespace std;
using namespace util;

MotorVehicle::MotorVehicle(Engine engine, Body body, Person owner,
                           float const *tireDiameters, int numberOfTires)
    : engine(engine), body(body), owner(owner), numberOfTires(numberOfTires) {
  this->tireDiameters = new float[numberOfTires];
  ::memcpy(this->tireDiameters, tireDiameters, sizeof(float) * numberOfTires);
}

MotorVehicle::~MotorVehicle() { delete[] this->tireDiameters; }

void printTireDiameters(float const *diameters, int count) {
  cout.precision(4);
  if (count == 1) {
    cout << "The vehicle has a single wheel with a diameter of " << fixed
         << diameters[0] << " (m).\n";
  } else {
    cout << "The vehicle has " << count
         << " wheels and their diameters in meters are ";
    cout << fixed << diameters[0];
    for (int i = 1; i < count - 1; i++) {
      cout << ", " << fixed << diameters[i];
    }
    cout << " and " << fixed << diameters[count - 1] << ".\n";
  }
}

void MotorVehicle::print() const {
  cout << "Motor vehicle data:\n";
  this->engine.print();
  this->body.print();
  this->owner.print();
  printTireDiameters(this->tireDiameters, this->numberOfTires);
  cout << endl;
}


std::optional<std::vector<float>> tireDiametersFromStdio() {

  auto count = in_range({1, {}}, input_i32("Number of tires: "));
  if (!count) {
    return {};
  }
  repeated_input input("Enter diameter in meters for each tire (seperated by "
                       "comma and/or space): ");
  std::vector<float> diameters(static_cast<size_t>(*count), 0.0f);
  for (auto &it : diameters) {
    auto value =
        in_range({std::numeric_limits<float>::epsilon(), {}}, input.f32());
    if (!value) {
      return {};
    }
    it = *value;
  }

  return diameters;
}

std::optional<MotorVehicle> motorVehicleFromStdio() {
  auto engine = engineFromStdio();
  if (!engine)
    return {};
  auto body = bodyFromStdio();
  if (!body)
    return {};
  auto owner = personFromStdio();
  if (!owner)
    return {};

  auto diameters = tireDiametersFromStdio();
  if (!diameters)
    return {};
  auto &vec = *diameters;
  return std::optional<MotorVehicle>{
      std::in_place_t{},           *engine, *body, *owner, vec.data(),
      static_cast<int>(vec.size())};
}