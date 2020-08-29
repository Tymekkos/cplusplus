#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int ile;
clock_t start, stop;
double czas;
void sortowanie_babelkowe(int *tab, int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=n-1; j>=1; j--)
        {
            if(tab[j]<tab[j-1])
            {
                int bufor;
                bufor=tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=bufor;
            }
        }
    }
}

int main()
{
    cout << "porownanie czasow sortowania" << endl;

    cout << "ile losowych liczb w tablicy: ";
    cin >>ile;

    int *tablica;
    tablica = new int [ile];

    srand(time(NULL));

    for(int i=0; i<ile; i++)
    {
        tablica[i] = rand()%10000+1;
    }

    cout<<"Przed sortowaniem: "<<endl;
    for(int i=0; i<ile; i++)
    {
        cout<<tablica[i]<<" ";
    }

    cout << "sortowanie babelkowe..."<< endl;

    start = clock();

    sortowanie_babelkowe(tablica,ile);

    stop = clock();

    czas = (double)(stop-start) / CLOCKS_PER_SEC;

    cout<<"po sortowaniu:"<<endl;
    for(int i=0; i<ile; i++)
    {
        cout<<tablica[i]<<" ";
    }
    cout <<endl<< "czas w ktorym liczby zostaly posortowane: "<<czas<<" s"<< endl;

    delete [] tablica;

    return 0;
}
