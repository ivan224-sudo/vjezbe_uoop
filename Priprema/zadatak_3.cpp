#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    map<string, vector<string>> slijedi;

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string linija;
        getline(cin, linija);

        istringstream iss(linija);
        string pratitelj, praceni;
        iss >> pratitelj >> praceni;

        slijedi[pratitelj].push_back(praceni);
    }

    string ime;
    getline(cin, ime);

    for (const string& s : slijedi[ime]) {
        cout << s << endl;
    }

    return 0;
}
