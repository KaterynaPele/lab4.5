#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    double x, y;
    double R;
    cout << "R = ";
    cin >> R;

    srand((unsigned)time(NULL));

    // --- 1 спосіб: введення 10 точок ---
    for (int i = 0; i < 10; i++)
    {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        if ((x >= 0 && x <= 2 * R && y >= R && y <= 2 * R) ||       // квадрат
            (x >= -2 * R && x <= 0 && y >= -2 * R && y <= x) ||     // трикутник
            (x >= 0 && y >= 0 && x * x + y * y <= R * R))             // чверть кола
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    cout << endl << fixed;

    // --- 2 спосіб: випадкові 10 точок ---
    for (int i = 0; i < 10; i++)
    {
        x = 4 * R * rand() / RAND_MAX - 2 * R;   // [-2R; 2R]
        y = 4 * R * rand() / RAND_MAX - 2 * R;   // [-2R; 2R]

        if ((x >= 0 && x <= 2 * R && y >= R && y <= 2 * R) ||       // квадрат
            (x >= -2 * R && x <= 0 && y >= -2 * R && y <= x) ||     // трикутник
            (x >= 0 && y >= 0 && x * x + y * y <= R * R))             // чверть кола
            cout << setw(8) << setprecision(4) << x << " "
            << setw(8) << setprecision(4) << y << " yes" << endl;
        else
            cout << setw(8) << setprecision(4) << x << " "
            << setw(8) << setprecision(4) << y << " no" << endl;
    }
    return 0;
}
