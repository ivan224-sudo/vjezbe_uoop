#pragma once
#include "Proizvod.h"
#include <map>
#include <iostream>

class Stavka {
protected:
    int sifraProizvoda;
    double kolicina;
    double popust;      // popust u postocima (0 ako nema)

public:
    Stavka();
    Stavka(int sifra, double kolicina, double popust = 0.0);

    // Getteri
    int getSifraProizvoda() const;
    double getKolicina() const;
    double getPopust() const;

    // Setteri
    void setSifraProizvoda(int s);
    void setKolicina(double k);
    void setPopust(double p);

    // Izracun na osnovi mape proizvoda
    double izracunajNetoCijenu(const std::map<int, Proizvod>& proizvodi) const;
    double izracunajPDV(const std::map<int, Proizvod>& proizvodi) const;
    double izracunajUkupnuCijenu(const std::map<int, Proizvod>& proizvodi) const;

    // Razvuceni ispis stavke s nazivom i popustom
    void ispisi(std::ostream& out, const std::map<int, Proizvod>& proizvodi) const;

    friend std::ostream& operator<<(std::ostream& out, const Stavka& s);
};
