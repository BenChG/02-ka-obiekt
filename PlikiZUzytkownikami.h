#ifndef PLIKIUZYTKOWNIKAMI_H
#define PLIKIUZYTKOWNIKAMI_H

#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Uzytkownik.h"

using namespace std;

class PlikiZUzytkownikami
{
    vector <Uzytkownik> uzytkownicy;
    vector <string> linieuzytkownikow;
    Uzytkownik uzytkownik;

public:
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    vector <string> wczytajLinieZPlikuDoWektora();
};

#endif
