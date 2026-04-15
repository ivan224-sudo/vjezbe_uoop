#include <iostream>
#include <fstream>
#include <iomanip>
#include "proizvod.h"

using namespace std;

void ispisi(string imedat){
    ifstream file(imedat);
    if(!file){
        cout << "ne mogu otvoriti" << endl;
        return;
    }
    double pdv;
    file >> pdv;
    Proizvod p;
    cout << "PDV: " << pdv << "%" << endl << endl;

    cout<<left<<setw(10)<<"sifra"<<setw(10)<<"naziv"<<setw(10)<<"kolicina"
    <<setw(10)<<"bez pdv"<<setw(15)<<"cijena_pdv"<<setw(15)<<"iznos"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;

    double ukupno = 0;

    while(file>>p){
        double stavka = p.GetCijenaPDV(pdv) * p.GetKolicina();
        ukupno += stavka;

        cout<<left<<setw(10)<<p.GetSifra()
        <<setw(10)<<p.GetNaziv()<<setw(10)<<p.GetKolicina()
        <<setw(10)<<fixed<<setprecision(2)<<p.GetCijena()
        <<setw(15)<<p.GetCijenaPDV(pdv)
        <<setw(15)<<p.GetIznos(pdv)<<endl;
    }
    cout<<endl;
    cout<<"Ukupno s PDV-om "<<ukupno<<endl;
    cout << defaultfloat;
    file.close();
}

void upisi(string imedat){
    ofstream file(imedat, ios::app);
    if(!file){
        cout << "ne mogu otvoriti" << endl;
        return;
    }
    int broj_proiz;
    cout<<"koliko proizvoda?";
    cin>>broj_proiz;
    Proizvod p;

    for(int i=0;i<broj_proiz;i++){
        cin>>p;
        file<<p;
    }
    file.close();
}
int main(int argc, char* argv[])
{
    if(argc < 2){
        cout << "nema datoteke" << endl;
        return 1;
    }
    string imedat = argv[1];

    int izbor=-1;
    do{
        cout<<"----Izbornik----"<<endl;
        cout<<"1 - Upis u datoteku"<<endl;
        cout<<"2 - Ispis iz datoteke"<<endl;
        cout<<"0 - Izlaz"<<endl;
        cout<<"Izbor: ";
        cin>>izbor;
        if(izbor==1){
            upisi(imedat);
        }
        else if(izbor==2){
            ispisi(imedat);
        }
    }while(izbor!=0);
    return 0;
}
