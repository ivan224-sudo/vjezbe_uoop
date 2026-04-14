#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Proizvod {
    string naziv;
    float nabavna;
    float prodajna;

    void ucitajProizvod() {
        cout << "Unesite naziv proizvoda: ";
        cin>>naziv;
        cout << "Unesite nabavnu cijenu: ";
        cin >> nabavna;
        cout << "Unesite prodajnu cijenu: ";
        cin >> prodajna;
    }

    void ispisiProizvod() {
        float zarada = prodajna - nabavna;
        float postotak;
        if (nabavna != 0) {
            postotak = (zarada / nabavna) * 100.0f;
            }
        else {
            postotak = 0.0f;
            }

        cout << left << setw(20) << naziv
             << right << setw(10) << fixed << setprecision(2) << nabavna
             << setw(10) << fixed << setprecision(2) << prodajna
             << setw(10) << fixed << setprecision(2) << zarada
             << setw(10) << fixed << setprecision(2) << postotak << "%" << endl;
    }
};

struct Spremiste {
    Proizvod proizvodi[100];
    int unesenoProizvoda = 0;

    void dodajProizvod(Proizvod &p) {
        if (unesenoProizvoda < 100) {
            proizvodi[unesenoProizvoda++] = p;
        } else {
            cout << "Spremiste je puno!" << endl;
        }
    }

    void unosPodataka() {
        int N;
        cout << "Koliko proizvoda zelite unijeti? ";
        cin >> N;
        if (N + unesenoProizvoda > 100) {
            cout << "Ne mozete unijeti toliko proizvoda, max je 100." << endl;
            N = 100 - unesenoProizvoda;
        }

        for (int i = 0; i < N; ++i) {
            cout << "Proizvod " << i + 1 << ":" << endl;
            Proizvod p;
            p.ucitajProizvod();
            dodajProizvod(p);
        }
    }

    void pregledPodataka() {
        if (unesenoProizvoda == 0) {
            cout << "Nema unesenih proizvoda." << endl;
            return;
        }

        cout << left << setw(20) << "Naziv"
             << right << setw(10) << "Nabavna"
             << setw(10) << "Prodajna"
             << setw(10) << "Zarada"
             << setw(10) << "%Zarada" << endl;
        cout << string(60, '-') << endl;

        for (int i = 0; i < unesenoProizvoda; ++i) {
            proizvodi[i].ispisiProizvod();
        }
    }

    void analizaPodataka() {
        if (unesenoProizvoda == 0) {
            cout << "Nema unesenih proizvoda za analizu." << endl;
            return;
        }

        int indexNajvecaRazlika = 0;
        int indexNajnizaCijena = 0;
        int indexNajvisaNabavna = 0;

        for (int i = 1; i < unesenoProizvoda; ++i) {
            float razlika_i = proizvodi[i].prodajna - proizvodi[i].nabavna;
            float razlika_max = proizvodi[indexNajvecaRazlika].prodajna - proizvodi[indexNajvecaRazlika].nabavna;
            if (razlika_i > razlika_max) indexNajvecaRazlika = i;

            if (proizvodi[i].nabavna < proizvodi[indexNajnizaCijena].nabavna)
                indexNajnizaCijena = i;

            if (proizvodi[i].nabavna > proizvodi[indexNajvisaNabavna].nabavna)
                indexNajvisaNabavna = i;
        }

        cout << "Proizvod s najvecom razlikom cijena: " << proizvodi[indexNajvecaRazlika].naziv << endl;
        cout << "Proizvod s najnizom nabavnom cijenom: " << proizvodi[indexNajnizaCijena].naziv << endl;
        cout << "Proizvod s najvisom nabavnom cijenom: " << proizvodi[indexNajvisaNabavna].naziv << endl;
    }
};

void ispisiIzbornik() {
    cout << "--- IZBORNIK ---"<<endl;
    cout << "A - Unos podataka"<<endl;
    cout << "B - Pregled podataka"<<endl;
    cout << "C - Analiza podataka"<<endl;
    cout << "X - Izlazak"<<endl;
    cout << "Odaberite opciju: "<<endl;
}

int main() {
    Spremiste spremiste;
    char izbor;

    do {
        ispisiIzbornik();
        cin >> izbor;
        izbor = toupper(izbor);

        switch (izbor) {
            case 'A':
                spremiste.unosPodataka();
                break;
            case 'B':
                spremiste.pregledPodataka();
                break;
            case 'C':
                spremiste.analizaPodataka();
                break;
            case 'X':
                cout << "Izlazak iz programa." << endl;
                break;
            default:
                cout << "Nepoznata opcija, pokusajte ponovno." << endl;
        }
    } while (izbor != 'X');

    return 0;
}
