#include "Koordinata.h"

Koordinata::Koordinata()
{
    x=0;
    y=0;
}

Koordinata::~Koordinata(){}

//getteri
double Koordinata::GetX() const {return x;}
double Koordinata::GetY() const {return y;}

//setteri
void Koordinata::SetX(double x_){x=x_;}
void Koordinata::SetY(double y_){y=y_;}

ostream& operator<<(ostream& izlaz, const Koordinata& k){
    izlaz<<"("<<k.x<<","<<k.y<<")";
    return izlaz;
}
istream& operator>>(istream& ulaz, Koordinata& k){
    ulaz>>k.x>>k.y;
    return ulaz;
}

Koordinata Koordinata::operator+(const Koordinata& druga) const{
    Koordinata rezultat;
    rezultat.x=x+druga.x;
    rezultat.y=y+druga.y;
    return rezultat;
}
