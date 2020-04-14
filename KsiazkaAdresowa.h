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
    char wybierzOpcjeZMenuGlownego();
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wyszukajPoImieniu(int idZalogowanegoUzytkownika);
    void wyszukajPoNazwisku(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow(int idZalogowanegoUzytkownika);
    void usunAdresata(int idZalogowanegoUzytkownika);
    void wyszukajAdresataDoEdycji(int idZalogowanegoUzytkownika);
    void wylogujUzytkownika();
    void zmianaHaslaUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
