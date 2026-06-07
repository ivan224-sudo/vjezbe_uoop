#include "Racun.h"
#include "Iznimke.h"
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Upotreba: " << argv[0] << " <proizvodi.txt> <racun.txt>\n";
        return 1;
    }

    // --- Ucitavanje proizvoda iz prve datoteke ---
    std::map<int, Proizvod> proizvodi;

    std::ifstream fProizvodi(argv[1]);
    if (!fProizvodi.is_open()) {
        std::cerr << "Greska: ne mogu otvoriti " << argv[1] << "\n";
        return 1;
    }
    try {
        Proizvod p;
        while (fProizvodi >> p)
            proizvodi[p.getSifra()] = p;
    } catch (const NeisparavnaStruktura& e) {
        std::cerr << "Greska u datoteci proizvoda: " << e.what() << "\n";
        return 1;
    }
    fProizvodi.close();

    if (proizvodi.empty()) {
        std::cerr << "Greska: niti jedan proizvod nije ucitan.\n";
        return 1;
    }

    // --- Ucitavanje racuna iz druge datoteke ---
    std::ifstream fRacun(argv[2]);
    if (!fRacun.is_open()) {
        std::cerr << "Greska: ne mogu otvoriti " << argv[2] << "\n";
        return 1;
    }

    Racun racun(proizvodi);
    try {
        fRacun >> racun;
    } catch (const NeisparavnaStruktura& e) {
        std::cerr << "Greska u datoteci racuna: " << e.what() << "\n";
        return 1;
    }
    fRacun.close();

    // --- Ispis racuna ---
    try {
        racun.ispisi(std::cout);
    } catch (const ProizvodNijePronadjen& e) {
        std::cerr << "Greska pri ispisu: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
