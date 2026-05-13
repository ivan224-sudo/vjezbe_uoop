#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> ormarici;
    string ime;
    int broj;

    // Učitavanje imena i brojeva ormarića
    while (true) {
        string linija;
        getline(cin, linija);

        // Ako je prazna linija, prekid unosa parova
        if (linija.empty()) {
            break;
        }

        // Obrada linije
        size_t razmak = linija.find(' ');
        ime = linija.substr(0, razmak);
        broj = stoi(linija.substr(razmak + 1));

        // Spremanje u mapu
        ormarici[ime] = broj;

        // Ispis svih dosad unešenih podataka
        for (const auto& par : ormarici) {
            cout << par.first << " " << par.second << endl;
        }
    }

    // Učitavanje samo imena i ispis brojeva ormarića
    while (cin >> ime) {
        if (ormarici.count(ime)) {
            cout << ormarici[ime] << endl;
        }
    }

    return 0;
}
