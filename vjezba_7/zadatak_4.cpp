#include <iostream>
#include <vector>

using namespace std;

// operator za skalarni produkt
int operator*(const vector<int>& a, const vector<int>& b) {
    int rezultat = 0;
    for (int i = 0; i < a.size(); i++) {
        rezultat += a[i] * b[i];
    }
    return rezultat;
}

int main() {
    int n;
    cout << "Unesite n:" << endl;
    cin >> n;

    vector<int> v1(n), v2(n);

    cout << "Unesite elemente prvog vektora:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }

    cout << "Unesite elemente drugog vektora:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
    }

    int skalarni = v1 * v2;

    cout << "Skalarni produkt: " << skalarni << endl;

    return 0;
}
