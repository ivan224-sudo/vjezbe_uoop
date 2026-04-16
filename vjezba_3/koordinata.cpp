#include "Koordinata.h"

// Konstruktor
Koordinata::Koordinata(double x, double y) {
    this->x = x;
    this->y = y;
}

// Kopirni konstruktor
Koordinata::Koordinata(const Koordinata& druga) {
    x = druga.x;
    y = druga.y;
}

// Destruktor
Koordinata::~Koordinata() {}

// Getteri
double Koordinata::dohvatiX() const { return x; }
double Koordinata::dohvatiY() const { return y; }

// Setteri
void Koordinata::postaviX(double x) { this->x = x; }
void Koordinata::postaviY(double y) { this->y = y; }

// Pomaci
void Koordinata::pomakX(double dx) { x += dx; }
void Koordinata::pomakY(double dy) { y += dy; }

void Koordinata::pomak(double dx, double dy) {
    x += dx;
    y += dy;
}

// Operator ==
bool Koordinata::operator==(const Koordinata& druga) const {
    return x == druga.x && y == druga.y;
}

// Operator +
Koordinata Koordinata::operator+(const Koordinata& druga) const {
    return Koordinata(x + druga.x, y + druga.y);
}

// Operator -
Koordinata Koordinata::operator-(const Koordinata& druga) const {
    return Koordinata(x - druga.x, y - druga.y);
}

// Operator <<
ostream& operator<<(ostream& izlaz, const Koordinata& k) {
    izlaz << "(" << k.x << ", " << k.y << ")";
    return izlaz;
}

// Operator >>
istream& operator>>(istream& ulaz, Koordinata& k) {
    cout << "Unesite x: ";
    ulaz >> k.x;
    cout << "Unesite y: ";
    ulaz >> k.y;
    return ulaz;
}
