#include <iostream>
#include <string>
using namespace std;

int main() {
    string datum;

    cout << "Unesite datum rodjenja (DD/MM/GGGG): ";
    cin >> datum;

    int checksum = 0;

    // prolazak kroz sve znakove
    for (int i = 0; i < datum.length(); i++) {
        if (datum[i] >= '0' && datum[i] <= '9') {
            checksum += datum[i] - '0'; // pretvaranje char u int
        } else if (datum[i] == '/') {
            datum[i] = '.';
        }
    }

    cout << "Datum rodjenja: " << datum << endl;
    cout << "checksum = " << checksum << endl;

    return 0;
}
