#pragma once
#include "podstawapostaci.h"

class Zlodziej : public Podstawa
{
protected:
	string rodzajAtaku;
	string rodzajZlodzieja;
public:
	Zlodziej();
	Zlodziej(string rodzajAtaku, string rodzajZlodzieja, int sila, int zrecznosc, int inteligencja, double zloto, int rozmiar_opisu, string* opisPostaci);

	void printPodstawa();

	void write(ofstream&);

	~Zlodziej();
};
