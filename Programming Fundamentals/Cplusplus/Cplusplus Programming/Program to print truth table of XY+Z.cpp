#include <iostream>

using namespace std;

int main()
{
    bool x, y, z;

    cout << "X\tY\tZ\tResult\n";

    for(x = 0; x <= 1; x++)
    {
        for(y = 0; y <= 1; y++)
        {
            for(z = 0; z <= 1; z++)
            {
                bool result = x * y + z;
                cout << x << "\t" << y << "\t" << z << "\t" << result << endl;
            }
        }
    }

    return 0;
}
