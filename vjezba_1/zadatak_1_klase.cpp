#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Osoba {
private:
    string ime;
    string prezime;
    int god_rod;

public:
    // funkcija za unos
    istream& ucitaj(istream &in) {
        in >> ime >> prezime >> god_rod;
        return in;
    }

    // funkcija za ispis
    ostream& ispisi(ostream &out) const {
        out << setw(10) << prezime
            << setw(10) << ime
            << setw(6) << dec << god_rod
            << setw(6) << oct << god_rod
            << setw(6) << hex << god_rod
            << setw(12) << ime
            << dec << endl;
        return out;
    }

    int getGodRod() const {
        return god_rod;
    }

    string getIme() const {
        return ime;
    }

    string getPrezime() const {
        return prezime;
    }
};

int main() {
    Osoba ljudi[3];

    cout << "Unesite ime, prezime i godinu rodenja za 3 osobe:\n";
    for (int i = 0; i < 3; i++) {
        ljudi[i].ucitaj(cin);
    }

    cout << "\nIspis:\n";
    for (int i = 0; i < 3; i++) {
        ljudi[i].ispisi(cout);
    }

    // prosjecna starost
    float uk_god = 0;
    int trenutna_god = 2026;

    for (int i = 0; i < 3; i++) {
        uk_god += ljudi[i].getGodRod();
    }

    float prosjek = trenutna_god - (uk_god / 3.0);
    cout << "Prosjecna starost: " << prosjek << endl;

    // najmladja osoba
    Osoba najmladi = ljudi[0];

    for (int i = 1; i < 3; i++) {
        if (ljudi[i].getGodRod() > najmladi.getGodRod()) {
            najmladi = ljudi[i];
        }
    }

    cout << "Najmladi: "
         << najmladi.getIme() << " "
         << najmladi.getPrezime() << " "
         << najmladi.getGodRod() << endl;

    return 0;
}
