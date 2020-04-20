#include "PlikiZUzytkownikami.h"

vector <Uzytkownik> PlikiZUzytkownikami::wczytajUzytkownikowZPliku()
{
    vector <Uzytkownik> uzytkownicy;
    Uzytkownik uzytkownik;
    uzytkownicy.clear();

    string nazwaUzytkownika;
    string hasloUzytkownika;
    string nowyWyraz;
    string linia;
    int idUzytkownika;
    int ostatniZnak[3];

    plik.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(),ios::in);

    if (plik.good() == true)
    {
        while(getline(plik,linia))
        {
            int k=0, pierwszyZnak=0, dlugoscLinii=linia.length();

            for (int i=0; i<dlugoscLinii; i++)
            {
                if(linia[i]==124)
                {
                    ostatniZnak[k]=i;
                    k++;
                }
            }

            nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[0]-pierwszyZnak);
            idUzytkownika=atoi(linia.c_str());
            pierwszyZnak=ostatniZnak[0]+1;

            nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[1]-pierwszyZnak);
            nazwaUzytkownika=nowyWyraz;
            pierwszyZnak=ostatniZnak[1]+1;

            nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[2]-pierwszyZnak);
            hasloUzytkownika=nowyWyraz;

            uzytkownik.ustawIdUzytkownika(idUzytkownika);
            uzytkownik.ustawNazweUzytkownika(nazwaUzytkownika);
            uzytkownik.ustawHasloUzytkownika(hasloUzytkownika);

            uzytkownicy.push_back(uzytkownik);
        }
        plik.close();
    }
    return uzytkownicy;
}

vector <string> PlikiZUzytkownikami::wczytajLinieZPlikuDoWektora ()
{
    vector <string> linieUzytkownikow;
    string linia;
    linieUzytkownikow.clear();

    plik.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(),ios::in);

    if (plik.good()==true)
    {
        while(getline(plik,linia))
        {
            linieUzytkownikow.push_back(linia);
        }
        plik.close();
    }

    return linieUzytkownikow;
}

void PlikiZUzytkownikami::dodajNowegoUzytkownikaDoPlikuZUzytkownikami (int id, string nazwa, string haslo)
{
    plik.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(), ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << id;
        plik << "|";
        plik << nazwa;
        plik << "|";
        plik << haslo;
        plik << "|";
        plik << endl;
        plik.close();

        cout << endl << "Uzytkownik zostal dodany." << endl;
        cout << "Wielkosc wektora uzytkownicy: " << id << endl << endl;
    }

    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl << endl;
    }

    system("pause");
}
