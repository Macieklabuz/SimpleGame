#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Podstawa {
protected:
	int sila;
	int zrecznosc;
	int inteligencja;
	double zloto;
	int rozmiar_opisu;
	vector<string> opisPostaci;
public:
	Podstawa();
	Podstawa(int sila, int zrecznosc, int inteligencja, double zloto, int rozmiar_opisu ,string *opisPostaci);

	int getSila();
	int getZrecznosc();
	int getInteligencja();
	double getZloto();

	virtual void printPodstawa();
	
	void write(ofstream&);

	int operator+ (const Podstawa& prawda);

	virtual ~Podstawa();
};
