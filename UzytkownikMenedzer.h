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

    const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;
    vector <Uzytkownik> uzytkownicy;
    vector <string> linieUzytkownikow;
    int idZalogowanegoUzytkownika;

    int logowanieUzytkownika(Uzytkownik uzytkownik, string nazwa);
    string edytujUzytkownika(Uzytkownik uzytkownik, string linia, string noweHaslo);

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami)
        : plikiZUzytkownikami(nazwaPlikuZUzytkownikami),
          NAZWA_PLIKU_Z_UZYTKOWNIKAMI (nazwaPlikuZUzytkownikami)
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
    bool czyUzytkownikJestZalogowany();
};

#endif
