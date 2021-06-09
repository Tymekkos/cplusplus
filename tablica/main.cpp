#include <iostream>

/*
a) Zadeklaruj struktur� postaci: imi�, nazwisko, wzrost, waga (wzrost jest liczb� ca�kowit�
i jest podany w centymetrach; waga jest liczb� rzeczywist� i podana jest w kilogramach).
b) Napisz funkcj� przyjmuj�c� jeden parametr (wska�nik na utworzon� przez siebie struktur�)
i pozwalaj�c� na ustawienie wszystkich trzech p�l warto�ciami przeczytanymi od
u�ytkownika z klawiatury.
c) Napisz funkcj� wypisuj�c� warto�ci element�w struktury (przyk�adowe wyj�cie �Jan
Kowal 175cm 73,5kg�).
d) W funkcji main():
a. Pobierz od u�ytkownika warto�� typu int.
b. Zadeklaruj dynamicznie alokowan� tablic� o rozmiarze pobranym wcze�niej od
u�ytkownika w punkcie a.
c. Pobierz od u�ytkownika dane os�b do wype�nienia tej tablicy.
d. Wypisz ca�� tablic� struktur na ekran. W tym celu u�yj funkcji napisanej
w punkcie 3.
*/
using namespace std;

struct student
{
    string imie;
    string nazwisko;
    int wzrost;
    int waga;

    void setImie()
    {
        cout << "podaj imie: ";
        cin >> imie;
    }
    string getImie()
    {
        return imie;
    }

    void setNazwisko()
    {
        cout << "podaj nazwisko: ";
        cin >> nazwisko;
    }
    string getNazwisko()
    {
        return nazwisko;
    }

    void setWzrost()
    {
        cout << "podaj wzrost: ";
        cin >> wzrost;
    }
    int getWzrost()
    {
        return wzrost;
    }

    void setWaga()
    {
        cout << "podaj wage: ";
        cin >> waga;
    }
    int getWaga()
    {
        return waga;
    }

    void wypisywanie()
    {
        cout << imie << " " << nazwisko << " " << wzrost << " " << waga << endl;
    }

};

int main()
{
    student *students = new student[1];
    //wypisywanie(students, 1);
    students[0].setImie();
    students[0].setNazwisko();
    students[0].setWzrost();
    students[0].setWaga();
    students[0].wypisywanie();
    /*
    cout << students[0].getImie() << endl;
    cout << students[0].getNazwisko() << endl;
    cout << students[0].getWzrost() << endl;
    cout << students[0].getWaga() << endl;
    */
    return 0;
}
