#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy2.txt","KsiazkaAdresowa2.txt");

    int idZalogowanegoUzytkownika=0;
    char wybor;

    while(true)
    {
        if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika()==0)
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuLogowania();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika=ksiazkaAdresowa.wyszukajUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }

        else
        {
            char wybor;

            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika);
                break;
            case '2':
                ksiazkaAdresowa.wyszukajPoImieniu(idZalogowanegoUzytkownika);
                break;
            case '3':
                ksiazkaAdresowa.wyszukajPoNazwisku(idZalogowanegoUzytkownika);
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow(idZalogowanegoUzytkownika);
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata(idZalogowanegoUzytkownika);
                break;
            case '6':
                ksiazkaAdresowa.wyszukajAdresataDoEdycji(idZalogowanegoUzytkownika);
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogujUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}
