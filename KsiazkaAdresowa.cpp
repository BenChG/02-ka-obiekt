#include "KsiazkaAdresowa.h"

char KsiazkaAdresowa::wybierzOpcjeZMenuLogowania()
{
    metodyPomocnicze.wybierzOpcjeZMenuLogowania();
}

int KsiazkaAdresowa::wyszukajUzytkownika()
{
    uzytkownikMenedzer.wyszukajUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer = new AdresatMenedzer (NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    metodyPomocnicze.wybierzOpcjeZMenuGlownego();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenedzer->dodajAdresata();
}

void KsiazkaAdresowa::wyszukajPoImieniu()
{
    adresatMenedzer->wyszukajPoImieniu();
}

void KsiazkaAdresowa::wyszukajPoNazwisku()
{
    adresatMenedzer->wyszukajPoNazwisku();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::usunAdresata()
{
    adresatMenedzer->usunAdresata();
}

void KsiazkaAdresowa::wyszukajAdresataDoEdycji()
{
    adresatMenedzer->wyszukajAdresataDoEdycji();
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikMenedzer.wylogujUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::zmianaHaslaUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaUzytkownika();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}
