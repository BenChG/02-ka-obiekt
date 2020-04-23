#include "AdresatMenedzer.h"

Adresat AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;
    int idAdresata=1;
    int idUzytkownika=ID_ZALOGOWANEGO_UZYTKOWNIKA;

    cout<<"idZalogowanegoUzytkownika"<<ID_ZALOGOWANEGO_UZYTKOWNIKA<<endl;
    system ("pause");

    cout << "Podaj imie: ";
    imie = metodyPomocnicze.wczytajLinie();

    cout << "Podaj nazwisko: ";
    nazwisko = metodyPomocnicze.wczytajLinie();

    cout << "Podaj numer telefonu: ";
    numerTelefonu = metodyPomocnicze.wczytajLinie();

    cout << "Podaj email: ";
    email = metodyPomocnicze.wczytajLinie();

    cout << "Podaj adres: ";
    adres = metodyPomocnicze.wczytajLinie();

    if (linieAdresatow.size()>=1)
    {
        int ostatniElement=linieAdresatow.size()-1;
        idAdresata=atoi(linieAdresatow[ostatniElement].c_str())+1;
    }

    adresat.ustawIdAdresata(idAdresata);
    adresat.ustawIdUzytkownika(idUzytkownika);
    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    adresaci.push_back(adresat);

    plikiZAdresatami.dodajNowegoAdresataDoPlikuZAdresatami (idAdresata, idUzytkownika, imie, nazwisko, numerTelefonu, email, adres);

    cout << "Wielkosc wektora adresaci: " << adresaci.size() << endl << endl;

    linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
    adresaci=plikiZAdresatami.wczytajAdresatowZPliku();

    return adresat;
}

void AdresatMenedzer::wyszukajPoImieniu()
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    string czyZnalezionoImie="NIE";
    string podaneImie = metodyPomocnicze.podajImie();

    for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (wyswietlaniePoImieniu(*itr, podaneImie)=="TAK")
        {
            czyZnalezionoImie="TAK";
        }
    }
    if (czyZnalezionoImie=="NIE")
    {
        cout << "Brak adresata o podanym imieniu w ksiazce adresowej." << endl << endl;
    }
    system("pause");
}

string AdresatMenedzer::wyswietlaniePoImieniu (Adresat adresat, string podaneImie)
{
    if (adresat.pobierzImie() == podaneImie & adresat.pobierzIdUzytkownika()== ID_ZALOGOWANEGO_UZYTKOWNIKA)
    {
        cout << endl;
        cout << "ID: " << adresat.pobierzIdAdresata()<< endl;
        cout << adresat.pobierzImie() << " " << adresat.pobierzNazwisko() << endl;
        cout << "Telefon: " <<adresat.pobierzNumerTelefonu() << endl;
        cout << "Email: " << adresat.pobierzEmail() << endl;
        cout << "Adres: " << adresat.pobierzAdres() << endl;
        cout << endl;
        string czyZnalezionoImie = "TAK";
        return czyZnalezionoImie;
    }

    else
    {
        string czyZnalezionoNazwisko = "NIE";
        return czyZnalezionoNazwisko;
    }
}

void AdresatMenedzer::wyszukajPoNazwisku()
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    string czyZnalezionoNazwisko = "NIE";
    string podaneNazwisko = metodyPomocnicze.podajNazwisko();

    for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (wyswietlaniePoNazwisku(*itr, podaneNazwisko)=="TAK")
        {
            czyZnalezionoNazwisko="TAK";
        }
    }

    if (czyZnalezionoNazwisko=="NIE")
    {
        cout << "Brak adresata o podanym nazwisku w ksiazce adresowej." << endl << endl;
    }
    system("pause");
}

string AdresatMenedzer::wyswietlaniePoNazwisku(Adresat adresat, string podaneNazwisko)
{
    if (adresat.pobierzNazwisko() == podaneNazwisko & adresat.pobierzIdUzytkownika() == ID_ZALOGOWANEGO_UZYTKOWNIKA)
    {
        cout << endl;
        cout << "ID adresata: " << adresat.pobierzIdAdresata() << endl;
        cout << adresat.pobierzImie() << " " << adresat.pobierzNazwisko() << endl;
        cout << "Telefon: " << adresat.pobierzNumerTelefonu() << endl;
        cout << "Email: " << adresat.pobierzEmail() << endl;
        cout << "Adres: " << adresat.pobierzAdres() << endl;
        cout << endl;
        string czyZnalezionoNazwisko = "TAK";

        return czyZnalezionoNazwisko;
    }

    else
    {
        string czyZnalezionoNazwisko = "NIE";
        return czyZnalezionoNazwisko;
    }
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    if (adresat.pobierzIdUzytkownika() == ID_ZALOGOWANEGO_UZYTKOWNIKA)
    {
        cout << "Id:         "         << adresat.pobierzIdAdresata() << endl;
        cout << "Imie:               " << adresat.pobierzImie() << endl;
        cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
        cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
        cout << "Email:              " << adresat.pobierzEmail() << endl;
        cout << "Adres:              " << adresat.pobierzAdres() << endl << endl;
    }
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    system("cls");

    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }

    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::usunAdresata()
{
    system("cls");

    int adresatDoUsuniecia;
    char czyPotwierdzono;

    cout << "Podaj nr ID adresata, ktory ma zostac usuniety: " << endl;
    cin >> adresatDoUsuniecia;

    cout << "Nacisnij 't', aby potwierdzic usunecie adresata o nr ID: " << adresatDoUsuniecia << endl;
    cin >> czyPotwierdzono;

    if (czyPotwierdzono=='t')
    {
        string czyZnalezionoAdresata=plikiZAdresatami.usunAdresataZPliku(adresatDoUsuniecia,ID_ZALOGOWANEGO_UZYTKOWNIKA, linieAdresatow);

        if (czyZnalezionoAdresata=="TAK")
        {
            cout << "Adresat o ID nr: " << adresatDoUsuniecia << " zostal usuniety." << endl << endl;
        }

        else
        {
            cout << "Brak adresata o nr ID: " << adresatDoUsuniecia << " w ksiazce adresowej." << endl << endl;
        }

    }

    adresaci=plikiZAdresatami.wczytajAdresatowZPliku();
    linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();

    if (czyPotwierdzono!='t')
    {
        cout << "Z powodu braku potwierdzenia adresat nie zostal usuniety." << endl << endl;
    }
    system("pause");
}


void AdresatMenedzer::wyszukajAdresataDoEdycji()
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    if (!adresaci.empty())
    {
        int adresatDoEdycji;
        char wybor;

        cout << "Podaj ID adresata, ktorej dane chcesz edytowac: ";
        cin >> adresatDoEdycji;

        wybor=metodyPomocnicze.wybierzDanaDoEdycji();

        if (wybor == '6')
        {
            cout << endl << "Za chwile zostaniesz przekierowany do Menu Glownego." << endl << endl;
        }

        else
        {

            plikiZAdresatami.edytujAdresataWPliku(adresatDoEdycji, ID_ZALOGOWANEGO_UZYTKOWNIKA, wybor, linieAdresatow, adresaci);

            adresaci=plikiZAdresatami.wczytajAdresatowZPliku();
            linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
        }
    }

    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
        system("pause");
    }
}
