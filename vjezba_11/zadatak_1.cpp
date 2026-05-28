#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> brojevi;
    int x;

    // Unos do Ctrl+Z (Windows)
    while (cin >> x)
    {
        brojevi.push_back(x);
    }

    // Sortiranje pomoću lambda izraza
    sort(brojevi.begin(), brojevi.end(),
        [](int a, int b)
        {
            // Ako je a neparan, a b paran -> a ide prije b
            if (a % 2 != 0 && b % 2 == 0)
                return true;

            // Ako je a paran, a b neparan -> b ide prije a
            if (a % 2 == 0 && b % 2 != 0)
                return false;

            // Ako su oba iste parnosti, sortiraj rastuće
            return a < b;
        });

    // Ispis
    for (int broj : brojevi)
    {
        cout << broj << " ";
    }

    return 0;
}
