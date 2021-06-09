#include <iostream>
/*
Napisz program drukuj¹cy na ekranie prostok¹t z literek X. Wysokoœæ i szerokoœæ prostok¹ta
wczytujemy z klawiatury:
pusty
XXXXXXXXXX
X        X
X        X
XXXXXXXXXX
pe³ny
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
Wynik zapisz równie¿ do pliku
*/
using namespace std;

int main()
{
    int wys, szer;
    cout << "podaj wysokosc: ";
    cin >> wys;
    cout << "podaj szerokosc: ";
    cin >> szer;
    cout << endl;
    cout << "pusty" << endl;
    for(int i=0; i<wys; i++)
    {
        for(int j=0; j<szer; j++)
        {
            if(i>0 && i<wys-1)
            {
                if(j>0 && j<szer-1)
                {
                    cout << "  ";
                }
                else
                {
                    cout << "x ";
                }
            }
            else
            {
               cout << "x ";
            }
        }
        cout << endl;
    }
    cout << "pelny" << endl;
    for(int i=0; i<wys; i++)
    {
        for(int j=0; j<szer; j++)
        {
            cout << "x ";
        }
        cout << endl;
    }
    return 0;
}
