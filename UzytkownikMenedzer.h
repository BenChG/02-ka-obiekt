#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include "Uzytkownik.h"
#include "PlikiZUzytkownikami.h"
#include "MetodyPomocnicze.h"
#include <vector>
#include <fstream>

using namespace std;

class UzytkownikMenedzer
{
    Uzytkownik uzytkownik;
    PlikiZUzytkownikami plikiZUzytkownikami;

    vector <Uzytkownik> uzytkownicy;
    vector <string> linieUzytkownikow;
    int idZalogowanegoUzytkownika;

public:


    UzytkownikMenedzer()
    {
        uzytkownicy=plikiZUzytkownikami.wczytajUzytkownikowZPliku();
        linieUzytkownikow=plikiZUzytkownikami.wczytajLinieZPlikuDoWektora();
        idZalogowanegoUzytkownika=0;
    };

    Uzytkownik rejestracjaUzytkownika();
    int wyszukajUzytkownika();
    int logowanieUzytkownika(Uzytkownik uzytkownik, string nazwa);
    void wyswietlDaneUzytkownika(Uzytkownik uzytkownik);
    void wyswietlWszystkichUzytkownikow();
    void wylogujUzytkownika();
    void zmianaHaslaUzytkownika();
    string edytujUzytkownika(Uzytkownik uzytkownik, string linia, string noweHaslo);
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
