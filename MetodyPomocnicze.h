#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <cstdlib>

using namespace std;

class MetodyPomocnicze
{
    char wczytajZnak();

public:
    char wybierzOpcjeZMenuLogowania();
    char wybierzOpcjeZMenuGlownego();
    char wybierzDanaDoEdycji();
    string wczytajLinie();
    string podajImie();
    string podajNazwisko();

};

#endif
