#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> // za for_each i next_permutation

// Pomoćna funkcija za ispis trostrukog broja
void ispisiTrostruko(int broj) {
    std::cout << broj * 3 << " ";
}

int main() {
    // učitavanje brojeva ----
    std::cout << "Unesite brojeve odvojene razmakom: ";
    std::string linija;
    std::getline(std::cin, linija);

    std::stringstream strum(linija);
    std::vector<int> brojevi;
    int broj;
    while (strum >> broj) {
        brojevi.push_back(broj);
    }

    // Ispis kvadrata brojeva koristeći normalnu for petlju
    std::cout << "Kvadrati brojeva: ";
    for (size_t i = 0; i < brojevi.size(); ++i) {
        std::cout << brojevi[i] * brojevi[i] << " ";
    }
    std::cout << std::endl;

    // Ispis trostrukih brojeva koristeći std::for_each i pomoćnu funkciju
    std::cout << "Trostruki brojevi: ";
    std::for_each(brojevi.begin(), brojevi.end(), ispisiTrostruko);
    std::cout << std::endl;

    //učitavanje riječi i ispis permutacija ----
    std::cout << "Unesite riječi odvojene razmakom: ";
    std::getline(std::cin, linija);
    std::stringstream strumRijeci(linija);
    std::vector<std::string> rijeci;
    std::string rijec;
    while (strumRijeci >> rijec) {
        rijeci.push_back(rijec);
    }

    // Sortiraj vector da bismo mogli koristiti next_permutation
    std::sort(rijeci.begin(), rijeci.end());

    std::cout << "Permutacije riječi: " << std::endl;
    do {
        for (const auto& r : rijeci) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(rijeci.begin(), rijeci.end()));

    return 0;
}
