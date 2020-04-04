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
    //PlikiZUzytkownikami plikiZUzytkownikami;

    vector <Uzytkownik> uzytkownicy;
    //vector <string> linieAdresatow;
    //string podaneImie;
    //string podaneNazwisko;

public:

    /*
    AdresatMenedzer()
    {
        adresaci=plikiZAdresatami.wczytajAdresatowZPliku();
        linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
    };
    */

    Uzytkownik rejestracjaUzytkownika();
};

#endif
