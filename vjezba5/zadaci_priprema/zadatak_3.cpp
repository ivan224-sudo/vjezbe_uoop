#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Zivotinja{
public:
    string ime;
    int kolikoZivih;
    float prosjecnaTezina;

    void ispis() const{
        cout<<setw(15)<<ime;
        cout<<setw(15)<<kolikoZivih;
        cout<<setw(15)<<prosjecnaTezina<<endl;
    }
};
int main()
{
    Zivotinja z1 = {"Pas", 900000, 15.5};
    Zivotinja z2 = {"Macka", 600000, 4.3};
    Zivotinja z3 = {"Slon", 50000, 5400.75};
    Zivotinja z4 = {"Lav", 20000, 190.8};
    cout<<setw(15)<<"Ime";
    cout<<setw(15)<<"Zivih";
    cout<<setw(15)<<"Prosj Tezina"<<endl;

    z1.ispis();
    z2.ispis();
    z3.ispis();
    z4.ispis();

    return 0;
}
