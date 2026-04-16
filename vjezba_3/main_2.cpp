#include <iostream>
#include "Koordinata.h"

using namespace std;

int main()
{
    Koordinata k1,k2;
    cout<<"unos prve koordinate: "<<endl;
    cin>>k1;

    cout<<"unos druge koordinate: "<<endl;
    cin>>k2;

    cout<<k1<<endl;
    cout<<k2<<endl;

    Koordinata k3=k1+k2;
    cout<<k3;
    return 0;
}
