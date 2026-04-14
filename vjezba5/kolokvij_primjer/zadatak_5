#include <iostream>
#include <string>
using namespace std;

// funkcija koja prima polje po referenci
float uvecajZaPDV(float (&polje)[], int size) {
    float suma = 0;

    for (int i = 0; i < size; i++) {
        polje[i] = polje[i] * 1.25; // +25% PDV
        suma += polje[i];
    }

    return suma;
}

int main()
{
    float polje[]={3.1,4.1,5.9,2.6,5.3,5.9};

    float suma=uvecajZaPDV(polje, 6);

    for(int i=0;i<6;i++){
        cout<<polje[i]<<endl;
    }

    cout<<"Suma je: "<<suma<<endl;
}
