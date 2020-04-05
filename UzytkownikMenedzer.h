#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include "Uzytkownik.h"
#include "PlikiZUzytkownikami.h"
#include "MetodyPomocnicze.h"
#include <vector>
#include <fstream>

using namespace std;

class UzytkownikMenedzer
{
    Uzytkownik uzytkownik;
    PlikiZUzytkownikami plikiZUzytkownikami;

    vector <Uzytkownik> uzytkownicy;

public:


    UzytkownikMenedzer()
    {
        uzytkownicy=plikiZUzytkownikami.wczytajUzytkownikowZPliku();
    };


    Uzytkownik rejestracjaUzytkownika();
    void wyswietlDaneUzytkownika(Uzytkownik uzytkownik);
    void wyswietlWszystkichUzytkownikow();
};

#endif
