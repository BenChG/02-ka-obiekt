#include "UzytkownikMenedzer.h"

Uzytkownik UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik;
    MetodyPomocnicze metodyPomocnicze;

    string nazwaUzytkownika, hasloUzytkownika;
    int idUzytkownika=1;

    cout << "Podaj nazwe uzytkownika: ";
    nazwaUzytkownika = metodyPomocnicze.wczytajLinie();

    cout << "Podaj haslo uzytkownika: ";
    hasloUzytkownika = metodyPomocnicze.wczytajLinie();


    /*
    if (uzytkownicy.size()>=1)
    {
        int ostatniElement=linieAdresatow.size()-1;
        id=atoi(linieAdresatow[ostatniElement].c_str())+1;
    }
    */

    uzytkownik.ustawIdUzytkownika(idUzytkownika);
    uzytkownik.ustawNazweUzytkownika(nazwaUzytkownika);
    uzytkownik.ustawHasloUzytkownika(hasloUzytkownika);

    uzytkownicy.push_back(uzytkownik);

    fstream plik;
    plik.open("Uzytkownicy.txt",ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << uzytkownik.pobierzIdUzytkownika();
        plik << "|";
        plik << uzytkownik.pobierzNazweUzytkownika();
        plik << "|";
        plik << uzytkownik.pobierzHasloUzytkownika();
        plik << "|";
        plik << endl;
        plik.close();

    cout << endl << "Uzytkownik zostal dodany." << endl;
    cout << "Wielkosc wektora uzytkownicy: " << uzytkownicy.size() << endl << endl;
    }

    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl << endl;
    }

    system("pause");

    //linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
    return uzytkownik;
}

void UzytkownikMenedzer::wyswietlDaneUzytkownika(Uzytkownik uzytkownik)
{
    cout << "Id Uzytkownika:       " << uzytkownik.pobierzIdUzytkownika() << endl;
    cout << "Nazwa uzytkownika:    " << uzytkownik.pobierzNazweUzytkownika() << endl;
    cout << "Haslo Uzytkownia:     " << uzytkownik.pobierzHasloUzytkownika() << endl;
}

void UzytkownikMenedzer::wyswietlWszystkichUzytkownikow()
{
    system("cls");

    if (!uzytkownicy.empty())
    {
        cout << "             >>> UZYTKOWNICY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Uzytkownik> :: iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            wyswietlDaneUzytkownika(*itr);
            cout << endl;
        }
        cout << endl;
    }

    else
    {
        cout << endl << "Ksiazka uzytkownikow jest pusta." << endl << endl;
    }
    system("pause");
}
