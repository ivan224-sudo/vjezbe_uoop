#include <iostream>

using namespace std;

// Template funkcija za maksimum od 3 elementa
template <typename T>
T maksimum(T a, T b, T c)
{
    T max = a;

    if (b > max)
        max = b;

    if (c > max)
        max = c;

    return max;
}

int main()
{
    // int
    int i1 = 5, i2 = 12, i3 = 8;
    cout << "Maksimum (int): "
         << maksimum(i1, i2, i3) << endl;

    // float
    float f1 = 3.5f, f2 = 7.2f, f3 = 6.1f;
    cout << "Maksimum (float): "
         << maksimum(f1, f2, f3) << endl;

    // double
    double d1 = 9.81, d2 = 2.71, d3 = 15.4;
    cout << "Maksimum (double): "
         << maksimum(d1, d2, d3) << endl;

    return 0;
}
