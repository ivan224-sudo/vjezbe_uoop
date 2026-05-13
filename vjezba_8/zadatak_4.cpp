#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ifstream dat("tekst.txt"); // datoteka s tekstom zadataka

    if (!dat) {
        cout << "Ne mogu otvoriti datoteku!" << endl;
        return 1;
    }

    map<string, int> brojac;
    string rijec;

    // a) Učitavanje riječi i brojanje pojavljivanja
    while (dat >> rijec) {
        brojac[rijec]++;
    }

    // Ispis koliko svake riječi ima
    cout << "Broj pojavljivanja svake rijeci:\n";
    for (const auto& par : brojac) {
        cout << par.first << " : " << par.second << endl;
    }

    // b) Pretvaranje mape u vektor parova
    vector<pair<string, int>> v(brojac.begin(), brojac.end());

    // Sortiranje prema broju pojavljivanja silazno
    sort(v.begin(), v.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });

    // Ispis prvih 10 elemenata
    cout << "\nTop 10 rijeci:\n";
    for (int i = 0; i < 10 && i < (int)v.size(); i++) {
        cout << v[i].first << " : " << v[i].second << endl;
    }

    return 0;
}
