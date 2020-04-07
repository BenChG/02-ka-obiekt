#include "UzytkownikMenedzer.h"

Uzytkownik UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik;
    MetodyPomocnicze metodyPomocnicze;

    string nazwaUzytkownika, hasloUzytkownika;
    int idUzytkownika=1;

    cout << "Podaj nazwe uzytkownika: ";
    nazwaUzytkownika = metodyPomocnicze.wczytajLinie();

    cout << "Podaj haslo uzytkownika: ";
    hasloUzytkownika = metodyPomocnicze.wczytajLinie();


    /*
    if (uzytkownicy.size()>=1)
    {
        int ostatniElement=linieAdresatow.size()-1;
        id=atoi(linieAdresatow[ostatniElement].c_str())+1;
    }
    */

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

    //linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
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

                idZnalezionegoUzytkownia=uzytkownik.pobierzIdUzytkownika();

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

    return idZnalezionegoUzytkownia;
}

int UzytkownikMenedzer::wyszukajUzytkownika()
{
    if (!uzytkownicy.empty())
    {
        string nazwa;
        int idZnalezionegoUzytkownika=0;

        cout << "Podaj nazwe: ";
        cin >> nazwa;


        for (vector <Uzytkownik> :: iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            idZnalezionegoUzytkownika=logowanieUzytkownika(*itr, nazwa);
            if (idZnalezionegoUzytkownika!=0)
            {
                return idZnalezionegoUzytkownika;
            }

        }

        if (idZnalezionegoUzytkownika==0)
        {
            cout << "Nie ma uzytkownika z takim loginem." << endl;
            system ("pause");
            return idZnalezionegoUzytkownika;
        }
    }
}



void UzytkownikMenedzer::wyswietlDaneUzytkownika(Uzytkownik uzytkownik)
{
    cout << "Id Uzytkownika:       " << uzytkownik.pobierzIdUzytkownika() << endl;
    cout << "Nazwa uzytkownika:    " << uzytkownik.pobierzNazweUzytkownika() << endl;
    cout << "Haslo Uzytkownia:     " << uzytkownik.pobierzHasloUzytkownika() << endl;
}

void UzytkownikMenedzer::wyswietlWszystkichUzytkownikow()
{
    system("cls");

    if (!uzytkownicy.empty())
    {
        cout << "             >>> UZYTKOWNICY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Uzytkownik> :: iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            wyswietlDaneUzytkownika(*itr);
            cout << endl;
        }
        cout << endl;
    }

    else
    {
        cout << endl << "Ksiazka uzytkownikow jest pusta." << endl << endl;
    }
    system("pause");
}
