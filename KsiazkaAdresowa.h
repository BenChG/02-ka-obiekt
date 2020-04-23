#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    MetodyPomocnicze metodyPomocnicze;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) :
        uzytkownikMenedzer(nazwaPlikuZUzytkownikami),
        NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
    adresatMenedzer = NULL;
    };

    ~KsiazkaAdresowa()
    {
     delete adresatMenedzer;
     adresatMenedzer = NULL;
    };

 int pobierzIdZalogowanegoUzytkownika();
    char wybierzOpcjeZMenuLogowania();
    void rejestracjaUzytkownika();
    int wyszukajUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    void dodajAdresata();
    void wyszukajPoImieniu();
    void wyszukajPoNazwisku();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
    void wyszukajAdresataDoEdycji();
    void wylogujUzytkownika();
    void zmianaHaslaUzytkownika();
};

#endif
