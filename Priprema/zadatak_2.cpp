#include <iostream>
#include <list>
#include <sstream>
using namespace std;

int main() {
    list<int> brojevi;
    string linija;
    getline(cin, linija);

    istringstream iss(linija);
    int x;
    while (iss >> x) {
        brojevi.push_back(x);
    }

    int p;
    cin >> p;

    int maxOstatak = -1;
    int maxBroj = 0;
    for (int b : brojevi) {
        int ostatak = b % p;
        if (ostatak > maxOstatak) {
            maxOstatak = ostatak;
            maxBroj = b;
        }
    }

    cout << maxBroj << " " << maxOstatak << endl;

    return 0;
}
