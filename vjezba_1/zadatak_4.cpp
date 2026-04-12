#include <iostream>
#include <string>
#include <sstream>

int main() {

    // "using namespace std;"


    using namespace std;
    string jmbg;
    cout << "Unesite JMBG: ";
    cin >> jmbg;

    string datum = jmbg.substr(0, 7);

    cout << "Datum rodenja (znak po znak): ";
    for(char c : datum) {
        cout << c << " ";
    }
    cout << endl;

    int zbroj = 0;
    for(char c : datum) {
        if(isdigit(c))
            zbroj += c - '0';
    }

    cout << "Zbroj znamenki: " << zbroj << endl;

    stringstream ss;
    ss << zbroj;
    string zbrojStr = ss.str();
    cout << "Zbroj kao string: " << zbrojStr << endl;


    //bez "using namespace std;"


    std::string jmbg2;
    std::cout << "Unesite JMBG: ";
    std::cin >> jmbg2;

    std::string datum2 = jmbg2.substr(0, 7);

    std::cout << "Datum rodenja (znak po znak): ";
    for(char c : datum2) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    int zbroj2 = 0;
    for(char c : datum2) {
        if(std::isdigit(c))
            zbroj2 += c - '0';
    }

    std::cout << "Zbroj znamenki: " << zbroj2 << std::endl;

    std::stringstream ss2;
    ss2 << zbroj2;
    std::string zbrojStr2 = ss2.str();
    std::cout << "Zbroj kao string: " << zbrojStr2 << std::endl;

    return 0;
}
