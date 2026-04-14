#include <iostream>
#include <string>
using namespace std;

int main() {
    string datum;

    cout << "Unesite datum rodjenja (DD/MM/GGGG): ";
    cin >> datum;

    // Zamjena '/' s '.'
    for (int i = 0; i < datum.length(); i++) {
        if (datum[i] == '/') {
            datum[i] = '.';
        }
    }

    cout << "Datum rodjenja: " << datum << endl;

    return 0;
}
