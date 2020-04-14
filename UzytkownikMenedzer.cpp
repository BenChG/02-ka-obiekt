#include "UzytkownikMenedzer.h"

Uzytkownik UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik;
    MetodyPomocnicze metodyPomocnicze;

    string nazwaUzytkownika, hasloUzytkownika;
    int idUzytkownika=0;

    if (uzytkownicy.size()>=1)
    {
        idUzytkownika=uzytkownicy.size()+1;
    }

    cout << "Podaj nazwe uzytkownika: ";
    nazwaUzytkownika = metodyPomocnicze.wczytajLinie();

    cout << "Podaj haslo uzytkownika: ";
    hasloUzytkownika = metodyPomocnicze.wczytajLinie();

    uzytkownik.ustawIdUzytkownika(idUzytkownika);
    uzytkownik.ustawNazweUzytkownika(nazwaUzytkownika);
    uzytkownik.ustawHasloUzytkownika(hasloUzytkownika);

    uzytkownicy.push_back(uzytkownik);

    fstream plik;
    plik.open("Uzytkownicy.txt",ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << uzytkownik.pobierzIdUzytkownika();
        plik << "|";
        plik << uzytkownik.pobierzNazweUzytkownika();
        plik << "|";
        plik << uzytkownik.pobierzHasloUzytkownika();
        plik << "|";
        plik << endl;
        plik.close();

        cout << endl << "Uzytkownik zostal dodany." << endl;
        cout << "Wielkosc wektora uzytkownicy: " << uzytkownicy.size() << endl << endl;
    }

    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl << endl;
    }

    system("pause");

    linieUzytkownikow=plikiZUzytkownikami.wczytajLinieZPlikuDoWektora();
    return uzytkownik;
}

int UzytkownikMenedzer::logowanieUzytkownika(Uzytkownik uzytkownik, string nazwa)
{
    string haslo, czyHasloJestPoprawne="NIE";
    int idZnalezionegoUzytkownia=0;

    if (uzytkownik.pobierzNazweUzytkownika() == nazwa)
    {
        for (int proby = 0; proby < 3; proby++)
        {
            cout << "Podaj haslo. Pozostalo prob " << 3-proby << ": ";
            cin >> haslo;
            if (uzytkownik.pobierzHasloUzytkownika() == haslo)
            {
                cout << "Zalogowales sie" << endl;
                system ("pause");
                czyHasloJestPoprawne = "TAK";

                idZalogowanegoUzytkownika=uzytkownik.pobierzIdUzytkownika();

                proby=2;
            }
        }

        if (czyHasloJestPoprawne=="NIE")
        {
            cout << "Nie udalo sie zalogowac, podano trzy razy bledne haslo!" << endl;
            system ("pause");
            exit(0);
        }
    }

    return idZalogowanegoUzytkownika;
}

int UzytkownikMenedzer::wyszukajUzytkownika()
{
    if (!uzytkownicy.empty())
    {
        string nazwa;
        int idZalogowanegoUzytkownika=0;

        cout << "Podaj nazwe: ";
        cin >> nazwa;


        for (vector <Uzytkownik> :: iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            idZalogowanegoUzytkownika=logowanieUzytkownika(*itr, nazwa);
            if (idZalogowanegoUzytkownika!=0)
            {
                return idZalogowanegoUzytkownika;
            }

        }

        if (idZalogowanegoUzytkownika==0)
        {
            cout << "Nie ma uzytkownika z takim loginem." << endl;
            system ("pause");
            return idZalogowanegoUzytkownika;
        }
    }
}

void UzytkownikMenedzer::wyswietlDaneUzytkownika(Uzytkownik uzytkownik)
{
    cout << "Id Uzytkownika:       " << uzytkownik.pobierzIdUzytkownika() << endl;
    cout << "Nazwa uzytkownika:    " << uzytkownik.pobierzNazweUzytkownika() << endl;
    cout << "Haslo Uzytkownia:     " << uzytkownik.pobierzHasloUzytkownika() << endl;
}

string UzytkownikMenedzer::edytujUzytkownika(Uzytkownik uzytkownik, string linia, string noweHaslo)
{
    int dlugoscLinii=linia.length();
    int ostatniZnak[3];
    int k=0;
    int pierwszyZnak=0;

    string idUzytkownika;
    string nazwaUzytkownika;
    string hasloUzytkownika;
    string nowyWyraz;

    for (int znak=0; znak<dlugoscLinii; znak++)
    {
        if(linia[znak]==124)
        {
            ostatniZnak[k]=znak;
            k++;
        }
    }
    nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[0]-pierwszyZnak);
    idUzytkownika=nowyWyraz;
    pierwszyZnak=ostatniZnak[0]+1;

    nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[1]-pierwszyZnak);
    nazwaUzytkownika=nowyWyraz;
    pierwszyZnak=ostatniZnak[1]+1;

    nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[2]-pierwszyZnak);
    hasloUzytkownika=nowyWyraz;
    pierwszyZnak=ostatniZnak[2]+1;

    linia=idUzytkownika+"|"+nazwaUzytkownika+"|"+noweHaslo+"|";
    return linia;
}

void UzytkownikMenedzer::zmianaHaslaUzytkownika()
{
    Uzytkownik uzytkownik;
    MetodyPomocnicze metodyPomocnicze;

    int ileUzytkownikow=linieUzytkownikow.size()-1;

    cout << "idZalogowanegoUzytkownika" << idZalogowanegoUzytkownika << endl;
    string noweHaslo;
    cout << "Podaj nowe haslo uzytkownika: " << endl;
    cin >> noweHaslo;

    fstream plik;
    plik.open("Uzytkownicy.txt", ios::out);

    if (plik.good() == true)
    {
        for (int itr = 0; itr <= ileUzytkownikow; itr++)
        {
            int id=atoi(linieUzytkownikow[itr].c_str());
            if (id==idZalogowanegoUzytkownika)
            {
                string trescDoEdycji=linieUzytkownikow[itr];
                plik << edytujUzytkownika(uzytkownik, trescDoEdycji, noweHaslo) << endl;
            }

            else
            {
                plik << linieUzytkownikow[itr] << endl;
            }
        }
        plik.close();

        uzytkownicy=plikiZUzytkownikami.wczytajUzytkownikowZPliku();
        linieUzytkownikow=plikiZUzytkownikami.wczytajLinieZPlikuDoWektora();
    }
}

void UzytkownikMenedzer::wylogujUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
