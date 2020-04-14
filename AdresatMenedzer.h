#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include "Adresat.h"
#include "PlikiZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
    Adresat adresat;
    PlikiZAdresatami plikiZAdresatami;

    vector <Adresat> adresaci;
    vector <string> linieAdresatow;
    string podaneImie;
    string podaneNazwisko;

    void wyswietlDaneAdresata(Adresat adresat, int idZalogowanegoUzytkownika);
    string wyswietlaniePoImieniu(Adresat adresat, string podaneImie, int idZalogowanegoUzytkowika);
    string wyswietlaniePoNazwisku(Adresat adresat, string podaneNazwisko, int idZalogowanegoUzytkownika);
    string edytujAdresata(Adresat adresat, string trescDoEdycji, string zmianaDanych, char wybor);

public:
    AdresatMenedzer()
    {
        adresaci=plikiZAdresatami.wczytajAdresatowZPliku();
        linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
    };

    Adresat dodajAdresata(int idZalogowanegoUzytkownika);
    void wyszukajPoImieniu(int idZalogowanegoUzytkownika);
    void wyszukajPoNazwisku(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow(int idZalogowanegoUzytkownika);
    void usunAdresata(int idZalogowanegoUzytkownika);
    void wyszukajAdresataDoEdycji(int idZalogowanegoUzytkownika);
};

#endif

