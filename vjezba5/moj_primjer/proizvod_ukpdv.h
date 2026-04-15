#ifndef PROIZVOD_H
#define PROIZVOD_H

#include <iostream>
#include <string>
using namespace std;

class Proizvod{
private:
    int sifra;
    string naziv;
    int kolicina;
    double cijena;

public:
    //konstruktor
    Proizvod();
    //destruktor
    ~Proizvod();

    //getteri
    int GetSifra()const;
    string GetNaziv()const;
    int GetKolicina()const;
    double GetCijena()const;

    //setteri
    void SetSifra(int s);
    void SetNaziv(string n);
    void SetKolicina(int k);
    void SetCijena(double c);

    //stream
    friend ostream& operator<<(ostream& izlaz, const Proizvod& p);
    friend istream& operator>>(istream& ulaz, Proizvod& p);

    //funkcija za pdv
    double GetCijenaPDV(double pdv);

    //funkcija za iznos
    double GetIznos(double pdv);
};
#endif // PROIZVOD_H
