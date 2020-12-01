#include <iostream>

#include "MotorVehicle.h"
#include "Input.h"

using namespace std;
using namespace util;

int main() {
  cout << "You will repeatedly be asked to enter another vehicle. Simply press "
          "enter to accept or type anything else than yes to exit.";

  for (;;) {
    if (!input_yesno("\nDo you wish to enter another vehicle? [Yes] ", true))
      break;

    cout << "Ok. Please enter the details of the vehicle." << endl;

    auto vehicle = motorVehicleFromStdio();

    if (vehicle) {
      cout << "\nYou have successfully entered all the details for the "
              "vehicle.\n"
           << endl;
      vehicle->print();
    } else {
      cout << "Invalid input." << endl;
    }
  }

  cout << "Bye bye." << endl;
}
