#ifndef PLIKIZADRESATAMI_H
#define PLIKIZADRESATAMI_H

#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Adresat.h"

using namespace std;

class PlikiZAdresatami
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    vector <Adresat> adresaci;
    vector <string> linieAdresatow;
    Adresat adresat;
    fstream plik;

public:

    PlikiZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {

    };

    vector <Adresat> wczytajAdresatowZPliku();
    vector <string> wczytajLinieZPlikuDoWektora();
    void dodajNowegoAdresataDoPlikuZAdresatami (int idA, int idU, string imie, string nazwisko, string tel, string email, string adres);
};

#endif
