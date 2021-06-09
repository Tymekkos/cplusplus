#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
/*
Majac dany nastepujacy plik wejsciowy rozdzielany przecinkami:

Imie, Nazwisko, Wzrost

Jan, Nowak, 1.80

Zbigniew, Kowalski, 2.40

Tomasz, Kozak, 1.64

Klara, Rydz, 1.70
Wczytaj z niego danego korzystaj¹c uprzednio zadeklarowanej przez siebie struktury
(struct). Nastepnie posortuj te dane rosnaco (dowolnym algorytmem sortowania) wedlug
nazwiska i wypisz je na ekran ze stalymi odstepami. Na koncu zapisz dane posortowane do pliku
o nazwie "test2.txt".
*/
using namespace std;

struct data
{
    string imie;
    string nazwisko;
    double wzrost;

};

//NIEAKTUALNE
/*
void posortuj_po_nazwiskach(data *tab, int n)
{
    for(int i=0; i<n; i++)
    {
        char pierwsza_litera_char_i = tab[i].nazwisko[0];
        for(int j=0; j<n; j++)
        {
            char pierwsza_litera_char_j = tab[j].nazwisko[0];
            if(pierwsza_litera_char_i < pierwsza_litera_char_j)
            {
                data tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
    }
}
*/
void zamien(data* a, data* b)
{
    data tmp = *a;
    *a = *b;
    *b = tmp;
}

void posortuj_po_indexie(data *tab, int n, int index)
{
    char litera_i;
    char litera_j;
    for(int i=0; i<n; i++)
    {
        if(tab[i].nazwisko.length() > index)
        {
            litera_i = tab[i].nazwisko[index];
        }
        else
        {
            litera_i = 0;
        }

        for(int j=0; j<n; j++)
        {
            if(tab[j].nazwisko.length() > index)
            {
                litera_j = tab[j].nazwisko[index];
            }
            else
            {
                litera_j = 0;
            }

            if(litera_i < litera_j)
            {
                zamien(&tab[j], &tab[i]);
            }

        }
    }
}

void posortuj_po_nazwiskach(data * tab, int n, int max_name_len)
{
    for(int i=max_name_len; i>=0; i--)
    {
        posortuj_po_indexie(tab, n, i);
    }
}

int znajdz_dlugosc_najdluzszego(data* tab, int n)
{
    int wynik = 0;
    for(int i=0; i<n; i++)
    {
        if(tab[i].nazwisko.length() > wynik)
        {
            wynik = tab[i].nazwisko.length();
        }
    }
    return wynik;
}

int main()
{

    ifstream plik;
    plik.open("wejscie.txt");
    int n;
    plik >> n;
    data dane[n];
    for(int i=0; i<n; i++)
    {
        plik >> dane[i].imie >> dane[i].nazwisko >> dane[i].wzrost;
        cout << dane[i].imie << "  " << dane[i].nazwisko << "  " << dane[i].wzrost << endl;
    }
    cout << endl;
    posortuj_po_nazwiskach(dane, n, znajdz_dlugosc_najdluzszego(dane, n));
    for(int i=0; i<n; i++)
    {
        cout << dane[i].imie << "  " << dane[i].nazwisko << "  " << dane[i].wzrost << endl;
    }

    plik.close();
    return 0;
}
