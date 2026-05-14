#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // za sort i binary_search

int main() {
    std::vector<int> podaci;
    std::vector<int> trazeno;

    // ---- Učitavanje podaci iz m7.txt ----
    std::ifstream datPodaci("m7.txt");
    if (!datPodaci) {
        std::cerr << "Ne mogu otvoriti datoteku m7.txt!" << std::endl;
        return 1;
    }

    int broj;
    while (datPodaci >> broj) {
        podaci.push_back(broj);
    }
    datPodaci.close();

    // ---- Učitavanje trazeno iz m13.txt ----
    std::ifstream datTrazeno("m13.txt");
    if (!datTrazeno) {
        std::cerr << "Ne mogu otvoriti datoteku m13.txt!" << std::endl;
        return 1;
    }

    while (datTrazeno >> broj) {
        trazeno.push_back(broj);
    }
    datTrazeno.close();

    // ---- Ispis broja elemenata u svakom vektoru ----
    std::cout << "Broj elemenata u podaci: " << podaci.size() << std::endl;
    std::cout << "Broj elemenata u trazeno: " << trazeno.size() << std::endl;

    // ---- Sortiranje podaci za binary_search ----
    std::sort(podaci.begin(), podaci.end());

    // ---- Prebrojavanje koliko brojeva iz trazeno postoji u podaci ----
    int brojPronaseno = 0;
    for (const auto& t : trazeno) {
        if (std::binary_search(podaci.begin(), podaci.end(), t)) {
            brojPronaseno++;
        }
    }

    std::cout << "Broj brojeva iz trazeno koji postoje u podaci: "
              << brojPronaseno << std::endl;

    return 0;
}
