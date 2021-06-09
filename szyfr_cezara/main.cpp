#include <iostream>
#include <string>
using namespace std;

string szyfruj( string tekst, int klucz )
{
    int i = 0;
    int spacja = 0;
    int ilosc_liter = 'z' - 'a' + 1;
    klucz = klucz % ilosc_liter;
    while( tekst[i] != '\0' )
    {
        tekst[i] += klucz;
        // w poni¿szej linijce jest rzutowanie, dlatego ¿e wartoœci w tekst mog¹ wyjœæ ujemne po dodaniu klucza (np 'z'+10)
        if((char) tekst[i] > 'z' ) tekst[i] -= ilosc_liter;

        if((char) tekst[i] < 'a' ) tekst[i] += ilosc_liter;

        if((char) tekst[i] == ' ' ) tekst[i] += spacja;

        i++;
    }
    return tekst;
}
int main()
{
    string tekst;
    int k;
    cout << "Podaj tekst do zaszyfrowania tylko male litery: ";
    cin >> tekst;
    cout << "Podaj klucz szyfru: ";
    cin >> k;
    tekst = szyfruj( tekst, k );
    cout << tekst;
    return 0;
}



