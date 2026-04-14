#include <iostream>

using namespace std;

int Suma(int n){
    int suma=0;
    for(int i=1;i<=n;i++)
        suma+=i;
    return suma;

}

long long int Produkt(int n){
    int produkt=1;
    for(int i=1;i<=n;i++)
        produkt*=i;
    return produkt;
}

void SumaProdukt(int n, int &suma, long long int &produkt){
    suma=Suma(n);
    produkt=Produkt(n);
}

void SumaProduktPtr(int n, int *suma, long long int *produkt){
    *suma=Suma(n);
    *produkt=Produkt(n);
}
    cin>>n;
    cout<<"Suma :"<<Suma(n)<<endl<<"Produkt: "<<Produkt(n)<<endl;

    int suma1=0;
    long long int produkt1=1;
    SumaProdukt(n, suma1, produkt1);
    cout<<"Reference"<<endl;
    cout<<"Suma: "<<suma1<<endl<<"Podukt :"<<produkt1<<endl;

    int suma2=0;
    long long int produkt2=1;
    SumaProduktPtr(n, &suma2, &produkt2);
    cout<<"Pokazivaci"<<endl;
    cout<<"Suma: "<<suma1<<endl<<"Podukt :"<<produkt1<<endl;
    return 0;
}
