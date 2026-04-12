#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
    struct osoba{
        string ime;
        string prezime;
        int god_rod;
    };

    osoba ljudi[3] = {
        {"Ivan", "Horvat", 2006},
        {"Ana", "Kovac", 1999},
        {"Marko", "Maric", 1994}
    };

    for(int i=0;i<3;i++){
        cout<<setw(10)<<ljudi[i].prezime<<setw(10)<<ljudi[i].ime;
        cout<<setw(6)<<dec<<ljudi[i].god_rod<<setw(6)<<oct<<ljudi[i].god_rod<<setw(6)<<hex<<ljudi[i].god_rod;
        cout<<setw(12)<<ljudi[i].ime<<dec<<endl;

    }

    float pros_starost=0;
    float uk_starost=0;
    float godina=2026;
    for(int i=0;i<3;i++){
        uk_starost+=ljudi[i].god_rod;
    }

    pros_starost=uk_starost/3.0;
    pros_starost=godina-pros_starost;
    cout<<"Prosjecna starost: "<<pros_starost<<endl;


    osoba najmladi;
    najmladi=ljudi[0];

    if(ljudi[0].god_rod>najmladi.god_rod){
        najmladi=ljudi[1];
    }
    if(ljudi[1].god_rod>najmladi.god_rod){
        najmladi=ljudi[2];
    }

    cout<<"Najmladi :"<<najmladi.ime<<" "<<najmladi.prezime<<" "<<najmladi.god_rod<<endl;
    return 0;
}
