#include "Racun.h"
#include "Iznimke.h"
#include <sstream>
#include <numeric>
#include <iomanip>

Racun::Racun() : proizvodi(nullptr) {}
Racun::Racun(const std::map<int, Proizvod>& mapa) : proizvodi(&mapa) {}

void Racun::setProizvodi(const std::map<int, Proizvod>& mapa) { proizvodi = &mapa; }
std::string Racun::getDatumVrijeme() const { return datumVrijeme; }
const std::vector<Stavka>& Racun::getStavke() const { return stavke; }

double Racun::ukupnaSuma() const {
    if (!proizvodi) throw std::runtime_error("Mapa proizvoda nije postavljena.");
    const auto& prod = *proizvodi;
    return std::accumulate(stavke.begin(), stavke.end(), 0.0,
        [&prod](double zbroj, const Stavka& s) {
            return zbroj + s.izracunajNetoCijenu(prod);
        });
}

double Racun::sumaPDV() const {
    if (!proizvodi) throw std::runtime_error("Mapa proizvoda nije postavljena.");
    const auto& prod = *proizvodi;
    return std::accumulate(stavke.begin(), stavke.end(), 0.0,
        [&prod](double zbroj, const Stavka& s) {
            return zbroj + s.izracunajPDV(prod);
        });
}

static void ocistiLiniju(std::string& linija) {
    linija.erase(0, linija.find_first_not_of(" \t\r\n"));
    if (linija.find_last_not_of(" \t\r\n") != std::string::npos)
        linija.erase(linija.find_last_not_of(" \t\r\n") + 1);
    // Ukloni UTF-8 BOM
    if (linija.size() >= 3 &&
        (unsigned char)linija[0] == 0xEF &&
        (unsigned char)linija[1] == 0xBB &&
        (unsigned char)linija[2] == 0xBF)
        linija = linija.substr(3);
    if (!linija.empty() && linija.back() == '\r')
        linija.pop_back();
}

std::istream& operator>>(std::istream& in, Racun& r) {
    r.stavke.clear();
    std::string linija;

    bool datumUcitan = false;
    while (std::getline(in, linija)) {
        ocistiLiniju(linija);
        if (linija.empty() || linija[0] == '#') continue;
        r.datumVrijeme = linija;
        datumUcitan = true;
        break;
    }
    if (!datumUcitan)
        throw NeisparavnaStruktura("nedostaje redak s datumom i vremenom.");

    while (std::getline(in, linija)) {
        ocistiLiniju(linija);
        if (linija.empty() || linija[0] == '#') continue;

        std::istringstream ss(linija);
        std::string tok;
        try {
            Stavka st;
            std::getline(ss, tok, ';'); st.setSifraProizvoda(std::stoi(tok));
            std::getline(ss, tok, ';'); st.setKolicina(std::stod(tok));
            if (std::getline(ss, tok, ';') && !tok.empty())
                st.setPopust(std::stod(tok));
            r.stavke.push_back(st);
        } catch (const std::exception& e) {
            throw NeisparavnaStruktura(std::string("neispravna stavka '") + linija + "': " + e.what());
        }
    }
    return in;
}

void Racun::ispisi(std::ostream& out) const {
    if (!proizvodi) throw std::runtime_error("Mapa proizvoda nije postavljena.");

    for (const Stavka& s : stavke)
        s.ispisi(out, *proizvodi);

    // Konverzija ISO -> DD.MM.YYYY HH:MM
    std::string dv = datumVrijeme;
    std::string ispisDatum = dv;
    if (dv.size() >= 16 && dv[4] == '-' && dv[7] == '-') {
        ispisDatum = dv.substr(8,2) + "." + dv.substr(5,2) + "." +
                     dv.substr(0,4) + " " + dv.substr(11,5);
    }

    // Ukupno: label poravnat lijevo kao naziv, iznos desno u stupcu cijene
    std::string labelUkupno = "Ukupno: (" + ispisDatum + ")";
    out << std::fixed << std::setprecision(2);
    out << "\t" << std::left  << std::setw(40) << labelUkupno
        << "\t" << std::right << std::setw(6)  << ""
        << "\t" << std::right << std::setw(7)  << ukupnaSuma() << "\n";
    out << "PDV: " << sumaPDV() << "\n";
}
