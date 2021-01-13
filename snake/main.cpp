#include <iostream>
#include <conio.h> //getch()
#include <cstdlib> //system("cls")
#include <time.h>  //srand(time(NULL));
#include <windows.h> // Sleep()

using namespace std;

int szerokosc, wysokosc, szybkosc;
int gora, dol, lewo, prawo;
int wspolrzednaXweza, wspolrzednaYweza;
int wspolrzednaXjedzenia, wspolrzednaYjedzenia;
int klawisz;
int dlugosc=3, historiaWspolrzednejX[10000], historiaWspolrzednejY[10000];
int ile=0;
char waz=219, jedz1 = 91, jedz2 = 93, pdr = 217, pgr = 191, lgr=218, ldr=192, poz=196, pion = 179 ;
char kierunek ='p'; //p - prawo, l - lewo, g - gora, d - dol
char pole[35][35];
/* pole[0][0], pole[1][0], pole[2][0], pole[3][0], pole[4][0], pole[5][0], pole[6][0]... pole[34][0]
   pole[0][1], pole[1][1], pole[2][1], pole[3][1], pole[4][1], pole[5][1], pole[6][1]... pole[34][1]
   pole[0][2], pole[1][2], pole[2][2], pole[3][2], pole[4][2], pole[5][2], pole[6][2]... pole[34][2]
   .
   .
   .
   pole[0][34]
*/

// p - pole jest puste, w - na polu znajduje sie waz, j - na polu znjaduje sie jedzenie

int upomnienie(int &x)
{
    cout << "wybierz liczbe zgodna z przedzialem (10-35)" <<endl;
    cin >> x;
    if(x<5 || x>35) x = 15;
}


int main()
{
    cout << "podaj szerokosc planszy od 10 do 35:" << endl;
    cin >> szerokosc;
    if(szerokosc<10 || szerokosc>35) upomnienie(szerokosc);

    cout << "podaj wysokosc planszy od 10 do 35:" << endl;
    cin >> wysokosc;
    if(wysokosc<10 || wysokosc>35) upomnienie(wysokosc);

    cout << "podaj szybkosc weza 1 do 10:" << endl;
    cin >> szybkosc;
    if(szybkosc<1) szybkosc=1;
    if(szybkosc<10) szybkosc=10;

    cout << "nacisnij klawisze, ktorymi chcesz zagrac" << endl;
    cout << "GORA" << endl;
    gora=getch();
    if(gora==224)gora+=getch();
    if(gora==0)gora-=getch();

    cout << "DOL" << endl;
    dol=getch();
    if(dol==224)dol+=getch();
    if(dol==0)dol-=getch();

    cout << "LEWO" << endl;
    lewo=getch();
    if(lewo==224)lewo+=getch();
    if(lewo==0)lewo-=getch();

    cout << "PRAWO" << endl;
    prawo=getch();
    if(prawo==224)prawo+=getch();
    if(prawo==0)prawo-=getch();

    //tu nadajemy wartosci 'p' tablicy pole
    for(int i=0; i<wysokosc; i++)
    {
        for(int j=0; j<szerokosc; j++)
        {
            pole[j][i]='p';
        }
    }
    srand(time(NULL)); //losowosc
    //losowanie pola dla weza
    wspolrzednaXweza=rand()%szerokosc;
    wspolrzednaYweza=rand()%wysokosc;

    pole[wspolrzednaXweza][wspolrzednaYweza]='w';

    //losowanie pola dla jedzenia
    do //wykonuj
    {
    wspolrzednaXjedzenia=rand()%szerokosc;
    wspolrzednaYjedzenia=rand()%wysokosc;
    //dopoki pole wylosowane jest puste
    }while(pole[wspolrzednaXjedzenia][wspolrzednaYjedzenia] != 'p');
    pole[wspolrzednaXjedzenia][wspolrzednaYjedzenia]='j';

    //rozpoczecie gry
    for(;;)
    {
        ile++;
        historiaWspolrzednejX[ile]=wspolrzednaXweza;
        historiaWspolrzednejY[ile]=wspolrzednaYweza;

        //rysowanie planszy
        system("CLS"); //oczyszczenie ekranu
        //gorna ramka
        cout << lgr;
        for(int i=0; i<szerokosc; i++)
        {
            cout << poz << poz;
        }
        cout << pgr;



        for(int i=0; i<wysokosc; i++)
        {
            cout << endl <<pion; // lewa ramka
            for(int j=0; j<szerokosc; j++)
            {
                if(pole[j][i]=='p') cout << "  ";
                if(pole[j][i]=='w') cout << waz << waz;
                if(pole[j][i]=='j') cout << jedz1 << jedz2;
            }
            cout <<pion; // prawa ramka
        }
        cout << endl;
        //dolna ramka
        cout << ldr;
        for(int i=0; i<szerokosc; i++)
        {
            cout << poz << poz;
        }
        cout << pdr;
        Sleep(1000/szybkosc); //czekaj
        if(kbhit()) // jesli zostanie nacisniety jakis klawisz...
        {
            klawisz=getch();
            if(klawisz==224)klawisz+=getch();
            if(klawisz==0)klawisz-=getch();//dla klawiszy f1,f2,f3...

            if(klawisz==gora)kierunek='g';
            if(klawisz==dol)kierunek='d';
            if(klawisz==lewo)kierunek='l';
            if(klawisz==prawo)kierunek='p';
        }

        if (kierunek=='d')wspolrzednaYweza++;
        if (kierunek=='g')wspolrzednaYweza--;
        if (kierunek=='l')wspolrzednaXweza--;
        if (kierunek=='p')wspolrzednaXweza++;

        //przechodzenie przez sciany
        if(wspolrzednaXweza==szerokosc) wspolrzednaXweza=0;
        if(wspolrzednaXweza==-1) wspolrzednaXweza=szerokosc-1;
        if(wspolrzednaYweza==wysokosc) wspolrzednaYweza=0;
        if(wspolrzednaYweza==-1) wspolrzednaYweza=wysokosc-1;

        //co jesli wpadnie w siebie
        if(pole[wspolrzednaXweza][wspolrzednaYweza]=='w')
        {
            Sleep(4000);
            system("CLS");
            cout << "KONIEC" <<endl;
            cout << "twoj waz byl dlugosci " << dlugosc + 1 <<endl;
            Sleep(5000);
            break;
        }

        // co jesli zje jedzenie
        if(pole[wspolrzednaXweza][wspolrzednaYweza]=='j')
        {
            dlugosc++;
               //losowanie pola dla jedzenia
            do //wykonuj
            {
                wspolrzednaXjedzenia=rand()%szerokosc;
                wspolrzednaYjedzenia=rand()%wysokosc;
                //dopoki pole wylosowane jest puste
            }while(pole[wspolrzednaXjedzenia][wspolrzednaYjedzenia] != 'p');

        pole[wspolrzednaXjedzenia][wspolrzednaYjedzenia]='j';
        }
        else
        //kasowanie ogona
        pole[historiaWspolrzednejX[ile-dlugosc]][historiaWspolrzednejY[ile-dlugosc]] = 'p';

        pole[wspolrzednaXweza][wspolrzednaYweza] = 'w';

    }
    //koniec petli for

    return 0;
}
