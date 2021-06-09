#include <iostream>

/*
a) Zadeklaruj strukturê postaci: imiê, nazwisko, wzrost, waga (wzrost jest liczb¹ ca³kowit¹
i jest podany w centymetrach; waga jest liczb¹ rzeczywist¹ i podana jest w kilogramach).
b) Napisz funkcjê przyjmuj¹c¹ jeden parametr (wskaŸnik na utworzon¹ przez siebie strukturê)
i pozwalaj¹c¹ na ustawienie wszystkich trzech pól wartoœciami przeczytanymi od
u¿ytkownika z klawiatury.
c) Napisz funkcjê wypisuj¹c¹ wartoœci elementów struktury (przyk³adowe wyjœcie „Jan
Kowal 175cm 73,5kg”).
d) W funkcji main():
a. Pobierz od u¿ytkownika wartoœæ typu int.
b. Zadeklaruj dynamicznie alokowan¹ tablicê o rozmiarze pobranym wczeœniej od
u¿ytkownika w punkcie a.
c. Pobierz od u¿ytkownika dane osób do wype³nienia tej tablicy.
d. Wypisz ca³¹ tablicê struktur na ekran. W tym celu u¿yj funkcji napisanej
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
