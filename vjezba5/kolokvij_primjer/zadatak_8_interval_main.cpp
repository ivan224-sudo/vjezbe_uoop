#include <iostream>
#include "Datum.h"
#include "Interval.h"

using namespace std;

int main() {

    Datum d1(1, 1, 2020);
    Datum d2(10, 1, 2020);

    Interval i(d1, d2);

    cout << "Duljina intervala = " << i.duljina() << endl;

    return 0;
}
