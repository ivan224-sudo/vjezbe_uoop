#include <iostream>
#include <list>

using namespace std;

int main() {

    list<int> brojevi;
    int x;

    // unos do kraja streama (Ctrl+Z pa Enter)
    while (cin >> x) {
        brojevi.push_back(x);
    }

    // ispis u obrnutom poretku
    list<int>::reverse_iterator it;

    for (it = brojevi.rbegin(); it != brojevi.rend(); it++) {
        cout << *it << " ";
    }

    return 0;
}
