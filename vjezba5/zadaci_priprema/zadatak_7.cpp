#include <iostream>
#include <string>
using namespace std;

class Vozilo {
private:
    string ime;
    int brojKotaca;

    // operator za ispis
    friend ostream& operator<<(ostream& out, const Vozilo& v) {
        out << "Ime: " << v.ime << ", Broj kotaca: " << v.brojKotaca;
        return out;
    }

    // operator za unos
    friend istream& operator>>(istream& in, Vozilo& v) {
        cout << "Unesite ime vozila: " << endl;
        in >> v.ime;
        cout << "Unesite broj kotaca: " << endl;
        in >> v.brojKotaca;
        return in;
    }
};

int main() {
    Vozilo v1, v2;

    cout << "Unos prvog vozila:" << endl;
    cin >> v1;

    cout << endl << "Unos drugog vozila:" << endl;
    cin >> v2;

    cout << endl << "Ispis vozila:" << endl;
    cout << v1 << endl;
    cout << v2 << endl;

    return 0;
}
