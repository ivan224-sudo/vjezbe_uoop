#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    vector<int> brojevi;
    string linija;
    getline(cin, linija);

    istringstream iss(linija);
    int x;
    while (iss >> x) {
        brojevi.push_back(x);
    }

    int n;
    cin >> n;

    bool nadjen = false;
    for (int b : brojevi) {
        if (b == n) {
            nadjen = true;
            break;
        }
    }

    cout << (nadjen ? "DA" : "NE") << endl;

    return 0;
}
