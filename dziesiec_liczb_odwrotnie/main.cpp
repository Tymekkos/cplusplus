#include <iostream>

using namespace std;

int tab[100];

int main (int arqc, char * argv [])
{
    cout << "Podaj 10 liczb : ";
    for (int i=0;i<10;i++)
    {
        cin >> tab[i];
    }
    cout << endl;
    cout << "Te same liczby w odwrotnej kolejnosci: ";
    for (int i=9;i>=0; i--)
    {
        cout << tab[i]<<" ";
    }


    return 0;
}
