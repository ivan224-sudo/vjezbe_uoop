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
    double pdv;

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
    double GetPDV()const;

    //setteri
    void SetSifra(int s);
    void SetNaziv(string n);
    void SetKolicina(int k);
    void SetCijena(double c);
    void SetPDV(double pd);

    //stream
    friend ostream& operator<<(ostream& izlaz, const Proizvod& p);
    friend istream& operator>>(istream& ulaz, Proizvod& p);

    //funkcija za pdv
    double GetCijenaPDV();

    //funckija za stavku
    double GetStavka();

    double GetIznosBezPDV();
    double GetIznosSaPDV();
    double GetIznosPDV();

};
#endif // PROIZVOD_H
