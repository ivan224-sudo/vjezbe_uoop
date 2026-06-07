#include "Proizvod.h"
#include "Iznimke.h"
#include <sstream>
#include <algorithm>

std::string Proizvod::ocistiNavodnike(const std::string& s) {
    std::string r = s;
    r.erase(std::remove(r.begin(), r.end(), '\''), r.end());
    r.erase(std::remove(r.begin(), r.end(), '"'), r.end());
    return r;
}

Proizvod::Proizvod()
    : sifra(0), naziv(""), kolicina(0.0), jedMjere(""), jedCijena(0.0), pdvPostotak(0.0) {}

Proizvod::Proizvod(int sifra, const std::string& naziv, double kolicina,
                   const std::string& jedMjere, double jedCijena, double pdvPostotak)
    : sifra(sifra), naziv(naziv), kolicina(kolicina),
      jedMjere(jedMjere), jedCijena(jedCijena), pdvPostotak(pdvPostotak) {}

int Proizvod::getSifra() const { return sifra; }
std::string Proizvod::getNaziv() const { return naziv; }
double Proizvod::getKolicina() const { return kolicina; }
std::string Proizvod::getJedMjere() const { return jedMjere; }
double Proizvod::getJedCijena() const { return jedCijena; }
double Proizvod::getPdvPostotak() const { return pdvPostotak; }

void Proizvod::setSifra(int s) { sifra = s; }
void Proizvod::setNaziv(const std::string& n) { naziv = n; }
void Proizvod::setKolicina(double k) { kolicina = k; }
void Proizvod::setJedMjere(const std::string& j) { jedMjere = j; }
void Proizvod::setJedCijena(double c) { jedCijena = c; }
void Proizvod::setPdvPostotak(double p) { pdvPostotak = p; }

void Proizvod::povecajKolicinu(double iznos) {
    if (iznos < 0) throw std::invalid_argument("Iznos ne smije biti negativan.");
    kolicina += iznos;
}

void Proizvod::smanjiKolicinu(double iznos) {
    if (iznos < 0) throw std::invalid_argument("Iznos ne smije biti negativan.");
    if (iznos > kolicina) throw std::invalid_argument("Nedovoljno raspolozive kolicine.");
    kolicina -= iznos;
}

std::istream& operator>>(std::istream& in, Proizvod& p) {
    std::string linija;
    while (std::getline(in, linija)) {
        // Ukloni UTF-8 BOM (EF BB BF) s pocetka datoteke
        if (linija.size() >= 3 &&
            (unsigned char)linija[0] == 0xEF &&
            (unsigned char)linija[1] == 0xBB &&
            (unsigned char)linija[2] == 0xBF)
            linija = linija.substr(3);
        // Ukloni \r (Windows line endings CRLF)
        if (!linija.empty() && linija.back() == '\r')
            linija.pop_back();
        if (linija.empty() || linija[0] == '#') continue;

        std::istringstream ss(linija);
        std::string tok;
        try {
            std::getline(ss, tok, ';'); p.sifra       = std::stoi(tok);
            std::getline(ss, tok, ';'); p.naziv       = Proizvod::ocistiNavodnike(tok);
            std::getline(ss, tok, ';'); p.jedCijena   = std::stod(tok);
            std::getline(ss, tok, ';'); p.pdvPostotak = std::stod(tok);
            std::getline(ss, tok, ';'); p.kolicina    = std::stod(tok);
            std::getline(ss, tok, ';'); p.jedMjere    = Proizvod::ocistiNavodnike(tok);
        } catch (const std::exception& e) {
            throw NeisparavnaStruktura(std::string("neispravni podatak proizvoda: ") + e.what());
        }
        return in;
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Proizvod& p) {
    out << p.sifra << ";"
        << "'" << p.naziv << "';"
        << p.jedCijena << ";"
        << p.pdvPostotak << ";"
        << p.kolicina << ";"
        << "'" << p.jedMjere << "'";
    return out;
}
