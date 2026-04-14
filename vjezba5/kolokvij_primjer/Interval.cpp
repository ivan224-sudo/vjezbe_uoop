#include "Interval.h"

// konstruktor
Interval::Interval(Datum p, Datum k) {
    pocetak = p;
    kraj = k;
}

// pomoćna funkcija: datum → broj dana
int pretvoriUDane(const Datum& d) {
    return d.getGodina() * 360 +
           d.getMjesec() * 30 +
           d.getDan();
}

// duljina intervala
int Interval::duljina() const {
    int start = pretvoriUDane(pocetak);
    int end = pretvoriUDane(kraj);

    return end - start;
}
