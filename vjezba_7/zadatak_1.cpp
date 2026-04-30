#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main() {
    vector<string> linije;
    ifstream file("ulaz.txt");
    string red;

    // a) ucitavanje iz file-a u vector
    while (getline(file, red)) {
        linije.push_back(red);
    }

    // a) range-based loop
    cout << "Range-based loop:" << endl;
    for (const auto& l : linije) {
        cout << l << endl;
    }

    // b) klasicni for loop
    cout << endl << "Normal for loop:" << endl;
    for (int i = 0; i < linije.size(); i++) {
        cout << linije[i] << endl;
    }

    // c) iteratorski ispis
    cout << endl << "Iterator loop:" << endl;
    for (auto it = linije.begin(); it != linije.end(); ++it) {
        cout << *it << endl;
    }

    // d) kopiranje u listu i ispis
    list<string> lista(linije.begin(), linije.end());

    cout << endl << "Lista (range loop):" << endl;
    for (const auto& l : lista) {
        cout << l << endl;
    }

    return 0;
}
