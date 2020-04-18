#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H
#include <iostream>

using namespace std;

class Uzytkownik
{
    int idUzytkownika;
    string nazwaUzytkownika;
    string hasloUzytkownika;

public:

    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawNazweUzytkownika (string nowaNazwaUzytkownika);
    void ustawHasloUzytkownika (string noweHasloUzytkownika);

    int pobierzIdUzytkownika();
    string pobierzNazweUzytkownika();
    string pobierzHasloUzytkownika();

    Osoba (int=0, string nazwaUzytkownika="", string hasloUzytkownika="")
    {
        this->idUzytkownika = idUzytkownika;
        this->nazwaUzytkownika = nazwaUzytkownika;
        this->hasloUzytkownika = hasloUzytkownika;
    }
};

#endif
