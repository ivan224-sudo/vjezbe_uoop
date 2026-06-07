#include "Stavka.h"
#include "Iznimke.h"
#include <iomanip>
#include <sstream>

Stavka::Stavka() : sifraProizvoda(0), kolicina(0.0), popust(0.0) {}

Stavka::Stavka(int sifra, double kolicina, double popust)
    : sifraProizvoda(sifra), kolicina(kolicina), popust(popust) {}

int Stavka::getSifraProizvoda() const { return sifraProizvoda; }
double Stavka::getKolicina() const { return kolicina; }
double Stavka::getPopust() const { return popust; }

void Stavka::setSifraProizvoda(int s) { sifraProizvoda = s; }
void Stavka::setKolicina(double k) { kolicina = k; }
void Stavka::setPopust(double p) { popust = p; }

static const Proizvod& dohvatiProizvod(const std::map<int, Proizvod>& mapa, int sifra) {
    auto it = mapa.find(sifra);
    if (it == mapa.end())
        throw ProizvodNijePronadjen(sifra);
    return it->second;
}

double Stavka::izracunajNetoCijenu(const std::map<int, Proizvod>& proizvodi) const {
    const Proizvod& p = dohvatiProizvod(proizvodi, sifraProizvoda);
    return kolicina * p.getJedCijena() * (1.0 - popust / 100.0);
}

double Stavka::izracunajPDV(const std::map<int, Proizvod>& proizvodi) const {
    const Proizvod& p = dohvatiProizvod(proizvodi, sifraProizvoda);
    return izracunajNetoCijenu(proizvodi) * p.getPdvPostotak() / 100.0;
}

double Stavka::izracunajUkupnuCijenu(const std::map<int, Proizvod>& proizvodi) const {
    return izracunajNetoCijenu(proizvodi) + izracunajPDV(proizvodi);
}

// Format ispisa prema PDF:
// 001234  Jabuka I klasa                          3 kg    3.00
//                          popust               10 %   -0.30
void Stavka::ispisi(std::ostream& out, const std::map<int, Proizvod>& proizvodi) const {
    const Proizvod& p = dohvatiProizvod(proizvodi, sifraProizvoda);

    double osnovica     = kolicina * p.getJedCijena();
    double iznosPopusta = osnovica * (popust / 100.0);

    // kolicina + jed.mjere kao string za poravnanje
    std::ostringstream kolSS;
    kolSS << (int)kolicina << " " << p.getJedMjere();
    std::string kolJed = kolSS.str();

    // redak stavke
    out << std::setfill('0') << std::setw(6) << sifraProizvoda;
    out << std::setfill(' ');
    out << "\t" << std::left  << std::setw(40) << p.getNaziv();
    out << "\t" << std::right << std::setw(6)  << kolJed;
    out << "\t" << std::right << std::setw(7)  << std::fixed << std::setprecision(2) << osnovica;
    out << "\n";

    // redak popusta
    if (popust > 0.0) {
        std::ostringstream postSS;
        postSS << (int)popust << " %";
        out << "\t" << std::right << std::setw(40) << "popust";
        out << "\t" << std::right << std::setw(6)  << postSS.str();
        out << "\t" << std::right << std::setw(7)  << std::fixed << std::setprecision(2) << -iznosPopusta;
        out << "\n";
    }
}

std::ostream& operator<<(std::ostream& out, const Stavka& s) {
    out << s.sifraProizvoda << ";" << s.kolicina;
    if (s.popust > 0.0)
        out << ";" << s.popust;
    return out;
}
