#include <iostream>
#include <string>

using namespace std;

void Spoji(string tekst1, string tekst2, string &spojeno){
    spojeno=tekst1+tekst2;
}

int main()
{
    string tekst1,tekst2,spojeno;
    tekst1="Ovo ";
    tekst2="je spojeno";

    Spoji(tekst1,tekst2,spojeno);
    cout<<spojeno;
    return 0;
}
