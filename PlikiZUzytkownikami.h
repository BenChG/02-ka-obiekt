#ifndef PLIKIUZYTKOWNIKAMI_H
#define PLIKIUZYTKOWNIKAMI_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Uzytkownik.h"

using namespace std;

class PlikiZUzytkownikami
{
    const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;
    vector <Uzytkownik> uzytkownicy;
    vector <string> linieuzytkownikow;
    Uzytkownik uzytkownik;
    fstream plik;

public:

    PlikiZUzytkownikami(string nazwaPlikuZUzytkownikami) : NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPlikuZUzytkownikami)
    {};

    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    vector <string> wczytajLinieZPlikuDoWektora();
    void dodajNowegoUzytkownikaDoPlikuZUzytkownikami(int id, string nazwa, string haslo);
};

#endif
