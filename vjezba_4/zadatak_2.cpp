#include <iostream>
#include <fstream>

using namespace std;

void unos(int brojevi[], int &broj) {
    cout << "Unesite broj elemenata: " << endl;
    cin >> broj;

    while (broj <= 0 || broj > 100) {
        cout << "Neispravan unos! Ponovno unesite broj (1-100): " << endl;
        cin >> broj;
    }

    for (int i = 0; i < broj; i++) {
        cout << "Unesite broj " << i + 1 << ": " << endl;
        cin >> brojevi[i];
    }
}

void ispisObrnuto(int brojevi[], int broj) {
    cout << "Ispis od zadnjeg prema prvom:" << endl;
    for (int i = broj - 1; i >= 0; i--) {
        cout << brojevi[i] << " ";
    }
    cout << endl;
}

void razlike(int brojevi[], int broj) {
    if (broj < 2) {
        cout << "Nedovoljno elemenata." << endl;
        return;
    }

    cout << "Razlike susjednih brojeva:" << endl;
    for (int i = 0; i < broj - 1; i++) {
        cout << brojevi[i] - brojevi[i + 1] << " ";
    }
    cout << endl;
}

void minMax(int brojevi[], int broj) {
    if (broj == 0) {
        cout << "Nema podataka." << endl;
        return;
    }

    int min = brojevi[0], max = brojevi[0];
    int indMin = 0, indMax = 0;

    for (int i = 1; i < broj; i++) {
        if (brojevi[i] < min) {
            min = brojevi[i];
            indMin = i;
        }
        if (brojevi[i] > max) {
            max = brojevi[i];
            indMax = i;
        }
    }

    cout << "Najmanji: " << min << " (indeks " << indMin << ")" << endl;
    cout << "Najveci: " << max << " (indeks " << indMax << ")" << endl;
}

void spremi(int brojevi[], int broj) {
    char naziv[100];

    cout << "Unesite naziv datoteke: " << endl;
    cin >> naziv;

    ofstream dat(naziv);

    if (!dat) {
        cout << "Greska!" << endl;
        return;
    }

    dat << broj << endl;
    for (int i = 0; i < broj; i++) {
        dat << brojevi[i] << endl;
    }

    dat.close();
    cout << "Spremljeno." << endl;
}

void ucitaj(int brojevi[], int &broj) {
    char naziv[100];

    cout << "Unesite naziv datoteke: " << endl;
    cin >> naziv;

    ifstream dat(naziv);

    if (!dat) {
        cout << "Greska!" << endl;
        return;
    }

    dat >> broj;

    for (int i = 0; i < broj; i++) {
        dat >> brojevi[i];
    }

    dat.close();
    cout << "Ucitano." << endl;
}

void sortiraj(int brojevi[], int sortirani[], int broj) {
    for (int i = 0; i < broj; i++) {
        sortirani[i] = brojevi[i];
    }

    for (int i = 0; i < broj - 1; i++) {
        for (int j = i + 1; j < broj; j++) {
            if (sortirani[i] > sortirani[j]) {
                int temp = sortirani[i];
                sortirani[i] = sortirani[j];
                sortirani[j] = temp;
            }
        }
    }
}

void ispisSortiranih(int sortirani[], int broj) {
    cout << "Sortirani brojevi:" << endl;
    for (int i = 0; i < broj; i++) {
        cout << sortirani[i] << " ";
    }
    cout << endl;
}

int main() {
    int brojevi[100];
    int sortirani[100];
    int broj = 0;
    int izbor;

    do {
        cout << endl;
        cout << "--- IZBORNIK ---" << endl;
        cout << "1. Unos brojeva" << endl;
        cout << "2. Ispis obrnutim redom" << endl;
        cout << "3. Razlike brojeva" << endl;
        cout << "4. Min i max" << endl;
        cout << "5. Spremanje u datoteku" << endl;
        cout << "6. Ucitavanje iz datoteke" << endl;
        cout << "7. Sortirani ispis" << endl;
        cout << "8. Izlaz" << endl;
        cout << "Odabir: " << endl;

        cin >> izbor;

        switch (izbor) {
            case 1:
                unos(brojevi, broj);
                break;
            case 2:
                ispisObrnuto(brojevi, broj);
                break;
            case 3:
                razlike(brojevi, broj);
                break;
            case 4:
                minMax(brojevi, broj);
                break;
            case 5:
                spremi(brojevi, broj);
                break;
            case 6:
                ucitaj(brojevi, broj);
                break;
            case 7:
                sortiraj(brojevi, sortirani, broj);
                ispisSortiranih(sortirani, broj);
                break;
            case 8:
                cout << "Kraj programa." << endl;
                break;
            default:
                cout << "Neispravan izbor!" << endl;
        }

    } while (izbor != 8);

    return 0;
}
