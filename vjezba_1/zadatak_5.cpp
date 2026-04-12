#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct vozilo{
    string naziv;
    string model;
    string reg_oznaka;
    float predjeni_km;
    float gorivo_l;
};

int main(){
    vozilo auta[2] = {
        {"BMW", "2002", "KC-PROBA", 202564, 21010},
        {"AUDI", "A8-118d", "KC-FRAJER", 150000, 7000}
    };

    cout << left << setw(15) << "Naziv" << setw(10) << "Model" << setw(10) << "Reg.ozn" << setw(10) << "Km" << setw(10) << "Gorivo" << setw(25) << "Opis potrosnje" << endl;

    float ukupna_potrosnja = 0;

    for(int i = 0; i < 2; i++){
        float potrosnja100 = auta[i].gorivo_l / auta[i].predjeni_km * 100;
        ukupna_potrosnja += potrosnja100;
        string opis;

        if(potrosnja100 < 6)
            opis = "stedljivo vozilo";
        else if(potrosnja100 <= 10)
            opis = "standardno";
        else
            opis = "vozilo s visokom potrosnjom";

        cout << left << setw(15) << auta[i].naziv << setw(10) << auta[i].model << setw(10) << auta[i].reg_oznaka << setw(10) << auta[i].predjeni_km << setw(10) << auta[i].gorivo_l << setw(25) << opis << endl;
    }

    cout << "Prosjecna potrosnja za oba vozila: " << ukupna_potrosnja / 2 << " L/100km" << endl;

    return 0;
}
