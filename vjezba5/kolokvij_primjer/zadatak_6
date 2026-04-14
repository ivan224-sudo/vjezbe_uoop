#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// funkcija iz prethodnog zadatka
float uvecajZaPDV(float (&polje)[], int size) {
    float suma = 0;

    for (int i = 0; i < size; i++) {
        polje[i] = polje[i] * 1.25f; // +25% PDV
        suma += polje[i];
    }

    return suma;
}

int main(int argc, char* argv[])
{
    float polje[100]; // dovoljno veliko za unos
    int size = argc - 1;

    // pretvorba argv -> float (stof)
    for (int i = 0; i < size; i++) {
        polje[i] = stof(argv[i + 1]);
    }

    float suma = uvecajZaPDV(polje, size);

    // ispis s 2 decimale
    cout << fixed << setprecision(2);

    for (int i = 0; i < size; i++) {
        cout << polje[i] << endl;
    }

    cout << "Suma je: " << suma << endl;

    return 0;
}
