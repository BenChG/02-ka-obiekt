#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include "Adresat.h"
#include "PlikiZAdresatami.h"
#include "MetodyPomocnicze.h"
#include <iostream>
using namespace std;

class AdresatMenedzer
{
    Adresat adresat;
    PlikiZAdresatami plikiZAdresatami;

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    vector <string> linieAdresatow;
    string podaneImie;
    string podaneNazwisko;

    void wyswietlDaneAdresata(Adresat adresat);
    string wyswietlaniePoImieniu(Adresat adresat, string podaneImie);
    string wyswietlaniePoNazwisku(Adresat adresat, string podaneNazwisko);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikiZAdresatami(nazwaPlikuZAdresatami),
          ID_ZALOGOWANEGO_UZYTKOWNIKA (idZalogowanegoUzytkownika)
    {
        adresaci=plikiZAdresatami.wczytajAdresatowZPliku();
        linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
    };

    Adresat dodajAdresata();
    void wyszukajPoImieniu();
    void wyszukajPoNazwisku();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
    void wyszukajAdresataDoEdycji();
};

#endif

