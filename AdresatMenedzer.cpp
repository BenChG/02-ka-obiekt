#include "AdresatMenedzer.h"

Adresat AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;
    int idAdresata=1;
    int idUzytkownika=idZalogowanegoUzytkownika;

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

void AdresatMenedzer::wyszukajPoImieniu(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    string czyZnalezionoImie="NIE";
    string podaneImie = metodyPomocnicze.podajImie();

    for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (wyswietlaniePoImieniu(*itr, podaneImie, idZalogowanegoUzytkownika)=="TAK")
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

string AdresatMenedzer::wyswietlaniePoImieniu (Adresat adresat, string podaneImie, int idZalogowanegoUzytkownika)
{
    if (adresat.pobierzImie() == podaneImie & adresat.pobierzIdUzytkownika()== idZalogowanegoUzytkownika)
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

void AdresatMenedzer::wyszukajPoNazwisku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    string czyZnalezionoNazwisko = "NIE";
    string podaneNazwisko = metodyPomocnicze.podajNazwisko();

    for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (wyswietlaniePoNazwisku(*itr, podaneNazwisko, idZalogowanegoUzytkownika)=="TAK")
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

string AdresatMenedzer::wyswietlaniePoNazwisku(Adresat adresat, string podaneNazwisko, int idZalogowanegoUzytkownika)
{
    if (adresat.pobierzNazwisko() == podaneNazwisko & adresat.pobierzIdUzytkownika() == idZalogowanegoUzytkownika )
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

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat, int idZalogowanegoUzytkownika)
{
    if (adresat.pobierzIdUzytkownika() == idZalogowanegoUzytkownika )
    {
        cout << "Id:         "         << adresat.pobierzIdAdresata() << endl;
        cout << "Imie:               " << adresat.pobierzImie() << endl;
        cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
        cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
        cout << "Email:              " << adresat.pobierzEmail() << endl;
        cout << "Adres:              " << adresat.pobierzAdres() << endl << endl;
    }
}

void AdresatMenedzer::wyswietlWszystkichAdresatow(int idZalogowanegoUzytkownika)
{
    system("cls");

    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr, idZalogowanegoUzytkownika);
        }
        cout << endl;
    }

    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::usunAdresata(int idZalogowanegoUzytkownika)
{
    system("cls");

    int liczbaAdresatow=linieAdresatow.size()-1;
    int i=0;
    int verticalLine[2];
    int adresatDoUsuniecia;
    char czyPotwierdzono;
    string czyZnalezionoAdresata="NIE";

    cout << "Podaj nr ID adresata, ktory ma zostac usuniety: " << endl;
    cin >> adresatDoUsuniecia;

    cout << "Nacisnij 't', aby potwierdzic usunecie adresata o nr ID: " << adresatDoUsuniecia << endl;
    cin >> czyPotwierdzono;

    if (czyPotwierdzono=='t')
    {
        fstream plik;
        plik.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(),ios::out);

        if (plik.good() == true)
        {

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
        }
        plik.close();

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

string AdresatMenedzer::edytujAdresata(Adresat adresat, string linia, string zmianaDanych, char wybor)
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

void AdresatMenedzer::wyszukajAdresataDoEdycji(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    if (!adresaci.empty())
    {
        string zmianaDanych="";
        string czyZnalezionoAdresata="NIE";
        string nazwaUzytkownika;
        string hasloUzytkownika;
        string nowyWyraz;
        char wybor;
        int ileAdresatow=linieAdresatow.size()-1;
        int adresatDoEdycji;
        int idAdresata;
        int idUzytkownika;
        int verticalLine;
        int i=0;

        cout << "Podaj ID adresata, ktorej dane chcesz edytowac: ";
        cin >> adresatDoEdycji;

        wybor=metodyPomocnicze.wybierzDanaDoEdycji();

        if (wybor == '6')
        {
         cout << endl << "Za chwile zostaniesz przekierowany do Menu Glownego." << endl << endl;
        }

        else
        {
            fstream plik;
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

                            plik << edytujAdresata(adresat, trescDoEdycji, zmianaDanych, wybor) << endl;
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

                adresaci=plikiZAdresatami.wczytajAdresatowZPliku();
                linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
            }
        }
    }

    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
        system("pause");
    }
}
