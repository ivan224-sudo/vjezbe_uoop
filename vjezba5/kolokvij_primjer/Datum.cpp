#include "Datum.h"

// inicijalizacija static člana
int Datum::format = 0;

// konstruktor
Datum::Datum(int d, int m, int g) {
    dan = d;
    mjesec = m;
    godina = g;
}

// setteri
void Datum::setDan(int d) { dan = d; }
void Datum::setMjesec(int m) { mjesec = m; }
void Datum::setGodina(int g) { godina = g; }

// getteri
int Datum::getDan() const { return dan; }
int Datum::getMjesec() const { return mjesec; }
int Datum::getGodina() const { return godina; }

// static setter
void Datum::setFormat(int f) {
    format = f;
}

// operator <<
ostream& operator<<(ostream& out, const Datum& d) {

    if (Datum::format == 0) {
        out << d.godina << "-"
            << (d.mjesec < 10 ? "0" : "") << d.mjesec << "-"
            << (d.dan < 10 ? "0" : "") << d.dan;
    }
    else if (Datum::format == 1) {
        out << (d.dan < 10 ? "0" : "") << d.dan << "."
            << (d.mjesec < 10 ? "0" : "") << d.mjesec << "."
            << d.godina;
    }
    else {
        out << (d.mjesec < 10 ? "0" : "") << d.mjesec << "/"
            << (d.dan < 10 ? "0" : "") << d.dan << "/"
            << d.godina;
    }

    return out;
}
