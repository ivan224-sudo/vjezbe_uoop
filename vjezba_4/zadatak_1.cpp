#include <iostream>
#include <fstream>

using namespace std;

void unos(char imena[][50], int &broj) {
    cout << "Unesite broj imena (manje od 20): " << endl;
    cin >> broj;

    while (broj <= 0 || broj >= 20) {
        cout << "Neispravan unos! Ponovno unesite broj (<20): " << endl;
        cin >> broj;
    }

    cin.ignore();

    for (int i = 0; i < broj; i++) {
        cout << "Unesite ime " << i + 1 << ": " << endl;
        cin.getline(imena[i], 50);
    }
}

void ispis(char imena[][50], int broj) {
    if (broj == 0) {
        cout << "Nema podataka." << endl;
        return;
    }

    cout << "Popis imena:" << endl;
    for (int i = 0; i < broj; i++) {
        cout << i + 1 << ". " << imena[i] << endl;
    }
}

void spremi(char imena[][50], int broj) {
    char nazivDatoteke[100];

    cout << "Unesite naziv datoteke: " << endl;
    cin >> nazivDatoteke;

    ofstream datoteka(nazivDatoteke);

    if (!datoteka) {
        cout << "Greska pri otvaranju datoteke!" << endl;
        return;
    }

    datoteka << broj << endl;

    for (int i = 0; i < broj; i++) {
        datoteka << imena[i] << endl;
    }

    datoteka.close();
    cout << "Podaci su spremljeni." << endl;
}

void ucitaj(char imena[][50], int &broj) {
    char nazivDatoteke[100];

    cout << "Unesite naziv datoteke: " << endl;
    cin >> nazivDatoteke;

    ifstream datoteka(nazivDatoteke);

    if (!datoteka) {
        cout << "Greska pri otvaranju datoteke!" << endl;
        return;
    }

    datoteka >> broj;
    datoteka.ignore();

    for (int i = 0; i < broj; i++) {
        datoteka.getline(imena[i], 50);
    }

    datoteka.close();
    cout << "Podaci su ucitani." << endl;
}

int main() {
    char imena[20][50];
    int broj = 0;
    int izbor;

    do {
        cout << endl;
        cout << "--- IZBORNIK ---" << endl;
        cout << "1. Unos imena" << endl;
        cout << "2. Ispis imena" << endl;
        cout << "3. Spremanje u datoteku" << endl;
        cout << "4. Ucitavanje iz datoteke" << endl;
        cout << "5. Izlaz" << endl;
        cout << "Odabir: " << endl;

        cin >> izbor;

        switch (izbor) {
            case 1:
                unos(imena, broj);
                break;
            case 2:
                ispis(imena, broj);
                break;
            case 3:
                spremi(imena, broj);
                break;
            case 4:
                ucitaj(imena, broj);
                break;
            case 5:
                cout << "Izlaz iz programa." << endl;
                break;
            default:
                cout << "Neispravan izbor!" << endl;
        }

    } while (izbor != 5);

    return 0;
}
