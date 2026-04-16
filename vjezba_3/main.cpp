#include <iostream>
#include "Koordinata.h"

using namespace std;

int main() {
    Koordinata k1, k2;

    cout << "Unos prve koordinate:" << endl;
    cin >> k1;

    cout << "Unos druge koordinate:" << endl;
    cin >> k2;

    cout << endl;
    cout << "Unesene koordinate:" << endl;
    cout << "k1 = " << k1 << endl;
    cout << "k2 = " << k2 << endl;

    Koordinata zbroj = k1 + k2;
    Koordinata razlika = k1 - k2;

    cout << endl;
    cout << "Zbroj: " << zbroj << endl;
    cout << "Razlika: " << razlika << endl;

    if (k1 == k2)
        cout << "Koordinate su jednake." << endl;
    else
        cout << "Koordinate nisu jednake." << endl;

    cout << endl;

    k1.pomak(1, 1);
    cout << "k1 nakon pomaka: " << k1 << endl;

    k2.pomakX(2);
    k2.pomakY(-1);
    cout << "k2 nakon pomaka: " << k2 << endl;

    return 0;
}
