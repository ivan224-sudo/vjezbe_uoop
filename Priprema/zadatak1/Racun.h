#pragma once
#include "Stavka.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>

class Racun {
protected:
    std::string datumVrijeme;           // ISO format: YYYY-MM-DD HH:MM
    std::vector<Stavka> stavke;
    const std::map<int, Proizvod>* proizvodi;  // dijeljena mapa

public:
    Racun();
    explicit Racun(const std::map<int, Proizvod>& mapa);

    void setProizvodi(const std::map<int, Proizvod>& mapa);
    std::string getDatumVrijeme() const;
    const std::vector<Stavka>& getStavke() const;

    // Ukupna suma svih stavki s PDV-om i popustima - lambda!
    double ukupnaSuma() const;

    // Suma samo PDV-a - lambda!
    double sumaPDV() const;

    // Ucitavanje iz datoteke:
    // redak 1 = datum i vrijeme
    // ostali retci = sifra;kolicina ili sifra;kolicina;popust
    friend std::istream& operator>>(std::istream& in, Racun& r);

    // Formatiran ispis cijelog racuna
    void ispisi(std::ostream& out) const;
};
