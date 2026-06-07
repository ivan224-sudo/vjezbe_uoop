#pragma once
#include <string>
#include <iostream>

class Proizvod {
protected:
    int sifra;
    std::string naziv;
    double kolicina;       // raspoloziva kolicina (zaliha)
    std::string jedMjere;
    double jedCijena;      // jedinicna cijena bez PDV-a
    double pdvPostotak;

public:
    Proizvod();
    Proizvod(int sifra, const std::string& naziv, double kolicina,
             const std::string& jedMjere, double jedCijena, double pdvPostotak);

    // Getteri
    int getSifra() const;
    std::string getNaziv() const;
    double getKolicina() const;
    std::string getJedMjere() const;
    double getJedCijena() const;
    double getPdvPostotak() const;

    // Setteri
    void setSifra(int s);
    void setNaziv(const std::string& n);
    void setKolicina(double k);
    void setJedMjere(const std::string& j);
    void setJedCijena(double c);
    void setPdvPostotak(double p);

    // Zad 3 - povecanje/smanjenje zalihe
    void povecajKolicinu(double iznos);
    void smanjiKolicinu(double iznos);

    // Operatori toka
    // Format: sifra;naziv;cijena;PDV%;zaliha;jed.mjere
    // Preskace retke koji pocinju s '#'
    friend std::istream& operator>>(std::istream& in, Proizvod& p);
    friend std::ostream& operator<<(std::ostream& out, const Proizvod& p);

private:
    static std::string ocistiNavodnike(const std::string& s);
};
