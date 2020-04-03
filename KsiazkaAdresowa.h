#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

//#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "MetodyPomocnicze.h"
#include <iostream>
using namespace std;

class KsiazkaAdresowa
{
    AdresatMenedzer adresatMenedzer;
    MetodyPomocnicze metodyPomocnicze;

public:
    char wybierzOpcjeZMenuGlownego();
    void dodajAdresata();
    void wyszukajPoImieniu();
    void wyszukajPoNazwisku();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
    void wyszukajAdresataDoEdycji();
};

#endif
