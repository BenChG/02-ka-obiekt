#include "PlikiZAdresatami.h"

vector <Adresat> PlikiZAdresatami::wczytajAdresatowZPliku()
{
    vector <Adresat> adresaci;
    Adresat adresat;
    adresaci.clear();

    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;
    string nowyWyraz;
    string linia;
    int idAdresata;
    int idUzytkownika;
    int ostatniZnak[7];

    plik.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(),ios::in);

    if (plik.good() == true)
    {
        while(getline(plik,linia))
        {
            int k=0, pierwszyZnak=0, dlugoscLinii=linia.length();

            for (int i=0; i<dlugoscLinii; i++)
            {
                if(linia[i]==124)
                {
                    ostatniZnak[k]=i;
                    k++;
                }
            }

            nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[0]-pierwszyZnak);
            idAdresata=atoi(nowyWyraz.c_str());
            pierwszyZnak=ostatniZnak[0]+1;

            nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[1]-pierwszyZnak);
            idUzytkownika=atoi(nowyWyraz.c_str());
            pierwszyZnak=ostatniZnak[1]+1;

            nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[2]-pierwszyZnak);
            imie=nowyWyraz;
            pierwszyZnak=ostatniZnak[2]+1;

            nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[3]-pierwszyZnak);
            nazwisko=nowyWyraz;
            pierwszyZnak=ostatniZnak[3]+1;

            nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[4]-pierwszyZnak);
            numerTelefonu=nowyWyraz;
            pierwszyZnak=ostatniZnak[4]+1;

            nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[5]-pierwszyZnak);
            email=nowyWyraz;
            pierwszyZnak=ostatniZnak[5]+1;

            nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[6]-pierwszyZnak);
            adres=nowyWyraz;

            adresat.ustawIdAdresata(idAdresata);
            adresat.ustawIdUzytkownika(idUzytkownika);
            adresat.ustawImie(imie);
            adresat.ustawNazwisko(nazwisko);
            adresat.ustawNumerTelefonu(numerTelefonu);
            adresat.ustawEmail(email);
            adresat.ustawAdres(adres);

            adresaci.push_back(adresat);
        }
        plik.close();
    }
    return adresaci;
}

vector <string> PlikiZAdresatami::wczytajLinieZPlikuDoWektora ()
{
    vector <string> linieAdresatow;
    string linia;
    linieAdresatow.clear();

    plik.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(),ios::in);

    if (plik.good()==true)
    {
        while(getline(plik,linia))
        {
            linieAdresatow.push_back(linia);
        }
        plik.close();
    }

    return linieAdresatow;
}

void PlikiZAdresatami::dodajNowegoAdresataDoPlikuZAdresatami (int idA, int idU, string imie, string nazwisko, string tel, string email, string adres)
{
    plik.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(),ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << idA;
        plik << "|";
        plik << idU;
        plik << "|";
        plik << imie;
        plik << "|";
        plik << nazwisko;
        plik << "|";
        plik << tel;
        plik << "|";
        plik << email;
        plik << "|";
        plik << adres;
        plik << "|";
        plik << endl;
        plik.close();

        cout << endl << "Adresat zostal dodany." << endl;
    }

    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl << endl;
    }
    system("pause");
}
