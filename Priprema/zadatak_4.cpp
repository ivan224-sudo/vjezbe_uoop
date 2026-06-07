#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
void ucitajIIspisiSortirano() {
    vector<T> podaci;
    cin.ignore();

    T vrijednost;
    while (cin >> vrijednost) {
        podaci.push_back(vrijednost);
    }

    sort(podaci.begin(), podaci.end());

    for (const T& v : podaci) {
        cout << v << endl;
    }
}

int main() {
    string tip;
    cin >> tip;
    if (tip == "double")
        ucitajIIspisiSortirano<double>();
    if (tip == "string")
        ucitajIIspisiSortirano<string>();
    return 0;
}
