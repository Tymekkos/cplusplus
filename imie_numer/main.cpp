#include <iostream>

using namespace std;

string imie; int numer;

int main()
{
    cout <<"jak masz na imie:";
    cin >>imie;
    cout <<"wybierz numer:";
    cin >>numer;

    for (int i=1; i<=numer; i++)
    {
        cout<<i<<". "<<imie<<endl;
    }
    return 0;
}
