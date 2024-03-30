#pragma once
#include "podstawapostaci.h"
class Mag : public Podstawa
{
protected:
	string umiejetnosciMaga;
	string specjalizacjeMaga;

public:
	Mag();
	Mag(string umiejetnosciMaga, string specjalizacjeMaga,int sila, int zrecznosc, int inteligencja, double zloto, int rozmiar_opisu, string* opisPostaci);
	
	void printPodstawa() override;

	void write(ofstream&);

	~Mag();
};
