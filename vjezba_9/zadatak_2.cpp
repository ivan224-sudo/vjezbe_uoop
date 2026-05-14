#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm> // za random_shuffle
#include <ctime>     // za srand

int main() {
    // ---- Učitavanje riječi iz datoteke ----
    std::ifstream datoteka("words.txt");
    if (!datoteka) {
        std::cerr << "Ne mogu otvoriti datoteku words.txt!" << std::endl;
        return 1;
    }

    std::vector<std::string> rijeci;
    std::string rijec;
    while (datoteka >> rijec) {
        rijeci.push_back(rijec);
    }
    datoteka.close();

    if (rijeci.size() < 2) {
        std::cerr << "Datoteka mora imati barem dvije riječi!" << std::endl;
        return 1;
    }

    // ---- Permutiranje riječi ----
    std::srand(unsigned(std::time(nullptr))); // seed za random_shuffle
    std::random_shuffle(rijeci.begin(), rijeci.end());

    // ---- Kreiranje mape korisnici -> lozinka ----
    std::map<std::string, std::string> korisnici;
    for (size_t i = 0; i + 1 < rijeci.size(); i += 2) {
        std::string korisnik = rijeci[i];     // neparni indeksi (0,2,4...) korisnici
        std::string lozinka = rijeci[i + 1];  // parni indeksi (1,3,5...) lozinke
        korisnici[korisnik] = lozinka;
    }

    // ---- Ispis prvih 10 parova ----
    std::cout << "Prvih 10 korisnik/lozinka parova: " << std::endl;
    int brojIspisa = 0;
    for (const auto& par : korisnici) {
        std::cout << par.first << " : " << par.second << std::endl;
        brojIspisa++;
        if (brojIspisa >= 10) break;
    }

    // ---- Provjera korisnika i lozinke ----
    std::string unosKorisnik, unosLozinka;
    std::cout << "\nUnesite korisnicko ime: ";
    std::cin >> unosKorisnik;
    std::cout << "Unesite lozinku: ";
    std::cin >> unosLozinka;

    auto it = korisnici.find(unosKorisnik);
    if (it != korisnici.end() && it->second == unosLozinka) {
        std::cout << "Dobro dosli osmijeh !" << std::endl;
    } else {
        std::cout << "Los pokusaj :P !" << std::endl;
    }

    return 0;
}
