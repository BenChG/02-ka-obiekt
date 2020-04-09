#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;
    MetodyPomocnicze metodyPomocnicze;

public:
    char wybierzOpcjeZMenuLogowania();
    void rejestracjaUzytkownika();
    int wyszukajUzytkownika();
    void wyswietlWszystkichUzytkownikow();
    char wybierzOpcjeZMenuGlownego();
    void dodajAdresata();
    void wyszukajPoImieniu();
    void wyszukajPoNazwisku();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
    void wyszukajAdresataDoEdycji();
    void wylogujUzytkownika();
    void zmianaHaslaUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
