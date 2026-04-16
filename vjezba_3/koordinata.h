#ifndef KOORDINATA_H
#define KOORDINATA_H

#include <iostream>
using namespace std;

class Koordinata {
private:
    double x, y;

public:
    // Konstruktori i destruktor
    Koordinata(double x = 0, double y = 0);
    Koordinata(const Koordinata& druga);
    ~Koordinata();

    // Getteri
    double dohvatiX() const;
    double dohvatiY() const;

    // Setteri
    void postaviX(double x);
    void postaviY(double y);

    // Pomaci
    void pomakX(double dx);
    void pomakY(double dy);
    void pomak(double dx, double dy);

    // Operatori
    bool operator==(const Koordinata& druga) const;
    Koordinata operator+(const Koordinata& druga) const;
    Koordinata operator-(const Koordinata& druga) const;

    // Stream operatori
    friend ostream& operator<<(ostream& izlaz, const Koordinata& k);
    friend istream& operator>>(istream& ulaz, Koordinata& k);
};

#endif
