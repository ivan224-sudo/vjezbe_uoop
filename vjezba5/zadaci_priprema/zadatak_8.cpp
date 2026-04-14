#include <iostream>
using namespace std;

// apstraktna klasa
class EUredaj {
public:
    virtual void ispis() = 0; // čista virtualna funkcija
    virtual ~EUredaj() {}     // virtualni destruktor za sigurno brisanje
};

// konkretna klasa Tipkovnica
class Tipkovnica : public EUredaj {
public:
    void ispis() override {
        cout << "Tipkovnica" << endl;
    }
};

// konkretna klasa Monitor
class Monitor : public EUredaj {
public:
    void ispis() override {
        cout << "Monitor" << endl;
    }
};

int main() {
    // pokazivači na apstraktnu klasu
    EUredaj* uredaji[2];

    uredaji[0] = new Tipkovnica();
    uredaji[1] = new Monitor();

    // demonstracija polimorfizma
    for (int i = 0; i < 2; i++) {
        uredaji[i]->ispis();  // poziva ispis() odgovarajuće klase
    }

    // oslobađanje memorije
    for (int i = 0; i < 2; i++) {
        delete uredaji[i];
    }

    return 0;
}
