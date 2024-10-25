#include <iostream>
using namespace std;

int main() {
  double gallons, liters;

  cout << "Enter the number of gallons: ";
  cin >> gallons;

  liters = gallons * 3.78541;

  cout << gallons << " gallons = " << liters << " liters." << endl;

  return 0;
}
