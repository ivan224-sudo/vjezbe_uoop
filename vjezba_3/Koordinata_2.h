#ifndef KOORDINATA_
#define KOORDINATA_

#include <iostream>
using namespace std;

class Koordinata
{
private:
    double x;
    double y;

public:
    Koordinata();
    ~Koordinata();

    double GetX()const;
    double GetY()const;

    void SetX(double x_);
    void SetY(double y_);

    friend ostream& operator<<(ostream& izlaz, const Koordinata& k);
    friend istream& operator>>(istream& ulaz, Koordinata& k);

    Koordinata operator+(const Koordinata& druga) const;
};

#endif // KOORDINATA_
