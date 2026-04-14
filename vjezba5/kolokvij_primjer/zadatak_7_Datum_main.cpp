#include <iostream>
#include "Datum.h"

using namespace std;

int main() {

    Datum d(14, 4, 2026);

    Datum::setFormat(0);
    cout << "ISO: " << d << endl;

    Datum::setFormat(1);
    cout << "HR: " << d << endl;

    Datum::setFormat(2);
    cout << "US: " << d << endl;

    return 0;
}
