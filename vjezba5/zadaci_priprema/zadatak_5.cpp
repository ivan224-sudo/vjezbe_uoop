// cd putanja
//naziv.exe arg1 arg2....
#include <iostream>
#include <cstdlib> // za atoi
using namespace std;

int main(int argc, char* argv[]) {
    int polje[10];
    int n = argc - 1; // broj unesenih argumenata (bez imena programa)

    if (n > 10) {
        n = 10; // maksimalno 10 elemenata
    }

    // Učitavanje elemenata u polje
    for (int i = 0; i < n; i++) {
        polje[i] = atoi(argv[i + 1]); // pretvorba iz string u int
    }

    // Kvadriranje elemenata
    for (int i = 0; i < n; i++) {
        polje[i] = polje[i] * polje[i];
    }

    // Ispis polja
    cout << "Kvadrirani elementi: ";
    for (int i = 0; i < n; i++) {
        cout << polje[i] << " ";
    }
    cout << endl;

    return 0;
}