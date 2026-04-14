#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

void unos(char imena[][21], char prezimena[][21], int bodovi[], int &broj) {
    cout << "Unesite broj studenata: " << endl;
    cin >> broj;

    while (broj <= 0 || broj > 100) {
        cout << "Neispravan unos! (1-100): " << endl;
        cin >> broj;
    }

    cin.ignore();

    for (int i = 0; i < broj; i++) {
        cout << "Ime: " << endl;
        cin.getline(imena[i], 21);

        cout << "Prezime: " << endl;
        cin.getline(prezimena[i], 21);

        cout << "Bodovi: " << endl;
        cin >> bodovi[i];
        cin.ignore();
    }
}

void ispis(char imena[][21], char prezimena[][21], int bodovi[], int broj) {
    cout << endl;
    for (int i = 0; i < broj; i++) {
        cout << left << setw(20) << imena[i]
             << left << setw(20) << prezimena[i]
             << right << setw(5) << bodovi[i] << endl;
    }
}

void spremi(char imena[][21], char prezimena[][21], int bodovi[], int broj) {
    char naziv[100];

    cout << "Naziv datoteke: " << endl;
    cin >> naziv;

    ofstream dat(naziv);

    if (!dat) {
        cout << "Greska!" << endl;
        return;
    }

    dat << broj << endl;

    for (int i = 0; i < broj; i++) {
        dat << imena[i] << endl;
        dat << prezimena[i] << endl;
        dat << bodovi[i] << endl;
    }

    dat.close();
    cout << "Spremljeno." << endl;
}

void ucitaj(char imena[][21], char prezimena[][21], int bodovi[], int &broj) {
    char naziv[100];

    cout << "Naziv datoteke: " << endl;
    cin >> naziv;

    ifstream dat(naziv);

    if (!dat) {
        cout << "Greska!" << endl;
        return;
    }

    dat >> broj;
    dat.ignore();

    for (int i = 0; i < broj; i++) {
        dat.getline(imena[i], 21);
        dat.getline(prezimena[i], 21);
        dat >> bodovi[i];
        dat.ignore();
    }

    dat.close();
    cout << "Ucitano." << endl;
}

void sortiraj(char imena[][21], char prezimena[][21], int bodovi[], int broj) {
    int izbor;

    cout << "1 - rastuce" << endl;
    cout << "2 - silazno" << endl;
    cin >> izbor;

    for (int i = 0; i < broj - 1; i++) {
        for (int j = i + 1; j < broj; j++) {

            bool uvjet = false;

            if (izbor == 1 && bodovi[i] > bodovi[j]) uvjet = true;
            if (izbor == 2 && bodovi[i] < bodovi[j]) uvjet = true;

            if (uvjet) {
                // zamjena bodova
                int tempB = bodovi[i];
                bodovi[i] = bodovi[j];
                bodovi[j] = tempB;

                // zamjena imena
                char tempIme[21];
                strcpy(tempIme, imena[i]);
                strcpy(imena[i], imena[j]);
                strcpy(imena[j], tempIme);

                // zamjena prezimena
                char tempPrezime[21];
                strcpy(tempPrezime, prezimena[i]);
                strcpy(prezimena[i], prezimena[j]);
                strcpy(prezimena[j], tempPrezime);
            }
        }
    }

    cout << "Sortirano." << endl;
}

int main() {
    char imena[100][21];
    char prezimena[100][21];
    int bodovi[100];
    int broj = 0;
    int izbor;

    do {
        cout << endl;
        cout << "--- IZBORNIK ---" << endl;
        cout << "1. Unos" << endl;
        cout << "2. Ispis" << endl;
        cout << "3. Spremanje" << endl;
        cout << "4. Ucitavanje" << endl;
        cout << "5. Sortiranje" << endl;
        cout << "6. Izlaz" << endl;
        cout << "Odabir: " << endl;

        cin >> izbor;

        switch (izbor) {
            case 1:
                unos(imena, prezimena, bodovi, broj);
                break;
            case 2:
                ispis(imena, prezimena, bodovi, broj);
                break;
            case 3:
                spremi(imena, prezimena, bodovi, broj);
                break;
            case 4:
                ucitaj(imena, prezimena, bodovi, broj);
                break;
            case 5:
                sortiraj(imena, prezimena, bodovi, broj);
                break;
            case 6:
                cout << "Kraj programa." << endl;
                break;
            default:
                cout << "Neispravan izbor!" << endl;
        }

    } while (izbor != 6);

    return 0;
}
