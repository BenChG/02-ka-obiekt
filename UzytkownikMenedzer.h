#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include "Uzytkownik.h"
#include "PlikiZUzytkownikami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class UzytkownikMenedzer
{
    Uzytkownik uzytkownik;
    PlikiZUzytkownikami plikiZUzytkownikami;

    vector <Uzytkownik> uzytkownicy;
    vector <string> linieUzytkownikow;
    int idZalogowanegoUzytkownika;

    int logowanieUzytkownika(Uzytkownik uzytkownik, string nazwa);
    void wyswietlDaneUzytkownika(Uzytkownik uzytkownik);
    string edytujUzytkownika(Uzytkownik uzytkownik, string linia, string noweHaslo);

public:

    UzytkownikMenedzer()
    {
        uzytkownicy=plikiZUzytkownikami.wczytajUzytkownikowZPliku();
        linieUzytkownikow=plikiZUzytkownikami.wczytajLinieZPlikuDoWektora();
        idZalogowanegoUzytkownika=0;
    };

    Uzytkownik rejestracjaUzytkownika();
    int wyszukajUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void zmianaHaslaUzytkownika();
    void wylogujUzytkownika();

     void wyswietlWszystkichUzytkownikow();
};

#endif
