#include <iostream>

using namespace std;

float meters;

float liczba_cali(float m)
{
    return m*39.37;
}
float liczba_jardow(float m)
{
    return m*1.094;
}
float liczba_stop(float m)
{
    return m*0.3048;
}
float liczba_aligatorow(float m)
{
    return m*0.3636363636363636363636363636363636;
}


int main()
{
    cout << "podaj liczbe metrow: " << endl;
    cin>>meters;

    cout <<"to: "<<endl<<liczba_cali(meters)<<" [In]"<<endl;
    cout <<liczba_jardow(meters)<<" [Yd]"<<endl;
    cout <<liczba_stop(meters)<<" [Ft]"<<endl;
    cout <<liczba_aligatorow(meters)<<" [szt. aligatora]"<<endl;



    return 0;
}
