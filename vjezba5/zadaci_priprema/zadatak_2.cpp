#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float br1,br2=0;
    cout<<"Unesi dva broja:"<<endl;
    cin>>br1>>br2;
    cout<<setw(10)<<fixed<<setprecision(5)<<(br1+br2)/2<<endl;
}
