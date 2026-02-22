#include <iostream>
using namespace std;

int main()
{
    float t;
    char u;

    cout << "Enter the temperature and unit (C/F): ";
    cin >> t >> u;

    if (u == 'C' || u == 'c')
    {
        float f = (1.8 * t) + 32;
        cout << "Temperature in Fahrenheit = " << f << endl;
    }
    else if (u == 'F' || u == 'f')
    {
        float c = (t - 32) * 5 / 9;
        cout << "Temperature in Celsius = " << c << endl;
    }
    else
    {
        cout << "Invalid unit! Please enter C or F." << endl;
    }

    return 0;
}
