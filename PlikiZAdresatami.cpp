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


string PlikiZAdresatami::usunAdresataZPliku(int adresatDoUsuniecia, int idZalogowanegoUzytkownika, vector <string> linieAdresatow)
{
    plik.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(),ios::out);

    if (plik.good() == true)
    {
        int liczbaAdresatow=linieAdresatow.size()-1;
        int i=0;
        int verticalLine[2];
        string czyZnalezionoAdresata = "NIE";

        for (int itr=0; itr<=liczbaAdresatow; itr++)

        {
            int idAdresata=atoi(linieAdresatow[itr].c_str());

            if (idAdresata!=adresatDoUsuniecia)
            {
                plik << linieAdresatow[itr] << endl;
            }

            else
            {
                string linia=linieAdresatow[itr];
                int dlugoscLinii=linia.length();

                for (int znak=0; znak<dlugoscLinii; znak++)
                {
                    if(linia[znak]==124)
                    {
                        verticalLine[i]=znak;
                        i++;
                        if (i==2)
                            break;
                    }
                }

                linia = linia.substr(verticalLine[0]+1,dlugoscLinii);
                int idUzytkownika=atoi(linia.c_str());

                if (idUzytkownika==idZalogowanegoUzytkownika)
                {
                    czyZnalezionoAdresata="TAK";
                }

                else
                {
                    plik << linieAdresatow[itr] << endl;
                }
            }
        }
        plik.close();
        return czyZnalezionoAdresata;
    }

    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl << endl;
    }
}

void PlikiZAdresatami::edytujAdresataWPliku(int adresatDoEdycji, int idZalogowanegoUzytkownika, char wybor, vector <string> linieAdresatow, vector <Adresat> adresaci)
{
    string zmianaDanych="";
    string czyZnalezionoAdresata="NIE";
    string nazwaUzytkownika;
    string hasloUzytkownika;
    string nowyWyraz;
    int ileAdresatow=linieAdresatow.size()-1;
    int idAdresata;
    int idUzytkownika;
    int verticalLine;
    int i=0;
    plik.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out);

    if (plik.good() == true)
    {
        for (int itr = 0; itr <= ileAdresatow; itr++)
        {
            idAdresata=atoi(linieAdresatow[itr].c_str());
            string linia=linieAdresatow[itr];
            int dlugoscLinii=linia.length()-1;

            for (int znak=0; znak<=dlugoscLinii; znak++)
            {
                if(linia[znak]==124)
                {
                    verticalLine=znak;
                    break;
                }
            }

            linia = linia.substr(verticalLine+1,dlugoscLinii);
            idUzytkownika=atoi(linia.c_str());

            if (idAdresata==adresatDoEdycji & idUzytkownika==idZalogowanegoUzytkownika)
            {
                cout << "Podaj nowa tresc wybranej danej: " << endl;
                cin >> zmianaDanych;

                string trescDoEdycji=linieAdresatow[itr];

                plik << zmienDaneAdresata(adresat, trescDoEdycji, zmianaDanych, wybor) << endl;
                czyZnalezionoAdresata="TAK";
            }

            else
            {
                plik << linieAdresatow[itr] << endl;
            }
        }
        plik.close();

        if (czyZnalezionoAdresata=="TAK")
        {
            cout << "Dane adresata o ID nr: " << adresatDoEdycji << " zostaly zmienione." << endl << endl;
        }

        else
        {
            cout << "Brak adresata o nr ID: " << adresatDoEdycji << " w ksiazce adresowej." << endl << endl;
        }
        system("pause");
    }
}

string PlikiZAdresatami::zmienDaneAdresata(Adresat adresat, string linia, string zmianaDanych, char wybor)
{
    string idAdresata;
    string idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;
    string nowyWyraz;

    int dlugoscLinii=linia.length()-1;
    int ostatniZnak[7];
    int k=0;
    int pierwszyZnak=0;

    for (int znak=0; znak<=dlugoscLinii; znak++)
    {
        if(linia[znak]==124)
        {
            ostatniZnak[k]=znak;
            k++;
        }
    }

    nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[0]-pierwszyZnak);
    idAdresata=nowyWyraz;
    pierwszyZnak=ostatniZnak[0]+1;

    nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[1]-pierwszyZnak);
    idUzytkownika=nowyWyraz;
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

    if (wybor == '1')
    {
        imie=zmianaDanych;
    }
    else if (wybor == '2')
    {
        nazwisko=zmianaDanych;
    }
    else if (wybor == '3')
    {
        numerTelefonu=zmianaDanych;
    }
    else if (wybor == '4')
    {
        email=zmianaDanych;
    }
    else if (wybor == '5')
    {
        adres=zmianaDanych;
    }

    linia=idAdresata+"|"+idUzytkownika+"|"+imie+"|"+nazwisko+"|"+numerTelefonu+"|"+email+"|"+adres+"|";

    return linia;
}
