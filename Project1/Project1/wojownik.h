#pragma once
#include "podstawapostaci.h"

class Wojownik : public Podstawa
{
protected:
	double pancerz;
	string rodzajBroni;
public:
	Wojownik();
	Wojownik(double pancerz, string rodzajBroni, int sila, int zrecznosc, int inteligencja, double zloto, int rozmiar_opisu, string* opisPostaci);

	void printPodstawa() override;

	void write(ofstream&);

	~Wojownik();
};
