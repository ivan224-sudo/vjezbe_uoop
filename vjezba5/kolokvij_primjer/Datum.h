#ifndef DATUM_H
#define DATUM_H

#include <iostream>
using namespace std;

class Datum {
private:
    int dan, mjesec, godina;
    static int format;

public:
    Datum(int d, int m, int g);

    void setDan(int d);
    void setMjesec(int m);
    void setGodina(int g);

    int getDan() const;
    int getMjesec() const;
    int getGodina() const;

    static void setFormat(int f);

    friend ostream& operator<<(ostream& out, const Datum& d);
};

#endif
