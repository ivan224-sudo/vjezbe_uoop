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
    Proizvod p;

    cout<<left<<setw(10)<<"sifra"<<setw(15)<<"naziv"<<setw(10)<<"kolicina"
    <<setw(10)<<"bez PDV"<<setw(10)<<"PDV %"<<setw(15)<<"Cijena PDV"<<setw(15)<<"Stavka"<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;


    double ukupnoBez = 0;
    double ukupnoSa = 0;
    double ukupnoPDV = 0;
    while(file>>p){
        ukupnoBez += p.GetIznosBezPDV();
        ukupnoSa  += p.GetIznosSaPDV();
        ukupnoPDV += p.GetIznosPDV();
        cout<<left<<setw(10)<<p.GetSifra()
        <<setw(15)<<p.GetNaziv()
        <<setw(10)<<p.GetKolicina()
        <<setw(10)<<fixed<<setprecision(2)<<p.GetCijena()
        <<setw(10)<<p.GetPDV()
        <<setw(15)<<p.GetCijenaPDV()
        <<setw(15)<<p.GetStavka()<<endl;
    }
    cout<<endl;
    cout<<setw(17)<<"Ukupno bez PDV: "<<ukupnoBez<<endl;
    cout<<setw(17)<<"Ukupno PDV: "<<ukupnoPDV<<endl;
    cout<<setw(17)<<"Ukupno: "<<ukupnoSa<<endl;
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
