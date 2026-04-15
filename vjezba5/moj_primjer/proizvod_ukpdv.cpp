#include "proizvod.h"

//konstruktor
Proizvod::Proizvod(){
    sifra = 0;
    naziv = "";
    kolicina = 0;
    cijena = 0.0;
}
//destruktor
Proizvod::~Proizvod(){}

//getteri
int Proizvod::GetSifra() const {return sifra;}
string Proizvod::GetNaziv() const {return naziv;}
int Proizvod::GetKolicina() const {return kolicina;}
double Proizvod::GetCijena() const {return cijena;}

//setteri
void Proizvod::SetSifra(int s){sifra=s;}
void Proizvod::SetNaziv(string n){naziv=n;}
void Proizvod::SetKolicina(int k){kolicina=k;}
void Proizvod::SetCijena(double c){cijena=c;}

//operator <<
ostream& operator<<(ostream& izlaz, const Proizvod& p){
    izlaz<<p.sifra<<" "<<p.naziv<<" "<<p.kolicina<<" "<<p.cijena<<endl;
    return izlaz;
}
//operator >>
istream& operator>>(istream& ulaz, Proizvod& p){
ulaz>>p.sifra;
ulaz>>p.naziv;
ulaz>>p.kolicina;
ulaz>>p.cijena;
return ulaz;
}

//funkcija pdv
double Proizvod::GetCijenaPDV(double pdv){
    return cijena+(cijena*pdv/100);
}

//funkcija za iznos
double Proizvod::GetIznos(double pdv){
    return kolicina*GetCijenaPDV(pdv);
}
