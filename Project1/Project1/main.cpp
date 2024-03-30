#include <string>
#include <fstream>
#include <vector>
#include "podstawapostaci.h"
#include "mag.h"
#include "wojownik.h"
#include "z³odziej.h"

string rodzajAtaku;
string rodzajZlodzieja;

double pancerz;
string rodzajBroni;

string umiejetnosciMaga;
string specjalizacjeMaga;

int sila;
int zrecznosc;
int inteligencja;
double zloto;
int rozmiar_opisu = 5;
vector<string> opisPostaci;
string opis[5];

void DodajPodstawowaPostac();
void DodajMaga();
void DodajWojownika();
void DodajZlodzieja();

vector<Podstawa> vectorPodstawa;
vector<Mag> vectorMag;
vector<Wojownik> vectorWojownik;
vector<Zlodziej> vectorZlodziej;

template<typename T>
T add(T a, T b) {
	return a + b;
}

int main(int argc, int argv[])
{
    if (argc > 2) {
        cout << "Zla ilosc argumentow" << endl;
    }
   
    int doWhile = 2;
    int wybor;
    while (doWhile > 0) {
        cout << "Podaj opcje : 1.Postac Podstawowa, 2.Mag, 3.Wojownik, 4.Zlodziej" << endl;
        cin >> wybor;
        if (wybor == 1) {
            DodajPodstawowaPostac();
        }
        else if (wybor == 2) {
            DodajMaga();
        }
        else if (wybor == 3) {
            DodajWojownika();
        }
        else if (wybor == 4) {
            DodajZlodzieja();
        }
        else {
            doWhile++;
            cout << "Podales zla opcje sprobuj ponownie";
        }
        doWhile--;
    }

    // ZAPISYWANIE DO PLIKU
    cout << "Czy chcesz zapisac swoje przedmioty do pliku (T / N)" << endl;
    char czy_zapisac;
    cin >> czy_zapisac;
    while (czy_zapisac != 'T' && czy_zapisac != 'N') {
        cout << "Nie rozumiem podaj wybor jeszcze raz (T / N)" << endl;
        cin >> czy_zapisac;
    }
    string plik;
    if (czy_zapisac == 'T') {
        cout << "Podaj nazwê pliku do ktorego mam zapisac dane: ";
        cin >> plik;
        plik += ".bin";
        ofstream streamBin{ plik, ios::binary };

        int rozmiar = size(vectorPodstawa);
        for (int i = 0; i < rozmiar; i++) {
            vectorPodstawa[i].write(streamBin);
        }
        rozmiar = size(vectorMag);
        for (int i = 0; i < rozmiar; i++) {
            vectorMag[i].write(streamBin);
        }
        rozmiar = size(vectorWojownik);
        for (int i = 0; i < rozmiar; i++) {
            vectorWojownik[i].write(streamBin);
        }
        rozmiar = size(vectorZlodziej);
        for (int i = 0; i < rozmiar; i++) {
            vectorZlodziej[i].write(streamBin);
        }
        streamBin.close();
    }

    // ODCZYTYWANIE Z PLIKU
    char czy_odczytac;
    cout << "Czy chcesz odtworzyc binarny plik i wypisac z niego informacje (T / N)" << endl;
    cin >> czy_odczytac;
    while (czy_odczytac != 'T' && czy_odczytac != 'N') {
        cout << "Nie rozumiem podaj wybor jeszcze raz (T / N)" << endl;
        cin >> czy_odczytac;
    }

    if (czy_odczytac == 'T') {
        cout << "Podaj nazwê pliku z ktorego mam zczytac dane: ";
        cin >> plik;
        plik += ".bin";
        ifstream streamBin2{ plik, ios::binary };

        int ilosc_ob;
        cout << "Ile jest obiektow w tym pliku: ";
        cin >> ilosc_ob;

        int pom_int;
        double pom_double;
        string pom_str;
        if (streamBin2.good()) {
            for (int i = 0; i < ilosc_ob; i++) {
                streamBin2.read(reinterpret_cast<char*>(&pom_double), sizeof(double));
                cout << pom_double << "	";
                for (int j = 0; j < rozmiar_opisu; j++) {
                    streamBin2.read(reinterpret_cast<char*>(&pom_int), sizeof(int));
                    pom_str.resize(pom_int);
                    streamBin2.read((&pom_str[0]), pom_int);
                    cout << pom_str << "	";
                }
                cout << endl;
            }
        }
        streamBin2.close();

    }

}

void DodajPodstawowaPostac() {
    cout << "Podaj sile postaci: ";
    cin >> (sila);
    cout << "Podaj zrecznosc postaci: ";
    cin >> (zrecznosc);
    cout << "Podaj inteligencje postaci: ";
    cin >> (inteligencja);
    cout << "Podaj zloto postaci: ";
    cin >> (zloto);
    cout << "Podaj dlugosc opisu postaci\n" << endl;
    for (int i = 0; i < rozmiar_opisu; i++) {
        cout << "Wpisz opis po jednym slowie " << opis[i] << ": ";
        cin >> opis[i];
    }
    cout << endl;
    Podstawa Podstawa1(sila, zrecznosc, inteligencja, zloto, rozmiar_opisu, opis);
    vectorPodstawa.push_back(Podstawa1);
    Podstawa1.printPodstawa();
}

void DodajMaga() {
    cout << "Podaj sile postaci: ";
    cin >> (sila);
    cout << "Podaj zrecznosc postaci: ";
    cin >> (zrecznosc);
    cout << "Podaj inteligencje postaci: ";
    cin >> (inteligencja);
    cout << "Podaj zloto postaci: ";
    cin >> (zloto);
    cout << "Podaj dlugosc opisu postaci\n" << endl;
    for (int i = 0; i < rozmiar_opisu; i++) {
        cout << "Wpisz opis po jednym slowie " << opis[i] << ": ";
        cin >> opis[i];
    }
    cout << endl;
    cout << "Podaj umiejetnosc Maga: ";
    cin >> (umiejetnosciMaga);
    cout << "Podaj specjalizacje Maga: ";
    cin >> (specjalizacjeMaga);

    Mag Mag1(umiejetnosciMaga, specjalizacjeMaga, sila, zrecznosc, inteligencja, zloto, rozmiar_opisu, opis);
    vectorMag.push_back(Mag1);
    Mag1.printPodstawa();
}

void DodajWojownika() {
    cout << "Podaj sile postaci: ";
    cin >> (sila);
    cout << "Podaj zrecznosc postaci: ";
    cin >> (zrecznosc);
    cout << "Podaj inteligencje postaci: ";
    cin >> (inteligencja);
    cout << "Podaj zloto postaci: ";
    cin >> (zloto);
    cout << "Podaj dlugosc opisu postaci\n" << endl;
    for (int i = 0; i < rozmiar_opisu; i++) {
        cout << "Wpisz opis po jednym slowie " << opis[i] << ": ";
        cin >> opis[i];
    }
    cout << endl;
    cout << "Podaj rodzaj broni Wojownika: ";
    cin >> (rodzajBroni);
    cout << "Podaj pancerz: ";
    cin >> (pancerz);

    Wojownik Wojownik1(pancerz, rodzajBroni, sila, zrecznosc, inteligencja, zloto, rozmiar_opisu, opis);
    vectorWojownik.push_back(Wojownik1);
    Wojownik1.printPodstawa();
}

void DodajZlodzieja() {
    cout << "Podaj sile postaci: ";
    cin >> (sila);
    cout << "Podaj zrecznosc postaci: ";
    cin >> (zrecznosc);
    cout << "Podaj inteligencje postaci: ";
    cin >> (inteligencja);
    cout << "Podaj zloto postaci: ";
    cin >> (zloto);
    cout << "Podaj dlugosc opisu postaci\n" << endl;
    for (int i = 0; i < rozmiar_opisu; i++) {
        cout << "Wpisz opis po jednym slowie " << opisPostaci[i] << ": ";
        cin >> opisPostaci[i];
    }
    cout << endl;
    cout << "Podaj rodzaj ataku Zlodzieja: ";
    cin >> (rodzajAtaku);
    cout << "Podaj rodzaj Zlodzieja: ";
    cin >> (rodzajZlodzieja);

    Zlodziej Zlodziej1(rodzajAtaku, rodzajZlodzieja, sila, zrecznosc, inteligencja, zloto, rozmiar_opisu, opis);
    vectorZlodziej.push_back(Zlodziej1);
    Zlodziej1.printPodstawa();
}