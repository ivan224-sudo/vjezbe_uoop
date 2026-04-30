#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

void generiraj(int niz[], int &n) {
    cout << "Unesite broj elemenata: " << endl;
    cin >> n;

    if (n <= 0 || n > 1000) {
        throw invalid_argument("Broj mora biti u rasponu 1-1000!");
    }

    srand(time(0));

    for (int i = 0; i < n; i++) {
        niz[i] = rand() % 1000 + 1;
    }
}

void ispisi(int niz[], int n) {
    for (int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    cout << endl;
}

void kopiraj(int izvor[], int odrediste[], int n) {
    for (int i = 0; i < n; i++) {
        odrediste[i] = izvor[i];
    }
}

void bubbleSort(int niz[], int n, int smjer) {
    int koraci = 0;
    int zamjene = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            koraci++;

            bool uvjet = false;

            if (smjer == 1 && niz[j] > niz[j + 1]) uvjet = true;
            if (smjer == 2 && niz[j] < niz[j + 1]) uvjet = true;

            if (uvjet) {
                int temp = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = temp;
                zamjene++;
            }
        }
    }

    cout << "Bubble sort - koraci: " << koraci << endl;
    cout << "Bubble sort - zamjene: " << zamjene << endl;
}

void selectionSort(int niz[], int n, int smjer) {
    int koraci = 0;
    int zamjene = 0;

    for (int i = 0; i < n - 1; i++) {
        int indeks = i;

        for (int j = i + 1; j < n; j++) {
            koraci++;

            if (smjer == 1 && niz[j] < niz[indeks]) indeks = j;
            if (smjer == 2 && niz[j] > niz[indeks]) indeks = j;
        }

        if (indeks != i) {
            int temp = niz[i];
            niz[i] = niz[indeks];
            niz[indeks] = temp;
            zamjene++;
        }
    }

    cout << "Selection sort - koraci: " << koraci << endl;
    cout << "Selection sort - zamjene: " << zamjene << endl;
}

int main() {
    int niz[1000], niz1[1000], niz2[1000];
    int n;
    int smjer;

    try {
        generiraj(niz, n);

        if (n < 50) {
            cout << "Ulazni niz:" << endl;
            ispisi(niz, n);
        }

        cout << "Odaberite sortiranje: 1-uzlazno, 2-silazno" << endl;
        cin >> smjer;

        if (smjer != 1 && smjer != 2) {
            throw invalid_argument("Smjer mora biti 1 ili 2!");
        }

        kopiraj(niz, niz1, n);
        kopiraj(niz, niz2, n);

        bubbleSort(niz1, n, smjer);
        selectionSort(niz2, n, smjer);

        if (n < 50) {
            cout << "Rezultat (bubble):" << endl;
            ispisi(niz1, n);

            cout << "Rezultat (selection):" << endl;
            ispisi(niz2, n);
        }
    }
    catch (exception &e) {
        cout << "Greska: " << e.what() << endl;
    }

    return 0;
}
