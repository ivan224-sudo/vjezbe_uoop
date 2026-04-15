#include "proizvod.h"

//konstruktor
Proizvod::Proizvod(){
    sifra = 0;
    naziv = "";
    kolicina = 0;
    cijena = 0.0;
    pdv=0.0;
}
//destruktor
Proizvod::~Proizvod(){}

//getteri
int Proizvod::GetSifra() const {return sifra;}
string Proizvod::GetNaziv() const {return naziv;}
int Proizvod::GetKolicina() const {return kolicina;}
double Proizvod::GetCijena() const {return cijena;}
double Proizvod::GetPDV() const {return pdv;}

//setteri
void Proizvod::SetSifra(int s){sifra=s;}
void Proizvod::SetNaziv(string n){naziv=n;}
void Proizvod::SetKolicina(int k){kolicina=k;}
void Proizvod::SetCijena(double c){cijena=c;}
void Proizvod::SetPDV(double pd){pdv=pd;}

//operator <<
ostream& operator<<(ostream& izlaz, const Proizvod& p){
    izlaz<<p.sifra<<" "<<p.naziv<<" "<<p.kolicina<<" "<<p.cijena<<" "<<p.pdv<<endl;
    return izlaz;
}
//operator >>
istream& operator>>(istream& ulaz, Proizvod& p)
{
    string pdvStr;
    ulaz >> p.sifra >> p.naziv >> p.kolicina >> p.cijena >> pdvStr; if (!ulaz) return ulaz; if (!pdvStr.empty() && pdvStr.back() == '%') pdvStr.pop_back(); p.pdv = stod(pdvStr);
    return ulaz;
}

//funkcija pdv
double Proizvod::GetCijenaPDV(){
    return cijena+(cijena*pdv/100);
}

//funkcija za stavku
double Proizvod::GetStavka(){
    return GetCijenaPDV()*kolicina;
}

double Proizvod::GetIznosBezPDV(){
    return cijena*kolicina;
}

double Proizvod::GetIznosSaPDV(){
    return GetCijenaPDV()*kolicina;
}

double Proizvod::GetIznosPDV(){
    return GetIznosSaPDV()-GetIznosBezPDV();
}
