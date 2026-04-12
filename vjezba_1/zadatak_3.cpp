#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){

    struct djelatnik{
        string ime;
        string prezime;
        float predeni_km;
        float priznato_iznos;
    };

    djelatnik ljudi[3] = {
        {"Ivan", "Horvat", 120.5, 35.50},
        {"Ana", "Kovac", 200.0, 40.00},
        {"Marko", "Novak", 150.3, 300.75}
    };

    cout << fixed << setprecision(2);

    // ispis tablice
    cout<<setw(10)<<"Ime"<<setw(10)<<"Prezime"<<setw(12)<<"Ukupno"<<endl;

    for(int i=0; i<3; i++){
        float ukupno = ljudi[i].priznato_iznos + ljudi[i].predeni_km*0.2;
        cout<<setw(10)<<ljudi[i].ime<<setw(10)<<ljudi[i].prezime<<setw(12)<<ukupno<< endl;
    }


    djelatnik najdulji = ljudi[0];
    djelatnik najveca_isplata = ljudi[0];

    for(int i = 1; i < 3; i++){
        if(ljudi[i].predeni_km > najdulji.predeni_km){
            najdulji = ljudi[i];
        }

        float isplata_i = ljudi[i].priznato_iznos + ljudi[i].predeni_km*0.2;
        float najveca_isplata_iznos = najveca_isplata.priznato_iznos + najveca_isplata.predeni_km*0.2;

        if(isplata_i > najveca_isplata_iznos){
            najveca_isplata = ljudi[i];
        }
    }

    cout << "Djelatnik koji je prosao najdulji put: "
         << najdulji.ime << " " << najdulji.prezime
         << " (" << najdulji.predeni_km << " km)" << endl;

    cout << "Djelatnik kojem ce se isplatiti najveci iznos: "
         << najveca_isplata.ime << " " << najveca_isplata.prezime
         << " (ukupno " << najveca_isplata.priznato_iznos + najveca_isplata.predeni_km*0.2 << " EUR)" << endl;

    return 0;
}
