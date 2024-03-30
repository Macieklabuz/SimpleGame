#include "mag.h"

Mag::Mag() {
	this->umiejetnosciMaga = "Kula Ognia";
	this->specjalizacjeMaga = "Magia Ognia";
}
Mag::Mag(string umiejetnosciMaga, string specjalizacjeMaga, int sila, int zrecznosc, int inteligencja, double zloto, int rozmiar_opisu, string* opisPostaci)
	:Podstawa(sila, zrecznosc, inteligencja, zloto, rozmiar_opisu, opisPostaci) {
	this->umiejetnosciMaga = umiejetnosciMaga;
	this->specjalizacjeMaga = specjalizacjeMaga;
}

void Mag::printPodstawa()
{
	cout << sila << " " << endl;
	cout << zrecznosc << " " << endl;
	cout << inteligencja << " " << endl;
	cout << zloto << " " << endl;
	for (int i = 0; i < rozmiar_opisu; i++) {
		cout << opisPostaci[i] << " ";
	}
	cout << endl;
	cout << " " << umiejetnosciMaga;
	cout << " " << specjalizacjeMaga;
}

void Mag::write(ofstream& file) {
	if (file.good()) {
		file.write(reinterpret_cast<char*>(&zloto), sizeof(double));
		int rozmiar = opisPostaci.size();
		for (int i = 0; rozmiar; i++) {
			int rozmiar1 = opisPostaci[i].size();
			file.write(reinterpret_cast<char*>(&rozmiar1), sizeof(int));
			file.write((&opisPostaci[i][0]), rozmiar1);
		}
	}
}

Mag::~Mag()
{
}
