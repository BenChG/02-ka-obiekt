#include "KsiazkaAdresowa.h"

char KsiazkaAdresowa::wybierzOpcjeZMenuLogowania()
{
    metodyPomocnicze.wybierzOpcjeZMenuLogowania();
}

int KsiazkaAdresowa::wyszukajUzytkownika()
{
    uzytkownikMenedzer.wyszukajUzytkownika();
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    metodyPomocnicze.wybierzOpcjeZMenuGlownego();
}

void KsiazkaAdresowa::dodajAdresata(int idZalogowanegoUzytkownika)
{
    adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wyszukajPoImieniu(int idZalogowanegoUzytkownika)
{
    adresatMenedzer.wyszukajPoImieniu(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wyszukajPoNazwisku(int idZalogowanegoUzytkownika)
{
    adresatMenedzer.wyszukajPoNazwisku(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(int idZalogowanegoUzytkownika)
{
    adresatMenedzer.wyswietlWszystkichAdresatow(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::usunAdresata(int idZalogowanegoUzytkownika)
{
    adresatMenedzer.usunAdresata(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wyszukajAdresataDoEdycji(int idZalogowanegoUzytkownika)
{
    adresatMenedzer.wyszukajAdresataDoEdycji(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikMenedzer.wylogujUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaUzytkownika();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}
