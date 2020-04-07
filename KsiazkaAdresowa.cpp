#include "KsiazkaAdresowa.h"

char KsiazkaAdresowa::wybierzOpcjeZMenuLogowania()
{
metodyPomocnicze.wybierzOpcjeZMenuLogowania();
}

int KsiazkaAdresowa::wyszukajUzytkownika()
{
uzytkownikMenedzer.wyszukajUzytkownika();
}

void KsiazkaAdresowa::wyswietlWszystkichUzytkownikow()
{
uzytkownikMenedzer.wyswietlWszystkichUzytkownikow();
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
adresatMenedzer.dodajAdresata();
}

void KsiazkaAdresowa::wyszukajPoImieniu()
{
adresatMenedzer.wyszukajPoImieniu();
}

void KsiazkaAdresowa::wyszukajPoNazwisku()
{
adresatMenedzer.wyszukajPoNazwisku();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
adresatMenedzer.wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::usunAdresata()
{
 adresatMenedzer.usunAdresata();
}

void KsiazkaAdresowa::wyszukajAdresataDoEdycji()
{
  adresatMenedzer.wyszukajAdresataDoEdycji();
}
