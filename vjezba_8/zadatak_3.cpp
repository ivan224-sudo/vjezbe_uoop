#include <iostream>
#include <deque>
#include <string>

using namespace std;

// Vlastita klasa Stack
class Stack {
private:
    deque<string> podaci;

public:
    // Dodaje element na vrh stoga
    void push(const string& s) {
        podaci.push_back(s);
    }

    // Miče i vraća element s vrha stoga
    string pop() {
        string vrh = podaci.back();
        podaci.pop_back();
        return vrh;
    }

    // Provjerava je li stog prazan
    bool empty() const {
        return podaci.empty();
    }
};

int main() {
    Stack stog;
    string rijec;

    // Učitavanje riječi i spremanje na stog
    while (cin >> rijec) {
        stog.push(rijec);
    }

    // Ispis u obrnutom poretku
    while (!stog.empty()) {
        cout << stog.pop() << endl;
    }

    return 0;
}
