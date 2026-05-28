#include <iostream>

using namespace std;

int main()
{
    // Lambda funkcija za maksimum proizvoljnog broja argumenata
    auto max = [](auto prvi, auto... ostali)
    {
        double maksimum = prvi;

        ((maksimum = (ostali > maksimum ? ostali : maksimum)), ...);

        return maksimum;
    };

    cout << max(2.5, 7.8, 4.1) << endl;
    cout << max(1.2, 9.4, 3.3, 12.7, 6.5) << endl;

    return 0;
}
