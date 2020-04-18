#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int idAdresata;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public:

    void ustawIdAdresata(int noweIdAdresata);
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawImie (string noweNazwisko);
    void ustawNazwisko (string noweNazwisko);
    void ustawNumerTelefonu (string nowyNumerTelefonu);
    void ustawEmail(string nowyEmail);
    void ustawAdres (string nowyAdres);

    int pobierzIdAdresata();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();

    Osoba (int idAdresata=0, int idUzytkownika=0, string imie="", string nazwisko="", string numerTelefonu="", string email="", string adres="")
    {
        this->idAdresata = idAdresata;
        this->idUzytkownika = idUzytkownika;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->numerTelefonu = numerTelefonu;
        this->email = email;
        this->adres = adres;
    }
};

#endif
