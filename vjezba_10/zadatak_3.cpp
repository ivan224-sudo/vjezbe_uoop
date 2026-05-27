#include <iostream>
#include <cstdarg>

using namespace std;

// Funkcija koja prima promjenjiv broj argumenata
double max(int count, ...)
{
    va_list args;
    va_start(args, count);

    double maksimum = va_arg(args, double);

    for (int i = 1; i < count; i++)
    {
        double broj = va_arg(args, double);

        if (broj > maksimum)
        {
            maksimum = broj;
        }
    }

    va_end(args);

    return maksimum;
}

int main()
{
    cout << max(3, 2.5, 7.8, 4.1) << endl;
    cout << max(5, 1.2, 9.4, 3.3, 12.7, 6.5) << endl;

    return 0;
}
