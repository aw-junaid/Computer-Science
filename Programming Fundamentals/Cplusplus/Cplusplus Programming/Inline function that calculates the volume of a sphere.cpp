#include <iostream>
using namespace std;

// Define the inline function to calculate the volume of a sphere
inline double sphereVolume(double radius)
{
    return (4.0 / 3.0) * 3.14159 * radius * radius * radius;
}

int main()
{
    double radius;
    cout << "Enter the radius of a sphere: ";
    cin >> radius;

    double volume = sphereVolume(radius);
    cout << "The volume of the sphere is: " << volume << endl;

    return 0;
}
