#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> brojevi;
    int x;

    // učitavanje sa standardnog ulaza
    cout << "Unosite brojeve (Ctrl+Z pa Enter za kraj):" << endl;
    while (cin >> x) {
        brojevi.push_back(x);
    }

    // provjera da lista nije prazna
    if (brojevi.empty()) {
        cout << "Nema unesenih brojeva." << endl;
        return 0;
    }

    int min = *brojevi.begin();
    int max = *brojevi.begin();

    // jedan range loop za min i max
    for (const auto& b : brojevi) {
        if (b < min) min = b;
        if (b > max) max = b;
    }

    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;

    return 0;
}
