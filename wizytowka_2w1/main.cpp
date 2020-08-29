#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

string imie, nazwisko, mail, hobby, nazwa;
int wybor;

int main()
{
    cout << "Podaj imie: "; cin>>wybor;
    if(wybor==1)
    {
        cout << "Podaj imie: "; cin>>imie;
        cout << "Podaj nazwisko: "; cin>>nazwisko;
        cout << "Podaj mail: "; cin>>mail;
        cout << "Jakie masz hobby? "; cin>>hobby;

        fstream plik;
        plik.open("wizytowka.txt", ios::out | ios::app);
        //ios:app jest opcjonalne, jesli chcemy miec wiecej wizytowek w jenym pliku

        plik<<imie<<endl;
        plik<<nazwisko<<endl;
        plik<<mail<<endl;
        plik<<"moje hobby to "<<hobby<<endl;

        plik.close();

    }
    else if(wybor==2)
    {
        fstream plik;
        plik.open("wizytowka.txt", ios::in);

        if(plik.good()==false)
        {
            cout<<"nie ma takiego pliku";
            exit(0);
        }

        string wyjscie;
        int ktora_linia=1;
        while(getline(plik, wyjscie))
        {
            switch(ktora_linia)
            {
                case 1: imie = wyjscie; break;
                case 2: nazwisko = wyjscie; break;
                case 3: mail = wyjscie; break;
                case 4: hobby = wyjscie; break;
            }

        ktora_linia++;
        }

        cout<<imie<<endl;
        cout<<nazwisko<<endl;
        cout<<mail<<endl;
        cout<<hobby<<endl;

        plik.close();

    }
    else if(wybor==3)
    {
        fstream plik;
        cout<<"wprowadz nazwe pliku, ktory chcesz utworzyc: ";
        cin>>nazwa;
        std::ofstream (nazwa);
;

        plik.close();

    }

    return 0;
}

