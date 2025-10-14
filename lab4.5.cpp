#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    double x, y, R;
    cout << "Введіть R: ";
    cin >> R;

    srand((unsigned)time(NULL));

    cout << "\n=== 1 спосіб: введення 10 точок вручну ===\n";
    for (int i = 0; i < 10; i++) {
        cout << "\nТочка №" << i + 1 << endl;
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        bool hit = false;

        // 1) Верхній правий квадрат
        if (x >= 0 && x <= 2 * R && y >= R && y <= 2 * R)
            hit = true;

        // 2) Нижній лівий трикутник
        if (x >= -2 * R && x <= 0 && y >= -2 * R && y <= x)
            hit = true;

        // 3) Чверть кола (1 чверть)
        if (x >= 0 && y >= 0 && x * x + y * y <= R * R)
            hit = true;

        if (hit)
            cout << "→ Потрапляє в область!" << endl;
        else
            cout << "→ Не потрапляє." << endl;
    }

    cout << "\n=== 2 спосіб: випадкові 10 точок (x, y ∈ [-2R; 2R]) ===\n";
    for (int i = 0; i < 10; i++) {
        // Генерація випадкових координат у межах [-2R; 2R]
        x = (double)rand() / RAND_MAX * (4 * R) - 2 * R;
        y = (double)rand() / RAND_MAX * (4 * R) - 2 * R;

        bool hit = false;

        if (x >= 0 && x <= 2 * R && y >= R && y <= 2 * R)
            hit = true;

        if (x >= -2 * R && x <= 0 && y >= -2 * R && y <= x)
            hit = true;

        if (x >= 0 && y >= 0 && x * x + y * y <= R * R)
            hit = true;

        cout << setw(8) << fixed << setprecision(3) << x << " "
            << setw(8) << fixed << setprecision(3) << y << " "
            << (hit ? "→ Потрапляє" : "→ Мимо") << endl;
    }

    return 0;
}