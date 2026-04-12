#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){

    struct proizvod{
        string ime;
        float cijena;
        int prodano_kom;
    };

    proizvod proizvodi[3] = {
        {"Kruh", 1.50, 10},
        {"Mlijeko", 1.20, 8},
        {"Cokolada", 2.80, 5}
    };

    float ukupno_racun = 0;
    float ukupno_pdv = 0;

    cout << setw(12) << "naziv"
         << setw(10) << "cijena"
         << setw(10) << "kolicina"
         << setw(12) << "uk_cijena"
         << setw(10) << "PDV" << endl;

    for(int i = 0; i < 3; i++)
    {
        float ukupno = proizvodi[i].cijena * proizvodi[i].prodano_kom;
        float pdv = ukupno * 0.25;

        ukupno_racun += ukupno + pdv;
        ukupno_pdv += pdv;

        cout << setw(12) << proizvodi[i].ime
             << setw(10) << proizvodi[i].cijena
             << setw(10) << proizvodi[i].prodano_kom
             << setw(12) << ukupno
             << setw(10) << pdv
             << endl;
    }

    cout << endl;
    cout << "Ukupno za naplatu: " << ukupno_racun << endl;
    cout << "Ukupni PDV: " << ukupno_pdv << endl;

    proizvod najskuplji = proizvodi[0];

    for(int i = 1; i < 3; i++){
        if(proizvodi[i].cijena > najskuplji.cijena){
            najskuplji = proizvodi[i];
        }
    }

    cout << "Najskuplji proizvod: " << najskuplji.ime << endl;

    return 0;
}
